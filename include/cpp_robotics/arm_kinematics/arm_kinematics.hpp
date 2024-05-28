#pragma once

#include "cpp_robotics/algorithm/auto_diff.hpp"
#include "cpp_robotics/optimize/derivative.hpp"
#include "cpp_robotics/optimize/quasi_newton_method.hpp"
#include "cpp_robotics/optimize/steepest_descent_method.hpp"
#include <Eigen/Dense>
#include <Eigen/Geometry>

namespace cpp_robotics {

namespace internal {

template <typename T, typename = void>
struct has_forward_kinematics : std::false_type {};

template <typename T, typename = void>
struct has_inverse_kinematics : std::false_type {};

template <typename T>
struct has_forward_kinematics<T, std::void_t<decltype(std::declval<T>().forward_kinematics(std::declval<Eigen::VectorXd>(), std::declval<Eigen::VectorXd &>()))>> : std::true_type {};

template <typename T>
struct has_inverse_kinematics<T, std::void_t<decltype(std::declval<T>().inverse_kinematics(std::declval<Eigen::VectorXd>(), std::declval<Eigen::VectorXd &>()))>> : std::true_type {};

} // namespace internal

template <class Derived>
class ArmKinematics {
public:
    /**
     * @brief Construct a new Arm IK object
     *
     * @param nq Number of joints
     * @param nx Number of end effector's degrees of freedom
     */
    ArmKinematics(size_t nq, size_t nx) : nq_(nq), nx_(nx), adq_(nq), adx_(nx) {
        static_assert(internal::has_forward_kinematics<Derived>::value, "Derived class must have forward_kinematics method");
        static_assert(internal::has_inverse_kinematics<Derived>::value, "Derived class must have inverse_kinematics method");
    }

    Eigen::VectorXd solve_fk(Eigen::VectorXd joint_angles) {
        return static_cast<Derived *>(this)->forward_kinematics(joint_angles);
    }

    Eigen::VectorXd solve_ik(Eigen::VectorXd pos, Eigen::VectorXd joint_angles0) {
        return static_cast<Derived *>(this)->inverse_kinematics(pos, joint_angles0);
    }

    Eigen::MatrixXd jacobian(Eigen::VectorXd joint_angles) {
        adq_ = joint_angles;
        static_cast<Derived *>(this)->forward_kinematics(adq_, adx_);
        Eigen::MatrixXd J(nx_, nq_);
        for (size_t i = 0; i < nq_; ++i) {
            J.col(i) = adx_[i].derivatives();
        }
        return J;
    }

private:
    size_t nq_;
    size_t nx_;
    ADVectorXd adq_, adx_;
};

template <class Derived>
class ArmForwardKinematics {
public:
    /**
     * @brief Construct a new Arm IK object
     *
     * @param nq Number of joints
     * @param nx Number of end effector's degrees of freedom
     */
    ArmForwardKinematics(size_t nq, size_t nx) : nq_(nq), nx_(nx), adq_(nq), adx_(nx) {}

    Eigen::VectorXd solve_fk(Eigen::VectorXd joint_angles) {
        Eigen::VectorXd x(nx_);
        static_cast<Derived *>(this)->forward_kinematics(joint_angles, x);
        return x;
    }

    Eigen::VectorXd solve_ik(Eigen::VectorXd pos, Eigen::VectorXd joint_angles0) {
        if (joint_angles0.size() == 0)
            joint_angles0 = Eigen::VectorXd::Zero(nq_);

        auto eval_func = [&](Eigen::VectorXd q) {
            return (solve_fk(q) - pos).squaredNorm();
        };

        auto jacobian_func = [&](Eigen::VectorXd q) {
            return derivative(eval_func, q);
        };

        auto [ret, rx, rcnt] = quasi_newton_method(eval_func, jacobian_func, joint_angles0);
        return rx;
    }

    Eigen::VectorXd solve_ik(Eigen::VectorXd pos) {
        return solve_ik(pos, Eigen::VectorXd::Zero(nq_));
    }

    Eigen::MatrixXd jacobian(Eigen::VectorXd joint_angles) {
        adq_ = joint_angles;
        static_cast<Derived *>(this)->forward_kinematics(adq_, adx_);
        Eigen::MatrixXd J(nx_, nq_);
        for (size_t i = 0; i < nq_; ++i) {
            J.col(i) = adx_[i].derivatives();
        }
        return J;
    }

private:
    size_t nq_;
    size_t nx_;
    ADVectorXd adq_, adx_;
};

namespace cpp_robotics {
template <class Derived>
class ArmForwardKinematicsWithPose {
public:
    /**
     * @brief Construct a new Arm IK object
     *
     * @param nq Number of joints
     */
    ArmForwardKinematicsWithPose(size_t nq) : nq_(nq), nx_(3 + 4) {}

    std::pair<Eigen::VectorXd, Eigen::Quaterniond> solve_fk(Eigen::VectorXd joint_angles) {
        Eigen::VectorXd x(3);
        Eigen::Quaterniond pose;
        static_cast<Derived *>(this)->forward_kinematics(joint_angles, x, pose);
        return {x, pose};
    }

    Eigen::VectorXd solve_ik(Eigen::VectorXd ref_pos, Eigen::Quaterniond ref_pose, Eigen::VectorXd joint_angles0) {
        if (joint_angles0.size() == 0)
            joint_angles0 = Eigen::VectorXd::Zero(nq_);

        auto eval_func = [&](Eigen::VectorXd q) {
            auto [pos, pose] = solve_fk(q);
            return (pos - ref_pos).squaredNorm() + std::pow((1 - ref_pose.dot(pose)), 2);
        };

        auto jacobian_func = [&](Eigen::VectorXd q) {
            return derivative(eval_func, q);
        };

        auto [ret, rx, rcnt] = quasi_newton_method(eval_func, jacobian_func, joint_angles0);
        return rx;
    }

    Eigen::VectorXd solve_ik(Eigen::VectorXd pos, Eigen::Quaterniond quat) {
        return solve_ik(pos, quat, Eigen::VectorXd::Zero(nq_));
    }

    Eigen::VectorXd solve_ik_with_dir(Eigen::VectorXd pos, Eigen::Vector3d axis, double angle) {
        Eigen::AngleAxisd rotation_vector(angle, axis);
        Eigen::Quaterniond pose(rotation_vector);
        return solve_ik(pos, pose);
    }

    Eigen::MatrixXd jacobian(Eigen::VectorXd joint_angles) {
        adq_ = joint_angles;
        ADVectorXd pose;
        static_cast<Derived *>(this)->forward_kinematics(adq_, adx_, pose);
        Eigen::MatrixXd J(nx_, nq_);
        for (size_t i = 0; i < nq_; ++i) {
            J.col(i) = adx_[i].derivatives();
        }
        return J;
    }

    template <typename Scalar>
    Eigen::Matrix<Scalar, 4, 4> transform_x(const Scalar &q, const Scalar &x, const Scalar &y, const Scalar &z) {
        Eigen::Matrix<Scalar, 4, 4> T;
        T << 1, 0, 0, x,
            0, cos(q), -sin(q), y,
            0, sin(q), cos(q), z,
            0, 0, 0, 1;
        return T;
    }

    template <typename Scalar>
    Eigen::Matrix<Scalar, 4, 4> transform_y(const Scalar &q, const Scalar &x, const Scalar &y, const Scalar &z) {
        Eigen::Matrix<Scalar, 4, 4> T;
        T << cos(q), 0, sin(q), x,
            0, 1, 0, y,
            -sin(q), 0, cos(q), z,
            0, 0, 0, 1;
        return T;
    }

    template <typename Scalar>
    Eigen::Matrix<Scalar, 4, 4> transform_z(const Scalar &q, const Scalar &x, const Scalar &y, const Scalar &z) {
        Eigen::Matrix<Scalar, 4, 4> T;
        T << cos(q), -sin(q), 0, x,
            sin(q), cos(q), 0, y,
            0, 0, 1, z,
            0, 0, 0, 1;
        return T;
    }

private:
    size_t nq_;
    size_t nx_;
    ADVectorXd adq_, adx_;
};

} // namespace cpp_robotics

template <class Derived>
class ArmInverseKinematics {
public:
    /**
     * @brief Construct a new Arm IK object
     *
     * @param nq Number of joints
     * @param nx Number of end effector's degrees of freedom
     */
    ArmInverseKinematics(size_t nq, size_t nx) : nq_(nq), nx_(nx), adq_(nq), adx_(nx) {
        static_assert(internal::has_inverse_kinematics<Derived>::value, "Derived class must have inverse_kinematics method");
    }

    Eigen::VectorXd solve_fk(Eigen::VectorXd joint_angles, Eigen::VectorXd pos0) {
        auto eval_func = [&](Eigen::VectorXd x) {
            return (solve_ik(x) - joint_angles).squaredNorm();
        };

        auto jacobian_func = [&](Eigen::VectorXd x) {
            return derivative(eval_func, x);
        };

        auto [ret, rx, rcnt] = quasi_newton_method(eval_func, jacobian_func, pos0);
        return rx;
    }

    Eigen::VectorXd solve_fk(Eigen::VectorXd joint_angles) {
        return solve_fk(joint_angles, Eigen::VectorXd::Zero(nx_));
    }

    Eigen::VectorXd solve_ik(Eigen::VectorXd pos) {
        Eigen::VectorXd q(nq_);
        static_cast<Derived *>(this)->inverse_kinematics(pos, q);
        return q;
    }

    Eigen::MatrixXd jacobian(Eigen::VectorXd joint_angles) {
        adq_ = joint_angles;
        static_cast<Derived *>(this)->forward_kinematics(adq_, adx_);
        Eigen::MatrixXd J(nx_, nq_);
        for (size_t i = 0; i < nq_; ++i) {
            J.col(i) = adx_[i].derivatives();
        }
        return J;
    }

private:
    size_t nq_;
    size_t nx_;
    ADVectorXd adq_, adx_;
};

} // namespace cpp_robotics