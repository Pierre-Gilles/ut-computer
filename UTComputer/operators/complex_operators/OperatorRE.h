#ifndef UTCOMPUTER_OPERATORRE_H
#define UTCOMPUTER_OPERATORRE_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

class OperatorRE : public CalculationOperator {

public:
    OperatorRE() : CalculationOperator(1, "RE",6) { }
    virtual ~OperatorRE() { }



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
     * OperatorRE applies to
     *      - one ComplexLiteral with or without imaginary part
     *          - return either imaginary part or 0 if no imaginary part
     *      - one ExpressionLiteral
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORRE_H
