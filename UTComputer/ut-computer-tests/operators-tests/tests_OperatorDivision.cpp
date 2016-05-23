#include <iostream>
#include <gtest/gtest.h>

#include "../../operators/OperatorDivision.h"



class Test_Operator_Division : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorDivision op_div;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};

/* ========================================================== */
/* Multiplication between two ComplexLiteral without imaginary part */
/* ========================================================== */


TEST_F(Test_Operator_Division, Integer_Div_Integer_Gives_Integer) {
    st.push(new ComplexLiteral(new NumericLiteral(6)));
    st.push(new ComplexLiteral(new NumericLiteral(3)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("2", st.top()->toString());
}

TEST_F(Test_Operator_Division, Integer_Div_Rational_Gives_Integer) {
    st.push(new ComplexLiteral(new NumericLiteral(6)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("9", st.top()->toString());
}

TEST_F(Test_Operator_Division, Integer_Div_Rational_Gives_Rational) {
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("15/2", st.top()->toString());
}

TEST_F(Test_Operator_Division, Integer_Div_Real_Gives_Real) {
    try {
        st.push(new ComplexLiteral(new NumericLiteral(3)));
        st.push(new ComplexLiteral(new NumericLiteral(0.8)));
        op_div.execute(&st);
        EXPECT_EQ(1, st.size());
        EXPECT_EQ("3.75", st.top()->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << "   " << st.top()->toString() << endl;
    }

}

TEST_F(Test_Operator_Division, Rational_Div_Integer_Gives_Rational) {
    st.push(new ComplexLiteral(new NumericLiteral(4, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("4/15", st.top()->toString());
}

TEST_F(Test_Operator_Division, Rational_Div_Rational_Gives_Integer) {
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Division, Rational_Div_Rational_Gives_Rational) {
    st.push(new ComplexLiteral(new NumericLiteral(4, 3)));
    st.push(new ComplexLiteral(new NumericLiteral(3, 2)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("8/9", st.top()->toString());
}

TEST_F(Test_Operator_Division, Rational_Div_Real_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(3, 4)));
    st.push(new ComplexLiteral(new NumericLiteral(0.6)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.25", st.top()->toString());
}

TEST_F(Test_Operator_Division, Real_Div_Rational_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(1.7)));
    st.push(new ComplexLiteral(new NumericLiteral(1, 4)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("6.8", st.top()->toString());
}

TEST_F(Test_Operator_Division, Real_Div_Rational_Gives_Integer) {
    /* real - rational = integer by simplification */
    st.push(new ComplexLiteral(new NumericLiteral(2.5)));
    st.push(new ComplexLiteral(new NumericLiteral(1, 2)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("5", st.top()->toString());
}

TEST_F(Test_Operator_Division, Real_Div_Real_Gives_Integer) {
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Division, Real_Div_Real_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(0.55)));
    st.push(new ComplexLiteral(new NumericLiteral(0.5)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.1", st.top()->toString());
}

TEST_F(Test_Operator_Division, Real_Div_Integer_Gives_Real) {
    st.push(new ComplexLiteral(new NumericLiteral(4.5)));
    st.push(new ComplexLiteral(new NumericLiteral(2)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("2.25", st.top()->toString());
}


/* ========================================================== */
/* Multiplication between two ComplexLiteral with imaginary part  */
/* ========================================================== */

TEST_F(Test_Operator_Division, ComplexInt_Div_ComplexInt) {
    /* Multiplication between two complex with integer parts */
    st.push(new ComplexLiteral(new NumericLiteral(2), new NumericLiteral(3)));
    st.push(new ComplexLiteral(new NumericLiteral(2), new NumericLiteral(2)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-2$10", st.top()->toString());
}

TEST_F(Test_Operator_Division, ComplexReal_Div_ComplexReal) {
    /* Multiplication between two complex with real parts */
    st.push(new ComplexLiteral(new NumericLiteral(1.1), new NumericLiteral(3.1)));
    st.push(new ComplexLiteral(new NumericLiteral(2.2), new NumericLiteral(1.2)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-1.3$8.14", st.top()->toString());
}

TEST_F(Test_Operator_Division, ComplexRational_Div_ComplexRational) {
    /* Multiplication between two complex with rational parts */
    st.push(new ComplexLiteral(new NumericLiteral(2,3), new NumericLiteral(3,4)));
    st.push(new ComplexLiteral(new NumericLiteral(1,3), new NumericLiteral(2,4)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-11/72$7/12", st.top()->toString());
}


/* ========================================================== */
/* Multiplication between a ComplexLiteral and an ExpressionLiteral */
/* ========================================================== */


TEST_F(Test_Operator_Division, Complex_Div_Expression) {
    st.push(new ComplexLiteral(new NumericLiteral(1,3)));
    st.push(new ExpressionLiteral("1+1"));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'1/3/(1+1)'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Complex) {
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ComplexLiteral(new NumericLiteral(1,3)));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1+1)/1/3'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression) {
    st.push(new ExpressionLiteral("1+1"));
    st.push(new ExpressionLiteral("1+1"));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1+1)/(1+1)'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression_1) {
    try {
        st.push(new ExpressionLiteral("1+1"));
        st.push(new ExpressionLiteral("1*1"));
        op_div.execute(&st);
        EXPECT_EQ(1, st.size());
        EXPECT_EQ("'(1+1)/1*1'", st.top()->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


}

TEST_F(Test_Operator_Division, Expression_Div_Expression_2) {
    st.push(new ExpressionLiteral("1<1"));
    st.push(new ExpressionLiteral("1+1"));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1<1)/(1+1)'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression_3) {
    st.push(new ExpressionLiteral("1AND1"));
    st.push(new ExpressionLiteral("1*1"));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1AND1)/1*1'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression_4) {
    st.push(new ExpressionLiteral("(1<1)+(1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'((1<1)+(1*1))/1/1'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression_5) {
    st.push(new ExpressionLiteral("(1<1)*(1*1)"));
    st.push(new ExpressionLiteral("1*1"));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1<1)*(1*1)/1*1'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression_6) {
    st.push(new ExpressionLiteral("(1*1*1*1)"));
    st.push(new ExpressionLiteral("1/1"));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1*1*1*1)/1/1'", st.top()->toString());
}



/* ========================================================== */
/*                   TEST THROWN EXCEPTIONS                   */
/* ========================================================== */

TEST_F(Test_Operator_Division, Throw_Exception_Two_Arguments_Invalid) {
    st.push(new NumericLiteral(2));
    st.push(new NumericLiteral(2));
    try {
//        op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Division, Throw_Exception_Null_Arguments) {
    st.push(nullptr);
    st.push(nullptr);
    try {
//        op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Division, Throw_Exception_First_Argument_Invalid) {
    st.push(new NumericLiteral(2));
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    try {
//        op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Division, Throw_Exception_First_Argument_Is_Null) {
    st.push(nullptr);
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    try {
//        op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Division, Throw_Exception_Second_Argument_Invalid) {
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    st.push(new NumericLiteral(2));
    try {
//        op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Division, Throw_Exception_Second_Argument_Is_Null) {
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    st.push(nullptr);
    try {
//        op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}