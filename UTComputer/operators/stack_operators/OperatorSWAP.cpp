#include "OperatorSWAP.h"


// ===============================================================================================================
// ======================                 Implement superclass interface                ==========================
// ===============================================================================================================
/*
 * Address of stack must not be changed, but "st" do not point to a const stack : we use a constant pointer
 * and not a pointer to constant
 */
void OperatorSWAP::execute(StackUTComputer * const st) {
    StackOperator::execute(st); // check usual possible errors

    try {
        shared_ptr<Literal> first = st->top();
        st->pop();
        shared_ptr<Literal> second = st->top();
        st->pop();

        st->push(first);
        st->push(second);
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore("Error in applying OperatorSWAP ");
        throw e1;
    }


}
// ===============================================================================================================

