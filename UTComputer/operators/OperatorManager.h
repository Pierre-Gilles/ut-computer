//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_OPERATORMANAGER_H
#define TESTLO21CLION_OPERATORMANAGER_H
#include <iostream>
#include <stack>
#include <unordered_map>
#include "../literals/Literal.h"
#include <string>
#include "Operator.h"

using namespace std;

class OperatorManager {
    unordered_map<string, Operator*> op_manager;

public:

    OperatorManager() {

    }

    virtual ~OperatorManager() { }


    bool operatorExists(const string &key) {
        unordered_map<string, Operator*>::const_iterator found = op_manager.find(key);
        return !(found == op_manager.cend());
    }

    Operator* getOperator(const string &key) {
        return op_manager[key];
    }

};


#endif //TESTLO21CLION_OPERATORMANAGER_H
