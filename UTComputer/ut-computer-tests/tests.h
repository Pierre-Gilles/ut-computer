//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_TESTS_H
#define TESTLO21CLION_TESTS_H

#include <iostream>
#include <vector>
#include "../exceptions/UTComputerException.h"
#include "assert.h"
#include "../lexer/Lexer.h"
#include "../literals/NumericLiteral.h"
#include "../literals/ComplexLiteral.h"
#include "../literals/StringLiteral.h"
#include "../literals/ExpressionLiteral.h"
#include "../operators/Operator.h"
#include "../operators/PlusOperator.h"



void testLexer();
void testNumericLiteral();



void testOperatorClass();
void testPlusOpertor();

inline void runtests() {
    testLexer();
    //testNumericLiteral();
    //testPlusOpertor();
}
#endif //TESTLO21CLION_TESTS_H
