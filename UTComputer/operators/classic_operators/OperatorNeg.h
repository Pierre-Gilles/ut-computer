#ifndef UTCOMPUTER_OPERATORNEG_H
#define UTCOMPUTER_OPERATORNEG_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

class OperatorNeg : public CalculationOperator {

public:
    OperatorNeg() : CalculationOperator(1, "NEG",6) { }
    virtual ~OperatorNeg() { }



private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorNeg applies to
     *      - one ComplexLiteral
     *      - one ExpressionLiteral
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORNEG_H
