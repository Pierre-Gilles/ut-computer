/**
 * \file Operator.h
 * \brief File containing the Operator class.
 */
#ifndef TESTLO21CLION_OPERATOR_H
#define TESTLO21CLION_OPERATOR_H

#include <iostream>
#include <string>
#include "../stack/StackUTComputer.h"
#include "../exceptions/UTComputerException.h"
using namespace std;

/**
 * \class Operator
 * \brief Abstract super class for all specific operators
 */
class Operator {
protected:
    int arity;
    string key;
    int priority;
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    /**
     * \fn Operator(int nb, string key, int prio)
     * \brief Constructor
     * \param[in] nb : int representing the operator's arity
     * \param[in] key : string representing the operator's key (+, -, DIV, ...)
     * \param[in] prio : int representing the operators's priority
     * \return "Nothing", the class is abstract
     */
    Operator(int nb, string key, int prio) : arity(nb), key(key), priority(prio) {
    }
    virtual ~Operator() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================
    /**
     * \fn int getArite() const
     * \brief Getter for the private attribute arity
     * \return The private attribute arity
     */
    int getArite() const {
        return arity;
    }
    /**
     * \fn const string &getKey() const
     * \brief Getter for the private attribute key
     * \return The private attribute key
     */
    const string &getKey() const {
        return key;
    }
    /**
     * \fn int getPriority() const
     * \brief Getter for the private attribute key
     * \return The private attribute key
     */
    int getPriority() const {
        return priority;
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                     Interface for subclasses                  ==========================
    // ===============================================================================================================
    /**
     * \fn virtual void execute(StackUTComputer * const st)
     * \brief Virtual pure method to be implemented by each specific operators
     * \param[in] st : constant pointer (referenced object can be modified but reference itself cannot) to an instance of StackUTComputer
     *
     * Every specific operator will redefine this function and do what needs to be done according to their function :
     *     - All stack operators implement it in a different way
     *         - OperatorCLEAR will call StackUTComputer::clear() method
     *         - ...
     *     - CalculationOperator implements it to do general actions that all its subclass must do and call a new
     *       virtual pure method that will be implemented by each subclass of CalculationOperator.
     */
    virtual void execute(StackUTComputer * const st) = 0;
    // ===============================================================================================================
};


#endif //TESTLO21CLION_OPERATOR_H
