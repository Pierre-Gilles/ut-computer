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

    unordered_map<string, int> operator_weight_map; /*!< unordered_map containing the priority (int value) of each
                                                        * operator used in this application or add later on by an user. */


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
     * \fn vector<string> tokenize(const string &s) const
     * \brief Method that tokenize a string
     * \param[in] s : the string to tokenize
     * \return A vector of string containing all tokens
     */
    vector<string> tokenize(const string &s) const;

    /**
     * \fn vector<string> infixToPostfix(const vector<string> elems) const
     * \brief Method that transform an infix expression into a postfix expression
     * \param[in] elems : the vector of string containing all the tokens of the infix expression
     * \return A vector of string containing all the tokens arranged in a postfix manner
     */
    vector<string> infixToPostfix(const vector<string> elems) const;

    /**
     * \fn vector<string> tokenizeInfixToPostfix(const string &s) const
     * \brief Combination of tokenize and infixToPostfix methods
     * \param[in] s : the string representing the infix expression
     * \return The infix expression tokenized and transformed in a postfix expression
     */
    vector<string> tokenizeInfixToPostfix(const string &s) const;
    // ===============================================================================================================




    // ===============================================================================================================
    // ======================                       Useful class functions                  ==========================
    // ===============================================================================================================
    /**
     * \fn bool addOperatorWeight(Operator *o)
     * \brief Method that add an operator weight to the operator_weight_map
     * \param[in] o : pointer to the Operator from which we want the weight
     * \return True if the operator is not already present in operator_weight_map, otherwise return false
     */
    bool addOperatorWeight(Operator *o);

    /**
     * \fn bool isOperator(const string s) const
     * \brief Check if "s" is an operator
     * \param[in] s : string
     * \return True if s is an operator, false otherwise
     */
    bool isOperator(const string s) const;

private:
    /**
     * \fn bool operatorWeightExists(const string &key) const
     * \brief Check if an Operator and its weight exist in operator_weight_map
     * \param[in] key : the operator's key
     * \return True if the Operator and its weight exist, false otherwise
     */
    bool operatorWeightExists(const string &key) const;

    /**
     * \fn int getWeightOperator(const string s) const
     * \brief Method to get an Operator's weight
     * \param[in] s : the operator's key
     * \return The Operator's weight
     */
    int getWeightOperator(const string s) const;
    // ===============================================================================================================

};


#endif //TESTLO21CLION_LEXER_H

