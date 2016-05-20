#include <iostream>
#include <gtest/gtest.h>

#include "../../operators/OperatorMinus.h"



class Test_Operator_Minus : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorMinus op_minus;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};

/* ========================================================== */
/* Difference between two ComplexLiteral without imaginary part */
/* ========================================================== */


TEST_F(Test_Operator_Minus, Integer_Minus_Integer_Gives_Integer) {
    st.push(new ComplexLiteral(new NumericLiteral(2)));
    st.push(new ComplexLiteral(new NumericLiteral(3)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-1", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Integer_Minus_Rational_Gives_Rational) {
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("13/3", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Integer_Minus_Real_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(1)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0.5", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Rational_Minus_Integer_Gives_Rational) {
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-13/3", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Rational_Minus_Rational_Gives_Rational) {
    st.push(new ComplexLiteral(new NumericLiteral(1, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-1/3", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Rational_Minus_Rational_Gives_Integer) {
    /* rational - rational = integer (by simplification) */
    st.push(new ComplexLiteral(new NumericLiteral(3, 2)));
    st.push(new ComplexLiteral(new NumericLiteral(5, 2)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-1", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Rational_Minus_Real_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(1, 2)));
    st.push(new ComplexLiteral(new NumericLiteral(0.1)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0.4", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Real_Minus_Rational_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(1.5)));
    st.push(new ComplexLiteral(new NumericLiteral(1, 4)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.25", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Real_Minus_Rational_Gives_Integer) {
    /* real - rational = integer by simplification */
    st.push(new ComplexLiteral(new NumericLiteral(1.5)));
    st.push(new ComplexLiteral(new NumericLiteral(1, 2)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Real_Minus_Real_Gives_Integer) {
    st.push(new ComplexLiteral(new NumericLiteral(1.5)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Real_Minus_Real_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(0.6)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-0.1", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Real_Minus_Integer_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(1)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-0.5", st.top()->toString());
}


/* ========================================================== */
/* Difference between two ComplexLiteral with imaginary part  */
/* ========================================================== */

TEST_F(Test_Operator_Minus, ComplexInt_Minus_ComplexInt) {
    /* Difference between two complex with integer parts */
    st.push(new ComplexLiteral(new NumericLiteral(1), new NumericLiteral(3)));
    st.push(new ComplexLiteral(new NumericLiteral(2), new NumericLiteral(1)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-1$2", st.top()->toString());
}

TEST_F(Test_Operator_Minus, ComplexReal_Minus_ComplexReal) {
    /* Difference between two complex with real parts */
    st.push(new ComplexLiteral(new NumericLiteral(1.1), new NumericLiteral(3.1)));
    st.push(new ComplexLiteral(new NumericLiteral(2.2), new NumericLiteral(1.2)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-1.1$1.9", st.top()->toString());
}

TEST_F(Test_Operator_Minus, ComplexRational_Minus_ComplexRational) {
    /* Difference between two complex with rational parts */
    st.push(new ComplexLiteral(new NumericLiteral(2,3), new NumericLiteral(3,4)));
    st.push(new ComplexLiteral(new NumericLiteral(1,3), new NumericLiteral(2,4)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1/3$1/4", st.top()->toString());
}


/* ========================================================== */
/* Difference between a ComplexLiteral and an ExpressionLiteral */
/* ========================================================== */


TEST_F(Test_Operator_Minus, Complex_Minus_Expression) {
    st.push(new ComplexLiteral(new NumericLiteral(1,3)));
    st.push(new ExpressionLiteral("1+1"));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1/3)-1+1", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Expression_Minus_Complex) {
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ComplexLiteral(new NumericLiteral(1,3)));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1+1-(1/3)", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Expression_Minus_Expression) {
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ExpressionLiteral("1+1"));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1+1-1+1", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Expression_Minus_Expression_1) {
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ExpressionLiteral("1*1"));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1+1-(1*1)", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Expression_Minus_Expression_2) {
    st.push(new ExpressionLiteral("1<1"));
    st.push(new ExpressionLiteral("1+1"));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1<1)-1+1", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Expression_Minus_Expression_3) {
    st.push(new ExpressionLiteral("1AND1"));
    st.push(new ExpressionLiteral("1*1"));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1AND1)-(1*1)", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Expression_Minus_Expression_4) {
    st.push(new ExpressionLiteral("(1<1)+(1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1<1)+(1*1)-(1/1)", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Expression_Minus_Expression_5) {
    st.push(new ExpressionLiteral("(1<1)*(1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("((1<1)*(1*1))-(1/1)", st.top()->toString());
}

TEST_F(Test_Operator_Minus, Expression_Minus_Expression_6) {
    st.push(new ExpressionLiteral("(1*1*1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_minus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1*1*1*1)-(1/1)", st.top()->toString());
}



/* ========================================================== */
/*                   TEST THROWN EXCEPTIONS                   */
/* ========================================================== */

TEST_F(Test_Operator_Minus, Throw_Exception_Two_Arguments_Invalid) {
    st.push(new NumericLiteral(2));
    st.push(new NumericLiteral(2));
    try {
//        op_minus.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_minus.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Minus, Throw_Exception_Null_Arguments) {
    st.push(nullptr);
    st.push(nullptr);
    try {
//        op_minus.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_minus.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Minus, Throw_Exception_First_Argument_Invalid) {
    st.push(new NumericLiteral(2));
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    try {
//        op_minus.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_minus.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Minus, Throw_Exception_First_Argument_Is_Null) {
    st.push(nullptr);
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    try {
//        op_minus.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_minus.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Minus, Throw_Exception_Second_Argument_Invalid) {
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    st.push(new NumericLiteral(2));
    try {
//        op_minus.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_minus.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Minus, Throw_Exception_Second_Argument_Is_Null) {
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    st.push(nullptr);
    try {
//        op_minus.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_minus.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}