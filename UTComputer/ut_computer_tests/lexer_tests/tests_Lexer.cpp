#include <iostream>
#include <gtest/gtest.h>

#include "../../lexer/Lexer.h"
#include "../../Calculator.h"


class Test_Lexer_Class : public ::testing::Test {
protected:
    LexerUTComputer lx;

public:
    virtual void SetUp() {
        // Classic Operators
        Operator * op1 = new OperatorPlus();
        lx.addOperatorWeight(op1);
        Operator * op2 = new OperatorMinus();
        lx.addOperatorWeight(op2);
        Operator * op3 = new OperatorMultiplication();
        lx.addOperatorWeight(op3);
        Operator * op4 = new OperatorDivision();
        lx.addOperatorWeight(op4);
        Operator * op5 = new OperatorIntegerDivision();
        lx.addOperatorWeight(op5);
        Operator * op6 = new OperatorModulo();
        lx.addOperatorWeight(op6);
        Operator * op7 = new OperatorNeg();
        lx.addOperatorWeight(op7);

        // Logical Operators
        Operator * op8 = new OperatorAnd();
        lx.addOperatorWeight(op8);
        Operator * op9 = new OperatorDifferent();
        lx.addOperatorWeight(op9);
        Operator * op10 = new OperatorEqual();
        lx.addOperatorWeight(op10);
        Operator * op11 = new OperatorInferior();
        lx.addOperatorWeight(op11);
        Operator * op12 = new OperatorInferiorEqual();
        lx.addOperatorWeight(op12);
        Operator * op13 = new OperatorNot();
        lx.addOperatorWeight(op13);
        Operator * op14 = new OperatorOr();
        lx.addOperatorWeight(op14);
        Operator * op15 = new OperatorSuperior();
        lx.addOperatorWeight(op15);
        Operator * op16 = new OperatorSuperiorEqual();
        lx.addOperatorWeight(op16);

        // Rational Operators
        Operator * op17 = new OperatorNumerator();
        lx.addOperatorWeight(op17);
        Operator * op18 = new OperatorDenominator();
        lx.addOperatorWeight(op18);

        // Complex Operators
        Operator * op19 = new OperatorDollar();
        lx.addOperatorWeight(op19);
        Operator * op20 = new OperatorIM();
        lx.addOperatorWeight(op20);
        Operator * op21 = new OperatorRE();
        lx.addOperatorWeight(op21);

        // Stack Operators
        Operator * op22 = new OperatorCLEAR();
        lx.addOperatorWeight(op22);
        Operator * op23 = new OperatorDROP();
        lx.addOperatorWeight(op23);
        Operator * op24 = new OperatorDUP();
        lx.addOperatorWeight(op24);
        Operator * op25 = new OperatorLASTARGS();
        lx.addOperatorWeight(op25);
        Operator * op26 = new OperatorLASTOP();
        lx.addOperatorWeight(op26);
        Operator * op27 = new OperatorREDO();
        lx.addOperatorWeight(op27);
        Operator * op28 = new OperatorUNDO();
        lx.addOperatorWeight(op28);
        Operator * op29 = new OperatorSWAP();
        lx.addOperatorWeight(op29);

        delete op1;
        delete op2;
        delete op3;
        delete op4;
        delete op5;
        delete op6;
        delete op7;
        delete op8;
        delete op9;
        delete op10;
        delete op11;
        delete op12;
        delete op13;
        delete op14;
        delete op15;
        delete op16;
        delete op17;
        delete op18;
        delete op19;
        delete op20;
        delete op21;
        delete op22;
        delete op23;
        delete op24;
        delete op25;
        delete op26;
        delete op27;
        delete op28;
        delete op29;
    }
    virtual void TearDown() { }
};



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

    result = lx.tokenize("'1 + 1' '0 + 0' AND");
    expected = {"'1 + 1'", "'0 + 0'", "AND"};
    EXPECT_EQ(result, expected);
}

TEST_F(Test_Lexer_Class, Test_Lexer_infixToPostfix) {

    // Testing
    vector<string> elems = {"(", "3", "+", "3", "+", "4", ")", "*", "2", "/", "DIV", "(", "5", "+", "3", ")", "*", "(", "(", "3", "-", "1",
                               ")", "*", "(", "4", "+", "2", ")", "/", "(", "2", "+", "4", "-", "1", ")", ")"};
    vector <string> result = lx.infixToPostfix(elems);
    vector<string> expected = { "3", "3", "+", "4", "+", "2", "*", "5", "3", "+", "DIV", "/", "3", "1", "-", "4", "2", "+", "*", "2", "4", "+", "1", "-", "/", "*" };
    EXPECT_EQ(result, expected);


    elems = {"3", "+", "3", "+", "DIV", "(" , "5", "+", "3", ")"};
    expected = {"3", "3", "+", "5", "3", "+", "DIV", "+"};
    result = lx.infixToPostfix(elems);
    EXPECT_EQ(result, expected);


    elems = { "(", "3", "+", "7", ")", "DIV", "(", "5", ")"};
    expected = {"3", "7", "+", "5", "DIV" };
    result = lx.infixToPostfix(elems);
    EXPECT_EQ(result, expected);


    elems = { "MOD", "(", "5", ",", "10", ")"};
    expected = {"5", "10", "MOD" };
    result = lx.infixToPostfix(elems);
    EXPECT_EQ(result, expected);

    result = lx.infixToPostfix(lx.tokenize("AND(1+1, 0+0)"));
    expected = {"1" ,"1" ,"+" ,"0", "0", "+", "AND"};
    EXPECT_EQ(result, expected);

}


