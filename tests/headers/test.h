#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>
#include <iostream>


class TestQString: public QObject {
    Q_OBJECT
    private slots:
        void test1();
};
#endif
