#ifndef UTCOMPUTER_OPERATORINFERIOR_H
#define UTCOMPUTER_OPERATORINFERIOR_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"

class OperatorInferior : public CalculationOperator {


public:

    OperatorInferior() : CalculationOperator(2, "<",2) {}
    virtual ~OperatorInferior() {}

private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorInferior applies to
     *      - two ComplexLiterals with no imaginary parts
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORINFERIOR_H
