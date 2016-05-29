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
        operators/Operator.cpp
        operators/Operator.h
        operators/OperatorManager.cpp
        operators/OperatorManager.h
        operators/StackOperator.cpp
        operators/StackOperator.h
        operators/CalculationOperator.cpp
        operators/CalculationOperator.h
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
        operators/logical_operators/OperatorSuperior.cpp
        operators/logical_operators/OperatorSuperior.h
        operators/logical_operators/OperatorSuperiorEqual.cpp
        operators/logical_operators/OperatorSuperiorEqual.h
        operators/logical_operators/OperatorEqual.cpp
        operators/logical_operators/OperatorEqual.h
        operators/logical_operators/OperatorDifferent.cpp
        operators/logical_operators/OperatorDifferent.h
        operators/logical_operators/OperatorAnd.cpp
        operators/logical_operators/OperatorAnd.h
        operators/logical_operators/OperatorOr.cpp
        operators/logical_operators/OperatorOr.h
        operators/logical_operators/OperatorNot.cpp
        operators/logical_operators/OperatorNot.h
        operators/classic_operators/OperatorIntegerDivision.cpp
        operators/classic_operators/OperatorIntegerDivision.h
        operators/classic_operators/OperatorModulo.cpp
        operators/classic_operators/OperatorModulo.h
        operators/classic_operators/OperatorNeg.cpp
        operators/classic_operators/OperatorNeg.h
        operators/rational_operators/OperatorNumerator.cpp
        operators/rational_operators/OperatorNumerator.h
        operators/rational_operators/OperatorDenominator.cpp
        operators/rational_operators/OperatorDenominator.h
        operators/complex_operators/OperatorRE.cpp
        operators/complex_operators/OperatorRE.h
        operators/complex_operators/OperatorIM.cpp
        operators/complex_operators/OperatorIM.h
        operators/complex_operators/OperatorDollar.cpp
        operators/complex_operators/OperatorDollar.h
        operators/stack_operators/OperatorDUP.cpp
        operators/stack_operators/OperatorDUP.h
        operators/stack_operators/OperatorDROP.cpp
        operators/stack_operators/OperatorDROP.h
        operators/stack_operators/OperatorSWAP.cpp
        operators/stack_operators/OperatorSWAP.h
        operators/stack_operators/OperatorLASTOP.cpp
        operators/stack_operators/OperatorLASTOP.h
        operators/stack_operators/OperatorLASTARGS.cpp
        operators/stack_operators/OperatorLASTARGS.h
        operators/stack_operators/OperatorCLEAR.cpp
        operators/stack_operators/OperatorCLEAR.h
        operators/stack_operators/OperatorUNDO.cpp
        operators/stack_operators/OperatorUNDO.h
        operators/stack_operators/OperatorREDO.cpp
        operators/stack_operators/OperatorREDO.h
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
        ut_computer_tests/operators_tests/logical_operators_tests/tests_OperatorInferiorEqual.cpp
        ut_computer_tests/operators_tests/logical_operators_tests/tests_OperatorAnd.cpp
        ut_computer_tests/operators_tests/logical_operators_tests/tests_OperatorOr.cpp
        ut_computer_tests/operators_tests/logical_operators_tests/tests_OperatorNot.cpp
        ut_computer_tests/operators_tests/logical_operators_tests/tests_OperatorSuperior.cpp
        ut_computer_tests/operators_tests/logical_operators_tests/tests_OperatorSuperiorEqual.cpp
        ut_computer_tests/operators_tests/logical_operators_tests/tests_OperatorEqual.cpp
        ut_computer_tests/operators_tests/logical_operators_tests/tests_OperatorDifferent.cpp
        ut_computer_tests/operators_tests/classic_operators_tests/tests_OperatorNeg.cpp
        ut_computer_tests/operators_tests/classic_operators_tests/tests_OperatorMod.cpp
        ut_computer_tests/operators_tests/classic_operators_tests/tests_OperatorIntegerDivision.cpp
        ut_computer_tests/operators_tests/rational_operators_tests/tests_OperatorNumerator.cpp
        ut_computer_tests/operators_tests/rational_operators_tests/tests_OperatorDenominator.cpp
        ut_computer_tests/operators_tests/complex_operators_tests/tests_OperatorDollar.cpp
        ut_computer_tests/operators_tests/complex_operators_tests/tests_OperatorRE.cpp
        ut_computer_tests/operators_tests/complex_operators_tests/tests_OperatorIM.cpp
        ut_computer_tests/operators_tests/stack_operators_tests/tests_OperatorDUP.cpp
        ut_computer_tests/operators_tests/stack_operators_tests/tests_OperatorCLEAR.cpp ut_computer_tests/operators_tests/stack_operators_tests/tests_OperatorDROP.cpp ut_computer_tests/operators_tests/stack_operators_tests/tests_OperatorSWAP.cpp ut_computer_tests/operators_tests/stack_operators_tests/tests_OperatorLASTOP.cpp ut_computer_tests/operators_tests/stack_operators_tests/tests_OperatorLASTARGS.cpp)


add_executable(ut-computer-tests ut_computer_tests/main.cpp ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(ut-computer-tests /usr/local/lib/libgtest.a)
#target_link_libraries(ut_computer_tests ${GTEST_LIBRARIES} pthread) // no need but keeping it just in case
