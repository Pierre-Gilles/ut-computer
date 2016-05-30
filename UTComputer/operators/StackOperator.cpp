#include "StackOperator.h"





// ===============================================================================================================
// ======================                 Implement superclass interface                ==========================
// ===============================================================================================================
/*
 * Adress of stack must not be changed, but "st" do not point to a const stack : we use a constant pointer
 * and not a pointer to constant
 *
 * We test usual possibles errors and every subclass will call this superclass test with  StackOperator::execute
 */
void StackOperator::execute(StackUTComputer * const st) {
    if (st == nullptr)
        throw UTComputerException("Error in StackOperator::execute : pointer to stack is null");

    if (st->size() < arity)
        throw UTComputerException("Error in StackOperator::execute : size of stack inferior to operator arity");



    if (key != "LASTOP")
        st->setLastOperator(this);
    if (key != "LASTARGS")
        st->setLastArguments(arity);
}
// ===============================================================================================================