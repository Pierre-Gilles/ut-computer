#include <iostream>
#include <gtest/gtest.h>
#include <regex>

#include "../../literals/ProgramLiteral.h"



class Test_Program_Literal : public ::testing::Test {
protected:

public:
    virtual void SetUp() { }
    virtual void TearDown() { }
};


TEST_F(Test_Program_Literal, Test_Regex) {

    regex r(ProgramLiteral::getProgramRegex());

    EXPECT_TRUE(std::regex_match("[1]", r));
    EXPECT_TRUE(std::regex_match("[12]", r));
    EXPECT_TRUE(std::regex_match("[12121]", r));
    EXPECT_TRUE(std::regex_match("[1.1]", r));
    EXPECT_TRUE(std::regex_match("[11.1]", r));
    EXPECT_TRUE(std::regex_match("[1.11]", r));
    EXPECT_TRUE(std::regex_match("[112.13]", r));
    EXPECT_TRUE(std::regex_match("[1+1*2*3]", r));

    EXPECT_FALSE(std::regex_match("[1+1", r));
    EXPECT_FALSE(std::regex_match("1+1]", r));

}