#pragma once

#include <array>
#include <Eigen/Dense>

namespace STB::ModernControl
{
    // 可制御性行列
    static Eigen::MatrixXd controllability_matrix(const Eigen::MatrixXd& A, const Eigen::VectorXd& b)
    {
        assert(A.rows() == A.cols());
        assert(A.rows() == b.size());
        const int dim = A.rows();

        Eigen::MatrixXd Uc(dim, dim);
        Eigen::VectorXd colv = b;

        for(int i = 0; i < dim; i++)
        {
            Uc.col(i) = colv;
            colv = A * colv;
        }

        return Uc;
    }

    // 可制御性の判別
    static bool is_controllable(const Eigen::MatrixXd&& A, const Eigen::MatrixXd& b)
    {
        assert(A.rows() == A.cols());
        assert(A.rows() == b.size());
        const int dim = A.rows();

        Eigen::FullPivLU<Eigen::MatrixXd> lu(controllability_matrix(A, b));
        return (lu.rank() == dim);
    }

    // 可観測性行列
    static Eigen::MatrixXd observability_matrix(const Eigen::MatrixXd& A, const Eigen::VectorXd& c)
    {
        assert(A.rows() == A.cols());
        assert(A.rows() == c.size());
        const int dim = A.rows();

        Eigen::MatrixXd Uo(dim, dim);
        Eigen::VectorXd colv = c.transpose();

        for(int i = 0; i < dim; i++)
        {
            Uo.row(i) = colv;
            colv = colv * A;
        }

        return Uo;
    }

    // 可観測性の判別
    static bool is_observable(const Eigen::MatrixXd&& A, const Eigen::MatrixXd& c)
    {
        assert(A.rows() == A.cols());
        assert(A.rows() == c.size());
        const int dim = A.rows();

        Eigen::FullPivLU<Eigen::MatrixXd> lu(observability_matrix(A, c));
        return (lu.rank() == dim);
    }

    // template<typename Scalar, size_t Dim>
    // static constexpr std::tuple<Matrix<Scalar, Dim, Dim>, Matrix<Scalar, Dim, Dim>> A_tilda(const Matrix<Scalar, Dim, Dim>& A, const Matrix<Scalar, Dim, 1>& b)
    // {
    //     auto Uc = controllability_mat(A, b);

    //     if(Uc.rank() != Dim)
    //         throw "this matrix is not full rank";

    //     return {(Uc.inverse()*A*Uc).transpose(), Uc};
    // }

    // template<typename Scalar, size_t Dim>
    // static constexpr Matrix<Scalar, Dim, Dim> transpose_mat(const Matrix<Scalar, Dim, Dim>& A, const Matrix<Scalar, Dim, 1>& b)
    // {
    //     auto AtilUc = A_tilda(A, b);
    //     auto Atil = std::get<0>(AtilUc);
    //     auto Uc   = std::get<1>(AtilUc);

    //     if(Uc.rank() != Dim)
    //         throw "this matrix is not full rank";

    //     Matrix<Scalar, Dim, Dim> W = MatrixHelper::gen_matrix<Dim, Dim>([&Atil](size_t i, size_t j){
    //         if(i+j < Dim-1)
    //             return -Atil(Dim-1, 1+i+j);
    //         else if (i+j == Dim-1)
    //             return Scalar(1);
    //         return Scalar(0);
    //     });

    //     auto T = Uc*W;
    //     T = T.inverse();

    //     return Atil;
    // }

    // template<typename Scalar, size_t Dim>
    // static constexpr Matrix<Scalar, 1, Dim> feedback_vec(const Matrix<Scalar, Dim, Dim>& A, const Matrix<Scalar, Dim, 1>& b, Matrix<Scalar, 1, Dim> pole_coeff, const std::tuple<Matrix<Scalar, Dim, Dim>, Matrix<Scalar, Dim, Dim>>& AtilUc)
    // {
    //     //auto AtilUc = A_tilda(A, b);
    //     auto Atil = std::get<0>(AtilUc);
    //     auto Uc   = std::get<1>(AtilUc);

    //     if(Uc.rank() != Dim)
    //         throw "this matrix is not full rank";

    //     Matrix<Scalar, Dim, Dim> W = MatrixHelper::gen_matrix<Dim, Dim>([&Atil](size_t i, size_t j){
    //         if(i+j < Dim-1)
    //             return -Atil(Dim-1, 1+i+j);
    //         else if (i+j == Dim-1)
    //             return Scalar(1);
    //         return Scalar(0);
    //     });

    //     Matrix<Scalar, 1, Dim> a_coeff = MatrixHelper::gen_matrix<1, Dim>([&Atil](size_t i, size_t j){
    //         return -Atil(Dim-1, j);
    //     });

    //     auto T = Uc*W;
    //     T = T.inverse();

    //     return (pole_coeff-a_coeff)*T;
    // }

    // template<typename Scalar, size_t Dim>
    // static constexpr std::tuple<Matrix<Scalar, Dim+1, Dim+1>, Matrix<Scalar, Dim+1, Dim+1>> extend_controllability_mat(const Matrix<Scalar, Dim, Dim>& A, const Matrix<Scalar, Dim, 1>& b, const Matrix<Scalar, 1, Dim>& c)
    // {
    //     Matrix<Scalar, Dim, Dim> mUc = controllability_mat(A, b);
    //     Matrix<Scalar, Dim+1, Dim+1> U = {}, W = {};

    //     U.set_sub_mat(A, 0, 0);
    //     U.set_sub_mat(b, 0, Dim);
    //     U.set_sub_mat(-c, Dim, 0);

    //     W(Dim, 0) = 1;
    //     W.set_sub_mat(mUc, 0, 1);

    //     return {U, U*W};
    // }
	


    // constexpr unsigned long fact(const unsigned long n)
    // {
    //     if(n == 0)
    //         return 1;
    //     return n * fact(n-1);
    // }

    // constexpr unsigned long combination(const unsigned long n, const unsigned long r)
    // {
    //     if (n == 0)
    //         return 1;
    //     else if (r == 0)
    //         return 1;
    //     else if (n == r)
    //         return 1;
    //     else
    //         return combination(n - 1, r) + combination(n - 1, r - 1);
    // }

    // template<int N, int R, typename Callable>
    // constexpr void combi_call_impl(int num, size_t K[R], int p, int w, int n, int r, Callable && f)
    // {
    //     std::array<size_t, R> comb = {};

    //     if (p > 0)
    //     {
    //         for (int i = 0; i <= w; i++)
    //         {
    //             K[p] = i;
    //             combi_call_impl(num, K, p - 1, w - i, n, r, f);
    //         }
    //     }
    //     else
    //     {
    //         int m = 0, pick = 0;

    //         for (int i = 1; i <= r; i++)
    //         {
    //             for (int j = 0; j < K[i]; j++, m++)
    //                 pick++;
    //             comb[m] = pick;
    //             m++;
    //         }
    //         f(num, p);
    //         num++;
    //     }
    // }

    // template<int N, int R, typename Callable>
    // constexpr void combi_call(Callable && f)
    // {
        
    //     size_t K[R] = {};
    //     size_t num = 0;

    //     combi_call_impl(num, K, R, N-R, N, R, f);

    //     // auto combi_impl = [&f, &comb, &K, &num, &combi_impl](int p, int w, int n, int r) {
    //     //     if (p > 0)
    //     //     {
    //     //         for (int i = 0; i <= w; i++)
    //     //         {
    //     //             K[p] = i;
    //     //             combi_impl(p - 1, w - i, n, r);
    //     //         }
    //     //     }
    //     //     else
    //     //     {
    //     //         int m = 0, pick = 0;

    //     //         for (int i = 1; i <= r; i++)
    //     //         {
    //     //             for (int j = 0; j < K[i]; j++, m++)
    //     //                 pick++;
    //     //             comb[m] = pick;
    //     //             m++;
    //     //         });
    //     //         f(num, p);
    //     //         num++;
    //     //     }
    //     // }(R, N - R, N, R);
        
    // }

    // template<int N = 5, int R = 3>
    // constexpr auto combi_call_test()
    // {
    //     std::array<std::array<size_t, R>, combination(N, R)> re = {};
    //     combi_call<N, R>([&re](size_t num, auto p){
    //         //re[num] = p;
    //     });

    //     return re;
    // }

    // template<size_t conum>
    // using twcoeff = std::array<size_t, conum>;

    // template<>
    // using twcoeff = std::array<size_t, 3>{1, 2, 1};

    // template<>
    // using twcoeff = std::array<size_t, 4>{1, 3, 3, 1};

    

    // template<typename Scalar, size_t Dim>
    // static constexpr std::array<Scalar, Dim> pole_to_coeff(const std::array<Scalar, Dim>& pole)
    // {
    //     std::array<Scalar, Dim> coeff = {};

    //     for(size_t i = 0; i < Dim; i++)
    //     {
    //         for(size_t c = 0; c < twcoeff<Dim+1>[i]; c++)
    //         {
    //             Scalar t = 1;
    //             for(size_t m = 0; m < (Dim-i); m++)
    //             {
    //                 t *= pole[m];
    //             }
    //             coeff[i] += t;
    //         }
    //     }

    //     return coeff;
    // }

    // template<typename Scalar>
    // static bool is_controllable(Eigen::Matrix<Scalar, 2, 2> A, Eigen::Matrix<Scalar, 2, 1> b)
    // {
    //     Eigen::Matrix<Scalar, 2, 2> M;
    //     M << b, A*b;
    //     return (M.determinant() != static_cast<Scalar>(0.0));
    // }

    // static bool is_observable()
    // {
    //     return false;
    // }

    // namespace
    // {
    //     template<typename Scalar, int Dim>
    //     auto solve_sim_equ(Eigen::Matrix<Scalar, Dim, Dim> A, Eigen::Matrix<Scalar, Dim, 1> b)
    //     {
    //         return A.fullPivLu().solve(b);
    //     }
    // }

    /*
    template<typename Scalar, int Dim>
    auto ppol(Eigen::Matrix<Scalar, Dim, Dim>& A, Eigen::Matrix<Scalar, Dim, 1>& b)
    {
        return solve_sim_equ(A, b);
    }
    */

    // 任意の次元に対応する
    // 状態フィードバック(サーボ問題)もこれのDim = 3で解ける
    // template<typename Scalar>
    // static auto ppol(Matrix<Scalar, 2, 2> A, Matrix<Scalar, 2, 1> b, Matrix<Scalar, 2, 1> k)
    // {
    //     using namespace std;

    //     Matrix<Scalar, 2, 2> Am = {b(0), b(1),
    //         (b(0)*A(1, 1) - b(1)*A(0, 1)), (b(1)*A(0, 0) - b(0)*A(1, 0))};

    //     Matrix<Scalar, 2, 1> bm = {
    //         (k(0)+k(1)) + A(0, 0) + A(1, 1),
    //         -(k(0)*k(1)) + A(1, 1)*A(0, 0) - A(1, 0)*A(0, 1);
    //     };

    //     //  cout << "B =\n" << bm << endl;
        
    //     return Am.fullPivLu().solve(bm).eval();
    // }
}