#include <iostream>
#include "views/mainwindow.h"
#include <QApplication>
#include "stack/StackUTComputer.h"
#include "operators/classic_operators/OperatorPlus.h"
using namespace std;


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
