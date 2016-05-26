#ifndef UTCOMPUTER_OPERATORNOT_H
#define UTCOMPUTER_OPERATORNOT_H

#include "../Operator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"


class OperatorNot : public Operator {


public:

    OperatorNot() : Operator(1, "NOT") {}
    virtual ~OperatorNot() {}

private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorNot applies to
     *      - a ComplexLiteral with no imaginary part
     *      - one ExpressionLiteral returning NOT(exp1)
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORNOT_H
