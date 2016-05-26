#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/classic_operators/OperatorMultiplication.h"



class Test_Operator_Multiplication : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorMultiplication op_mult;
    shared_ptr<NumericLiteral> numeric_literal_pointer_1;
    shared_ptr<NumericLiteral> numeric_literal_pointer_2;


public:
    virtual void SetUp() {
        numeric_literal_pointer_1 = shared_ptr<NumericLiteral>(new NumericLiteral(2));
        numeric_literal_pointer_2 = shared_ptr<NumericLiteral>(new NumericLiteral(2));
    }

    virtual void TearDown() {
        st.clear();
    }
};

/* ========================================================== */
/* Multiplication between two ComplexLiteral without imaginary part */
/* ========================================================== */


TEST_F(Test_Operator_Multiplication, Integer_Mult_Integer_Gives_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("6", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Integer_Mult_Rational_Gives_Rational) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("10/3", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Integer_Mult_Real_Gives_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.5))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.5", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Rational_Mult_Integer_Gives_Rational) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("20/3", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Rational_Mult_Rational_Gives_Rational) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("4/9", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Rational_Mult_Real_Gives_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.1))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0.05", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Real_Mult_Rational_Gives_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1.5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,4))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0.375", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Real_Mult_Rational_Gives_Integer) {
    /* real - rational = integer by simplification */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,5))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

// Not sure if possible
/*TEST_F(Test_Operator_Multiplication, Real_Mult_Real_Gives_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1.5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.5))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}*/

TEST_F(Test_Operator_Multiplication, Real_Mult_Real_Gives_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.6))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0.3", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Real_Mult_Integer_Gives_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.5", st.top()->toString());
}


/* ========================================================== */
/* Multiplication between two ComplexLiteral with imaginary part  */
/* ========================================================== */

TEST_F(Test_Operator_Multiplication, ComplexInt_Mult_ComplexInt) {
    /* Multiplication between two complex with integer parts */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(2),
            NumericLiteral(3)
    )));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(2),
            NumericLiteral(2)
    )));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-2$10", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, ComplexReal_Mult_ComplexReal) {
    /* Multiplication between two complex with real parts */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(1.1),
            NumericLiteral(3.1)
    )));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(2.2),
            NumericLiteral(1.2)
    )));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-1.3$8.14", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, ComplexRational_Mult_ComplexRational) {
    /* Multiplication between two complex with rational parts */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(2,3),
            NumericLiteral(3,4)
    )));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(1,3),
            NumericLiteral(2,4)
    )));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-11/72$7/12", st.top()->toString());
}


/* ========================================================== */
/* Multiplication between a ComplexLiteral and an ExpressionLiteral */
/* ========================================================== */


TEST_F(Test_Operator_Multiplication, Complex_Mult_Expression) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,3))));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'1/3*(1+1)'", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Complex) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,3))));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1+1)*1/3'", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1+1)*(1+1)'", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_1) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1*1")));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1+1)*1*1'", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_2) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1<1")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1<1)*(1+1)'", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_3) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1AND1")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1*1")));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1AND1)*1*1'", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_4) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("(1<1)+(1*1)")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1/1")));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'((1<1)+(1*1))*1/1'", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_5) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("(1<1)*(1*1)")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1/1")));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1<1)*(1*1)*1/1'", st.top()->toString());
}

TEST_F(Test_Operator_Multiplication, Expression_Mult_Expression_6) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("(1*1*1*1)")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1/1")));
    op_mult.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1*1*1*1)*1/1'", st.top()->toString());
}



/* ========================================================== */
/*                   TEST THROWN EXCEPTIONS                   */
/* ========================================================== */

TEST_F(Test_Operator_Multiplication, Throw_Exception_Null_Arguments) {
    st.push(shared_ptr<ComplexLiteral>());
    st.push(shared_ptr<ComplexLiteral>());
    try {
       //op_mult.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_mult.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Multiplication, Throw_Exception_First_Argument_Is_Null) {
    st.push(shared_ptr<ComplexLiteral>());
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    try {
       //op_mult.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_mult.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Multiplication, Throw_Exception_Second_Argument_Is_Null) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    st.push(shared_ptr<ComplexLiteral>());
    try {
       //op_mult.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_mult.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Multiplication, Throw_Exception_Two_Arguments_Invalid) {
    st.push(numeric_literal_pointer_1);
    st.push(numeric_literal_pointer_2);
    try {
       //op_mult.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_mult.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Multiplication, Throw_Exception_First_Argument_Invalid) {
    st.push(numeric_literal_pointer_1);
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    try {
       //op_mult.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_mult.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Multiplication, Throw_Exception_Second_Argument_Invalid) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    st.push(numeric_literal_pointer_1);
    try {
        //op_mult.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_mult.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}
