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


    shared_ptr<Literal> createLiteral(const string &s) {
        regex regexNumeric = regex(NumericLiteral::getNumericRegex());
        regex regexExpression = regex(ExpressionLiteral::getExpressionRegex());
        regex regexProgram = regex(ProgramLiteral::getProgramRegex());

        if (regex_match(s, regexNumeric)) {
            return shared_ptr<ComplexLiteral>(new ComplexLiteral(s));
        }

        /*
         * If it's an Expression.
         * Important : regex fails if there is \n in expression, but there is no good reason for such character to
         * be in an expression
         */
        if (regex_match(s, regexExpression)) {
            string tmp = s.substr(1, s.length()-2); // we want all the string without the first and last character
            return shared_ptr<ExpressionLiteral>(new ExpressionLiteral(tmp));
        }

        if (regex_match(s, regexProgram)) {
            string tmp = s.substr(1, s.length()-2); // we want all the string without the first and last character
            return shared_ptr<ProgramLiteral>(new ProgramLiteral(tmp));
        }

        // Here we didn't return anything so the string "s" is invalid (error in syntax)
        throw UTComputerException("Error LiteralFactory::createLiteral : syntax error for the token \"" + s + "\"");
    }

};


#endif //TESTLO21CLION_LITERALFACTORY_H
