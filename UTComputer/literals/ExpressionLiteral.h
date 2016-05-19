//
// Created by Raphael on 15/05/2016.
//

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

    ExpressionLiteral(const string &value) : StringLiteral(value) { }

    virtual ~ExpressionLiteral() { }



    bool hasSamePriority(const string &op, const string &expression) const {
        bool inParenthesis = false;
        vector<string> priority0 = {"<", ">", "<=", ">=", "=", "!="};
        vector<string> priority1 = {"+", "-"};
        vector<string> priority2 = {"*", "/"};
        vector<string> priority3 = {"$"};
        vector<string> op_diff;

        stack<int> stackOfParenthesis;

        // construct the vector of operators containing all operators having a different priority than "op"
        if ( (find(priority0.begin(), priority0.end(), op)) != priority0.end() ) {
            op_diff.reserve(priority1.size() + priority2.size() + priority3.size());
            op_diff.insert(op_diff.end(), priority1.begin(), priority1.end());
            op_diff.insert(op_diff.end(), priority2.begin(), priority2.end());
            op_diff.insert(op_diff.end(), priority3.begin(), priority3.end());
        }
        else if ((find(priority1.begin(), priority1.end(), op)) != priority1.end()) {
            op_diff.reserve(priority0.size() + priority2.size() + priority3.size());
            op_diff.insert(op_diff.end(), priority0.begin(), priority0.end());
            op_diff.insert(op_diff.end(), priority2.begin(), priority2.end());
            op_diff.insert(op_diff.end(), priority3.begin(), priority3.end());
        }
        else if ((find(priority2.begin(), priority2.end(), op)) != priority2.end()) {
            op_diff.reserve(priority0.size() + priority1.size() + priority3.size());
            op_diff.insert(op_diff.end(), priority0.begin(), priority0.end());
            op_diff.insert(op_diff.end(), priority1.begin(), priority1.end());
            op_diff.insert(op_diff.end(), priority3.begin(), priority3.end());
        }
        else if ((find(priority3.begin(), priority3.end(), op)) != priority3.end()) {
            op_diff.reserve(priority0.size() + priority1.size() + priority2.size());
            op_diff.insert(op_diff.end(), priority0.begin(), priority0.end());
            op_diff.insert(op_diff.end(), priority1.begin(), priority1.end());
            op_diff.insert(op_diff.end(), priority2.begin(), priority2.end());
        }
        else {
            throw UTComputerException("Error ExpressionLiteral::hasSamePriority invalid \"op\" argument");
        }



        string::const_iterator it = expression.cbegin();
        unsigned long int i=0;
        while (i < expression.size()) {
//            cout << i << "  -  ";
            if (!inParenthesis) {
//                cout << "!inParenthesis" << endl;
//                cout << "substr  " << expression.substr(i,1) << endl;
                // if there is an operator different than "op" in "expression"
                if ( find(op_diff.begin(), op_diff.end(), expression.substr(i,1)) != op_diff.end() ) {
//                    cout << expression.substr(i,i) << endl;
                    return false;
                }

                // special for operator <= >= !=
                if (expression[i] == '=')
                    if (i != 0 && (expression[i-1] == '<' || expression[i-1] == '>' || expression[i-1] == '!') ) {
                        if ( find(op_diff.begin(), op_diff.end(), expression.substr(i-1,2)) != op_diff.end() )
                            return false;
                    }

                if (expression[i] == '(') {
                    inParenthesis = true;
                    stackOfParenthesis.push(1);
                }
                i++;
            }
            else {
                if (stackOfParenthesis.empty())
                    throw UTComputerException("ExpressionLiteral::samePriority stackOfParenthesis should not happen here.");

                if (expression[i] == ')') {
                    stackOfParenthesis.pop();
//                    cout << "pop" << endl;
                    if (stackOfParenthesis.empty()) {// we are out of parenthesis
//                        cout << "we are out of parenthesis" << endl;
                        inParenthesis = false;
                    }
                }
                i++;
            }
        }

        if (!stackOfParenthesis.empty())
            throw UTComputerException("ExpressionLiteral::samePriority stack not empty means absence of closing parenthesis");

        return true; // we didn't found operators of different priority than "op"
    }

    ExpressionLiteral* operator+(ExpressionLiteral &l) const {
        // use of const_cast<ExpressionLiteral*>(this)->toString() in order to use a non const method (toString) in a const method
        string newExpression = "";


        if ( hasSamePriority("+", const_cast<ExpressionLiteral*>(this)->toString()) ) {
            newExpression.insert(0, const_cast<ExpressionLiteral*>(this)->toString());
        }
        else {
            newExpression.insert(0, "(" + const_cast<ExpressionLiteral*>(this)->toString() + ")");
        }

        newExpression.insert(newExpression.length(), "+");
        if ( hasSamePriority("+", l.toString()) ) {
            newExpression.insert(newExpression.length(), l.toString());
        }
        else {
            newExpression.insert(newExpression.length(), "(" + l.toString() + ")");
        }
        return new ExpressionLiteral(newExpression);
    }

//    ExpressionLiteral* operator+(ComplexLiteral &l) const {
//        ExpressionLiteral tmp(l.toString());
//        return this->operator+(tmp);
//    }
};


#endif //TESTLO21CLION_EXPRESSIONLITERAL_H
