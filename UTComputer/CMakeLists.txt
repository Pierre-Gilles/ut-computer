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
        exceptions/UTComputerException.cpp
        exceptions/UTComputerException.h
        lexer/Lexer.cpp
        lexer/Lexer.h
        stack/StackUTComputer.cpp
        stack/StackUTComputer.h
        literals/LiteralFactory.cpp
        literals/LiteralFactory.h
        literals/Literal.cpp
        literals/Literal.h
        literals/NumericLiteral.cpp
        literals/NumericLiteral.h
        literals/ComplexLiteral.cpp
        literals/ComplexLiteral.h
        literals/StringLiteral.cpp
        literals/StringLiteral.h
        literals/ExpressionLiteral.cpp
        literals/ExpressionLiteral.h
        literals/ProgramLiteral.cpp
        literals/ProgramLiteral.h
        literals/AtomLiteral.cpp
        literals/AtomLiteral.h
        operators/OperatorManager.cpp
        operators/OperatorManager.h
        operators/Operator.cpp
        operators/Operator.h
        operators/classic_operators/OperatorPlus.cpp
        operators/classic_operators/OperatorPlus.h
        operators/classic_operators/OperatorMinus.cpp
        operators/classic_operators/OperatorMinus.h
        operators/classic_operators/OperatorMultiplication.cpp
        operators/classic_operators/OperatorMultiplication.h
        operators/classic_operators/OperatorDivision.cpp
        operators/classic_operators/OperatorDivision.h
        operators/logical_operators/OperatorInferior.cpp
        operators/logical_operators/OperatorInferior.h
        operators/logical_operators/OperatorInferiorEqual.cpp
        operators/logical_operators/OperatorInferiorEqual.h
        )


add_executable(ut-computer main.cpp ${SOURCE_FILES})

# Tests
set(TEST_FILES
        ut_computer_tests/lexer_tests/tests_Lexer.cpp.cpp
        ut_computer_tests/stack_tests/tests_StackUTComputer.cpp
        ut_computer_tests/literals-tests/tests_ExpressionLiteral.cpp
        ut_computer_tests/operators_tests/tests_Operator.cpp
        ut_computer_tests/operators_tests/tests_Operator_Manager.cpp
        ut_computer_tests/operators_tests/classic_operators_tests/tests_OperatorPlus.cpp
        ut_computer_tests/operators_tests/classic_operators_tests/tests_OperatorMinus.cpp
        ut_computer_tests/operators_tests/classic_operators_tests/tests_OperatorMultiplication.cpp
        ut_computer_tests/operators_tests/classic_operators_tests/tests_OperatorDivision.cpp
        ut_computer_tests/operators_tests/logical_operators_tests/tests_OperatorInferior.cpp
        )


add_executable(ut-computer-tests ut_computer_tests/main.cpp ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(ut-computer-tests /usr/local/lib/libgtest.a)
#target_link_libraries(ut_computer_tests ${GTEST_LIBRARIES} pthread) // no need but keeping it just in case
