#include <iostream>
#include <gtest/gtest.h>

#include "../../literals/NumericLiteral.h"
#include <regex>



class Test_Numeric_Literal : public ::testing::Test {

public:
    virtual void SetUp() { }
    virtual void TearDown() {

    }
};



TEST_F(Test_Numeric_Literal, Test_Regex) {

    regex r(NumericLiteral::getNumericRegex());

    EXPECT_TRUE(regex_match("1", r));
    EXPECT_TRUE(regex_match("12", r));
    EXPECT_TRUE(regex_match("12121", r));
    EXPECT_TRUE(regex_match("1.1", r));
    EXPECT_TRUE(regex_match("11.1", r));
    EXPECT_TRUE(regex_match("1.11", r));
    EXPECT_TRUE(regex_match("112.13", r));
    EXPECT_TRUE(regex_match("11.1123", r));
    EXPECT_TRUE(regex_match(".1", r));
    EXPECT_TRUE(regex_match(".122", r));

    EXPECT_FALSE(regex_match(".", r));
    EXPECT_FALSE(regex_match("1.", r));
    EXPECT_FALSE(regex_match("12Z.", r));

}