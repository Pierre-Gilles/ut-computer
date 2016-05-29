#ifndef TESTLO21CLION_STACKUTCOMPUTER_H
#define TESTLO21CLION_STACKUTCOMPUTER_H

#include <iostream>
#include <deque>
#include <memory>
#include <vector>

#include "../exceptions/UTComputerException.h"
#include "../literals/Literal.h"

//#include "../operators/Operator.h"

class Operator; // we need Operator class but we can't include the header file because Operator also need StackUTComputer for its function execute()

using namespace std;


class StackUTComputer {

    deque<shared_ptr<Literal>> st;
    deque<shared_ptr<Literal>> lastArguments;
    Operator *lastOperator;



public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================

    StackUTComputer() : lastOperator(nullptr) {}
    virtual ~StackUTComputer() {
        st.clear(); // remove all elements from the container
        lastArguments.clear();
    }
    // ===============================================================================================================



    // ===============================================================================================================
    // ======================                   Getters and Setters                         ==========================
    // ===============================================================================================================

    void setLastOperator(Operator *lastOp) {
        lastOperator = lastOp;
    }

    Operator *getLastOperator() const {
        return lastOperator;
    }

    void setLastArguments(int operatorArity) {
        if (st.size() < operatorArity)
            throw UTComputerException("Error in StackUTComputer::setLastArguments : arity superior to stack size");

        for (int i=0; i<operatorArity; i++) {
            lastArguments.push_front(st[i]); // save last arguments
        }
    }


    // ===============================================================================================================


    // ===============================================================================================================
    // ======================        Implement Stack Interface and Stack Operators          ==========================
    // ===============================================================================================================





    int size() {
        return (int)st.size(); // cast from "unsigned long int" in "int"
    }

    shared_ptr<Literal> top() {
        return st[0];
    }

    void pop() {
        st.pop_front(); // remove top element from the container
    }

    void clear() {
        st.clear(); // remove all elements from the container
    }

    void push(shared_ptr<Literal> l) {
        st.push_front(l); // add element on top of the container
    }

    void pushLastArgs() {
        for (int i=0; i<lastArguments.size(); i++)
            st.push_front(lastArguments[i]);
    }

    // ===============================================================================================================






    // ===============================================================================================================
    // ======================                            Class services                     ==========================
    // ===============================================================================================================
    /**
     * Function that fill the Literal* table arguments with the right ones and in
     * the right order : first argument is the last one to be unstacked
     */
    void getArguments(int arity, vector<shared_ptr<Literal>> &arguments);

    /**
     * Function that delete the right number of elements from the container by calling
     * its function pop(). This function will take care of deleting the dynamically created objects
     * and remove the pointer element from the container.
     */
    void deleteArguments(int arity);
    // ===============================================================================================================

};


#endif //TESTLO21CLION_STACKUTCOMPUTER_H
