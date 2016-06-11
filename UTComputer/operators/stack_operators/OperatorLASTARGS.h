/**
 * \file OperatorLASTARGS.h
 * \brief File containing the OperatorLASTARGS class.
 */


#ifndef UTCOMPUTER_OPERATORLASTARGS_H
#define UTCOMPUTER_OPERATORLASTARGS_H



#include "../StackOperator.h"
#include "../../literals/Literal.h"


/**
 * \class OperatorLASTARGS
 */

class OperatorLASTARGS : public StackOperator {

public:
    OperatorLASTARGS() : StackOperator(0, "LASTARGS",6) { }
    virtual ~OperatorLASTARGS() { }



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
     *    - try to push on top of the stack the last used arguments
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORLASTARGS_H
