#include <iostream>
#include "views/mainwindow.h"
#include <QApplication>
#include "stack/StackUTComputer.h"
#include "Calculator.h"

using namespace std;


int main(int argc, char *argv[]){

    // Creating calculator
    Calculator calc;

    // Creating MainView
    QApplication a(argc, argv);
    MainWindow w(&calc);
    w.show();


    return a.exec();
}
