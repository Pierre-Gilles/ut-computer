#include <iostream>
#include <gtest/gtest.h>

#include "../../literals/LiteralFactory.h"



class Test_Literal_Factory : public ::testing::Test {
protected:
    LiteralFactory lf;
public:
    virtual void SetUp() { }
    virtual void TearDown() {

    }
};



TEST_F(Test_Literal_Factory, Test_Create_Complex_Numeric) {

    shared_ptr<Literal> test;
    ComplexLiteral *comp;

    test = lf.createLiteral("1");
    comp = dynamic_cast<ComplexLiteral*>(test.get());
    EXPECT_NE(nullptr, comp);
    EXPECT_EQ("1", comp->toString());

    test = lf.createLiteral("112");
    comp = dynamic_cast<ComplexLiteral*>(test.get());
    EXPECT_NE(nullptr, comp);
    EXPECT_EQ("112", comp->toString());

    test = lf.createLiteral("1.1");
    comp = dynamic_cast<ComplexLiteral*>(test.get());
    EXPECT_NE(nullptr, comp);
    EXPECT_EQ("1.1", comp->toString());

    test = lf.createLiteral("112.12");
    comp = dynamic_cast<ComplexLiteral*>(test.get());
    EXPECT_NE(nullptr, comp);
    EXPECT_EQ("112.12", comp->toString());

    test = lf.createLiteral(".112");
    comp = dynamic_cast<ComplexLiteral*>(test.get());
    EXPECT_NE(nullptr, comp);
    EXPECT_EQ("0.112", comp->toString());

}




TEST_F(Test_Literal_Factory, Test_Create_Expression) {

    try {
        shared_ptr<Literal> test;
        ExpressionLiteral *exp;

        test = lf.createLiteral("'1+1'");
        exp = dynamic_cast<ExpressionLiteral*>(test.get());
        EXPECT_NE(nullptr, exp);
        EXPECT_EQ("1+1", exp->getValue()); // the expression is created without the ''
        EXPECT_EQ("'1+1'", exp->toString()); // the toString function add the ''

        test = lf.createLiteral("'1+1*2+3/4*SIN(3+3)'");
        exp = dynamic_cast<ExpressionLiteral*>(test.get());
        EXPECT_NE(nullptr, exp);
        EXPECT_EQ("1+1*2+3/4*SIN(3+3)", exp->getValue()); // the expression is created without the ''
        EXPECT_EQ("'1+1*2+3/4*SIN(3+3)'", exp->toString()); // the toString function add the ''

        test = lf.createLiteral("'1+1 *2 +3 /4 \t * SIN (3+3)'");
        exp = dynamic_cast<ExpressionLiteral*>(test.get());
        EXPECT_NE(nullptr, exp);
        EXPECT_EQ("1+1*2+3/4*SIN(3+3)", exp->getValue()); // the expression is created without the ''
        EXPECT_EQ("'1+1*2+3/4*SIN(3+3)'", exp->toString()); // the toString function add the ''
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }

}

TEST_F(Test_Literal_Factory, Test_Create_Program) {

    try {
        shared_ptr<Literal> test;
        ProgramLiteral *prgm;

        test = lf.createLiteral("[1 1 +]");
        prgm = dynamic_cast<ProgramLiteral*>(test.get());
        EXPECT_NE(nullptr, prgm);
        EXPECT_EQ("1 1 +", prgm->getValue()); // the program is created without the []
        EXPECT_EQ("[1 1 +]", prgm->toString()); // the toString function add the []

        test = lf.createLiteral("[1 1 + 2 * 3 + 4 / 3 3 + SIN *]");
        prgm = dynamic_cast<ProgramLiteral*>(test.get());
        EXPECT_NE(nullptr, prgm);
        EXPECT_EQ("1 1 + 2 * 3 + 4 / 3 3 + SIN *", prgm->getValue()); // the program is created without the []
        EXPECT_EQ("[1 1 + 2 * 3 + 4 / 3 3 + SIN *]", prgm->toString()); // the toString function add the []
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}



TEST_F(Test_Literal_Factory, Test_Create_Raise_Error_If_Incorrect_Syntax) {

    try {

        //lf.createLiteral("1/1"); // uncomment to get error message
        EXPECT_THROW(lf.createLiteral("1/1"), UTComputerException);

        //lf.createLiteral("."); // uncomment to get error message
        EXPECT_THROW(lf.createLiteral("."), UTComputerException);

        //lf.createLiteral("1*1"); // uncomment to get error message
        EXPECT_THROW(lf.createLiteral("1*1"), UTComputerException);

        //lf.createLiteral("1$1"); // uncomment to get error message
        EXPECT_THROW(lf.createLiteral("1$1"), UTComputerException);

        //lf.createLiteral("REF"); // uncomment to get error message
        EXPECT_THROW(lf.createLiteral("REF"), UTComputerException);

        //lf.createLiteral("'1+1"); // uncomment to get error message
        EXPECT_THROW(lf.createLiteral("'1+1"), UTComputerException);

        //lf.createLiteral("1+1'"); // uncomment to get error message
        EXPECT_THROW(lf.createLiteral("1+1'"), UTComputerException);

        //lf.createLiteral("[1 1 +"); // uncomment to get error message
        EXPECT_THROW(lf.createLiteral("[1 1 +"), UTComputerException);

        //lf.createLiteral("1 1 +]"); // uncomment to get error message
        EXPECT_THROW(lf.createLiteral("1 1 +]"), UTComputerException);

    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}