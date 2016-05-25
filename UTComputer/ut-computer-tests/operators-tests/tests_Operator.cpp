#include <iostream>
#include <gtest/gtest.h>

#include "../../operators/OperatorPlus.h"



class Test_Operator_Class : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorPlus op_plus;

};

TEST_F(Test_Operator_Class, Test_execute_Throw_Exception_When_Stack_Is_Null) {


    try {
        //op_plus_1.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_plus.execute(nullptr),UTComputerException);

    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Class, test_execute_throw_exception_when_stack_size_inferior_to_arity) {
    try {
        //op_plus.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_plus.execute(&st),UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

