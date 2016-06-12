#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/stack_operators/OperatorUNDO.h"
#include "../../../operators/stack_operators/OperatorREDO.h"
#include "../../../operators/classic_operators/OperatorPlus.h"
#include "../../../literals/ComplexLiteral.h"

using namespace std;

class Test_Operator_UNDO_REDO : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorUNDO op_UNDO;
    OperatorREDO op_REDO;
    OperatorPlus op_plus;
    vector<shared_ptr<Literal>> arguments;
public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
        arguments.clear();
    }
};



/* ========================================================== */
/*                        classic tests                       */
/* ========================================================== */

/*
 * In those tests, we artificially emulate the calculator :
 *  - the calculator take a string[]
 *      - before iterating through the string[], the calculator save the stack current state with StackUTComputer::createMemento()
 *      - then, the calculator perform an operation for each token in the string table
 *          - push a literal to the stack
 *          - execute an operator
 *          - ...
 *      - and finally, after each performed operation, the calculator save the new state by calling StackUTComputer::createMemento()
 */

TEST_F(Test_Operator_UNDO_REDO, UNDO_Do_Not_Crash_if_no_memento) {
    try {
        op_UNDO.execute(&st);
        op_UNDO.execute(&st);
        op_UNDO.execute(&st);

    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_UNDO_REDO, REDO_Do_Not_Crash_if_no_memento) {
    try {
        op_REDO.execute(&st);
        op_REDO.execute(&st);
        op_REDO.execute(&st);

    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_UNDO_REDO, UNDO_And_REDO_Works_after_push_on_stack) {
    try {
        st.createMemento();

        // set the stack with two arguments
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
        st.createMemento();
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
        st.createMemento();

        // assert that the stack is what we expect it to be
        EXPECT_EQ(2, st.size());
        st.getArguments(2, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        EXPECT_EQ("3.1", arguments[1]->toString());
        arguments.clear();

        /* Wanted history of stack :
         *  - first state is empty stack
         *  - second state is stack with 3/4 literal
         *  - last and current state is stack with 3.1 on top and 3/4 at the bottom
         * */


        /* =================   tests on UNDO   ================ */
        /* ==================================================== */

        // UNDO -> get the stack back to it's previous state, so stack with only 3/4 (state 2)
        op_UNDO.execute(&st);
        EXPECT_EQ(1, st.size());
        st.getArguments(1, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        arguments.clear();

        // UNDO -> get the stack back to it's previous state (so state 1)
        op_UNDO.execute(&st);
        EXPECT_EQ(0, st.size());
        st.getArguments(0, arguments);
        arguments.clear();

        // test that undo won't crash when there is nothing to undo : crtl-Z just not "working"
        op_UNDO.execute(&st);
        op_UNDO.execute(&st);
        op_UNDO.execute(&st);
        op_UNDO.execute(&st);



        /* =================   tests on REDO   ================ */
        /* ==================================================== */
        // REDO -> get the stack back to it's next state (so state 2)
        op_REDO.execute(&st);
        EXPECT_EQ(1, st.size());
        st.getArguments(1, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        arguments.clear();

        // REDO -> get the stack back to it's next state (so state 3)
        op_REDO.execute(&st);
        EXPECT_EQ(2, st.size());
        st.getArguments(2, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        EXPECT_EQ("3.1", arguments[1]->toString());
        arguments.clear();

    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}



TEST_F(Test_Operator_UNDO_REDO, Undo_Works_after_call_to_operator) {
    try {
        st.createMemento();

        // set the stack with 3 arguments and call an operator
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,4))));
        st.createMemento();
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
        st.createMemento();
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
        st.createMemento();
        op_plus.execute(&st);
        st.createMemento();

        /* Wanted history of stack :
         *  - first state is empty stack
         *  - second state is stack with 3/4 literal
         *  - third state is stack with two arguments : 3.1 on top and 3/4 at the bottom
         *  - fourth state is stack with 3 arguments : 2 on top, 3.1, and 3/4 at the bottom
         *  - last and current state is
         *      - stack with 5.1 on top and 3/4 at the bottom
         *      - lastOperator is set to the address of op_plus
         *      - lastArguments is a stack which contains 3.1 and 2
         * */


        // assert that the stack is what we expect it to be
        EXPECT_EQ(2, st.size());
        st.getArguments(2, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        EXPECT_EQ("5.1", arguments[1]->toString());
        EXPECT_EQ("3.1", st.getLastArguments()[0]->toString());
        EXPECT_EQ("2", st.getLastArguments()[1]->toString());
        EXPECT_EQ(&op_plus, st.getLastOperator());
        arguments.clear();



        /* =================   tests on UNDO   ================ */
        /* ==================================================== */

        // UNDO -> get the stack back to it's previous state, so state 4
        op_UNDO.execute(&st);
        EXPECT_EQ(3, st.size());
        st.getArguments(3, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        EXPECT_EQ("3.1", arguments[1]->toString());
        EXPECT_EQ("2", arguments[2]->toString());
        EXPECT_EQ(nullptr, st.getLastOperator());
        EXPECT_EQ(0, st.getLastArguments().size());
        arguments.clear();

        // UNDO -> get the stack back to it's previous state, so state 3
        op_UNDO.execute(&st);
        EXPECT_EQ(2, st.size());
        st.getArguments(2, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        EXPECT_EQ("3.1", arguments[1]->toString());
        EXPECT_EQ(nullptr, st.getLastOperator());
        EXPECT_EQ(0, st.getLastArguments().size());
        arguments.clear();

        // UNDO -> get the stack back to it's previous state, so state 2
        op_UNDO.execute(&st);
        EXPECT_EQ(1, st.size());
        st.getArguments(1, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        EXPECT_EQ(nullptr, st.getLastOperator());
        EXPECT_EQ(0, st.getLastArguments().size());
        arguments.clear();

        // UNDO -> get the stack back to it's previous state, so state 1
        op_UNDO.execute(&st);
        EXPECT_EQ(0, st.size());
        EXPECT_EQ(nullptr, st.getLastOperator());
        EXPECT_EQ(0, st.getLastArguments().size());
        arguments.clear();

        // test that undo won't crash when there is nothing to undo : crtl-Z just not "working"
        op_UNDO.execute(&st);
        op_UNDO.execute(&st);
        op_UNDO.execute(&st);
        op_UNDO.execute(&st);







        /* =================   tests on REDO   ================ */
        /* ==================================================== */

        // REDO -> get the stack back to it's next state, so state 2
        op_REDO.execute(&st);
        EXPECT_EQ(1, st.size());
        st.getArguments(1, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        EXPECT_EQ(nullptr, st.getLastOperator());
        EXPECT_EQ(0, st.getLastArguments().size());
        arguments.clear();

        // REDO -> get the stack back to it's next state, so state 3
        op_REDO.execute(&st);
        EXPECT_EQ(2, st.size());
        st.getArguments(2, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        EXPECT_EQ("3.1", arguments[1]->toString());
        EXPECT_EQ(nullptr, st.getLastOperator());
        EXPECT_EQ(0, st.getLastArguments().size());
        arguments.clear();

        // REDO -> get the stack back to it's next state, so state 4
        op_REDO.execute(&st);
        EXPECT_EQ(3, st.size());
        st.getArguments(3, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        EXPECT_EQ("3.1", arguments[1]->toString());
        EXPECT_EQ("2", arguments[2]->toString());
        EXPECT_EQ(nullptr, st.getLastOperator());
        EXPECT_EQ(0, st.getLastArguments().size());
        arguments.clear();

        // REDO -> get the stack back to it's next state, so state 5
        op_REDO.execute(&st);
        EXPECT_EQ(2, st.size());
        st.getArguments(2, arguments);
        EXPECT_EQ("3/4", arguments[0]->toString());
        EXPECT_EQ("5.1", arguments[1]->toString());
        EXPECT_EQ("3.1", st.getLastArguments()[0]->toString());
        EXPECT_EQ("2", st.getLastArguments()[1]->toString());
        EXPECT_EQ(&op_plus, st.getLastOperator());
        arguments.clear();



        op_REDO.execute(&st);
        op_REDO.execute(&st);
        op_REDO.execute(&st);
        op_REDO.execute(&st);

    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


