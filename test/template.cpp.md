# gtest template

```c++
#include <gtest/gtest.h>

TEST(test_suite_name, test_name) {

    // 以下の全てのテストについて{EXPECT|ASSERT}_XXX

    // true/falseのアサーション
    EXPECT_TRUE(condition);  // condition が true か
    EXPECT_FALSE(condition);  // condition が false か

    // 2つの値を比較するアサーション
    EXPECT_EQ(expected, actual);  // expected == actual か
    EXPECT_NE(expected, actual);  // expected != actual か
    EXPECT_LT(expected, actual);  // expected < actual か
    EXPECT_LE(expected, actual);  // expected <= actual か
    EXPECT_GT(expected, actual);  // expected > actual か
    EXPECT_GE(expected, actual);  // expected >= actual か

    // 文字列比較
    EXPECT_STREQ(s1, s2);     // s1 == s2
    EXPECT_STRNE(s1, s2);     // s1 != s2
    EXPECT_STRCASEEQ(s1, s2); // s1 == s2(ケースの違いは無視)
    EXPECT_STRCASENE(s1, s2); // s1 != s2(ケースの違いは無視)

    EXPECT_FLOAT_EQ(val1, val2);
    EXPECT_DOUBLE_EQ(val1, val2);
    EXPECT_NEAR(val1, val2, abs_error);
}
```