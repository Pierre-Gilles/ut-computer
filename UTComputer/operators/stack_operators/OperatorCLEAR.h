#ifndef UTCOMPUTER_OPERATORCLEAR_H
#define UTCOMPUTER_OPERATORCLEAR_H



#include "../StackOperator.h"
#include "../../literals/Literal.h"

class OperatorCLEAR : public StackOperator {

public:
    OperatorCLEAR() : StackOperator(0, "CLEAR") { }
    virtual ~OperatorCLEAR() { }



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

#endif //UTCOMPUTER_OPERATORCLEAR_H
