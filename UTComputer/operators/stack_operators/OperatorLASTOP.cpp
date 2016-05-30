#include "OperatorLASTOP.h"


// ===============================================================================================================
// ======================                 Implement superclass interface                ==========================
// ===============================================================================================================
/*
 * Address of stack must not be changed, but "st" do not point to a const stack : we use a constant pointer
 * and not a pointer to constant
 */
void OperatorLASTOP::execute(StackUTComputer * const st) {
    /*
     * Call to StackOperator::execute(st) :
     *      The super class function test that the current operator IS NOT "OperatorLASTOP" before setting
     *      StackUTComputer.lastOperator attribute to the current operator.
     *      Otherwise, we have an infinite loop :
     *          - setting last operator to OperatorLASTOP
     *          - calling this operator with st->getLastOperator()->execute(st)
     *          - setting last operator to OperatorLASTOP
     *          - ...
     * */
    StackOperator::execute(st); // check usual possible errors

    try {
        if (st->getLastOperator() != nullptr)
            st->getLastOperator()->execute(st);
        else
            throw UTComputerException("Error OperatorLASTOP::execute : StackUTComputer.lastOperator is null.");
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore("Error in applying OperatorLASTOP ");
        throw e1;
    }


}
// ===============================================================================================================

