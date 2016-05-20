#include <iostream>
#include <gtest/gtest.h>

#include "../../operators/OperatorManager.h"




class Test_Operator_Manager : public ::testing::Test {
protected:
    OperatorManager op_manager;


public:
    virtual void SetUp() { }
    virtual void TearDown() { }
};

TEST_F(Test_Operator_Manager, Test_Operators_Instantiation) {
    // test that every Operator* in op_vector is not null
    for (int i=0; i<op_manager.getOp_vector().size(); i++) {
        EXPECT_TRUE(op_manager.getOp_vector()[i] != nullptr);
    }
}

TEST_F(Test_Operator_Manager, Test_Copy_In_Map) {
    // test that adress of all Operator* in op_vector is copied to op_map
    for (int i=0; i<op_manager.getOp_vector().size(); i++) {
        EXPECT_TRUE(op_manager.operatorExists(op_manager.getOp_vector()[i]->getKey()));
    }
}

TEST_F(Test_Operator_Manager, Test_getOperator_Works) {
    for (int i=0; i<op_manager.getOp_vector().size(); i++) {

        // For each op_vector[i] test that adresses are equals in unordered_map and in vector
        EXPECT_TRUE(op_manager.getOperator(op_manager.getOp_vector()[i]->getKey()) == op_manager.getOp_vector()[i]);


        /* For each op_vector[i] test that the function OperatorManager::getOperator return the right type of operator */
        if (op_manager.getOp_vector()[i]->getKey() == "+")
            EXPECT_TRUE( (dynamic_cast<OperatorPlus*>(op_manager.getOperator("+"))) != nullptr );

        if (op_manager.getOp_vector()[i]->getKey() == "-")
            EXPECT_TRUE( (dynamic_cast<OperatorMinus*>(op_manager.getOperator("-"))) != nullptr );

        if (op_manager.getOp_vector()[i]->getKey() == "*")
            EXPECT_TRUE( (dynamic_cast<OperatorMultiplication*>(op_manager.getOperator("*"))) != nullptr );

        // Add if statements along the creation of new operators
    }
}

TEST_F(Test_Operator_Manager, Test_Call_Operator_Execute_From_Map) {
    StackUTComputer st;
    /* For each op_vector[i] test that the call to the operator->execute() function works */
    for (int i=0; i<op_manager.getOp_vector().size(); i++) {
        st.push(new ComplexLiteral(new NumericLiteral(1)));
        st.push(new ComplexLiteral(new NumericLiteral(1)));
        op_manager.getOperator(op_manager.getOp_vector()[i]->getKey())->execute(&st);
        EXPECT_EQ(1, st.size());

        if (op_manager.getOp_vector()[i]->getKey() == "+")
            EXPECT_EQ("2", st.top()->toString());

        if (op_manager.getOp_vector()[i]->getKey() == "-")
            EXPECT_EQ("0", st.top()->toString());

        if (op_manager.getOp_vector()[i]->getKey() == "*")
            EXPECT_EQ("1", st.top()->toString());

        // Add if statements along the creation of new operators
        st.clear();
    }
}

TEST_F(Test_Operator_Manager, Test_function_addOperator_throw_exception) {
    OperatorPlus *op_plus_test = new OperatorPlus;
    OperatorMinus *op_minus_test = new OperatorMinus;
    OperatorMultiplication *op_mlut_test = new OperatorMultiplication;
    EXPECT_THROW(op_manager.addOperator(op_plus_test), UTComputerException);
    EXPECT_THROW(op_manager.addOperator(op_minus_test), UTComputerException);
    EXPECT_THROW(op_manager.addOperator(op_mlut_test), UTComputerException);
}












