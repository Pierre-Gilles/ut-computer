#include <iostream>
#include <gtest/gtest.h>

#include "../../literals/ComplexLiteral.h"



class Test_Complex_Literal : public ::testing::Test {

public:
    virtual void SetUp() { }
    virtual void TearDown() {

    }
};


TEST_F(Test_Complex_Literal, Test_Constructor_With_String) {

    string s = "1";
    ComplexLiteral c(s);

    EXPECT_EQ("1", c.toString());
    EXPECT_EQ("1", c.getReal().toString());
    EXPECT_EQ("0", c.getIm().toString());


    s = "1.1";
    c = ComplexLiteral(s);
    EXPECT_EQ("1.1", c.toString());
    EXPECT_EQ("1.1", c.getReal().toString());
    EXPECT_EQ("0", c.getIm().toString());

    s = "112.12";
    c = ComplexLiteral(s);
    EXPECT_EQ("112.12", c.toString());
    EXPECT_EQ("112.12", c.getReal().toString());
    EXPECT_EQ("0", c.getIm().toString());

}