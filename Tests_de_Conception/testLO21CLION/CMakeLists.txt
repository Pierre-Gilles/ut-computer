cmake_minimum_required(VERSION 3.5)
project(testLO21CLION)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp literals/LiteralFactory.cpp literals/LiteralFactory.h literals/Literal.cpp literals/Literal.h operators/OperatorManager.cpp operators/OperatorManager.h lexer/Lexer.cpp lexer/Lexer.h stack/StackUTComputer.cpp stack/StackUTComputer.h operators/Operator.cpp operators/Operator.h operators/PlusOperator.cpp operators/PlusOperator.h literals/ComplexLiteral.cpp literals/ComplexLiteral.h literals/NumericLiteral.cpp literals/NumericLiteral.h tests.cpp tests.h literals/ExpressionLiteral.cpp literals/ExpressionLiteral.h literals/StringLiteral.cpp literals/StringLiteral.h exceptions/UTComputerException.cpp exceptions/UTComputerException.h)
add_executable(testLO21CLION ${SOURCE_FILES})