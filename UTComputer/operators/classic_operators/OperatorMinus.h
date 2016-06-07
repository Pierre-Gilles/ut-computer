#ifndef UTCOMPUTER_MINUSOPERATOR_H
#define UTCOMPUTER_MINUSOPERATOR_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

class OperatorMinus : public CalculationOperator {

public:
    OperatorMinus() : CalculationOperator(2, "-",3) { }
    virtual ~OperatorMinus() { }




private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================

    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorMinus applies to
     *      - two ComplexLiterals
     *      - two ExpressionLiteral
     *      - an ExpressionLiteral and a ComplexLiteral */
    virtual shared_ptr<Literal> executeSpecificOperator() override;

    // ===============================================================================================================
};


#endif //UTCOMPUTER_MINUSOPERATOR_H
