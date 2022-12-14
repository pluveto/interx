#include <gtest/gtest.h>

#include "../ast.h"

TEST(EvalResultTest, DefaultConstructor) {
    EvalResult result;

    // Check that the default values are set correctly
    EXPECT_EQ(result.type, ValType_STRING);
    EXPECT_EQ(result.str_val, "");
    EXPECT_EQ(result.num_val, 0.0);
    EXPECT_EQ(result.bool_val, false);
}

TEST(EvalResultTest, StringConstructor) {
    std::string str_val = "hello world";
    EvalResult result(str_val);

    // Check that the values are set correctly
    EXPECT_EQ(result.type, ValType_STRING);
    EXPECT_EQ(result.str_val, str_val);
    EXPECT_EQ(result.num_val, 0.0);
    EXPECT_EQ(result.bool_val, false);
}

TEST(EvalResultTest, NumberConstructor) {
    double num_val = 123.45;
    EvalResult result(num_val);

    // Check that the values are set correctly
    EXPECT_EQ(result.type, ValType_NUMBER);
    EXPECT_EQ(result.str_val, "");
    EXPECT_EQ(result.num_val, num_val);
    EXPECT_EQ(result.bool_val, false);
}

TEST(EvalResultTest, BoolConstructor) {
    bool bool_val = true;
    EvalResult result(bool_val);

    // Check that the values are set correctly
    EXPECT_EQ(result.type, ValType_BOOL);
    EXPECT_EQ(result.str_val, "");
    EXPECT_EQ(result.num_val, 0.0);
    EXPECT_EQ(result.bool_val, bool_val);
}

TEST(EvalResultTest, OperatorEqual) {
    // Check that the operator== override works correctly
    EXPECT_EQ(EvalResult("hello"), EvalResult("hello"));
    EXPECT_EQ(EvalResult(123.45), EvalResult(123.45));
    EXPECT_EQ(EvalResult(true), EvalResult(true));
    EXPECT_EQ(EvalResult(false), EvalResult(false));
    EXPECT_EQ(EvalResult(0.0), EvalResult(0.0));
}

