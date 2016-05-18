//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_STRINGLITERAL_H
#define TESTLO21CLION_STRINGLITERAL_H

#include "Literal.h"

class StringLiteral : public Literal {
protected:
    string value;
public:


    StringLiteral(const string &value) : value(value) { }

    virtual ~StringLiteral() { }


    const string &getValue() const {
        return value;
    }

    void setValue(const string &val) {
        value = val;
    }

    virtual string toString() override {
        return value;
    }


};


#endif //TESTLO21CLION_STRINGLITERAL_H
