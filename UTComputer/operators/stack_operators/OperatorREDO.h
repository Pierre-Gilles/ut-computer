#ifndef UTCOMPUTER_OPERATORREDO_H
#define UTCOMPUTER_OPERATORREDO_H




#include "../StackOperator.h"
#include "../../literals/Literal.h"

class OperatorREDO : public StackOperator {

public:
    OperatorREDO() : StackOperator(0, "REDO",6) { }
    virtual ~OperatorREDO() { }



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

#endif //UTCOMPUTER_OPERATORREDO_H
