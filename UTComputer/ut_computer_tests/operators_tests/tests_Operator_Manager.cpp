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
        listOperators = {"+", "-", "*", "/", "DIV", "MOD", "NEG",
                         "AND", "!=", "=", "<", "<=", "NOT", "OR", ">", ">=",
                        "NUM", "DEN",
                        "$", "RE", "IM"};
        /* dynamically instantiate one time each operator and store them in the unordered_map */

        // Classic Operators
        op_manager.addOperator(new OperatorPlus());
        op_manager.addOperator(new OperatorMinus());
        op_manager.addOperator(new OperatorMultiplication());
        op_manager.addOperator(new OperatorDivision());
        op_manager.addOperator(new OperatorIntegerDivision());
        op_manager.addOperator(new OperatorModulo());
        op_manager.addOperator(new OperatorNeg());

        // Logical Operators
        op_manager.addOperator(new OperatorAnd());
        op_manager.addOperator(new OperatorDifferent());
        op_manager.addOperator(new OperatorEqual());
        op_manager.addOperator(new OperatorInferior());
        op_manager.addOperator(new OperatorInferiorEqual());
        op_manager.addOperator(new OperatorNot());
        op_manager.addOperator(new OperatorOr());
        op_manager.addOperator(new OperatorSuperior());
        op_manager.addOperator(new OperatorSuperiorEqual());

        // Rational Operators
        op_manager.addOperator(new OperatorNumerator());
        op_manager.addOperator(new OperatorDenominator());

        // Complex Operators
        op_manager.addOperator(new OperatorDollar());
        op_manager.addOperator(new OperatorIM());
        op_manager.addOperator(new OperatorRE());
    }
    virtual void TearDown() {
        op_manager.~OperatorManager();
    }
};





TEST_F(Test_Operator_Manager, Test_addOperatorFunction) {
    cerr << "Test OpManager : Information sur les operateurs existants et testés : " << endl;
    cerr << "Key" << "\t\t\t" << "getKey()" << "\t\t" << "getArite()" << endl;
    for (int i=0; i<listOperators.size(); i++) {
        EXPECT_TRUE(op_manager.operatorExists(listOperators[i])) << "operator : " << listOperators[i];
        cerr << listOperators[i] << "\t\t\t\t" << op_manager.getOperator(listOperators[i])->getKey()
            << "\t\t\t\t" << op_manager.getOperator(listOperators[i])->getArite() << endl;
    }
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

        if (listOperators[i] == "DIV")
            EXPECT_TRUE( (dynamic_cast<OperatorIntegerDivision*>(op_manager.getOperator("DIV"))) != nullptr );

        if (listOperators[i] == "MOD")
            EXPECT_TRUE( (dynamic_cast<OperatorModulo*>(op_manager.getOperator("MOD"))) != nullptr );

        if (listOperators[i] == "NEG")
            EXPECT_TRUE( (dynamic_cast<OperatorNeg*>(op_manager.getOperator("NEG"))) != nullptr );

        if (listOperators[i] == "AND")
            EXPECT_TRUE( (dynamic_cast<OperatorAnd*>(op_manager.getOperator("AND"))) != nullptr );

        if (listOperators[i] == "!=")
            EXPECT_TRUE( (dynamic_cast<OperatorDifferent*>(op_manager.getOperator("!="))) != nullptr );

        if (listOperators[i] == "=")
            EXPECT_TRUE( (dynamic_cast<OperatorEqual*>(op_manager.getOperator("="))) != nullptr );

        if (listOperators[i] == "<")
            EXPECT_TRUE( (dynamic_cast<OperatorInferior*>(op_manager.getOperator("<"))) != nullptr );

        if (listOperators[i] == "<=")
            EXPECT_TRUE( (dynamic_cast<OperatorInferiorEqual*>(op_manager.getOperator("<="))) != nullptr );

        if (listOperators[i] == "NOT")
            EXPECT_TRUE( (dynamic_cast<OperatorNot*>(op_manager.getOperator("NOT"))) != nullptr );

        if (listOperators[i] == "OR")
            EXPECT_TRUE( (dynamic_cast<OperatorOr*>(op_manager.getOperator("OR"))) != nullptr );

        if (listOperators[i] == ">")
            EXPECT_TRUE( (dynamic_cast<OperatorSuperior*>(op_manager.getOperator(">"))) != nullptr );

        if (listOperators[i] == ">=")
            EXPECT_TRUE( (dynamic_cast<OperatorSuperiorEqual*>(op_manager.getOperator(">="))) != nullptr );

        if (listOperators[i] == "NUM")
            EXPECT_TRUE( (dynamic_cast<OperatorNumerator*>(op_manager.getOperator("NUM"))) != nullptr );

        if (listOperators[i] == "DEN")
            EXPECT_TRUE( (dynamic_cast<OperatorDenominator*>(op_manager.getOperator("DEN"))) != nullptr );

        if (listOperators[i] == "$")
            EXPECT_TRUE( (dynamic_cast<OperatorDollar*>(op_manager.getOperator("$"))) != nullptr );

        if (listOperators[i] == "RE")
            EXPECT_TRUE( (dynamic_cast<OperatorRE*>(op_manager.getOperator("RE"))) != nullptr );

        if (listOperators[i] == "IM")
            EXPECT_TRUE( (dynamic_cast<OperatorIM*>(op_manager.getOperator("IM"))) != nullptr );

        // Add if statements along the creation of new operators
    }
}

TEST_F(Test_Operator_Manager, Test_Call_Operator_Execute_From_Map) {
    StackUTComputer st;
    /* For each op_vector[i] test that the call to the operator->execute() function works */
    try {
        for (int i=0; i<listOperators.size(); i++) {
            st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(8))));
            st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
            op_manager.getOperator(listOperators[i])->execute(&st);

            if (listOperators[i] == "+")
                EXPECT_EQ("11", st.top()->toString());

            if (listOperators[i] == "-")
                EXPECT_EQ("5", st.top()->toString());

            if (listOperators[i] == "*")
                EXPECT_EQ("24", st.top()->toString());

            if (listOperators[i] == "/")
                EXPECT_EQ("8/3", st.top()->toString());

            if (listOperators[i] == "DIV")
                EXPECT_EQ("2", st.top()->toString());

            if (listOperators[i] == "MOD") {
                st.clear();
                st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(8))));
                st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
                op_manager.getOperator(listOperators[i])->execute(&st);
                EXPECT_EQ("3", st.top()->toString());
            }

            if (listOperators[i] == "NEG")
                EXPECT_EQ("-3", st.top()->toString());

            if (listOperators[i] == "AND")
                EXPECT_EQ("1", st.top()->toString());

            if (listOperators[i] == "!=")
                EXPECT_EQ("1", st.top()->toString());

            if (listOperators[i] == "=")
                EXPECT_EQ("0", st.top()->toString());

            if (listOperators[i] == "<")
                EXPECT_EQ("0", st.top()->toString());

            if (listOperators[i] == "<=")
                EXPECT_EQ("0", st.top()->toString());

            if (listOperators[i] == "NOT")
                EXPECT_EQ("0", st.top()->toString());

            if (listOperators[i] == "OR")
                EXPECT_EQ("1", st.top()->toString());

            if (listOperators[i] == ">")
                EXPECT_EQ("1", st.top()->toString());

            if (listOperators[i] == ">=")
                EXPECT_EQ("1", st.top()->toString());

            if (listOperators[i] == "NUM")
                EXPECT_EQ("3", st.top()->toString());

            if (listOperators[i] == "DEN")
                EXPECT_EQ("1", st.top()->toString());

            if (listOperators[i] == "$")
                EXPECT_EQ("8$3", st.top()->toString());

            if (listOperators[i] == "RE")
                EXPECT_EQ("3", st.top()->toString()); // because st.top() is ComplexLiteral(NumericLiteral(3)) with no imaginary part

            if (listOperators[i] == "IM")
                EXPECT_EQ("0", st.top()->toString());

            // Add if statements along the creation of new operators
            st.clear();
        }
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}










