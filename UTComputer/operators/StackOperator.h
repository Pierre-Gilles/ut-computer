#ifndef UTCOMPUTER_OPERATORSTACK_H
#define UTCOMPUTER_OPERATORSTACK_H

#include "Operator.h"

class StackOperator : public Operator {


public:
    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================

    StackOperator(int nb, string key, int prio) : Operator(nb, key, prio) {}
    virtual ~StackOperator() { }



    // ===============================================================================================================
    // ======================                 Implement superclass interface                ==========================
    // ===============================================================================================================
    /*
     * Adress of stack must not be changed, but "st" do not point to a const stack : we use a constant pointer
     * and not a pointer to constant
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORSTACK_H
