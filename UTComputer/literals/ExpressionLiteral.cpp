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
// public to test it
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

int ExpressionLiteral::getWeightOperator(const char ch) const {
    switch (ch) {
        case '$': return 3;
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

string ExpressionLiteral::infixToPostfix(const string infix) const {
    stack<char> s;
    string postfix;
    unsigned long int size = infix.length();
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

// ===============================================================================================================