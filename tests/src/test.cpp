#include "headers/test.h"

void TestQString::test1(){
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
}

QTEST_MAIN(TestQString)
//#include "TestQString.moc"
