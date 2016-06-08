#ifndef UTCOMPUTER_OPERATORDIFFERENT_H
#define UTCOMPUTER_OPERATORDIFFERENT_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"

class OperatorDifferent : public CalculationOperator {


public:

    OperatorDifferent() : CalculationOperator(2, "!=",2) {}
    virtual ~OperatorDifferent() {}

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
     * OperatorDifferent applies to
     *      - two ComplexLiteral
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};



#endif //UTCOMPUTER_OPERATORDIFFERENT_H
