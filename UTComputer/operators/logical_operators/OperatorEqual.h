#ifndef UTCOMPUTER_OPERATOREQUAL_H
#define UTCOMPUTER_OPERATOREQUAL_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"

class OperatorEqual : public CalculationOperator {


public:

    OperatorEqual() : CalculationOperator(2, "=",2) {}
    virtual ~OperatorEqual() {}

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
     * OperatorEqual applies to
     *      - two ComplexLiteral
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATOREQUAL_H
