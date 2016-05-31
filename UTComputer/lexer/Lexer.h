//
// Created by Raphael on 15/05/2016.
//

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
#include "../exceptions/UTComputerException.h"

using namespace std;

enum modes { UnLocked, ExpressionLocked, ProgLocked, LitteralLocked };

class LexerUTComputer {
public:

    static const vector<char> operatorTypes;
    static const vector<char> separatorTypes;
    static const char progSeparatorStart;
    static const char progSeparatorStop;
    static const char expressionSeparator;

    static const vector<string> operatorEval;





    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    LexerUTComputer() { }
    virtual ~LexerUTComputer() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                        Class main services                    ==========================
    // ===============================================================================================================
    vector<string> split(const string &s) const;
    vector<string> tokenize(const string &s) const;
    vector<string> infixToPostfix(const vector<string> elems) const;
    vector<string> tokenizeInfixToPostfix(const string &s) const;
    // ===============================================================================================================




    // ===============================================================================================================
    // ======================                       Useful class functions                  ==========================
    // ===============================================================================================================
private:
    bool findInArray(const char c, const vector<char> array) const;
    bool findInArrayString(const string c, const vector<string> array) const;
    int getWeightOperator(const string s) const;
    // ===============================================================================================================

};


#endif //TESTLO21CLION_LEXER_H

