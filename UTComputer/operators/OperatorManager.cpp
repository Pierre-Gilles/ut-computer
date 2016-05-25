#include "OperatorManager.h"



// ===============================================================================================================
// ======================                       Class main services                     ==========================
// ===============================================================================================================

bool OperatorManager::operatorExists(const string &key) const {
    unordered_map<string, Operator*>::const_iterator found = op_map.find(key);
    return !(found == op_map.cend());
}

Operator* OperatorManager::getOperator(const string &key) {
    return op_map[key];
}

bool OperatorManager::addOperator(Operator* o) {
    if (operatorExists(o->getKey()))
        throw UTComputerException("Error in OperatorManager::addOperator : operator key already exists.");

    pair<string, Operator*> operator_pair (o->getKey(), o);
    op_map.insert(operator_pair);
    return true;
}
// ===============================================================================================================
