//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_OPERATORMANAGER_H
#define TESTLO21CLION_OPERATORMANAGER_H
#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

#include "../literals/Literal.h"
#include "Operator.h"
#include "OperatorPlus.h"
#include "OperatorMinus.h"
#include "OperatorMultiplication.h"
#include "OperatorDivision.h"

using namespace std;


class OperatorManager {
    vector<Operator*> op_vector;
    unordered_map<string, Operator*> op_map;

public:

    OperatorManager() {
        // dynamically instantiate one time each operator and store them in a vector
        op_vector.insert(op_vector.begin(), new OperatorPlus);
        op_vector.insert(op_vector.begin(), new OperatorMinus);
        op_vector.insert(op_vector.begin(), new OperatorMultiplication);
        op_vector.insert(op_vector.begin(), new OperatorDivision);


        // Loop through op_vector and add the pair <key,Operator*> to the unordered_map
        for (int i=0; i<op_vector.size(); i++) {
            addOperator(op_vector[i]);
        }
    }

    virtual ~OperatorManager() {
        op_map.clear();
        for (int i=0; i<op_vector.size(); i++) {
            delete op_vector[i];
            op_vector[i] = nullptr;
        }
        op_vector.clear();
    }

    const vector<Operator *> &getOp_vector() const {
        return op_vector;
    }

    bool operatorExists(const string &key) {
        unordered_map<string, Operator*>::const_iterator found = op_map.find(key);
        return !(found == op_map.cend());
    }

    Operator* getOperator(const string &key) {
        return op_map[key];
    }

    bool addOperator(Operator *o) {
        if (operatorExists(o->getKey()))
            throw UTComputerException("Error in OperatorManager::addOperator : operator key already exists.");

        pair<string, Operator*> operator_pair (o->getKey(), o);
        op_map.insert(operator_pair);
        return true;
    }

};


#endif //TESTLO21CLION_OPERATORMANAGER_H
