/**
 * \file OperatorSWAP.h
 * \brief File containing the OperatorSWAP class.
 */


#ifndef UTCOMPUTER_OPERATORSWAP_H
#define UTCOMPUTER_OPERATORSWAP_H


#include "../StackOperator.h"
#include "../../literals/Literal.h"

/**
 * \class OperatorSWAP
 */
class OperatorSWAP : public StackOperator {

public:
    OperatorSWAP() : StackOperator(2, "SWAP",6) { }
    virtual ~OperatorSWAP() { }



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
     *    - try to swap the first two elements
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================

};



#endif //UTCOMPUTER_OPERATORSWAP_H
