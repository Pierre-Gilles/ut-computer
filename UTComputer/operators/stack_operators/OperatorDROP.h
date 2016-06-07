#ifndef UTCOMPUTER_OPERATORDROP_H
#define UTCOMPUTER_OPERATORDROP_H

#include "../StackOperator.h"
#include "../../literals/Literal.h"

class OperatorDROP : public StackOperator {

public:
    OperatorDROP() : StackOperator(1, "DROP",6) { }
    virtual ~OperatorDROP() { }



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


#endif //UTCOMPUTER_OPERATORDROP_H
