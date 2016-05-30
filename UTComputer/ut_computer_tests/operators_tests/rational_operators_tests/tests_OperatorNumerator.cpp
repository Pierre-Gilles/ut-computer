#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/rational_operators/OperatorNumerator.h"

using namespace std;

class Test_Operator_Numerator : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorNumerator op_num;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};



/* ========================================================== */
/*                        classic tests                       */
/* ========================================================== */

TEST_F(Test_Operator_Numerator, Works_On_Rational) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
    op_num.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3", st.top()->toString());

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4,3))));
    op_num.execute(&st);
    EXPECT_EQ(2, st.size());
    EXPECT_EQ("4", st.top()->toString());
}

TEST_F(Test_Operator_Numerator, Works_On_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_num.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3", st.top()->toString());

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4))));
    op_num.execute(&st);
    EXPECT_EQ(2, st.size());
    EXPECT_EQ("4", st.top()->toString());
}

TEST_F(Test_Operator_Numerator, Works_On_Literal) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("(3+2-3*)12")));
    EXPECT_EQ(1, st.size());
    op_num.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'NUM((3+2-3*)12)'", st.top()->toString());
}

/* ========================================================== */
/*                    Thrown exceptions                       */
/* ========================================================== */

TEST_F(Test_Operator_Numerator, Exception_if_Real) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
        EXPECT_EQ(1, st.size());
        //op_num.execute(&st); // uncomment to see message
        EXPECT_THROW(op_num.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Numerator, Exception_if_Complex) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3), NumericLiteral(3))));
        EXPECT_EQ(1, st.size());
        //op_num.execute(&st); // uncomment to see message
        EXPECT_THROW(op_num.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}