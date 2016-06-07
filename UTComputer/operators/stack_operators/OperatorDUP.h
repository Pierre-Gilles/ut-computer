#ifndef UTCOMPUTER_OPERATORDUP_H
#define UTCOMPUTER_OPERATORDUP_H

#include "../StackOperator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"
#include "../../literals/ProgramLiteral.h"

class OperatorDUP : public StackOperator {

public:
    OperatorDUP() : StackOperator(1, "DUP",6) { }
    virtual ~OperatorDUP() { }



    // ===============================================================================================================
    // ======================                 Implement superclass interface                ==========================
    // ===============================================================================================================
    /*
     * Address of stack must not be changed, but "st" do not point to a const stack : we use a constant pointer
     * and not a pointer to constant
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================

};

#endif //UTCOMPUTER_OPERATORDUP_H
