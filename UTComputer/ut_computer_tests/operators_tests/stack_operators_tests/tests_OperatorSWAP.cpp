#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/stack_operators/OperatorSWAP.h"
#include "../../../literals/ComplexLiteral.h"

using namespace std;

class Test_Operator_SWAP : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorSWAP op_SWAP;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};



/* ========================================================== */
/*                        classic tests                       */
/* ========================================================== */


TEST_F(Test_Operator_SWAP, Stack_Size_Superior_to_one) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(34))));
        EXPECT_EQ(3, st.size());
        EXPECT_EQ("34", st.top()->toString());
        op_SWAP.execute(&st);
        EXPECT_EQ(3, st.size());
        EXPECT_EQ("3.1", st.top()->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}



/* ========================================================== */
/*                    Thrown exceptions                       */
/* ========================================================== */

TEST_F(Test_Operator_SWAP, Exception_if_Stack_Size_0) {
    try {
        //op_SWAP.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_SWAP.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_SWAP, Exception_if_Stack_Size_1) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
        EXPECT_EQ(1, st.size());
        //op_SWAP.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_SWAP.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}