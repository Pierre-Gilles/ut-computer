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


TEST_F(Test_Lexer_Class, Test_Lexer_split_function) {
    vector<string> result = lx.split("3 3 + 5 * '3+3' 4 +");
    vector<string> expected = {"3", "3", "+", "5", "*", "'3+3'", "4", "+"};
    ASSERT_EQ(result, expected);
}

TEST_F(Test_Lexer_Class, Test_Lexer_split_function_test) {
    vector<string> result = lx.tokenize("3+3+SIN(5+3)");
    vector<string> expected = {"3", "+", "3", "+", "SIN", "(" , "5", "+", "3", ")"};
    ASSERT_EQ(result, expected);

    result = lx.tokenize("(3+3+4)*2/SIN(5+3)*((3-1)*(4+2)/(2+4-1))");
    expected = {"(", "3", "+", "3", "+", "4", ")", "*", "2", "/", "SIN", "(", "5", "+", "3", ")", "*", "(", "(", "3", "-", "1",
                    ")", "*", "(", "4", "+", "2", ")", "/", "(", "2", "+", "4", "-", "1", ")", ")"};
    ASSERT_EQ(result, expected);

}

TEST_F(Test_Lexer_Class, Test_Lexer_infixToPostfix) {

    // Testing
    vector<string> elems = {"(", "3", "+", "3", "+", "4", ")", "*", "2", "/", "SIN", "(", "5", "+", "3", ")", "*", "(", "(", "3", "-", "1",
                               ")", "*", "(", "4", "+", "2", ")", "/", "(", "2", "+", "4", "-", "1", ")", ")"};

    vector <string> result = lx.infixToPostfix(elems);

    vector<string> expected = { "3", "3", "+", "4", "+", "2", "*", "5", "3", "+", "SIN", "/", "3", "1", "-", "4", "2", "+", "*", "2", "4", "+", "1", "-", "/", "*" };

    ASSERT_EQ(result, expected);

    elems = {"3", "+", "3", "+", "SIN", "(" , "5", "+", "3", ")"};
    expected = {"3", "3", "+", "5", "3", "+", "SIN", "+"};
    result = lx.infixToPostfix(elems);

    ASSERT_EQ(result, expected);

    elems = { "(", "3", "+", "7", ")", "DIV", "5" };
    expected = {"3", "7", "+", "5", "DIV" };
    result = lx.infixToPostfix(elems);

    ASSERT_EQ(result, expected);
}


