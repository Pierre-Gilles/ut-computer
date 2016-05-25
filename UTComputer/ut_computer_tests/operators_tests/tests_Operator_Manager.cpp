#include <iostream>
#include <gtest/gtest.h>

#include "../../operators/OperatorManager.h"
#include <vector>




class Test_Operator_Manager : public ::testing::Test {
protected:
    OperatorManager op_manager;
    StackUTComputer st;
    vector<string> listOperators;

public:
    virtual void SetUp() {
        listOperators = {"+", "-", "*", "/"};
        // dynamically instantiate one time each operator and store them in the unordered_map
        op_manager.addOperator(new OperatorPlus());
        op_manager.addOperator(new OperatorMinus());
        op_manager.addOperator(new OperatorMultiplication());
        op_manager.addOperator(new OperatorDivision());

    }
    virtual void TearDown() {
        op_manager.~OperatorManager();
    }
};





TEST_F(Test_Operator_Manager, Test_addOperatorFunction) {
    for (int i=0; i<listOperators.size(); i++)
        EXPECT_TRUE(op_manager.operatorExists(listOperators[i]));
}


TEST_F(Test_Operator_Manager, Test_function_addOperator_throw_exception) {
    // throw exception when operator already exists in the unordered_map
    OperatorPlus* op_plus_test = new OperatorPlus();
    OperatorMinus* op_minus_test = new OperatorMinus();
    OperatorMultiplication* op_mlut_test = new OperatorMultiplication();
    OperatorDivision* op_div_test = new OperatorDivision();
    EXPECT_THROW(op_manager.addOperator(op_plus_test), UTComputerException);
    EXPECT_THROW(op_manager.addOperator(op_minus_test), UTComputerException);
    EXPECT_THROW(op_manager.addOperator(op_mlut_test), UTComputerException);
    EXPECT_THROW(op_manager.addOperator(op_div_test), UTComputerException);
}


TEST_F(Test_Operator_Manager, Test_getOperator_Works) {
    for (int i=0; i<listOperators.size(); i++) {

        /* For each listOperators[i] test that the function OperatorManager::getOperator return the right type of operator */
        if (listOperators[i] == "+")
            EXPECT_TRUE( (dynamic_cast<OperatorPlus*>(op_manager.getOperator("+"))) != nullptr );

        if (listOperators[i] == "-")
            EXPECT_TRUE( (dynamic_cast<OperatorMinus*>(op_manager.getOperator("-"))) != nullptr );

        if (listOperators[i] == "*")
            EXPECT_TRUE( (dynamic_cast<OperatorMultiplication*>(op_manager.getOperator("*"))) != nullptr );

        if (listOperators[i] == "/")
           EXPECT_TRUE( (dynamic_cast<OperatorDivision*>(op_manager.getOperator("/"))) != nullptr );

        // Add if statements along the creation of new operators
    }
}

TEST_F(Test_Operator_Manager, Test_Call_Operator_Execute_From_Map) {
    StackUTComputer st;
    /* For each op_vector[i] test that the call to the operator->execute() function works */
    try {
        for (int i=0; i<listOperators.size(); i++) {
            st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(shared_ptr<NumericLiteral>(new NumericLiteral(1.0)))));
            st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(shared_ptr<NumericLiteral>(new NumericLiteral(4.0)))));
            op_manager.getOperator(listOperators[i])->execute(&st);
            EXPECT_EQ(1, st.size());

            if (listOperators[i] == "+")
                EXPECT_EQ("5", st.top()->toString());

            if (listOperators[i] == "-")
                EXPECT_EQ("-3", st.top()->toString());

            if (listOperators[i] == "*")
                EXPECT_EQ("4", st.top()->toString());

            if (listOperators[i] == "/")
                EXPECT_EQ("1/4", st.top()->toString());

            // Add if statements along the creation of new operators
            st.clear();
        }
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}










