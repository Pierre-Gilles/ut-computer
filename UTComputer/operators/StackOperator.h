/**
 * \file StackOperator.h
 * \brief File containing the StackOperator class.
 */
#ifndef UTCOMPUTER_OPERATORSTACK_H
#define UTCOMPUTER_OPERATORSTACK_H

#include "Operator.h"


/**
 * \class StackOperator
 * \brief Super class for all specific stack operators
 */
class StackOperator : public Operator {


public:
    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================

    StackOperator(int nb, string key, int prio) : Operator(nb, key, prio) {}
    virtual ~StackOperator() { }



    // ===============================================================================================================
    // ======================                 Implement superclass interface                ==========================
    // ===============================================================================================================

    /**
     * \fn virtual void execute(StackUTComputer * const st)
     * \brief Joint method that will be called in all  StackOperator's subclasses
     * \param[in] st : constant pointer (referenced object can be modified but reference itself cannot) to an instance of StackUTComputer
     *
     * Redefinition of Operator::execute function
     *    - check that parameter "st" isn't null
     *    - check that stack size is superior or equal to the operator's arity
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORSTACK_H
