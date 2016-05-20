#ifndef UTCOMPUTER_PROGRAMLITERAL_H
#define UTCOMPUTER_PROGRAMLITERAL_H


#include "StringLiteral.h"

class ProgramLiteral : public StringLiteral {

public:

    ProgramLiteral(const string &value) : StringLiteral(value) { }


    virtual ~ProgramLiteral() { }
};


#endif //UTCOMPUTER_PROGRAMLITERAL_H
