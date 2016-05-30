#include "Lexer.h"

using namespace std;


const vector<char> LexerUTComputer::operatorTypes = {'+', '-', '*', '/', '$'};
const vector<char> LexerUTComputer::separatorTypes = {' ', '\t'};
const char LexerUTComputer::progSeparatorStart = '[';
const char LexerUTComputer::progSeparatorStop = ']';
const char LexerUTComputer::expressionSeparator = '\'';


//
const vector<string> LexerUTComputer::operatorEval = { "+", "-", "/", "=", "*", "DIV", "MOD", "NEG", "NUM", "DEN", "$", "RE", "IM", "END", "OR", "NOT"};





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
vector<string> LexerUTComputer::infixTokeniser(const string &s) const {

    vector<string> elems;
    regex r("([A-Z]+|[A-Z][0-9A-Z]*|[0-9.$]+|[\\+\\-\\*\\/\\(\\),<>=]|<=|>=|\\!=)");

    for (sregex_token_iterator it = sregex_token_iterator(s.begin(), s.end(), r, 1); it != sregex_token_iterator(); ++it)
        elems.push_back((string)*it);

    return elems;

}

/*vector<string> LexerUTComputer::infixTokeniser2(const string &s) const {

    // result will contain the array of token
    vector<string> result;

    string tmp = "";
    evalModes actualMode = UnLocked;

    // foreach character in string
    for (int i=0; i<s.length(); i++) {

        switch(actualMode){

            case UnLocked:

                // if the character is an operator
                if(isalpha(s[i])) {
                    tmp = s[i];
                    actualMode = operatorLocked;
                }

                 else if(s[i] == '(' || s[i] == ')'){
                    tmp = s[i];
                    result.push_back(tmp);
                    tmp = "";
                }


                else {
                    actualMode = LitteralLocked;
                    tmp.insert(tmp.length(), 1, s[i]);
                }


                break;

            case operatorLocked:

                bool foundParenthesis = s[i] == '(' || s[i] == ')';
                bool foundNumber = isdigit(s[i]);

                if(foundParenthesis){
                    result.push_back(tmp);
                    tmp = s[i];
                    result.push_back(tmp);
                    tmp = "";
                }

                else if(foundNumber){
                    result.push_back(tmp);
                    tmp = s[i];
                    actualMode = LitteralLocked;
                }

                else {
                    tmp.insert(tmp.length(), 1, s[i]);
                }


                break;

            case LitteralLocked:

                if(isdigit(s[i])){
                    tmp.insert(tmp.length(), 1, s[i]);
                } else {
                    result.push_back(tmp);
                    tmp = "";
                    actualMode = UnLocked;
                }
        }
    }

    if(actualMode == LitteralLocked){
        result.push_back(tmp);
    }

    return result;
}*/
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