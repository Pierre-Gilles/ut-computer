/**
 * \file LiteralFactory.h
 * \brief File containing the declaration of the LiteralFactory class.
 */
#ifndef TESTLO21CLION_LITERALFACTORY_H
#define TESTLO21CLION_LITERALFACTORY_H
#include "ComplexLiteral.h"
#include "ProgramLiteral.h"
#include "ExpressionLiteral.h"
#include "AtomLiteral.h"
#include <regex>

using namespace std;


/**
 * \class LiteralFactory
 * \brief Class used to create specifics literals (Program, Complex, ...)
 */
class LiteralFactory {

public:
    LiteralFactory() { }
    virtual ~LiteralFactory() { }

    /**
     * \fn shared_ptr<Literal> createLiteral(const string &s)
     * \brief Method that create a Literal
     * \param[in] s : string containing the future value of the literal
     * \return A new shared_ptr<Literal> containing the right type of Literal
     */
    shared_ptr<Literal> createLiteral(const string &s);

};


#endif //TESTLO21CLION_LITERALFACTORY_H
