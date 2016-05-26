#ifndef UTCOMPUTER_OPERATORMODULO_H
#define UTCOMPUTER_OPERATORMODULO_H

#include "../Operator.h"
#include "../../literals/ComplexLiteral.h"

class OperatorModulo : public Operator {

public:
    OperatorModulo() : Operator(2, "MOD") { }
    virtual ~OperatorModulo() { }



private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorModulo applies to
     *      - two ComplexLiterals that are of "type" integer : no complex, no real nor rational */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORMODULO_H
