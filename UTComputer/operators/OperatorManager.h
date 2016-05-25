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

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    OperatorManager() { }
    virtual ~OperatorManager() {
        for (auto it = op_map.begin(); it != op_map.end(); ++it) {
            delete it->second;
            it->second = nullptr;
        }
        op_map.clear();
    }





    // ===============================================================================================================
    // ======================                       Class main services                     ==========================
    // ===============================================================================================================

    bool operatorExists(const string &key) const;

    Operator* getOperator(const string &key);

    bool addOperator(Operator* o);
    // ===============================================================================================================

};


#endif //TESTLO21CLION_OPERATORMANAGER_H
