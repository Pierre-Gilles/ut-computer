#include "LiteralFactory.h"


shared_ptr<Literal> LiteralFactory::createLiteral(const string &s) {
    if (s == "") {
        throw UTComputerException("Error LiteralFactory::createLiteral : token should not be empty)");
    }

    regex regexNumeric = regex(NumericLiteral::getNumericRegex());
    regex regexExpression = regex(ExpressionLiteral::getExpressionRegex());
    regex regexProgram = regex(ProgramLiteral::getProgramRegex());

    if (regex_match(s, regexNumeric)) {
        return shared_ptr<ComplexLiteral>(new ComplexLiteral(s));
    }

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