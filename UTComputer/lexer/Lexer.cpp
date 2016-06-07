#include "Lexer.h"

using namespace std;




// ===============================================================================================================
// ======================                        Class main services                    ==========================
// ===============================================================================================================


vector<string> LexerUTComputer::tokenize(const string &s) const {

    vector<string> elems;
    regex r("('.[^']*'|\\[.*\\]|[A-Z]+|[A-Z][0-9A-Z]*|[0-9.$]+|[\\+\\-\\*\\/\\(\\),<>=]|<=|>=|\\!=)");

    for (sregex_token_iterator it = sregex_token_iterator(s.begin(), s.end(), r, 1); it != sregex_token_iterator(); ++it)
        elems.push_back((string)*it);

    return elems;

}

vector<string> LexerUTComputer::tokenizeInfixToPostfix(const string &s) const{
    vector<string> elems = tokenize(s);
    return infixToPostfix(elems);
}


vector<string> LexerUTComputer::infixToPostfix(const vector<string> infix) const {

    stack<string> s;
    vector<string> postfix;
    unsigned long int size = infix.size();
    int weight;
    int i = 0;
    int k = 0;
    string ch;

    // iterate over the infix expression
    while (i < size) {

        ch = infix[i];
        if (ch == "(") {
            // simply push the opening parenthesis
            s.push(ch);
            i++;
            continue;
        }
        if (ch == ")") {
            // if we see a closing parenthesis,
            // pop of all the elements and append it to
            // the postfix expression till we encounter
            // a opening parenthesis
            while (!s.empty() && s.top() != "(") {

                if(s.top() != ",")
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
                while (!s.empty() && s.top() != "(" &&
                       weight <= getWeightOperator(s.top())) {

                    if(s.top() != ",")
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

        if(s.top() != ",")
            postfix.push_back(s.top());
        s.pop();
    }

    return postfix;

}

// ===============================================================================================================




// ===============================================================================================================
// ======================                       Useful class functions                  ==========================
// ===============================================================================================================

bool LexerUTComputer::isOperator(const string s) const{
    int weight = getWeightOperator(s);
    return (weight == 6 || weight == 4 || weight == 3 || weight == 2);
}

bool LexerUTComputer::operatorWeightExists(const string &key) const {
    unordered_map<string, int>::const_iterator found = operator_weight_map.find(key);
    return !(found == operator_weight_map.cend());
}

bool LexerUTComputer::addOperatorWeight(Operator *o) {
    if (operatorWeightExists(o->getKey()))
        throw UTComputerException("Error in Lexer::addOperatorWeigth : operator key already exists.");

    pair<string, int> operator_weigth (o->getKey(), o->getPriority());
    operator_weight_map.insert(operator_weigth);
    return true;
}


int LexerUTComputer::getWeightOperator(const string s) const {

    if (s == ",") return 1;
    else if (operatorWeightExists(s)) return operator_weight_map.at(s);
    else return 0;
}
// ===============================================================================================================
