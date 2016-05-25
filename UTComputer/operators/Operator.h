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
    int arity;
    string key;
    vector<shared_ptr<Literal>> arguments; // vector of shared_ptr<Literal>
    virtual shared_ptr<Literal> executeSpecificOperator() = 0;
public:

    Operator(int nb, string key) : arity(nb), key(key) {
        arguments.reserve((unsigned long int)nb); // reserve space in vector
    }
    virtual ~Operator() {

    }


    int getArite() const {
        return arity;
    }

    const string &getKey() const {
        return key;
    }

    void execute(StackUTComputer *st) { // do not override ???
        if (st == nullptr)
            throw UTComputerException("Error in Operator::execute : pointer to stack is null");

        if (st->size() < arity)
            throw UTComputerException("Error in Operator::execute : size of stack inferior to operator arity");

        st->getArguments(arity, arguments);

        shared_ptr<Literal> result;

        try {
            result = executeSpecificOperator();
        } catch (UTComputerException e) {
            UTComputerException e1(e.getMessage());
            e1.insertBefore("Error in Operator::executeSpecificOperator --> ");
            throw e1;
        }

        st->deleteArguments(arity);
        st->push(result);
    }


};


#endif //TESTLO21CLION_OPERATOR_H
