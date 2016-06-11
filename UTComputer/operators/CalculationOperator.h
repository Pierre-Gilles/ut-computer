/**
 * \file CalculationOperator.h
 * \brief File containing the CalculationOperator class.
 */

#ifndef UTCOMPUTER_CALCULATIONOPERATOR_H
#define UTCOMPUTER_CALCULATIONOPERATOR_H

#include "Operator.h"


/**
 * \class CalculationOperator
 * \brief Super class for all specific calculation operators
 */
class CalculationOperator : public Operator {
protected:
    vector<shared_ptr<Literal>> arguments;
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    CalculationOperator(int nb, string key, int prio) : Operator(nb, key, prio) {
        arguments.reserve((unsigned long int)nb); // reserve space in vector
    }
    virtual ~CalculationOperator() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Class main services                     ==========================
    // ===============================================================================================================
    /**
     * \fn virtual void execute(StackUTComputer * const st)
     * \brief Implementation of Operator::execute
     * \param[in] st : constant pointer (referenced object can be modified but reference itself cannot) to an instance of StackUTComputer
     *
     * Redefinition of Operator::execute function
     *    - check that parameter "st" isn't null
     *    - check that stack size is superior or equal to the operator's arity
     *    - manage the operation : get the right arguments, calculate the operation result and push back this result
     *    on top of the stack
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                   Interface for subclasses                    ==========================
    // ===============================================================================================================
private:
    /**
     * \fn virtual shared_ptr<Literal> executeSpecificOperator()
     * \brief Virtual pure method that manage the operation made by the operator
     * \param[in] st : constant pointer (referenced object can be modified but reference itself cannot) to an instance of StackUTComputer
     */
    virtual shared_ptr<Literal> executeSpecificOperator() = 0;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_CALCULATIONOPERATOR_H
