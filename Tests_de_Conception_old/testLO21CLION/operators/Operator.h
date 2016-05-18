//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_OPERATOR_H
#define TESTLO21CLION_OPERATOR_H

#include <iostream>
#include <string>
#include "../stack/StackUTComputer.h"
#include "../exceptions/UTComputerException.h"
using namespace std;

class Operator {
protected:
    int n;
    string key;
    Literal **arguments; // table of Literal*
    virtual Literal* executeSpecificOperator(StackUTComputer* st) = 0;
public:

    Operator(int nb, string key) : n(nb), key(key) {
        arguments = new Literal*[nb];
        for (int i=0; i<nb; i++)
            arguments[i] = nullptr;
    }
    virtual ~Operator() { }


    int getArite() const {
        return n;
    }

    const string &getKey() const {
        return key;
    }

    void execute(StackUTComputer* st) { // do not override
        if (st == nullptr)
            throw UTComputerException("Error in Operator::execute : pointer to stack is null");

        if (st->size() < n)
            throw UTComputerException("Error in Operator::execute : size of stack inferior to operator arity");

        st->getArguments(n, arguments);

        Literal* result;

        try {
            result = executeSpecificOperator(st); /* call to private executeSpecificOperator()
                                                    * we may not need to pass the stack
                                                    * but maybe some specifics operators we'll need the stack */
        } catch (UTComputerException e) {
            UTComputerException e1(e.getMessage());
            e1.insertBefore("Error in Operator::executeSpecificOperator --> ");
            throw e1;
        }

        st->deleteArguments(n);
        st->push(result);
    }
};


#endif //TESTLO21CLION_OPERATOR_H
