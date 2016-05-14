cmake_minimum_required(VERSION 3.5)
project(testLO21CLION)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp IntegerLiteral.cpp IntegerLiteral.h LiteralFactory.cpp LiteralFactory.h Literal.cpp Literal.h RealLiteral.cpp RealLiteral.h)
add_executable(testLO21CLION ${SOURCE_FILES})