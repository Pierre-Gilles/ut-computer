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
#include "rational_operators/OperatorNumerator.h"
#include "rational_operators/OperatorDenominator.h"
#include "complex_operators/OperatorDollar.h"
#include "complex_operators/OperatorIM.h"
#include "complex_operators/OperatorRE.h"
#include "stack_operators/OperatorCLEAR.h"
#include "stack_operators/OperatorDROP.h"
#include "stack_operators/OperatorDUP.h"
#include "stack_operators/OperatorLASTARGS.h"
#include "stack_operators/OperatorLASTOP.h"
#include "stack_operators/OperatorREDO.h"
#include "stack_operators/OperatorUNDO.h"
#include "stack_operators/OperatorSWAP.h"







using namespace std;


class OperatorManager {
    unordered_map<string, Operator*> op_map; /*!< Container to store and access to Operator* */



public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    OperatorManager() { }

    /**
     * \fn virtual ~OperatorManager()
     * \brief Destructor
     *
     * Iterates in the unordered_map \a op_map and delete all the pointers to Operator.
     * Operators are created in the Calculator constructor bur deleted here, in the OperatorManager descructor.
     */
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

    /**
     * \fn bool operatorExists(const string &key) const;
     * \brief Check if an Operator exists
     * \param[in] key :  Operator's key
     * \return True if the Operator exists in \a op_map, otherwise return false
     */
    bool operatorExists(const string &key) const;

    /**
     * \fn Operator* getOperator(const string &key);
     * \brief Get a specific Operator
     * \param[in] key : Operator's key
     * \return A pointer to an Operator matching the key parameter
     */
    Operator* getOperator(const string &key);


    /**
     * \fn bool addOperator(Operator* o);
     * \brief Method that add an Operator* to the \a op_map attribute
     * \param[in] o : Pointer to the Operator
     * \return True adding the Operator went well, false otherwise
     */
    bool addOperator(Operator* o);
    // ===============================================================================================================

};


#endif //TESTLO21CLION_OPERATORMANAGER_H
