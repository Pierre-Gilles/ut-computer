#ifndef UTCOMPUTER_OPERATORMODULO_H
#define UTCOMPUTER_OPERATORMODULO_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"

class OperatorModulo : public CalculationOperator {

public:
    OperatorModulo() : CalculationOperator(2, "MOD",6) { }
    virtual ~OperatorModulo() { }



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
     * OperatorModulo applies to
     *      - two ComplexLiteral that are of "type" integer : no complex, no real nor rational
     */

    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORMODULO_H
