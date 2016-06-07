#ifndef UTCOMPUTER_OPERATORINTEGERDIVISION_H
#define UTCOMPUTER_OPERATORINTEGERDIVISION_H

#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"

class OperatorIntegerDivision : public CalculationOperator {

public:
    OperatorIntegerDivision() : CalculationOperator(2, "DIV",6) { }
    virtual ~OperatorIntegerDivision() { }



private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorIntegerDivision applies to
     *      - two ComplexLiterals that are of "type" integer : no complex, no real nor rational */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORINTEGERDIVISION_H
