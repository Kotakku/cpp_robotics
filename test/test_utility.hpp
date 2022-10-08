#pragma once

#include <gtest/gtest.h>

#define EXPECT_NEAR_VEC(v1, v2, eps)\
    EXPECT_NEAR((v1-v2).norm(), 0.0, eps)

#define EXPECT_NEAR_STD_VECTOR(v1, v2, eps)\
    EXPECT_EQ(v1.size(), v2.size());\
    for(size_t i = 0; i < v1.size(); i++)\
    {\
        EXPECT_NEAR(v1[i], v2[i], eps);\
    }