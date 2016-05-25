#ifndef TESTLO21CLION_OPERATOR_H
#define TESTLO21CLION_OPERATOR_H

#include <iostream>
#include <string>
#include "../stack/StackUTComputer.h"
#include "../exceptions/UTComputerException.h"
using namespace std;

class Operator {
protected:
    int arity;
    string key;
    vector<shared_ptr<Literal>> arguments; // vector of shared_ptr<Literal>
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    Operator(int nb, string key) : arity(nb), key(key) {
        arguments.reserve((unsigned long int)nb); // reserve space in vector
    }
    virtual ~Operator() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================
    int getArite() const {
        return arity;
    }

    const string &getKey() const {
        return key;
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Class main services                     ==========================
    // ===============================================================================================================
    /*
     * Adress of stack must not bu changed, but "st" do not point to a const stack : we use a constant pointer
     * and not a pointer to constant
     */
    void execute(StackUTComputer * const st);
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                   Interface for subclasses                    ==========================
    // ===============================================================================================================
private:
    virtual shared_ptr<Literal> executeSpecificOperator() = 0;
    // ===============================================================================================================

};


#endif //TESTLO21CLION_OPERATOR_H
