#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/logical_operators/OperatorNot.h"

using namespace std;

class Test_Operator_Not : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorNot op_not;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};




TEST_F(Test_Operator_Not, Not_1_Gives_0_equal_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_not.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Not, Not_Superior_to_1_Gives_0_equal_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_not.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    op_not.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,2))));
    op_not.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
    st.clear();
}

TEST_F(Test_Operator_Not, Not_0_Gives_1_equal_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    op_not.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}


TEST_F(Test_Operator_Not, Test_NOT_On_two_ExpressionLiteral) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("3+SIN(3-2)*4")));
    op_not.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'NOT(3+SIN(3-2)*4)'", st.top()->toString());
    st.clear();
}
