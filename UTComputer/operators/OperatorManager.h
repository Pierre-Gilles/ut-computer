#ifndef TESTLO21CLION_OPERATORMANAGER_H
#define TESTLO21CLION_OPERATORMANAGER_H
#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <memory>

#include "../literals/Literal.h"
#include "Operator.h"
#include "classic_operators/OperatorPlus.h"
#include "classic_operators/OperatorMinus.h"
#include "classic_operators/OperatorMultiplication.h"
#include "classic_operators/OperatorDivision.h"
#include "classic_operators/OperatorIntegerDivision.h"
#include "classic_operators/OperatorNeg.h"
#include "classic_operators/OperatorModulo.h"
#include "logical_operators/OperatorAnd.h"
#include "logical_operators/OperatorOr.h"
#include "logical_operators/OperatorNot.h"
#include "logical_operators/OperatorInferior.h"
#include "logical_operators/OperatorInferiorEqual.h"
#include "logical_operators/OperatorSuperior.h"
#include "logical_operators/OperatorSuperiorEqual.h"
#include "logical_operators/OperatorEqual.h"
#include "logical_operators/OperatorDifferent.h"




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
