#ifndef TESTLO21CLION_LITERALFACTORY_H
#define TESTLO21CLION_LITERALFACTORY_H
#include "ComplexLiteral.h"
#include "ProgramLiteral.h"
#include "ExpressionLiteral.h"
#include "AtomLiteral.h"
#include <regex>

using namespace std;



class LiteralFactory {

public:
    LiteralFactory() { }
    virtual ~LiteralFactory() { }


    shared_ptr<Literal> createLiteral(const string &s);

};


#endif //TESTLO21CLION_LITERALFACTORY_H
