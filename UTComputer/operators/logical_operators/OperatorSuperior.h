#ifndef UTCOMPUTER_OPERATORSUPERIOR_H
#define UTCOMPUTER_OPERATORSUPERIOR_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"

class OperatorSuperior : public CalculationOperator {


public:

    OperatorSuperior() : CalculationOperator(2, ">",2) {}
    virtual ~OperatorSuperior() {}

private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorSuperior applies to
     *      - two ComplexLiterals with no imaginary parts
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORSUPERIOR_H
