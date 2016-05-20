#include <iostream>
#include <gtest/gtest.h>

#include "../../operators/OperatorPlus.h"




class Test_Operator_Plus : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorPlus op_plus;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};
/* ========================================================== */
/* addition between two ComplexLiteral without imaginary part */
/* ========================================================== */


TEST_F(Test_Operator_Plus, Integer_Plus_Integer_Gives_Integer) {
    /* integer + integer = integer */
    st.push(new ComplexLiteral(new NumericLiteral(2)));
    st.push(new ComplexLiteral(new NumericLiteral(3)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("5", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Integer_Plus_Rational_Gives_Rational) {
    /* integer + rational = rational */
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("17/3", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Integer_Plus_Real_Gives_Real) {
    /* integer + rational = rational */
    st.push(new ComplexLiteral(new NumericLiteral(1)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.5", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Rational_Plus_Integer_Gives_Rational) {
    /* rational + integer = rational */
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("17/3", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Rational_Plus_Rational_Gives_Rational) {
    /* rational + rational = rational */
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("4/3", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Rational_Plus_Rational_Gives_Integer) {
    /* rational + rational = integer (by simplification) */
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(1, 3)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Rational_Plus_Real_Gives_Real) {
    /* rational + real = real */
    st.push(new ComplexLiteral(new NumericLiteral(3, 4)));
    st.push(new ComplexLiteral(new NumericLiteral(0.3)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.05", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Rational_Plus_Real_Gives_Real_Not_Rational) {
    /* rational + real = rational */
    st.push(new ComplexLiteral(new NumericLiteral(3, 4)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_NE("5/4", st.top()->toString());
    EXPECT_EQ("1.25", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Real_Plus_Rational_Gives_Real) {
    /* real + rational = real */
    st.push(new ComplexLiteral(new NumericLiteral(0.3)));
    st.push(new ComplexLiteral(new NumericLiteral(3, 4)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.05", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Real_Plus_Rational_Gives_Real_Not_Rational) {
    /* real + rational = rational */
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(3, 4)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_NE("5/4", st.top()->toString());
    EXPECT_EQ("1.25", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Real_Plus_Rational_Gives_Integer) {
    /* real + rational = integer by simplification */
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(1, 2)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Real_Plus_Real_Gives_Integer) {
    /* real + real = integer  */
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Real_Plus_Real_Gives_Real) {
    /* real + real = real */
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(0.6)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.1", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Real_Plus_Integer_Gives_Real) {
    /* real + real = real */
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(1)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.5", st.top()->toString());
}


/* ========================================================== */
/*   addition between two ComplexLiteral with imaginary part  */
/* ========================================================== */

TEST_F(Test_Operator_Plus, ComplexInt_Plus_ComplexInt) {
    /* Addition of two complex with integer parts */
    st.push(new ComplexLiteral(new NumericLiteral(1), new NumericLiteral(3)));
    st.push(new ComplexLiteral(new NumericLiteral(2), new NumericLiteral(1)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3$4", st.top()->toString());
}

TEST_F(Test_Operator_Plus, ComplexReal_Plus_ComplexReal) {
    /* Addition of two complex with real parts */
    st.push(new ComplexLiteral(new NumericLiteral(1.1), new NumericLiteral(3.1)));
    st.push(new ComplexLiteral(new NumericLiteral(2.1), new NumericLiteral(1.1)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3.2$4.2", st.top()->toString());
}

TEST_F(Test_Operator_Plus, ComplexRational_Plus_ComplexRational) {
    /* Addition of two complex with rational parts */
    st.push(new ComplexLiteral(new NumericLiteral(1,3), new NumericLiteral(3,4)));
    st.push(new ComplexLiteral(new NumericLiteral(1,3), new NumericLiteral(2,4)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("2/3$5/4", st.top()->toString());
}


/* ========================================================== */
/* addition between a ComplexLiteral and an ExpressionLiteral */
/* ========================================================== */


TEST_F(Test_Operator_Plus, Complex_Plus_Expression) {
    st.push(new ComplexLiteral(new NumericLiteral(1,3)));
    st.push(new ExpressionLiteral("1+1"));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1/3)+1+1", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Expression_Plus_Complex) {
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ComplexLiteral(new NumericLiteral(1,3)));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1+1+(1/3)", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Expression_Plus_Expression) {
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ExpressionLiteral("1+1"));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1+1+1+1", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Expression_Plus_Expression_1) {
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ExpressionLiteral("1*1"));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1+1+(1*1)", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Expression_Plus_Expression_2) {
    st.push(new ExpressionLiteral("1<1"));
    st.push(new ExpressionLiteral("1+1"));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1<1)+1+1", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Expression_Plus_Expression_3) {
    st.push(new ExpressionLiteral("1AND1"));
    st.push(new ExpressionLiteral("1*1"));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1AND1)+(1*1)", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Expression_Plus_Expression_4) {
    st.push(new ExpressionLiteral("(1<1)+(1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1<1)+(1*1)+(1/1)", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Expression_Plus_Expression_5) {
    st.push(new ExpressionLiteral("(1<1)*(1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("((1<1)*(1*1))+(1/1)", st.top()->toString());
}

TEST_F(Test_Operator_Plus, Expression_Plus_Expression_6) {
    st.push(new ExpressionLiteral("(1*1*1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_plus.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("(1*1*1*1)+(1/1)", st.top()->toString());
}