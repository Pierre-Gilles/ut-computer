#include <iostream>
#include <gtest/gtest.h>

#include "../../Calculator.h"



class Test_Calculator : public ::testing::Test {
protected:
    Calculator c;
    string inputTest;
public:
    virtual void SetUp() { }
    virtual void TearDown() { }
};



TEST_F(Test_Calculator, Test_Classic_Operations) {

    try {
        // stack is empty
        inputTest = "2 2 +";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("4", c.getSt().top()->toString());


        // stack is : 4
        inputTest = "2 2 /";
        c.run(inputTest);
        EXPECT_EQ(2, c.getSt().size());
        EXPECT_EQ("1", c.getSt().top()->toString());


        // stack is : 4,1
        inputTest = "2 *";
        c.run(inputTest);
        EXPECT_EQ(2, c.getSt().size());
        EXPECT_EQ("2", c.getSt().top()->toString());


        // stack is : 4,2
        inputTest = "*";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("8", c.getSt().top()->toString());


        // stack is : 8
        inputTest = "16 /";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("1/2", c.getSt().top()->toString());


        // stack is : 1/2
        inputTest = "3 4 / *";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("3/8", c.getSt().top()->toString());


        // stack is : 3/8
        inputTest = "5 8 / +";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("1", c.getSt().top()->toString());


        // stack is : 1
        inputTest = "7 * 3 DIV"; // integer division : 7/3 = 2
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("2", c.getSt().top()->toString());


        // stack is : 2
        inputTest = "9 * 5 MOD"; // integer modulo : 5 MOD 18 = 3
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("3", c.getSt().top()->toString());


        // stack is : 3
        inputTest = "2.3 *";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("6.9", c.getSt().top()->toString());


        // stack is : 6.9
        inputTest = ".5 *";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("3.45", c.getSt().top()->toString());


        // stack is : 3.45
        inputTest = "2 5 / *";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("1.38", c.getSt().top()->toString());


        // stack is : 1.38
        inputTest = ".62 + 3 /";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("2/3", c.getSt().top()->toString());


        // stack is : 2/3
        inputTest = "2 3 / *";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("4/9", c.getSt().top()->toString());


        // stack is : 4/9
        inputTest = "1 2 / /";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("8/9", c.getSt().top()->toString());


        // stack is : 8/9
        inputTest = "1 9 / +";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("1", c.getSt().top()->toString());


        // stack is : 1
        inputTest = "4 /";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("1/4", c.getSt().top()->toString());


        // stack is : 1/4
        inputTest = "1.6 /";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("0.15625", c.getSt().top()->toString());
    }

    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


TEST_F(Test_Calculator, Test_Rational_Operations) {

    try {
        inputTest = "3 5 / NUM";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("3", c.getSt().top()->toString());


        // stack is 3
        inputTest = "3 5 / DEN";
        c.run(inputTest);
        EXPECT_EQ(2, c.getSt().size());
        EXPECT_EQ("5", c.getSt().top()->toString());

        inputTest = "8 NUM";
        c.run(inputTest);
        EXPECT_EQ(3, c.getSt().size());
        EXPECT_EQ("8", c.getSt().top()->toString());

        inputTest = "8 DEN";
        c.run(inputTest);
        EXPECT_EQ(4, c.getSt().size());
        EXPECT_EQ("1", c.getSt().top()->toString());
    }

    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


TEST_F(Test_Calculator, Test_Complex_Operations) {

    try {
        inputTest = "3 4 $";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("3$4", c.getSt().top()->toString());

        inputTest = "87878 4.222 $";
        c.run(inputTest);
        EXPECT_EQ(2, c.getSt().size());
        EXPECT_EQ("87878$4.222", c.getSt().top()->toString());
    }

    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


TEST_F(Test_Calculator, Test_Logical_Operations) {

    try {
        inputTest = "1 NOT";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("0", c.getSt().top()->toString());

        inputTest = "1 1 OR";
        c.run(inputTest);
        EXPECT_EQ(2, c.getSt().size());
        EXPECT_EQ("1", c.getSt().top()->toString());

        inputTest = "0 1 OR";
        c.run(inputTest);
        EXPECT_EQ(3, c.getSt().size());
        EXPECT_EQ("1", c.getSt().top()->toString());

        inputTest = "0 0 OR";
        c.run(inputTest);
        EXPECT_EQ(4, c.getSt().size());
        EXPECT_EQ("0", c.getSt().top()->toString());

        inputTest = "1 1 AND";
        c.run(inputTest);
        EXPECT_EQ(5, c.getSt().size());
        EXPECT_EQ("1", c.getSt().top()->toString());

        inputTest = "0 1 AND";
        c.run(inputTest);
        EXPECT_EQ(6, c.getSt().size());
        EXPECT_EQ("0", c.getSt().top()->toString());

        inputTest = "0 0 AND";
        c.run(inputTest);
        EXPECT_EQ(7, c.getSt().size());
        EXPECT_EQ("0", c.getSt().top()->toString());

        inputTest = "'1 + 1' '0 + 0' AND";
        c.run(inputTest);
        EXPECT_EQ(8, c.getSt().size());
        EXPECT_EQ("'AND(1+1,0+0)'", c.getSt().top()->toString());

        inputTest = "EVAL";
        c.run(inputTest);
        EXPECT_EQ(8, c.getSt().size());
        EXPECT_EQ("0", c.getSt().top()->toString());
    }

    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


TEST_F(Test_Calculator, Test_Stack_Operations) {

    try {

        inputTest = "1 CLEAR";
        c.run(inputTest);
        EXPECT_EQ(0, c.getSt().size());

        inputTest = "1 DROP";
        c.run(inputTest);
        EXPECT_EQ(0, c.getSt().size());

        inputTest = "1 DUP";
        c.run(inputTest);
        EXPECT_EQ(2, c.getSt().size());

        inputTest = "1 2 SWAP";
        c.run(inputTest);
        EXPECT_EQ(4, c.getSt().size());
        EXPECT_EQ("1", c.getSt().top()->toString());
        c.run("DROP");
        EXPECT_EQ("2", c.getSt().top()->toString());


        // LASTARGS
        c.run("CLEAR");
        inputTest = "2 2 +";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("4", c.getSt().top()->toString());
        inputTest = "LASTARGS";
        c.run(inputTest);
        EXPECT_EQ(3, c.getSt().size());
        EXPECT_EQ("2", c.getSt().top()->toString());
        c.run("DROP");
        EXPECT_EQ("2", c.getSt().top()->toString());
        c.run("DROP");
        EXPECT_EQ("4", c.getSt().top()->toString());


        // LASTOP
        c.run("CLEAR");
        inputTest = "2 2 + 2 LASTOP";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("6", c.getSt().top()->toString());

        // UNDO
        c.run("CLEAR");
        inputTest = "2 2 + 3 3 + UNDO";
        c.run(inputTest);
        EXPECT_EQ(3, c.getSt().size());
        // UNDO enlève + uniquement
        EXPECT_EQ("3", c.getSt().top()->toString());

        c.run("UNDO");
        EXPECT_EQ(2, c.getSt().size());
        EXPECT_EQ("3", c.getSt().top()->toString());

        c.run("UNDO");
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("4", c.getSt().top()->toString());

        c.run("UNDO");
        EXPECT_EQ(2, c.getSt().size());
        EXPECT_EQ("2", c.getSt().top()->toString());

        c.run("UNDO");
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("2", c.getSt().top()->toString());

        c.run("UNDO");
        EXPECT_EQ(0, c.getSt().size());

        c.run("REDO");
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("2", c.getSt().top()->toString());

        c.run("REDO");
        EXPECT_EQ(2, c.getSt().size());
        EXPECT_EQ("2", c.getSt().top()->toString());

        c.run("REDO");
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("4", c.getSt().top()->toString());

        c.run("REDO");
        EXPECT_EQ(2, c.getSt().size());
        EXPECT_EQ("3", c.getSt().top()->toString());

        c.run("REDO");
        EXPECT_EQ(3, c.getSt().size());
        EXPECT_EQ("3", c.getSt().top()->toString());

        c.run("REDO");
        EXPECT_EQ(2, c.getSt().size());
        EXPECT_EQ("6", c.getSt().top()->toString());

        c.run("REDO");
        EXPECT_EQ(2, c.getSt().size());
        EXPECT_EQ("6", c.getSt().top()->toString());
    }

    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


TEST_F(Test_Calculator, Test_Expression_Evaluation) {

    try {
        // stack is empty
        inputTest = "'2+2+2'";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("'2+2+2'", c.getSt().top()->toString());
        EXPECT_EQ("2+2+2", dynamic_cast<ExpressionLiteral*>(c.getSt().top().get())->getValue());


        // stack is expression '2+2+2'
        inputTest = "EVAL";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("6", c.getSt().top()->toString());


        // stack is 6
        inputTest = "'(2*2 + (5-2)) / 2  ' EVAL +";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("19/2", c.getSt().top()->toString());


        c.run("CLEAR");
        EXPECT_EQ(0, c.getSt().size());


        // stack is empty
        inputTest = "' MOD(2*5,4)  ' EVAL";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("2", c.getSt().top()->toString());

    }

    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}



TEST_F(Test_Calculator, Test_Program_Evaluation) {

    try {
        // stack is empty
        inputTest = "[2 2 + 2 +]";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("[2 2 + 2 +]", c.getSt().top()->toString());
        EXPECT_EQ("2 2 + 2 +", dynamic_cast<ProgramLiteral*>(c.getSt().top().get())->getValue());

        // stack is program [2+2+2]
        inputTest = "EVAL";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("6", c.getSt().top()->toString());

        // stack is 6
        inputTest = "[2 2 * 5 2 - + 2 /] EVAL +";
        c.run(inputTest);
        EXPECT_EQ(1, c.getSt().size());
        EXPECT_EQ("19/2", c.getSt().top()->toString());


    }

    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}



TEST_F(Test_Calculator, Test_Thrown_Exception) {

    // Problem with stack size

    // What if empty string

    // EVAL something else than expression or program


}