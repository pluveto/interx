#include <gtest/gtest.h>
#include "../environment.h"

TEST(EnvironmentTest, TestGet) {
    Environment env;
    // Test getting an undefined variable
    ASSERT_DEATH(env.get("undefined"), "undefined variable");

    // Test getting a string variable
    env.set("str", "hello");
    EvalResult result = env.get("str");
    ASSERT_EQ(result.type, ValType_STRING);
    ASSERT_EQ(result.str_val, "hello");

    // Test getting a number variable
    env.set("num", 5.0);
    result = env.get("num");
    ASSERT_EQ(result.type, ValType_NUMBER);
    ASSERT_DOUBLE_EQ(result.num_val, 5.0);

    // Test getting a boolean variable
    env.set("bool", true);
    result = env.get("bool");
    ASSERT_EQ(result.type, ValType_BOOL);
    ASSERT_TRUE(result.bool_val);
}

TEST(EnvironmentTest, TestSet) {
    Environment env;
    // Test setting a string variable
    bool ret = env.set("str", "hello");
    ASSERT_FALSE(ret);
    ret = env.set("str", "world");
    ASSERT_TRUE(ret);
    EvalResult result = env.get("str");
    ASSERT_EQ(result.type, ValType_STRING);
    ASSERT_EQ(result.str_val, "world");

    // Test setting a number variable
    ret = env.set("num", 5.0);
    ASSERT_FALSE(ret);
    ret = env.set("num", 10.0);
    ASSERT_TRUE(ret);
    result = env.get("num");
    ASSERT_EQ(result.type, ValType_NUMBER);
    ASSERT_DOUBLE_EQ(result.num_val, 10.0);

    // Test setting a boolean variable
    ret = env.set("bool", true);
    ASSERT_FALSE(ret);
    ret = env.set("bool", false);
    ASSERT_TRUE(ret);
    result = env.get("bool");
    ASSERT_EQ(result.type, ValType_BOOL);
    ASSERT_FALSE(result.bool_val);
}