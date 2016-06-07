#ifndef TESTLO21CLION_LEXER_H
#define TESTLO21CLION_LEXER_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <regex>
#include <ctype.h>
#include <iterator>
#include <unordered_map>
#include "../operators/Operator.h"
#include "../exceptions/UTComputerException.h"

using namespace std;


class LexerUTComputer {
public:

    unordered_map<string, int> operator_weight_map;





    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    LexerUTComputer() { }
    virtual ~LexerUTComputer() { }
    // ===============================================================================================================



    // ===============================================================================================================
    // ======================                     Getters and Setters                       ==========================
    // ===============================================================================================================
    const unordered_map<string, int> &getOperator_weigth_map() const {
        return operator_weight_map;
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                        Class main services                    ==========================
    // ===============================================================================================================
    vector<string> tokenize(const string &s) const;
    vector<string> infixToPostfix(const vector<string> elems) const;
    vector<string> tokenizeInfixToPostfix(const string &s) const;
    // ===============================================================================================================




    // ===============================================================================================================
    // ======================                       Useful class functions                  ==========================
    // ===============================================================================================================
    bool addOperatorWeight(Operator *o); //
    bool isOperator(const string s) const;
private:
    bool operatorWeightExists(const string &key) const;
    int getWeightOperator(const string s) const;
    // ===============================================================================================================

};


#endif //TESTLO21CLION_LEXER_H

