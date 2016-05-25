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

    StackUTComputer(){}

    virtual ~StackUTComputer() {
        st.clear(); // remove all elements from the container
    }

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


    /**
     * Function that fill the Literal* table arguments with the right ones and in
     * the right order : first argument is the last one to be unstacked
     */
    void getArguments(int arity, vector<shared_ptr<Literal>> &arguments) {
        if (st.size() < arity)
            throw UTComputerException("Error in StackUTComputer::getArguments : arity superior to stack size");

        for (int it=0; it<arity; it++) {
            if (!st[arity-1-it]) { // means that st[arity-1-i] is null
                arguments.clear(); // in case we have insert items before having the exception
                throw UTComputerException("Error StackUTComputer::getArguments : at least one argument is null.");
            }

            arguments.insert(arguments.begin()+it, st[arity-1-it]);
        }
    }

    /**
     * Function that delete the right number of elements from the container by calling
     * its function pop(). This function will take care of deleting the dynamically created objects
     * and remove the pointer element from the container.
     */
    void deleteArguments(int arity) {
        if (st.size() < arity) {
            throw UTComputerException("Error in StackUTComputer::deleteArguments : arity superior to stack size");
        }
        for (int i=0; i<arity; i++) {
            pop();
        }
    }

};


#endif //TESTLO21CLION_STACKUTCOMPUTER_H
