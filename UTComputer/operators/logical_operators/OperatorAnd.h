#ifndef UTCOMPUTER_OPERATORAND_H
#define UTCOMPUTER_OPERATORAND_H

#include "../Operator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

class OperatorAnd : public Operator {


public:

    OperatorAnd() : Operator(2, "AND") {}
    virtual ~OperatorAnd() {}

private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorAnd applies to
     *      - two ComplexLiterals with no imaginary parts
     *      - two ExpressionLiteral returning AND(exp1,exp2)
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORAND_H
