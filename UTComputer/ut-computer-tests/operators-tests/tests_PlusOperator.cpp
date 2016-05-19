#include <iostream>
#include <gtest/gtest.h>
#include <string>

#include "../../operators/Operator.h"
#include "../../operators/PlusOperator.h"

StackUTComputer st;
PlusOperator op_plus(2);


/* ========================================================== */
/* addition between two ComplexLiteral without imaginary part */
/* ========================================================== */


TEST(OperatorPlus, Integer_Plus_Integer_Gives_Integer) {
    /* integer + integer = integer */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(2)));
    st.push(new ComplexLiteral(new NumericLiteral(3)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("5", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Integer_Plus_Rational_Gives_Rational) {
    /* integer + rational = rational */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("17/3", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Integer_Plus_Real_Gives_Real) {
    /* integer + rational = rational */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(1)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("1.5", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Rational_Plus_Integer_Gives_Rational) {
    /* rational + integer = rational */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("17/3", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Rational_Plus_Rational_Gives_Rational) {
    /* rational + rational = rational */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("4/3", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Rational_Plus_Rational_Gives_Integer) {
    /* rational + rational = integer (by simplification) */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(1, 3)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("1", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Rational_Plus_Real_Gives_Real) {
    /* rational + real = real */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(3, 4)));
    st.push(new ComplexLiteral(new NumericLiteral(0.3)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("1.05", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Rational_Plus_Real_Gives_Rational) {
    /* rational + real = rational */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(3, 4)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("5/4", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Real_Plus_Rational_Gives_Real) {
    /* real + rational = real */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(0.3)));
    st.push(new ComplexLiteral(new NumericLiteral(3, 4)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("1.05", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Real_Plus_Rational_Gives_Rational) {
    /* real + rational = rational */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(3, 4)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("5/4", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Real_Plus_Rational_Gives_Integer) {
    /* real + rational = integer by simplification */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(1, 2)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("1", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Real_Plus_Real_Gives_Integer) {
    /* real + real = integer  */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("1", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Real_Plus_Real_Gives_Real) {
    /* real + real = real */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(0.6)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("1.1", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Real_Plus_Integer_Gives_Real) {
    /* real + real = real */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(1)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("1.5", st.top()->toString());
    st.clear();
}


/* ========================================================== */
/*   addition between two ComplexLiteral with imaginary part  */
/* ========================================================== */

TEST(OperatorPlus, ComplexInt_Plus_ComplexInt) {
    /* Addition of two complex with integer parts */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(1), new NumericLiteral(3)));
    st.push(new ComplexLiteral(new NumericLiteral(2), new NumericLiteral(1)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("3$4", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, ComplexReal_Plus_ComplexReal) {
    /* Addition of two complex with real parts */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(1.1), new NumericLiteral(3.1)));
    st.push(new ComplexLiteral(new NumericLiteral(2.1), new NumericLiteral(1.1)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("3.2$4.2", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, ComplexRational_Plus_ComplexRational) {
    /* Addition of two complex with rational parts */
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(1,3), new NumericLiteral(3,4)));
    st.push(new ComplexLiteral(new NumericLiteral(1,3), new NumericLiteral(2,4)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("2/3$5/4", st.top()->toString());
    st.clear();
}


/* ========================================================== */
/* addition between a ComplexLiteral and an ExpressionLiteral */
/* ========================================================== */


TEST(OperatorPlus, Complex_Plus_Expression) {
    st.clear();
    st.push(new ComplexLiteral(new NumericLiteral(1,3)));
    st.push(new ExpressionLiteral("1+1"));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("(1/3)+1+1", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Expression_Plus_Complex) {
    st.clear();
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ComplexLiteral(new NumericLiteral(1,3)));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("1+1+(1/3)", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Expression_Plus_Expression) {
    st.clear();
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ExpressionLiteral("1+1"));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("1+1+1+1", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Expression_Plus_Expression_1) {
    st.clear();
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ExpressionLiteral("1*1"));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("1+1+(1*1)", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Expression_Plus_Expression_2) {
    st.clear();
    st.push(new ExpressionLiteral("1<1"));
    st.push(new ExpressionLiteral("1+1"));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("(1<1)+1+1", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Expression_Plus_Expression_3) {
    st.clear();
    st.push(new ExpressionLiteral("1<1"));
    st.push(new ExpressionLiteral("1*1"));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("(1<1)+(1*1)", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Expression_Plus_Expression_4) {
    st.clear();
    st.push(new ExpressionLiteral("(1<1)+(1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("(1<1)+(1*1)+(1/1)", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Expression_Plus_Expression_5) {
    st.clear();
    st.push(new ExpressionLiteral("(1<1)*(1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("((1<1)*(1*1))+(1/1)", st.top()->toString());
    st.clear();
}

TEST(OperatorPlus, Expression_Plus_Expression_6) {
    st.clear();
    st.push(new ExpressionLiteral("(1*1*1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_plus.execute(&st);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ("(1*1*1*1)+(1/1)", st.top()->toString());
    st.clear();
}