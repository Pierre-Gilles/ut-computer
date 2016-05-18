//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_STACKUTCOMPUTER_H
#define TESTLO21CLION_STACKUTCOMPUTER_H

#include <iostream>
//#include <stack>
#include <deque>

#include "../exceptions/UTComputerException.h"
#include "../literals/Literal.h"

using namespace std;


class StackUTComputer {

    deque<Literal*> st;

public:

    StackUTComputer(){}

    virtual ~StackUTComputer() {
        for (int i=0; i<st.size(); i++) {
            delete st[i]; // delete each dynamically created object
        }
        st.clear(); // remove all elements from the container
    }

    Literal* top() {
        return st[0];
    }

    void pop() {
        delete st[0]; // delete the dynamically created object
        st.pop_front(); // remove top element from the container
    }

    void push(Literal* l) {
        st.push_front(l); // add element on top of the container
    }

    int size() {
        return (int)st.size(); // cast from "unsigned long int" in "int"
    }

    /**
     * Function that fill the Literal* table arguments with the right ones and in
     * the right order : first argument is the last one to be unstacked
     */
    void getArguments(int arity, Literal **arguments) {
        if (st.size() < arity)
            throw UTComputerException("Error in StackUTComputer::getArguments : arity superior to stack size");

        for (int i=0; i<arity; i++) {
            arguments[i] = st[arity-1-i];
        }
    }

    /**
     * Function that delete the right number of elements from the container by calling
     * its function pop(). This function will take care of deleting the dynamically created objects
     * and remove the pointer element from the container.
     */
    void deleteArguments(int arity) {
        if (st.size() < arity)
            throw UTComputerException("Error in StackUTComputer::deleteArguments : arity superior to stack size");
        for (int i=0; i<arity; i++) {
            pop();
        }
    }

    void clear() {
        for (int i=0; i<st.size(); i++) {
            delete st[i]; // delete each dynamically created object
        }
        st.clear(); // remove all elements from the container
    }
};


#endif //TESTLO21CLION_STACKUTCOMPUTER_H
