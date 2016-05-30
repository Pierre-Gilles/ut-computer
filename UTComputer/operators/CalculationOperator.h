#ifndef UTCOMPUTER_CALCULATIONOPERATOR_H
#define UTCOMPUTER_CALCULATIONOPERATOR_H

#include "Operator.h"

class CalculationOperator : public Operator {
protected:
    //int arity;
    //string key;
    vector<shared_ptr<Literal>> arguments; // vector of shared_ptr<Literal>
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    CalculationOperator(int nb, string key) : Operator(nb, key) {
        arguments.reserve((unsigned long int)nb); // reserve space in vector
    }
    virtual ~CalculationOperator() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Class main services                     ==========================
    // ===============================================================================================================
    /*
     * Adress of stack must not be changed, but "st" do not point to a const stack : we use a constant pointer
     * and not a pointer to constant
     */
    virtual void execute(StackUTComputer * const st) override;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                   Interface for subclasses                    ==========================
    // ===============================================================================================================
private:
    virtual shared_ptr<Literal> executeSpecificOperator() = 0;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_CALCULATIONOPERATOR_H
