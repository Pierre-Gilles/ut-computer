#include <iostream>
#include <gtest/gtest.h>

#include "../../operators/OperatorMultiplication.h"



class Test_Operator_Multiplication : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorMultiplication op_mult;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};

/* ========================================================== */
/* Multiplication between two ComplexLiteral without imaginary part */
/* ========================================================== */


TEST_F(Test_Operator_Multiplication, Integer_Mult_Integer_Gives_Integer) {
    st.push(new ComplexLiteral(new NumericLiteral(2)));
    st.push(new ComplexLiteral(new NumericLiteral(3)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("6", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Integer_Mult_Rational_Gives_Rational) {
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("10/3", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Integer_Mult_Real_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(3)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.5", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Rational_Mult_Integer_Gives_Rational) {
    st.push(new ComplexLiteral(new NumericLiteral(4, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("20/3", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Rational_Mult_Rational_Gives_Rational) {
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("4/9", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Rational_Mult_Real_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(1, 2)));
    st.push(new ComplexLiteral(new NumericLiteral(0.1)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0.05", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Real_Mult_Rational_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(1.5)));
    st.push(new ComplexLiteral(new NumericLiteral(1, 4)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0.375", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Real_Mult_Rational_Gives_Integer) {
    /* real - rational = integer by simplification */
    st.push(new ComplexLiteral(new NumericLiteral(2.5)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 5)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

// Not sure if possible
/*TEST_F(Test_Operator_Multiplication, Real_Mult_Real_Gives_Integer) {
    st.push(new ComplexLiteral(new NumericLiteral(1.5)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}*/

TEST_F(Test_Operator_Multiplication, Real_Mult_Real_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(0.6)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0.3", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Real_Mult_Integer_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(3)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.5", st.top()->toString());
}


/* ========================================================== */
/* Multiplication between two ComplexLiteral with imaginary part  */
/* ========================================================== */

TEST_F(Test_Operator_Multiplication, ComplexInt_Mult_ComplexInt) {
    /* Multiplication between two complex with integer parts */
    st.push(new ComplexLiteral(new NumericLiteral(2), new NumericLiteral(3)));
    st.push(new ComplexLiteral(new NumericLiteral(2), new NumericLiteral(2)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("4$6", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, ComplexReal_Mult_ComplexReal) {
    /* Multiplication between two complex with real parts */
    st.push(new ComplexLiteral(new NumericLiteral(1.1), new NumericLiteral(3.1)));
    st.push(new ComplexLiteral(new NumericLiteral(2.2), new NumericLiteral(1.2)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("2.42$3.72", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, ComplexRational_Mult_ComplexRational) {
    /* Multiplication between two complex with rational parts */
    st.push(new ComplexLiteral(new NumericLiteral(2,3), new NumericLiteral(3,4)));
    st.push(new ComplexLiteral(new NumericLiteral(1,3), new NumericLiteral(2,4)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("2/9$3/8", st.top()->toString());
}


/* ========================================================== */
/* Multiplication between a ComplexLiteral and an ExpressionLiteral */
/* ========================================================== */


TEST_F(Test_Operator_Multiplication, Complex_Mult_Expression) {
    st.push(new ComplexLiteral(new NumericLiteral(1,3)));
    st.push(new ExpressionLiteral("1+1"));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1/3*(1+1)", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Complex) {
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ComplexLiteral(new NumericLiteral(1,3)));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1+1)*1/3", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression) {
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ExpressionLiteral("1+1"));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1+1)*(1+1)", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_1) {
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ExpressionLiteral("1*1"));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1+1)*1*1", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_2) {
    st.push(new ExpressionLiteral("1<1"));
    st.push(new ExpressionLiteral("1+1"));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1<1)*(1+1)", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_3) {
    st.push(new ExpressionLiteral("1AND1"));
    st.push(new ExpressionLiteral("1*1"));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1AND1)*1*1", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_4) {
    st.push(new ExpressionLiteral("(1<1)+(1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("((1<1)+(1*1))*1/1", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_5) {
    st.push(new ExpressionLiteral("(1<1)*(1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1<1)*(1*1)*1/1", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_6) {
    st.push(new ExpressionLiteral("(1*1*1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1*1*1*1)*1/1", st.top()->toString());
}