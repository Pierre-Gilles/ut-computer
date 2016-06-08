/**
 * \file Lexer.h
 * \brief File containing the LexerUTComputer class.
 */

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


/**
 * \class LexerUTComputer
 */
class LexerUTComputer {
public:

    unordered_map<string, int> operator_weight_map; /*!< unordered_map containing the priority (int value) of each operator used in this application. */


    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    LexerUTComputer() { }
    virtual ~LexerUTComputer() { }
    // ===============================================================================================================



    // ===============================================================================================================
    // ======================                     Getters and Setters                       ==========================
    // ===============================================================================================================
    /**
     * \fn const unordered_map<string, int> &getOperator_weigth_map() const
     * \return the \a operator_weight_map attribute
     */
    const unordered_map<string, int> &getOperator_weigth_map() const {
        return operator_weight_map;
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                        Class main services                    ==========================
    // ===============================================================================================================
    /**
     * \fn
     * \brief
     * \param[in] s the string to tokenize
     * \return
     */
    vector<string> tokenize(const string &s) const;

    /**
     * \fn
     * \brief
     * \param[]
     * \return
     */
    vector<string> infixToPostfix(const vector<string> elems) const;

    /**
     * \fn
     * \brief
     * \param[]
     * \return
     */
    vector<string> tokenizeInfixToPostfix(const string &s) const;
    // ===============================================================================================================




    // ===============================================================================================================
    // ======================                       Useful class functions                  ==========================
    // ===============================================================================================================
    /**
     * \fn
     * \brief
     * \param[]
     * \return
     */
    bool addOperatorWeight(Operator *o); //

    /**
     * \fn
     * \brief
     * \param[]
     * \return
     */
    bool isOperator(const string s) const;
private:
    /**
     * \fn
     * \brief
     * \param[]
     * \return
     */
    bool operatorWeightExists(const string &key) const;

    /**
     * \fn
     * \brief
     * \param[]
     * \return
     */
    int getWeightOperator(const string s) const;
    // ===============================================================================================================

};


#endif //TESTLO21CLION_LEXER_H

