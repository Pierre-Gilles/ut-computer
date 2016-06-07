#ifndef UTCOMPUTER_OPERATORINFERIOREQUAL_H
#define UTCOMPUTER_OPERATORINFERIOREQUAL_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"

class OperatorInferiorEqual : public CalculationOperator {


public:

    OperatorInferiorEqual() : CalculationOperator(2, "<=",2) {}
    virtual ~OperatorInferiorEqual() {}


private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorInferiorEqual applies to
     *      - two ComplexLiterals with no imaginary parts
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORINFERIOREQUAL_H
