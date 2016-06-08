#ifndef UTCOMPUTER_OPERATORSWAP_H
#define UTCOMPUTER_OPERATORSWAP_H


#include "../StackOperator.h"
#include "../../literals/Literal.h"

class OperatorSWAP : public StackOperator {

public:
    OperatorSWAP() : StackOperator(2, "SWAP",6) { }
    virtual ~OperatorSWAP() { }



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



#endif //UTCOMPUTER_OPERATORSWAP_H
