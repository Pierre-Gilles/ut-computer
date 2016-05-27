#ifndef UTCOMPUTER_OPERATORIM_H
#define UTCOMPUTER_OPERATORIM_H

#include "../Operator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

class OperatorIM : public Operator {

public:
    OperatorIM() : Operator(1, "IM") { }
    virtual ~OperatorIM() { }



private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorIM applies to
     *      - one ComplexLiteral with or without imaginary part
     *          - return either imaginary part or 0 if no imaginary part
     *      - an ExpressionLiteral
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORIM_H
