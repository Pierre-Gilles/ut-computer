/**
 * \file OperatorUNDO.h
 * \brief File containing the OperatorUNDO class.
 */


#ifndef UTCOMPUTER_OPERATORUNDO_H
#define UTCOMPUTER_OPERATORUNDO_H




#include "../StackOperator.h"
#include "../../literals/Literal.h"

/**
 * \class OperatorUNDO
 */
class OperatorUNDO : public StackOperator {

public:
    OperatorUNDO() : StackOperator(0, "UNDO",6) { }
    virtual ~OperatorUNDO() { }



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
     *    - try to apply StackUTComputer::undo
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORUNDO_H
