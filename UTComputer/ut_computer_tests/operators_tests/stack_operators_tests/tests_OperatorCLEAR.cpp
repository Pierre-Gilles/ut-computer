#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/stack_operators/OperatorCLEAR.h"
#include "../../../literals/ComplexLiteral.h"

using namespace std;

class Test_Operator_CLEAR : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorCLEAR op_CLEAR;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};



/* ========================================================== */
/*                        classic tests                       */
/* ========================================================== */

TEST_F(Test_Operator_CLEAR, Stack_Size_0) {
    try {
        EXPECT_EQ(0, st.size());
        op_CLEAR.execute(&st);
        EXPECT_EQ(0, st.size());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_CLEAR, Stack_Size_1) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
        EXPECT_EQ(1, st.size());
        op_CLEAR.execute(&st);
        EXPECT_EQ(0, st.size());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}



TEST_F(Test_Operator_CLEAR, Stack_Size_Superior_to_one) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
        EXPECT_EQ(3, st.size());
        op_CLEAR.execute(&st);
        EXPECT_EQ(0, st.size());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

