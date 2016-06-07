#include "ProgramLiteral.h"



const string ProgramLiteral::programRegex = "^\\[.*\\]$";




string ProgramLiteral::toString() const {
    /* replace all \t or \n by spaces for the toString method (use the getValue() to get the program with \t and \n */
    string tmp = value;
    replace(tmp.begin(), tmp.end(), '\t', ' ');
    replace(tmp.begin(), tmp.end(), '\n', ' ');
    return "[" + tmp + "]";
}