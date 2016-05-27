#ifndef UTCOMPUTER_OPERATORNUMERATOR_H
#define UTCOMPUTER_OPERATORNUMERATOR_H


#include "../Operator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

class OperatorNumerator : public Operator {

public:
    OperatorNumerator() : Operator(1, "NUM") { }
    virtual ~OperatorNumerator() { }



private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorNumerator applies to
     *      - a ComplexLiteral that is really only a rational
     *      - an ExpressionLiteral
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORNUMERATOR_H
