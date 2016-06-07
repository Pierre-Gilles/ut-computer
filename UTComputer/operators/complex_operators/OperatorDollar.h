#ifndef UTCOMPUTER_OPERATORDOLLAR_H
#define UTCOMPUTER_OPERATORDOLLAR_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"

class OperatorDollar : public CalculationOperator {

public:
    OperatorDollar() : CalculationOperator(2, "$",5) { }
    virtual ~OperatorDollar() { }



private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorDollar applies to
     *      - two ComplexLiterals with no imaginary parts
     *      - NOT ON ExpressionLiteral : a complex can't have other complex numbers as imaginary or real part and we don't know
     *          what is in an ExpressionLiteral before we apply EVAL on it : maybe the ExpressionLiteral, once evaluated, will be
     *          a complex number...
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};

#endif //UTCOMPUTER_OPERATORDOLLAR_H
