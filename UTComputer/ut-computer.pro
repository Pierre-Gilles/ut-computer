#-------------------------------------------------
#
# Project created by QtCreator 2016-06-04T10:40:05
#
#-------------------------------------------------

QT       += core gui sql multimedia

CONFIG += c++11

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
    db/Database.cpp \
    views/programdialog.cpp \
    views/atomdialog.cpp \
    sounds/sound.cpp \
    views/paramdialog.cpp \
    views/progeditdialog.cpp

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
    db/Database.h \
    views/programdialog.h \
    views/atomdialog.h \
    sounds/sound.h \
    views/paramdialog.h \
    views/progeditdialog.h

FORMS    +=  views/mainwindow.ui \
    views/programdialog.ui \
    views/atomdialog.ui \
    views/paramdialog.ui \
    views/progeditdialog.ui

RESOURCES += database.db \
    sounds/attention.wav \
    sounds/binz.wav \
    sounds/boule_merdasse.wav \
    sounds/c_est_cela_oui.wav \
    sounds/Les_cons_tontons_flingeurs.wav \
    sounds/monumentale_erreur.wav \
    sounds/mortecouille.wav \
    sounds/pas_jour_faire_chier_kamelott.wav \
    sounds/que_trepasse.wav \
    sounds/wou_pinaise.wav \
    sounds/you_shall_not_pass.wav \

ICON = icone/icone.icns

win32: RC_ICONS += icone/icone.ico
