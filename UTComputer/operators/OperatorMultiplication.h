#ifndef UTCOMPUTER_OPERATORMULTIPLICATION_H
#define UTCOMPUTER_OPERATORMULTIPLICATION_H

#include "Operator.h"
#include "../literals/ComplexLiteral.h"
#include "../literals/ExpressionLiteral.h"

class OperatorMultiplication : public Operator {

public:
    OperatorMultiplication() : Operator(2, "*") { }
    virtual ~OperatorMultiplication() { }



private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================

    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorMultiplication applies to
     *      - two ComplexLiterals
     *      - two ExpressionLiteral
     *      - an ExpressionLiteral and a ComplexLiteral */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================
};


#endif //UTCOMPUTER_OPERATORMULTIPLICATION_H
