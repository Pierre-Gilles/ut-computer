#-------------------------------------------------
#
# Project created by QtCreator 2016-06-04T10:40:05
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ut-computer
TEMPLATE = app


SOURCES += main.cpp\
        views/mainwindow.cpp \
    exceptions/UTComputerException.cpp \
    lexer/Lexer.cpp \
    literals/AtomLiteral.cpp \
    literals/ComplexLiteral.cpp \
    literals/ExpressionLiteral.cpp \
    literals/Literal.cpp \
    literals/LiteralFactory.cpp \
    literals/NumericLiteral.cpp \
    literals/ProgramLiteral.cpp \
    literals/StringLiteral.cpp \
    operators/classic_operators/OperatorDivision.cpp \
    operators/classic_operators/OperatorIntegerDivision.cpp \
    operators/classic_operators/OperatorMinus.cpp \
    operators/classic_operators/OperatorModulo.cpp \
    operators/classic_operators/OperatorMultiplication.cpp \
    operators/classic_operators/OperatorNeg.cpp \
    operators/classic_operators/OperatorPlus.cpp \
    operators/complex_operators/OperatorDollar.cpp \
    operators/complex_operators/OperatorIM.cpp \
    operators/complex_operators/OperatorRE.cpp \
    operators/logical_operators/OperatorAnd.cpp \
    operators/logical_operators/OperatorDifferent.cpp \
    operators/logical_operators/OperatorEqual.cpp \
    operators/logical_operators/OperatorInferior.cpp \
    operators/logical_operators/OperatorInferiorEqual.cpp \
    operators/logical_operators/OperatorNot.cpp \
    operators/logical_operators/OperatorOr.cpp \
    operators/logical_operators/OperatorSuperior.cpp \
    operators/logical_operators/OperatorSuperiorEqual.cpp \
    operators/rational_operators/OperatorDenominator.cpp \
    operators/rational_operators/OperatorNumerator.cpp \
    operators/stack_operators/OperatorCLEAR.cpp \
    operators/stack_operators/OperatorDROP.cpp \
    operators/stack_operators/OperatorDUP.cpp \
    operators/stack_operators/OperatorLASTARGS.cpp \
    operators/stack_operators/OperatorLASTOP.cpp \
    operators/stack_operators/OperatorREDO.cpp \
    operators/stack_operators/OperatorSWAP.cpp \
    operators/stack_operators/OperatorUNDO.cpp \
    operators/CalculationOperator.cpp \
    operators/Operator.cpp \
    operators/OperatorManager.cpp \
    operators/StackOperator.cpp \
    stack/StackUTComputer.cpp \
    Calculator.cpp \
    db/Database.cpp

HEADERS  += views/mainwindow.h \
    exceptions/UTComputerException.h \
    lexer/Lexer.h \
    literals/AtomLiteral.h \
    literals/ComplexLiteral.h \
    literals/ExpressionLiteral.h \
    literals/Literal.h \
    literals/LiteralFactory.h \
    literals/NumericLiteral.h \
    literals/ProgramLiteral.h \
    literals/StringLiteral.h \
    operators/classic_operators/OperatorDivision.h \
    operators/classic_operators/OperatorIntegerDivision.h \
    operators/classic_operators/OperatorMinus.h \
    operators/classic_operators/OperatorModulo.h \
    operators/classic_operators/OperatorMultiplication.h \
    operators/classic_operators/OperatorNeg.h \
    operators/classic_operators/OperatorPlus.h \
    operators/complex_operators/OperatorDollar.h \
    operators/complex_operators/OperatorIM.h \
    operators/complex_operators/OperatorRE.h \
    operators/logical_operators/OperatorAnd.h \
    operators/logical_operators/OperatorDifferent.h \
    operators/logical_operators/OperatorEqual.h \
    operators/logical_operators/OperatorInferior.h \
    operators/logical_operators/OperatorInferiorEqual.h \
    operators/logical_operators/OperatorNot.h \
    operators/logical_operators/OperatorOr.h \
    operators/logical_operators/OperatorSuperior.h \
    operators/logical_operators/OperatorSuperiorEqual.h \
    operators/rational_operators/OperatorDenominator.h \
    operators/rational_operators/OperatorNumerator.h \
    operators/stack_operators/OperatorCLEAR.h \
    operators/stack_operators/OperatorDROP.h \
    operators/stack_operators/OperatorDUP.h \
    operators/stack_operators/OperatorLASTARGS.h \
    operators/stack_operators/OperatorLASTOP.h \
    operators/stack_operators/OperatorREDO.h \
    operators/stack_operators/OperatorSWAP.h \
    operators/stack_operators/OperatorUNDO.h \
    operators/CalculationOperator.h \
    operators/Operator.h \
    operators/OperatorManager.h \
    operators/StackOperator.h \
    stack/StackUTComputer.h \
    Calculator.h \
    db/Database.h

FORMS    +=  views/mainwindow.ui
