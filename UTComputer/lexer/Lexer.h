//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_LEXER_H
#define TESTLO21CLION_LEXER_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
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
    vector<string> infixTokeniser(const string &s) const;
    // ===============================================================================================================




    // ===============================================================================================================
    // ======================                       Useful class functions                  ==========================
    // ===============================================================================================================
private:
    bool findInArray(const char c, const vector<char> array) const;
    bool findInArrayString(const string c, const vector<string> array) const;
    // ===============================================================================================================

};


#endif //TESTLO21CLION_LEXER_H

