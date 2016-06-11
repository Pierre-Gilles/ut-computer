/**
 * \file OperatorDUP.h
 * \brief File containing the OperatorDUP class.
 */

#ifndef UTCOMPUTER_OPERATORDUP_H
#define UTCOMPUTER_OPERATORDUP_H

#include "../StackOperator.h"
#include "../../literals/ComplexLiteral.h"
#include "../../literals/ExpressionLiteral.h"
#include "../../literals/ProgramLiteral.h"



/**
 * \class OperatorDUP
 */
class OperatorDUP : public StackOperator {

public:
    OperatorDUP() : StackOperator(1, "DUP",6) { }
    virtual ~OperatorDUP() { }



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
     *    - try to duplicate the top of the stack
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================

};

#endif //UTCOMPUTER_OPERATORDUP_H
