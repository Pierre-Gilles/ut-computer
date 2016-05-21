#include <iostream>
#include <gtest/gtest.h>

#include "../../lexer/Lexer.h"


class Test_Lexer_Class : public ::testing::Test {
protected:
    LexerUTComputer lx;

public:
    virtual void SetUp() { }
    virtual void TearDown() {

    }
};


TEST_F(Test_Lexer_Class, Test_Thrown_Exceptions_In_Execute_Function) {
    vector<string> result = lx.split("3 3 + 5 * '3 3 +' 4 +");
    vector<string> expected = {"3", "3", "+", "5", "*", "'3 3 +'", "4", "+"};
    ASSERT_EQ(result, expected);
}