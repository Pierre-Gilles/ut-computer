#include <iostream>
#include <gtest/gtest.h>

#include "../../lexer/Lexer.h"


class Test_Lexer_Class : public ::testing::Test {
protected:
    LexerUTComputer lx;

public:
    virtual void SetUp() { }
    virtual void TearDown() { }
};


TEST_F(Test_Lexer_Class, Test_Lexer_split_function_on_postfix_expression) {
    vector<string> result = lx.split("3 3 + 5 * '3+3' 4 +");
    vector<string> expected = {"3", "3", "+", "5", "*", "'3+3'", "4", "+"};
    EXPECT_EQ(result, expected);
}

TEST_F(Test_Lexer_Class, Test_Lexer_tokenize_function_on_infixe_expression) {
    vector<string> result = lx.tokenize("3+3+SIN(5+3)");
    vector<string> expected = {"3", "+", "3", "+", "SIN", "(" , "5", "+", "3", ")"};
    EXPECT_EQ(result, expected);

    result = lx.tokenize("(3+3+4)*2/SIN(5+3)*((3-1)*(4+2)/(2+4-1))");
    expected = {"(", "3", "+", "3", "+", "4", ")", "*", "2", "/", "SIN", "(", "5", "+", "3", ")", "*", "(", "(", "3", "-", "1",
                    ")", "*", "(", "4", "+", "2", ")", "/", "(", "2", "+", "4", "-", "1", ")", ")"};
    EXPECT_EQ(result, expected);
}

TEST_F(Test_Lexer_Class, Test_Lexer_tokenize_function_on_postfixe_expression) {
    vector<string> result = lx.tokenize("3 3 + 5 * '3+3' 4 +");
    vector<string> expected = {"3", "3", "+", "5", "*", "'3+3'", "4", "+"};
    EXPECT_EQ(result, expected);

    result = lx.tokenize("3 3 + 5 * [3+3] 4 +");
    expected = {"3", "3", "+", "5", "*", "[3+3]", "4", "+"};
    EXPECT_EQ(result, expected);

    result = lx.tokenize("3 3 + 5 * [3+3] 4 + '1+2+3*2' 3 43 21.2 DIV 23.2 DROP DUP 1.1231 - * 23 /");
    expected = {"3", "3", "+", "5", "*", "[3+3]", "4", "+", "'1+2+3*2'","3","43","21.2","DIV","23.2","DROP","DUP","1.1231","-","*","23","/"};
    EXPECT_EQ(result, expected);


    result = lx.tokenize("3 3 + 2 - 132 * 34 32.12 / 231 DIV $ 2 3 / NEG 23 9.3 OR 23 .4 AND");
    expected = {"3","3","+","2","-","132","*","34","32.12","/","231","DIV","$","2","3","/","NEG","23","9.3","OR","23",".4","AND"};
    EXPECT_EQ(result, expected);
}

TEST_F(Test_Lexer_Class, Test_Lexer_infixToPostfix) {

    // Testing
    vector<string> elems = {"(", "3", "+", "3", "+", "4", ")", "*", "2", "/", "SIN", "(", "5", "+", "3", ")", "*", "(", "(", "3", "-", "1",
                               ")", "*", "(", "4", "+", "2", ")", "/", "(", "2", "+", "4", "-", "1", ")", ")"};
    vector <string> result = lx.infixToPostfix(elems);
    vector<string> expected = { "3", "3", "+", "4", "+", "2", "*", "5", "3", "+", "SIN", "/", "3", "1", "-", "4", "2", "+", "*", "2", "4", "+", "1", "-", "/", "*" };
    EXPECT_EQ(result, expected);


    elems = {"3", "+", "3", "+", "SIN", "(" , "5", "+", "3", ")"};
    expected = {"3", "3", "+", "5", "3", "+", "SIN", "+"};
    result = lx.infixToPostfix(elems);
    EXPECT_EQ(result, expected);


    elems = { "(", "3", "+", "7", ")", "DIV", "(", "5", ")"};
    expected = {"3", "7", "+", "5", "DIV" };
    result = lx.infixToPostfix(elems);
    EXPECT_EQ(result, expected);


    elems = { "(", "3", "+", "7", ")", "MOD", "(", "5", ",", "10" ")"};
    expected = {"3", "7", "+", "5", "10", "MOD" };
    result = lx.infixToPostfix(elems);
    EXPECT_EQ(result, expected);

}


