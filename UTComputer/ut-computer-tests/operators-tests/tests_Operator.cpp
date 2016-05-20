#include <iostream>
#include <gtest/gtest.h>

#include "../../operators/OperatorPlus.h"



class Test_Operator_Class : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorPlus op;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};


TEST_F(Test_Operator_Class, Test_Thrown_Exceptions_In_Execute_Function) {
    try {
        // if StackUTComputer* is null
//        op.execute(nullptr); // uncomment to see error message
        EXPECT_THROW(op.execute(nullptr),UTComputerException);

        // if StackUTComputer* size inferior to arity
//        op.execute(&st); // uncomment to see error message
        EXPECT_THROW(op.execute(&st),UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


}