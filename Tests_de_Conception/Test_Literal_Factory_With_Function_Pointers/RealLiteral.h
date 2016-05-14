//
// Created by Raphael on 13/05/2016.
//

#ifndef TESTLO21CLION_REALLITERAL_H
#define TESTLO21CLION_REALLITERAL_H



#include <iostream>
#include <string>
#include "Literal.h"
// #include <stdlib.h>

using namespace std;

class RealLiteral : public Literal {
    static const string key;
    double value;

public:
    RealLiteral(double v) : value(v){}
    RealLiteral(const string& s) {
        value = (double)stoi(s);
    }

    static Literal* create(const string& s) {
        if (s == key) {
//            l = new IntegerLiteral(s);
//            l->print_literal();
            return new RealLiteral(s);
        }
        return nullptr;
    }

    void print_literal() {
        cout << "RealLit : "<<value << endl;
    }

};


#endif //TESTLO21CLION_REALLITERAL_H
