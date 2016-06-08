#ifndef UTCOMPUTER_OPERATORLASTARGS_H
#define UTCOMPUTER_OPERATORLASTARGS_H



#include "../StackOperator.h"
#include "../../literals/Literal.h"

class OperatorLASTARGS : public StackOperator {

public:
    OperatorLASTARGS() : StackOperator(0, "LASTARGS",6) { }
    virtual ~OperatorLASTARGS() { }



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


#endif //UTCOMPUTER_OPERATORLASTARGS_H
