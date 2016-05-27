#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/classic_operators/OperatorNeg.h"
#include "../../../literals/ProgramLiteral.h"

using namespace std;

class Test_Operator_Neg : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorNeg op_neg;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};


TEST_F(Test_Operator_Neg, Integer_Negation) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_neg.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-2", st.top()->toString());

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(-2))));
    op_neg.execute(&st);
    EXPECT_EQ(2, st.size());
    EXPECT_EQ("2", st.top()->toString());
}

TEST_F(Test_Operator_Neg, Rational_Negation) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_neg.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-2/3", st.top()->toString());

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(-2,3))));
    op_neg.execute(&st);
    EXPECT_EQ(2, st.size());
    EXPECT_EQ("2/3", st.top()->toString());
}

TEST_F(Test_Operator_Neg, Real_Negation) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    op_neg.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-2.1", st.top()->toString());

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(-2.1))));
    op_neg.execute(&st);
    EXPECT_EQ(2, st.size());
    EXPECT_EQ("2.1", st.top()->toString());
}

TEST_F(Test_Operator_Neg, Complex_Negation) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2), NumericLiteral(2))));
    op_neg.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("-2$-2", st.top()->toString());

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(-2), NumericLiteral(-2))));
    op_neg.execute(&st);
    EXPECT_EQ(2, st.size());
    EXPECT_EQ("2$2", st.top()->toString());

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(-2), NumericLiteral(2))));
    op_neg.execute(&st);
    EXPECT_EQ(3, st.size());
    EXPECT_EQ("2$-2", st.top()->toString());

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2), NumericLiteral(-2))));
    op_neg.execute(&st);
    EXPECT_EQ(4, st.size());
    EXPECT_EQ("-2$2", st.top()->toString());
}


TEST_F(Test_Operator_Neg, Test_NOT_On_one_ExpressionLiteral) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("3+SIN(3-2)*4")));
    op_neg.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'NEG(3+SIN(3-2)*4)'", st.top()->toString());
    st.clear();
}



/* ========================================================== */
/*                   TEST THROWN EXCEPTIONS                   */
/* ========================================================== */

TEST_F(Test_Operator_Neg, Throw_Exception_Null_Argument) {
    try {
        st.push(shared_ptr<ComplexLiteral>());
        //op_neg.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_neg.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}



TEST_F(Test_Operator_Neg, Throw_Exception_Argument_Invalid) {
    try {
        st.push(shared_ptr<ProgramLiteral>(new ProgramLiteral(" ")));
        //op_neg.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_neg.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}
