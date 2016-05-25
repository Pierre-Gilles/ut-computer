//
// Created by Raphael on 13/05/2016.
//

#ifndef TESTLO21CLION_LITERALFACTORY_H
#define TESTLO21CLION_LITERALFACTORY_H
#include "Literal.h"

using namespace std;

typedef Literal* (*createFunction)(const string& s);


class LiteralFactory {
    createFunction *tabStaticCreateFunctions;
    int nb_literals;

public:
    LiteralFactory() {
//        nb_literals = 7;
//        tabStaticCreateFunctions = new createFunction[nb_literals];
//        tabStaticCreateFunctions[0] = &IntegerLiteral::create;
//        tabStaticCreateFunctions[1] = &RealLiteral::create;
//        tabStaticCreateFunctions[2] = nullptr;
//        tabStaticCreateFunctions[3] = nullptr;
//        tabStaticCreateFunctions[4] = nullptr;
//        tabStaticCreateFunctions[5] = nullptr;
//        tabStaticCreateFunctions[6] = nullptr;

    }

//    Literal* createLiteral(const string& s) {
//        Literal* tmp = nullptr;
//        for (int i=0; i<nb_literals; i++) {
//
//            if (tabStaticCreateFunctions[i] != nullptr) {
//                tmp = tabStaticCreateFunctions[i](s);
//                if (tmp != nullptr) {
//                    return tmp;
//                }
//            }
//        }
//        return tmp;
//    }
};


#endif //TESTLO21CLION_LITERALFACTORY_H
