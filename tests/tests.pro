#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T10:24:56
#
#-------------------------------------------------

QT       += core gui testlib widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ut-computerUnitTests
TEMPLATE = app

CONFIG += console

SOURCES += \
    src/test.cpp

HEADERS  += \
            headers/test.h

DESTDIR = $$PWD/../build
