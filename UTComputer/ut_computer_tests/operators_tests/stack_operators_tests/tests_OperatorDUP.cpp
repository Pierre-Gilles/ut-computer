#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/stack_operators/OperatorDUP.h"

using namespace std;

class Test_Operator_DUP : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorDUP op_DUP;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};



/* ========================================================== */
/*                        classic tests                       */
/* ========================================================== */

TEST_F(Test_Operator_DUP, Stack_Size_1) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
        EXPECT_EQ(1, st.size());
        EXPECT_EQ("3/4", st.top()->toString());
        op_DUP.execute(&st);
        EXPECT_EQ(2, st.size());
        EXPECT_EQ("3/4", st.top()->toString());
        st.pop();
        EXPECT_EQ(1, st.size());
        EXPECT_EQ("3/4", st.top()->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_DUP, Stack_Size_Superior_to_one) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(34))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4.2))));
        EXPECT_EQ(3, st.size());
        EXPECT_EQ("4.2", st.top()->toString());
        op_DUP.execute(&st);
        EXPECT_EQ(4, st.size());
        EXPECT_EQ("4.2", st.top()->toString());
        st.pop();
        st.pop();
        op_DUP.execute(&st);
        EXPECT_EQ(3, st.size());
        EXPECT_EQ("34", st.top()->toString());
        st.pop();
        EXPECT_EQ(2, st.size());
        EXPECT_EQ("34", st.top()->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


/* ========================================================== */
/*                    Thrown exceptions                       */
/* ========================================================== */


TEST_F(Test_Operator_DUP, Exception_if_Stack_Size_0) {
    try {
        //op_DUP.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_DUP.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_DUP, Exception_if_invalid_argument) {
    try {
        st.push(shared_ptr<Literal>());
        //op_DUP.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_DUP.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}