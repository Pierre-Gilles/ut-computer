#ifndef UTCOMPUTER_OPERATOROR_H
#define UTCOMPUTER_OPERATOROR_H
#include "../Operator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

class OperatorOr : public Operator {


public:

    OperatorOr() : Operator(2, "OR") {}
    virtual ~OperatorOr() {}

private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorOr applies to
     *      - two ComplexLiterals with no imaginary parts
     *      - two ExpressionLiteral returning OR(exp1,exp2)
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATOROR_H
