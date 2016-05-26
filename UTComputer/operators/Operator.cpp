#include "Operator.h"


// ===============================================================================================================
// ======================                       Class main services                     ==========================
// ===============================================================================================================
/*
 * Adress of stack must not be changed, but "st" do not point to a const stack : we use a constant pointer
 * and not a pointer to constant
 */
void Operator::execute(StackUTComputer * const st) { // do not override ???
    if (st == nullptr)
        throw UTComputerException("Error in Operator::execute : pointer to stack is null");

    if (st->size() < arity)
        throw UTComputerException("Error in Operator::execute : size of stack inferior to operator arity");

    st->getArguments(arity, arguments);

    shared_ptr<Literal> result;

    try {
        result = executeSpecificOperator();
    } catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore("Error in Operator::executeSpecificOperator --> ");
        throw e1;
    }

    st->deleteArguments(arity);
    st->push(result);
}
// ===============================================================================================================