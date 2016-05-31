#ifndef UTCOMPUTER_OPERATORUNDO_H
#define UTCOMPUTER_OPERATORUNDO_H




#include "../StackOperator.h"
#include "../../literals/Literal.h"

class OperatorUNDO : public StackOperator {

public:
    OperatorUNDO() : StackOperator(0, "UNDO") { }
    virtual ~OperatorUNDO() { }



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


#endif //UTCOMPUTER_OPERATORUNDO_H