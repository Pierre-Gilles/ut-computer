#ifndef UTCOMPUTER_OPERATORDIVISION_H
#define UTCOMPUTER_OPERATORDIVISION_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

using namespace std;

class OperatorDivision : public CalculationOperator {

public:
    OperatorDivision() : CalculationOperator(2, "/",4) { }
    virtual ~OperatorDivision() { }


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
     * OperatorDivision applies to
     *      - two ComplexLiteral
     *      - two ExpressionLiteral
     *      - an ExpressionLiteral and a ComplexLiteral
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;

    // ===============================================================================================================
};


#endif //UTCOMPUTER_OPERATORDIVISION_H
