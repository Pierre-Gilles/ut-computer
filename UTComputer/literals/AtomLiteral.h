#ifndef UTCOMPUTER_ATOMLITERAL_H
#define UTCOMPUTER_ATOMLITERAL_H


#include "StringLiteral.h"

class AtomLiteral : public StringLiteral {

    const static string atomRegex;

public:
    AtomLiteral(const string &value) : StringLiteral(value) { }

    virtual ~AtomLiteral() { }


    static const string &getAtomRegex() {
        return atomRegex;
    }
};


#endif //UTCOMPUTER_ATOMLITERAL_H
