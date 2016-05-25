#ifndef TESTLO21CLION_EXPRESSIONLITERAL_H
#define TESTLO21CLION_EXPRESSIONLITERAL_H

#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include "StringLiteral.h"


class ExpressionLiteral : public StringLiteral {
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    ExpressionLiteral(const string &value) : StringLiteral(value) { }
    virtual ~ExpressionLiteral() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================
    string getPostfixExpression() const {
        return infixToPostfix(value);
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                         Override Methods                      ==========================
    // ===============================================================================================================
    virtual string toString() const override;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Operators overload                      ==========================
    // ===============================================================================================================
    shared_ptr<ExpressionLiteral> operator+(const ExpressionLiteral &l) const;
    shared_ptr<ExpressionLiteral> operator-(const ExpressionLiteral &l) const;
    shared_ptr<ExpressionLiteral> operator*(const ExpressionLiteral &l) const;
    shared_ptr<ExpressionLiteral> operator/(const ExpressionLiteral &l) const;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Useful class functions                  ==========================
    // ===============================================================================================================
    // public to test it
    bool hasSamePriority(const string &op, const string &expression) const;

private:
    string constructNewExpression(const string &op, const ExpressionLiteral &l) const;
    int getWeightOperator(const char ch) const;
    string infixToPostfix(const string infix) const;
    // ===============================================================================================================


};


#endif //TESTLO21CLION_EXPRESSIONLITERAL_H
