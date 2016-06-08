#include "ExpressionLiteral.h"



const string ExpressionLiteral::expressionRegex = "^'.*'$";

// ===============================================================================================================
// ======================                         Override Methods                      ==========================
// ===============================================================================================================
string ExpressionLiteral::toString() const {
    return "'" + value + "'";
}
// ===============================================================================================================






// ===============================================================================================================
// ======================                       Operators overload                      ==========================
// ===============================================================================================================
shared_ptr<ExpressionLiteral> ExpressionLiteral::operator+(const ExpressionLiteral &l) const {
    return shared_ptr<ExpressionLiteral>(new ExpressionLiteral(constructNewExpression("+", l)));
}

shared_ptr<ExpressionLiteral> ExpressionLiteral::operator-(const ExpressionLiteral &l) const {
    return shared_ptr<ExpressionLiteral>(new ExpressionLiteral(constructNewExpression("-", l)));
}

shared_ptr<ExpressionLiteral> ExpressionLiteral::operator*(const ExpressionLiteral &l) const {
    return shared_ptr<ExpressionLiteral>(new ExpressionLiteral(constructNewExpression("*", l)));
}

shared_ptr<ExpressionLiteral> ExpressionLiteral::operator/(const ExpressionLiteral &l) const {
    return shared_ptr<ExpressionLiteral>(new ExpressionLiteral(constructNewExpression("/", l)));
}
// ===============================================================================================================








// ===============================================================================================================
// ======================                       Useful class functions                  ==========================
// ===============================================================================================================
bool ExpressionLiteral::hasSamePriority(const string &op, const string &expression) const {
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

string ExpressionLiteral::constructNewExpression(const string &op, const ExpressionLiteral &l) const {
    string newExpression = "";

    if ( hasSamePriority(op, toString()) ) {
        newExpression.insert(0, getValue());
    }
    else {
        newExpression.insert(0, "(" + getValue() + ")");
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



// ===============================================================================================================