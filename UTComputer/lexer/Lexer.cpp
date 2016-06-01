#include "Lexer.h"

using namespace std;


const vector<char> LexerUTComputer::operatorTypes = {'+', '-', '*', '/', '$'};
const vector<char> LexerUTComputer::separatorTypes = {' ', '\t'};
const char LexerUTComputer::progSeparatorStart = '[';
const char LexerUTComputer::progSeparatorStop = ']';
const char LexerUTComputer::expressionSeparator = '\'';


const vector<string> LexerUTComputer::operatorEval = { "DIV", "MOD", "NEG", "NUM", "DEN", "RE", "IM", "END", "OR", "NOT"};





// ===============================================================================================================
// ======================                        Class main services                    ==========================
// ===============================================================================================================
vector<string> LexerUTComputer::split(const string &s) const {

    // result will contain the array of token
    vector<string> result;

    string tmp = "";
    modes actualMode = UnLocked;

    // foreach character in string
    for (int i=0; i<s.length(); i++) {

        switch(actualMode){

            case UnLocked:

                // if the character is an operator
                if(findInArray(s[i], operatorTypes)) {
                    tmp = s[i];
                    result.push_back(tmp);
                    tmp = "";
                }

                    // if the character is a progSeparator
                else if (s[i] == progSeparatorStart){
                    actualMode = ProgLocked;
                }

                    // if character is an expression separator
                else if(s[i] == expressionSeparator){
                    tmp = s[i];
                    actualMode = ExpressionLocked;
                }

                    // if character is a separator ( space, tab )
                else if (findInArray(s[i], separatorTypes)) {
                    // do nothing for the moment
                }
                else {
                    actualMode = LitteralLocked;
                    tmp.insert(tmp.length(), 1, s[i]);
                }


                break;


            case ProgLocked:

                if(s[i] == progSeparatorStop){
                    result.push_back(tmp);
                    tmp = "";
                    actualMode = UnLocked;
                } else {
                    tmp.insert(tmp.length(), 1, s[i]);
                }

                break;

            case ExpressionLocked:

                tmp.insert(tmp.length(), 1, s[i]);

                if(s[i] == expressionSeparator){
                    result.push_back(tmp);
                    tmp = "";
                    actualMode = UnLocked;
                }

                break;


            case LitteralLocked:

                if(findInArray(s[i], separatorTypes)){
                    result.push_back(tmp);
                    tmp = "";
                    actualMode = UnLocked;
                } else {
                    tmp.insert(tmp.length(), 1, s[i]);
                }

        }
    }

    if(actualMode == LitteralLocked){
        result.push_back(tmp);
    } else if(actualMode == ExpressionLocked){
        throw UTComputerException("LexerUTComputer::split - Missing end of expression");
    } else if(actualMode == ProgLocked ){
        throw UTComputerException("LexerUTComputer::split - Missing end of program");
    }
    return result;
}
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


int LexerUTComputer::getWeightOperator(const string s) const {

    if(s == "SIN" || s == "COS" || s == "NUM" || s == "NEG" || s == "DEN" || s == "RE" || s == "IM" ) return 6;
    if(s == "$" ) return 5;
    if(s == "/" || s == "*" || s == "DIV" || s == "MOD" ) return 4;
    if(s == "+" || s == "-") return 3;

    if(s == "OR" || s == "AND" || s == "NOT") return 2;
    if(s == ",") return 1;

    return 0;
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
bool LexerUTComputer::findInArray(const char c, const vector<char> array) const {
    bool found = false;
    int i = 0;
    while(!found && i < array.size()){
        found = (array[i] == c);
        i++;
    }
    return found;
}

bool LexerUTComputer::findInArrayString(const string c, const vector<string> array) const {
    bool found = false;
    int i = 0;
    while(!found && i < array.size()){
        found = (array[i] == c);
        i++;
    }
    return found;
}
// ===============================================================================================================