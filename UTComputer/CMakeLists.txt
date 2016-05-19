cmake_minimum_required(VERSION 3.5)
project(UTComputer)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(gtest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(/usr/local/include)

# If you're on mac os and that build fail, try uncomment the following lines
#if (APPLE)
#    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE=1)
#    add_definitions(-D__GLIBCXX__)
#endif (APPLE)

set(SOURCE_FILES
        literals/LiteralFactory.cpp
        literals/LiteralFactory.h
        literals/Literal.cpp
        literals/Literal.h
        operators/OperatorManager.cpp
        operators/OperatorManager.h
        lexer/Lexer.cpp
        lexer/Lexer.h
        stack/StackUTComputer.cpp
        stack/StackUTComputer.h
        operators/Operator.cpp
        operators/Operator.h
        operators/PlusOperator.cpp
        operators/PlusOperator.h
        literals/ComplexLiteral.cpp
        literals/ComplexLiteral.h
        literals/NumericLiteral.cpp
        literals/NumericLiteral.h
        literals/ExpressionLiteral.cpp
        literals/ExpressionLiteral.h
        literals/StringLiteral.cpp
        literals/StringLiteral.h
        exceptions/UTComputerException.cpp
        exceptions/UTComputerException.h)

add_executable(ut-computer main.cpp ${SOURCE_FILES})

# Tests
set(TEST_FILES
        ut-computer-tests/operators-tests/tests_PlusOperator.cpp
        ut-computer-tests/literals-tests/tests_ExpressionLiteral.cpp)


add_executable(ut-computer-tests ut-computer-tests/main.cpp ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(ut-computer-tests /usr/local/lib/libgtest.a)
#target_link_libraries(ut-computer-tests ${GTEST_LIBRARIES} pthread) // no need but keeping it just in case
