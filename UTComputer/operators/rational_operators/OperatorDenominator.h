#ifndef UTCOMPUTER_OPERATEURDENOMINATOR_H
#define UTCOMPUTER_OPERATEURDENOMINATOR_H
#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"


class OperatorDenominator : public CalculationOperator {

public:
    OperatorDenominator() : CalculationOperator(1, "DEN") { }
    virtual ~OperatorDenominator() { }



private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorDenominator applies to
     *      - a ComplexLiteral that is really only a rational
     *      - an ExpressionLiteral
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATEURDENOMINATOR_H
