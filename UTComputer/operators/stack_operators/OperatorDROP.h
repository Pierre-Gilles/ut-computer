/**
 * \file OperatorDROP.h
 * \brief File containing the OperatorDROP class.
 */

#ifndef UTCOMPUTER_OPERATORDROP_H
#define UTCOMPUTER_OPERATORDROP_H

#include "../StackOperator.h"
#include "../../literals/Literal.h"


/**
 * \class OperatorDROP
 */
class OperatorDROP : public StackOperator {

public:
    OperatorDROP() : StackOperator(1, "DROP",6) { }
    virtual ~OperatorDROP() { }



    // ===============================================================================================================
    // ======================                 Implement superclass interface                ==========================
    // ===============================================================================================================
    /**
     * \fn virtual void execute(StackUTComputer * const st) override
     * \brief Execute specific operations of the operator
     * \param[in] st : constant pointer (referenced object can be modified but reference itself cannot) to an instance of StackUTComputer
     *
     * Redefinition of StackOperator::execute :
     *    - call to StackOperator::execute method
     *    - try to drop the top of the stack
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORDROP_H
