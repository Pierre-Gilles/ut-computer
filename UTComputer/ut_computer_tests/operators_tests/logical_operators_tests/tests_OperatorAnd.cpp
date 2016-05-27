#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/logical_operators/OperatorAnd.h"

using namespace std;

class Test_Operator_And : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorAnd op_and;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};



/* ========================================================== */
/*                  test whit one and zeros                   */
/* ========================================================== */

TEST_F(Test_Operator_And, 1_and_1_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_And, 1_and_0_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_And, 0_and_1_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_And, 0_and_0_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}



/* ========================================================== */
/*                  test whit >=1 and zeros                   */
/* ========================================================== */

TEST_F(Test_Operator_And, Superior_to_1_and_1_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();
}


TEST_F(Test_Operator_And, Superior_to_1_and_Superior_to_1_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4,5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4,5))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4.4))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();
}

TEST_F(Test_Operator_And, Superior_to_1_and_0_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
    st.clear();
}



TEST_F(Test_Operator_And, Test_AND_On_two_ExpressionLiteral) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("3+SIN(3-2)*4")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("4+7*8*2")));
    op_and.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'AND(3+SIN(3-2)*4,4+7*8*2)'", st.top()->toString());
    st.clear();
}
