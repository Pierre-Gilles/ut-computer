#ifndef UTCOMPUTER_OPERATORAND_H
#define UTCOMPUTER_OPERATORAND_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

class OperatorAnd : public CalculationOperator {


public:

    OperatorAnd() : CalculationOperator(2, "AND",2) {}
    virtual ~OperatorAnd() {}

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
     * OperatorAnd applies to
     *      - two ComplexLiteral with no imaginary parts
     *      - two ExpressionLiteral returning AND(exp1,exp2)
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORAND_H
