#include "CalculationOperator.h"


void CalculationOperator::execute(StackUTComputer * const st) {
    if (st == nullptr)
        throw UTComputerException("Error in Operator::execute : pointer to stack is null");

    if (st->size() < arity)
        throw UTComputerException("Error in Operator::execute : size of stack inferior to operator arity");

//    st->createMemento();

    st->getArguments(arity, arguments);
    st->setLastOperator(this);
    st->setLastArguments(arity);

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

