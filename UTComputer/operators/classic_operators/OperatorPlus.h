#ifndef TESTLO21CLION_PLUSOPERATOR_H
#define TESTLO21CLION_PLUSOPERATOR_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"



class OperatorPlus : public CalculationOperator {

public:
    OperatorPlus() : CalculationOperator(2, "+",3) { }
    virtual ~OperatorPlus() { }



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
     * OperatorPlus applies to
     *      - two ComplexLiteral
     *      - two ExpressionLiteral
     *      - an ExpressionLiteral and a ComplexLiteral
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};
#endif //TESTLO21CLION_PLUSOPERATOR_H
