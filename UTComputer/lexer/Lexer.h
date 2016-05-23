//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_LEXER_H
#define TESTLO21CLION_LEXER_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../exceptions/UTComputerException.h"

using namespace std;

enum modes { UnLocked, ExpressionLocked, ProgLocked, LitteralLocked };

class LexerUTComputer {


    bool findInArray(const char c, const vector<char> array){
        bool found = false;
        int i = 0;
        while(!found && i < array.size()){
            found = (array[i] == c);
            i++;
        }
        return found;
    }



public:


    LexerUTComputer() { }
    virtual ~LexerUTComputer() { }

    static const vector<char> operatorTypes;
    static const vector<char> separatorTypes;
    static const char progSeparatorStart;
    static const char progSeparatorStop;
    static const char expressionSeparator;


    vector<string> split(const string &s){

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


};


#endif //TESTLO21CLION_LEXER_H

