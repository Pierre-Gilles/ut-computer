#ifndef UTCOMPUTER_OPERATORIM_H
#define UTCOMPUTER_OPERATORIM_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

class OperatorIM : public CalculationOperator {

public:
    OperatorIM() : CalculationOperator(1, "IM",6) { }
    virtual ~OperatorIM() { }



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
     * OperatorIM applies to
     *      - one ComplexLiteral with or without imaginary part
     *          - return either imaginary part or 0 if no imaginary part
     *      - an ExpressionLiteral
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORIM_H
