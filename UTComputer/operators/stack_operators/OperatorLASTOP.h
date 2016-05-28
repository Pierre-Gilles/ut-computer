#ifndef UTCOMPUTER_OPERATORLASTOP_H
#define UTCOMPUTER_OPERATORLASTOP_H


#include "../StackOperator.h"
#include "../../literals/Literal.h"

class OperatorLASTOP : public StackOperator {

public:
    OperatorLASTOP() : StackOperator(0, "LASTOP") { }
    virtual ~OperatorLASTOP() { }



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



#endif //UTCOMPUTER_OPERATORLASTOP_H
