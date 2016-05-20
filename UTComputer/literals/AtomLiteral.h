#ifndef UTCOMPUTER_ATOMLITERAL_H
#define UTCOMPUTER_ATOMLITERAL_H


#include "StringLiteral.h"

class AtomLiteral : public StringLiteral {

public:
    AtomLiteral(const string &value) : StringLiteral(value) { }

    virtual ~AtomLiteral() { }
};


#endif //UTCOMPUTER_ATOMLITERAL_H
