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

private:

    string constructNewExpression(const string &op, ExpressionLiteral &l) const {
        // Parameter of type "ExpressionLiteral &l" and not "const ExpressionLiteral &l" because of the non const toString() method
        // use of const_cast<ExpressionLiteral*>(this)->toString() in order to use the non const method toString() in a const method
        string newExpression = "";

        if ( hasSamePriority(op, const_cast<ExpressionLiteral*>(this)->toString()) ) {
            newExpression.insert(0, const_cast<ExpressionLiteral*>(this)->getValue());
        }
        else {
            newExpression.insert(0, "(" + const_cast<ExpressionLiteral*>(this)->getValue() + ")");
        }

        newExpression.insert(newExpression.length(), op);
        if ( hasSamePriority(op, l.toString()) ) {
            newExpression.insert(newExpression.length(), l.getValue());
        }
        else {
            newExpression.insert(newExpression.length(), "(" + l.getValue() + ")");
        }
        return newExpression;
    }

    int getWeightOperator(char ch) {
        switch (ch) {
            case '$': return 3;
            case '/':
            case '*': return 2;
            case '+':
            case '-': return 1;
            default : return 0;
        }
    }

public:

    ExpressionLiteral(const string &value) : StringLiteral(value) { }

    virtual ~ExpressionLiteral() { }

    bool hasSamePriority(const string &op, const string &expression) const {
        bool inParenthesis = false;
        vector<string> priority0 = {"<", ">", "<=", ">=", "=", "!=", "AND", "OR", "NOT"};
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
            if (!inParenthesis) {
                // if there is an operator different than "op" in "expression"
                if ( find(op_diff.begin(), op_diff.end(), expression.substr(i,1)) != op_diff.end() ) {
                    return false;
                }

                // special for operator <= >= !=
                if (expression[i] == '=') {
                    if (i != 0 && (expression[i - 1] == '<' || expression[i - 1] == '>' || expression[i - 1] == '!')) {
                        if (find(op_diff.begin(), op_diff.end(), expression.substr(i - 1, 2)) != op_diff.end())
                            return false;
                    }
                }

                // special for operator AND OR NOT
                if (expression[i] == 'A' || expression[i] == 'N') {
                    if (i != expression.length()-3) {
                        if (find(op_diff.begin(), op_diff.end(), expression.substr(i, 3)) != op_diff.end())
                            return false;
                    }
                }
                if (expression[i] == 'O') {
                    if (i != expression.length()-2) {
                        if (find(op_diff.begin(), op_diff.end(), expression.substr(i, 2)) != op_diff.end())
                            return false;
                    }
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
                    if (stackOfParenthesis.empty()) { // we are out of parenthesis
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


    string infixToPostfix(string infix){
        stack<char> s;
        string postfix;
        int size = infix.length();
        int weight;
        int i = 0;
        int k = 0;
        char ch;

        // iterate over the infix expression
        while (i < size) {

            ch = infix[i];
            if (ch == '(') {
                // simply push the opening parenthesis
                s.push(ch);
                i++;
                continue;
            }
            if (ch == ')') {
                // if we see a closing parenthesis,
                // pop of all the elements and append it to
                // the postfix expression till we encounter
                // a opening parenthesis
                while (!s.empty() && s.top() != '(') {

                    // if character is an operator, we add a space before
                    if(getWeightOperator(s.top()) > 0){
                        postfix.push_back(' ');
                    }
                    postfix.push_back(s.top());
                    k++;
                    s.pop();

                }
                // pop off the opening parenthesis also
                if (!s.empty()) {
                    s.pop();
                }
                i++;
                continue;
            }
            weight = getWeightOperator(ch);

            if (weight == 0) {
                // we saw an operand
                // simply append it to postfix expression
                postfix.push_back(ch);
                k++;
            }
            else {
                // we saw an operator
                if (s.empty()) {
                    // simply push the operator onto stack if
                    // stack is empty

                    s.push(ch);
                }
                else {
                    // pop of all the operators from the stack and
                    // append it to the postfix expression till we
                    // see an operator with a lower precedence that
                    // the current operator
                    while (!s.empty() && s.top() != '(' &&
                           weight <= getWeightOperator(s.top())) {

                        postfix.push_back(' ');
                        postfix.push_back(s.top());
                        k++;
                        s.pop();

                    }
                    // push the current operator onto stack
                    s.push(ch);
                }
            }
            i++;
        }
        // pop of the remaining operators present in the stack
        // and append it to postfix expression
        while (!s.empty()) {
            postfix.push_back(' ');
            postfix.push_back(s.top());
            s.pop();
        }

        return postfix;
    }

    ExpressionLiteral* operator+(ExpressionLiteral &l) const {
        return new ExpressionLiteral(constructNewExpression("+", l));
    }

    ExpressionLiteral* operator-(ExpressionLiteral &l) const {
        return new ExpressionLiteral(constructNewExpression("-", l));
    }

    ExpressionLiteral* operator*(ExpressionLiteral &l) const {
        return new ExpressionLiteral(constructNewExpression("*", l));
    }

};


#endif //TESTLO21CLION_EXPRESSIONLITERAL_H
