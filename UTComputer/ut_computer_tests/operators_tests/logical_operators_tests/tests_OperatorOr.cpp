#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/logical_operators/OperatorOr.h"

using namespace std;

class Test_Operator_Or : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorOr op_or;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};



/* ========================================================== */
/*                  test whit one and zeros                   */
/* ========================================================== */

TEST_F(Test_Operator_Or, 1_or_1_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Or, 1_or_0_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Or, 0_or_1_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Or, 0_or_0_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}



/* ========================================================== */
/*                  test whit >=1 and zeros                   */
/* ========================================================== */

TEST_F(Test_Operator_Or, Superior_to_1_or_1_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();
}


TEST_F(Test_Operator_Or, Superior_to_1_or_Superior_to_1_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4,5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4,5))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4.4))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();
}

TEST_F(Test_Operator_Or, Superior_to_1_or_0_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();

    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0))));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
    st.clear();
}


TEST_F(Test_Operator_Or, Test_OR_On_two_ExpressionLiteral) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("3+SIN(3-2)*4")));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("4+7*8*2")));
    op_or.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'OR(3+SIN(3-2)*4,4+7*8*2)'", st.top()->toString());
    st.clear();
}



/* ========================================================== */
/*                   TEST THROWN EXCEPTIONS                   */
/* ========================================================== */

TEST_F(Test_Operator_Or, Throw_Exception_Null_Arguments) {
    st.push(shared_ptr<ComplexLiteral>());
    st.push(shared_ptr<ComplexLiteral>());
    try {
        //op_or.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_or.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Or, Throw_Exception_First_Argument_Is_Null) {
    st.push(shared_ptr<ComplexLiteral>());
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    try {
        //op_or.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_or.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Or, Throw_Exception_Second_Argument_Is_Null) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    st.push(shared_ptr<ComplexLiteral>());
    try {
        //op_or.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_or.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Or, Throw_Exception_Two_Arguments_Invalid) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(1),
            NumericLiteral(3)
    )));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(2),
            NumericLiteral(1)
    )));
    try {
        //op_or.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_or.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Or, Throw_Exception_First_Argument_Invalid) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(1),
            NumericLiteral(3)
    )));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    try {
        //op_or.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_or.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Or, Throw_Exception_Second_Argument_Invalid) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(
            NumericLiteral(1),
            NumericLiteral(3)
    )));
    try {
        //op_or.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_or.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}