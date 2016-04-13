#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T10:24:56
#
#-------------------------------------------------

QT += core gui testlib widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ut-computerUnitTests
TEMPLATE = app

CONFIG += console

SOURCES += \
    src/test.cpp

HEADERS  += \
    headers/test.h \

# Set two different directories for debug and release
CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/build/debug
}
CONFIG(release, debug|release) {
    DESTDIR = $$PWD/build/release
}
# Set different directories for different types of file, using the DESTIR debug or release depending on the build type
OBJECTS_DIR = $$DESTDIR/obj
MOC_DIR = $$DESTDIR/moc
RCC_DIR = $$DESTDIR/rcc
UI_DIR = $$DESTDIR/ui
