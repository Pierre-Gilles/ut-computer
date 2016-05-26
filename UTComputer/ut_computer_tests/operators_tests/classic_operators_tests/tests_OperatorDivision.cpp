#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/classic_operators/OperatorDivision.h"



class Test_Operator_Division : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorDivision op_div;
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
/* Division between two ComplexLiteral without imaginary part */
/* ========================================================== */


TEST_F(Test_Operator_Division, Integer_Div_Integer_Gives_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(6))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("2", st.top()->toString());
}

TEST_F(Test_Operator_Division, Integer_Div_Rational_Gives_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(6))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("9", st.top()->toString());
}

TEST_F(Test_Operator_Division, Integer_Div_Rational_Gives_Rational) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("15/2", st.top()->toString());
}

TEST_F(Test_Operator_Division, Integer_Div_Real_Gives_Real) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.8))));
        op_div.execute(&st);
        EXPECT_EQ(1, st.size());
        EXPECT_EQ("3.75", st.top()->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << "   " << st.top()->toString() << endl;
    }

}

TEST_F(Test_Operator_Division, Rational_Div_Integer_Gives_Rational) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("4/15", st.top()->toString());
}

TEST_F(Test_Operator_Division, Rational_Div_Rational_Gives_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Division, Rational_Div_Rational_Gives_Rational) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,2))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("8/9", st.top()->toString());
}

TEST_F(Test_Operator_Division, Rational_Div_Real_Gives_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.6))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.25", st.top()->toString());
}

TEST_F(Test_Operator_Division, Real_Div_Rational_Gives_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1.7))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,4))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("6.8", st.top()->toString());
}

TEST_F(Test_Operator_Division, Real_Div_Rational_Gives_Integer) {
    /* real - rational = integer by simplification */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,2))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("5", st.top()->toString());
}

TEST_F(Test_Operator_Division, Real_Div_Real_Gives_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.5))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Division, Real_Div_Real_Gives_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.55))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.5))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1.1", st.top()->toString());
}

TEST_F(Test_Operator_Division, Real_Div_Integer_Gives_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4.5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("2.25", st.top()->toString());
}


/* ========================================================== */
/* Division between two ComplexLiteral with imaginary part  */
/* ========================================================== */

TEST_F(Test_Operator_Division, ComplexInt_Div_ComplexInt) {
    /* Division between two complex with integer parts */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(2),
            NumericLiteral(3)
    )));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(2),
            NumericLiteral(2)
    )));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("5/4$1/4", st.top()->toString());
}

TEST_F(Test_Operator_Division, ComplexReal_Div_ComplexReal) {
    /* Division between two complex with real parts */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(1.1),
            NumericLiteral(3.1)
    )));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(2.2),
            NumericLiteral(1.2)
    )));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0.977707$0.875796", st.top()->toString());
}

TEST_F(Test_Operator_Division, ComplexRational_Div_ComplexRational) {
    /* Division between two complex with rational parts */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(2,3),
            NumericLiteral(3,4)
    )));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(1,3),
            NumericLiteral(2,4)
    )));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("43/26$-3/13", st.top()->toString());
}


/* ========================================================== */
/* Division between a ComplexLiteral and an ExpressionLiteral */
/* ========================================================== */


TEST_F(Test_Operator_Division, Complex_Div_Expression) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,3))));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'1/3/(1+1)'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Complex) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,3))));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1+1)/1/3'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1+1)/(1+1)'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression_1) {
    try {
        st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
        st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1*1")));
        op_div.execute(&st);
        EXPECT_EQ(1, st.size());
        EXPECT_EQ("'(1+1)/1*1'", st.top()->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


}

TEST_F(Test_Operator_Division, Expression_Div_Expression_2) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1<1")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1<1)/(1+1)'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression_3) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1AND1")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1*1")));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1AND1)/1*1'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression_4) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("(1<1)+(1*1)")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1/1")));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'((1<1)+(1*1))/1/1'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression_5) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("(1<1)*(1*1)")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1*1")));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1<1)*(1*1)/1*1'", st.top()->toString());
}

TEST_F(Test_Operator_Division, Expression_Div_Expression_6) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("(1*1*1*1)")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1/1")));
    op_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'(1*1*1*1)/1/1'", st.top()->toString());
}



/* ========================================================== */
/*                   TEST THROWN EXCEPTIONS                   */
/* ========================================================== */

TEST_F(Test_Operator_Division, Throw_Exception_Null_Arguments) {
    st.push(shared_ptr<ComplexLiteral>());
    st.push(shared_ptr<ComplexLiteral>());
    try {
       //op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Division, Throw_Exception_First_Argument_Is_Null) {
    st.push(shared_ptr<ComplexLiteral>());
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    try {
       //op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Division, Throw_Exception_Second_Argument_Is_Null) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    st.push(shared_ptr<ComplexLiteral>());
    try {
       //op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Division, Throw_Exception_Two_Arguments_Invalid) {
    st.push(numeric_literal_pointer_1);
    st.push(numeric_literal_pointer_2);
    try {
       //op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Division, Throw_Exception_First_Argument_Invalid) {
    st.push(numeric_literal_pointer_1);
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    try {
       //op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Division, Throw_Exception_Second_Argument_Invalid) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    st.push(numeric_literal_pointer_1);
    try {
       //op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}



/* ========================================================== */
/*                      TEST DIVISION BY 0                    */
/* ========================================================== */



TEST_F(Test_Operator_Division, Throw_Exception_Division_By_Zero) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
        //op_div.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_div.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}