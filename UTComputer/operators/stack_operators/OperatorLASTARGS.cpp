#include "OperatorLASTARGS.h"



// ===============================================================================================================
// ======================                 Implement superclass interface                ==========================
// ===============================================================================================================
/*
 * Address of stack must not be changed, but "st" do not point to a const stack : we use a constant pointer
 * and not a pointer to constant
 */
void OperatorLASTARGS::execute(StackUTComputer * const st) {
    StackOperator::execute(st); // check usual possible errors

    try {
        st->pushLastArgs();
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore("Error in applying OperatorLASTARGS ");
        throw e1;
    }


}
// ===============================================================================================================

