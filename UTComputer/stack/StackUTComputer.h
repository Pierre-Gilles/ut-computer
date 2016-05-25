//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_STACKUTCOMPUTER_H
#define TESTLO21CLION_STACKUTCOMPUTER_H

#include <iostream>
#include <deque>
#include <memory>
#include <vector>

#include "../exceptions/UTComputerException.h"
#include "../literals/Literal.h"

using namespace std;


class StackUTComputer {

    deque<shared_ptr<Literal>> st;

public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================

    StackUTComputer(){}
    virtual ~StackUTComputer() {
        st.clear(); // remove all elements from the container
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                     Implement Stack Interface                 ==========================
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
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                            Class services                     ==========================
    // ===============================================================================================================
    /**
     * Function that fill the Literal* table arguments with the right ones and in
     * the right order : first argument is the last one to be unstacked
     */
    void getArguments(int arity, vector<shared_ptr<Literal>> &arguments) const;

    /**
     * Function that delete the right number of elements from the container by calling
     * its function pop(). This function will take care of deleting the dynamically created objects
     * and remove the pointer element from the container.
     */
    void deleteArguments(int arity);
    // ===============================================================================================================

};


#endif //TESTLO21CLION_STACKUTCOMPUTER_H
