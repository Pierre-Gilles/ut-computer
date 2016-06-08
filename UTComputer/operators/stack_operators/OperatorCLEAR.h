/**
 * \file OperatorCLEAR.h
 * \brief File containing the OperatorCLEAR class.
 */
#ifndef UTCOMPUTER_OPERATORCLEAR_H
#define UTCOMPUTER_OPERATORCLEAR_H



#include "../StackOperator.h"
#include "../../literals/Literal.h"

/**
 * \class OperatorCLEAR
 */
class OperatorCLEAR : public StackOperator {

public:

    OperatorCLEAR() : StackOperator(0, "CLEAR",6) { }
    virtual ~OperatorCLEAR() { }



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
     *    - try to clear the stack
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================

};

#endif //UTCOMPUTER_OPERATORCLEAR_H
