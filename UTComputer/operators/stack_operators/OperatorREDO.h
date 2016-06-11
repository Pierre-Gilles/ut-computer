/**
 * \file OperatorREDO.h
 * \brief File containing the OperatorREDO class.
 */


#ifndef UTCOMPUTER_OPERATORREDO_H
#define UTCOMPUTER_OPERATORREDO_H




#include "../StackOperator.h"
#include "../../literals/Literal.h"

/**
 * \class OperatorREDO
 */
class OperatorREDO : public StackOperator {

public:
    OperatorREDO() : StackOperator(0, "REDO",6) { }
    virtual ~OperatorREDO() { }



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
     *    - try to apply StackUTComputer::redo
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================

};

#endif //UTCOMPUTER_OPERATORREDO_H
