//
// Created by Raphael on 15/05/2016.
//

#include "Lexer.h"
#include "assert.h"

using namespace std;


const vector<char> LexerUTComputer::operatorTypes = {'+', '-', '*', '/', '$'};
const vector<char> LexerUTComputer::separatorTypes = {' ', '\t'};
const char LexerUTComputer::progSeparatorStart = '[';
const char LexerUTComputer::progSeparatorStop = ']';
const char LexerUTComputer::expressionSeparator = '\'';


