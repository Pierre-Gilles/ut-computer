//
// Created by Raphael on 13/05/2016.
//

#ifndef TESTLO21CLION_INTEGERLITERAL_H
#define TESTLO21CLION_INTEGERLITERAL_H

#include <iostream>
#include <string>
#include "Literal.h"
// #include <stdlib.h>

using namespace std;

class IntegerLiteral : public Literal {
    static const string key;
    int value;

public:
    IntegerLiteral(int v) : value(v){}
    IntegerLiteral(const string& s) {
            value = stoi(s);
    }

    static Literal* create(const string& s) {
        if (s == key) {
//            l = new IntegerLiteral(s);
//            l->print_literal();
            return new IntegerLiteral(s);
        }
        return nullptr;
    }

    void print_literal() {
        cout << "IntegerLit : "<<value << endl;
    }
};


#endif //TESTLO21CLION_INTEGERLITERAL_H
