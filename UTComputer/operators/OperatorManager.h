//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_OPERATORMANAGER_H
#define TESTLO21CLION_OPERATORMANAGER_H
#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <memory>

#include "../literals/Literal.h"
#include "Operator.h"
#include "OperatorPlus.h"
#include "OperatorMinus.h"
#include "OperatorMultiplication.h"
#include "OperatorDivision.h"

using namespace std;


class OperatorManager {
    unordered_map<string, Operator*> op_map;

public:

    OperatorManager() { }

    virtual ~OperatorManager() {
        for (auto it = op_map.begin(); it != op_map.end(); ++it) {
            delete it->second;
            it->second = nullptr;
        }
        op_map.clear();
    }


    bool operatorExists(const string &key) {
        unordered_map<string, Operator*>::const_iterator found = op_map.find(key);
        return !(found == op_map.cend());
    }

    Operator* getOperator(const string &key) {
        return op_map[key];
    }

    bool addOperator(Operator* o) {
        if (operatorExists(o->getKey()))
            throw UTComputerException("Error in OperatorManager::addOperator : operator key already exists.");

        pair<string, Operator*> operator_pair (o->getKey(), o);
        op_map.insert(operator_pair);
        return true;
    }

};


#endif //TESTLO21CLION_OPERATORMANAGER_H
