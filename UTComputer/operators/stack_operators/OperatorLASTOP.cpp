#include "OperatorLASTOP.h"


// ===============================================================================================================
// ======================                 Implement superclass interface                ==========================
// ===============================================================================================================
/*
 * Address of stack must not be changed, but "st" do not point to a const stack : we use a constant pointer
 * and not a pointer to constant
 */
void OperatorLASTOP::execute(StackUTComputer * const st) {
    StackOperator::execute(st); // check usual possible errors

    try {
        st->getLastOperator()->execute(st);
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore("Error in applying OperatorLASTOP ");
        throw e1;
    }


}
// ===============================================================================================================

