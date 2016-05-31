#ifndef UTCOMPUTER_PROGRAMLITERAL_H
#define UTCOMPUTER_PROGRAMLITERAL_H


#include "StringLiteral.h"

class ProgramLiteral : public StringLiteral {

    const static string programRegex;
public:

    ProgramLiteral(const string &value) : StringLiteral(value) { }
    ProgramLiteral(const ProgramLiteral &l) : StringLiteral(l.value) { }
    virtual ~ProgramLiteral() { }

    virtual string toString() const override {
        return value;
    }


    static const string &getProgramRegex() {
        return programRegex;
    }
};


#endif //UTCOMPUTER_PROGRAMLITERAL_H
