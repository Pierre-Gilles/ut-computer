//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_LEXER_H
#define TESTLO21CLION_LEXER_H
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class LexerUTComputer {



public:


    LexerUTComputer() { }
    virtual ~LexerUTComputer() { }

    vector<string> split(const string &s) {
        string::const_iterator it, it_backup;
        vector<string> result;

        string tmp = "";
        for (it = s.cbegin(); it != s.cend(); ++it) {
            it_backup = it;
            if (it == s.cend()-1) { // end of string
                if (*(it-1) == ' ') { // if previous character is whitespace then proceed as usual
                    tmp += *it;
                    result.push_back(tmp);
                    tmp = "";
                }
                /* if last character is a "single character operator" and previous character is different
                    then whitespace, we must add to the vector what was before the operator then add
                    the operator */
                else if (*it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == '$') {
                    result.push_back(tmp);
                    tmp = *it;
                    result.push_back(tmp);
                }
                /* here we are at the end but previous character is different from whitespace and las character
                 * is not an operator + - / * or $ */
                else {
                    tmp += *it;
                    result.push_back(tmp);
                    tmp = "";
                }
            }
            else if (*it == '\'') {
                do {
                    tmp += *it_backup;
                    cout << tmp << endl;
                    ++it_backup;
                } while (*it_backup != '\'');
                it = it_backup;
            }
            else if (*it != ' ') {
                tmp += *it;
            }
            else { // whitespace
                result.push_back(tmp);
                tmp = "";
            }
        }
        return result;
    }


};


#endif //TESTLO21CLION_LEXER_H

