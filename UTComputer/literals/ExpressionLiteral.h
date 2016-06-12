/**
 * \file ExpressionLiteral.h
 * \brief File containing the declaration of the class ExpressionLiteral
 */

#ifndef TESTLO21CLION_EXPRESSIONLITERAL_H
#define TESTLO21CLION_EXPRESSIONLITERAL_H

#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include "StringLiteral.h"
#include <memory>



/**
 * \class ExpressionLiteral
 * \brief Subclass of StringLiteral
 *
 * Class used to manage expressions (example : '(2+2)*3/4-(10+2-5)' )
 */

class ExpressionLiteral : public StringLiteral {

    const static string expressionRegex; /*!< String containing the regex specific to ExpressionLiteral */


public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================

    /**
     * \fn ExpressionLiteral(const string &v)
     * \brief Constructor taking a string to construct a new ExpressionLiteral
     * \param[in] v : string from which the ExpressionLiteral is created
     * \return An instance of ExpressionLiteral. Delete all spaces, \\t and \\n character.
     */
    ExpressionLiteral(const string &v) : StringLiteral(v) {
        if (value.length() == 0)
            throw UTComputerException("Error ExpressionLiteral::constructor : expression must have a non empty value.");

        value.erase(std::remove(value.begin(), value.end(), ' '), value.end()); // delete all spaces
        value.erase(std::remove(value.begin(), value.end(), '\t'), value.end()); // delete all tab
        value.erase(std::remove(value.begin(), value.end(), '\n'), value.end()); // delete all "new line"
    }

    /**
     * \fn ExpressionLiteral(const ExpressionLiteral &l)
     * \brief Constructor taking a ExpressionLiteral reference to construct a new ExpressionLiteral
     * \param[in] l : ExpressionLiteral from which the new ExpressionLiteral is created
     * \return An ExpressionLiteral instance, copy of the parameter.
     */
    ExpressionLiteral(const ExpressionLiteral &l) : StringLiteral(l.value) { }
    virtual ~ExpressionLiteral() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================
    /**
     * \fn static const string &getExpressionRegex()
     * \brief Static function to get the static attribute expressionRegex
     * \return The static private attribute expressionRegex
     */
    static const string &getExpressionRegex() {
        return expressionRegex;
    }

    // ===============================================================================================================







    // ===============================================================================================================
    // ======================                         Override Methods                      ==========================
    // ===============================================================================================================
    /**
     * \fn virtual string toString() const override
     * \brief Override of the virtual pure toString() function
     * \return The protected attribute \a value surrounded by simples quotes : 'value'.
     */
    virtual string toString() const override;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Operators overload                      ==========================
    // ===============================================================================================================
    /**
     * \fn shared_ptr<ExpressionLiteral> operator+(const ExpressionLiteral &l) const
     * \brief Overload of operator+ between two ExpressionLiteral
     * \param[in] l : const ExpressionLiteral
     * \return A new shared_ptr<ExpressionLiteral> containing the concatenation of the two ExpressionLiteral and the
     * operator plus
     */
    shared_ptr<ExpressionLiteral> operator+(const ExpressionLiteral &l) const;

    /**
     * \fn shared_ptr<ExpressionLiteral> operator-(const ExpressionLiteral &l) const
     * \brief Overload of operator- between two ExpressionLiteral
     * \param[in] l : const ExpressionLiteral
     * \return A new shared_ptr<ExpressionLiteral> containing the concatenation of the two ExpressionLiteral and the
     * operator minus
     */
    shared_ptr<ExpressionLiteral> operator-(const ExpressionLiteral &l) const;

    /**
     * \fn shared_ptr<ExpressionLiteral> operator*(const ExpressionLiteral &l) const
     * \brief Overload of operator* between two ExpressionLiteral
     * \param[in] l : const ExpressionLiteral
     * \return A new shared_ptr<ExpressionLiteral> containing the concatenation of the two ExpressionLiteral and the
     * operator multiplication
     */
    shared_ptr<ExpressionLiteral> operator*(const ExpressionLiteral &l) const;

    /**
     * \fn shared_ptr<ExpressionLiteral> operator/(const ExpressionLiteral &l) const
     * \brief Overload of operator/ between two ExpressionLiteral
     * \param[in] l : const ExpressionLiteral
     * \return A new shared_ptr<ExpressionLiteral> containing the concatenation of the two ExpressionLiteral and the
     * operator division
     */
    shared_ptr<ExpressionLiteral> operator/(const ExpressionLiteral &l) const;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Useful class functions                  ==========================
    // ===============================================================================================================


private:
    /**
     * \fn hasSamePriority(const string &op, const string &expression) const
     * \brief Method used to test if an expression contains operators having the same priority than parameter \a op or not
     * \param[in] op : string containing the operator
     * \param[in] expression : string containing the expression
     * \return True if \a expression's operators have the same priority than \ op, Fale otherwise.
     */
    bool hasSamePriority(const string &op, const string &expression) const;

    /**
     * \fn constructNewExpression(const string &op, const ExpressionLiteral &l) const
     * \brief Method used to construct a new expression from two expressions and an operator +, -, * or /
     * \param[in] op : string containing the operator
     * \param[in] l : const ExpressionLiteral &
     * \return The concatenation of the operator \a op and the two expressions (the one given as a parameter and the implicit one)
     */
    string constructNewExpression(const string &op, const ExpressionLiteral &l) const;
    // ===============================================================================================================


};


#endif //TESTLO21CLION_EXPRESSIONLITERAL_H
