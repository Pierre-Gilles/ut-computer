#ifndef UTCOMPUTER_OPERATORNEG_H
#define UTCOMPUTER_OPERATORNEG_H

#include "../Operator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"

class OperatorNeg : public Operator {

public:
    OperatorNeg() : Operator(1, "NEG") { }
    virtual ~OperatorNeg() { }



private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorNeg applies to
     *      - two ComplexLiterals that are of "type" integer : no complex, no real nor rational */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORNEG_H
