#ifndef UTCOMPUTER_OPERATORNUMERATOR_H
#define UTCOMPUTER_OPERATORNUMERATOR_H


#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

class OperatorNumerator : public CalculationOperator {

public:
    OperatorNumerator() : CalculationOperator(1, "NUM",6) { }
    virtual ~OperatorNumerator() { }



private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /**
     * \fn virtual shared_ptr<Literal> executeSpecificOperator() override
     * \brief Apply the operator
     *
     * Tests done before :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorNumerator applies to
     *      - a ComplexLiteral that is really only a rational
     *      - an ExpressionLiteral
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORNUMERATOR_H
