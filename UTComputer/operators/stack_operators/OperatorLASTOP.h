/**
 * \file OperatorLASTOP.h
 * \brief File containing the OperatorLASTOP class.
 */


#ifndef UTCOMPUTER_OPERATORLASTOP_H
#define UTCOMPUTER_OPERATORLASTOP_H


#include "../StackOperator.h"
#include "../../literals/Literal.h"

/**
 * \class OperatorLASTOP
 */
class OperatorLASTOP : public StackOperator {

public:
    OperatorLASTOP() : StackOperator(0, "LASTOP",6) { }
    virtual ~OperatorLASTOP() { }



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
     *    - try to execute the previous executed operator
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================

};



#endif //UTCOMPUTER_OPERATORLASTOP_H
