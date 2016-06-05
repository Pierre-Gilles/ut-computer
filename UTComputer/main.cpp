#include <iostream>
#include "views/mainwindow.h"
#include <QApplication>
#include "stack/StackUTComputer.h"
#include "db/Database.h"
#include "Calculator.h"
#include <QDebug>

using namespace std;


int main(int argc, char *argv[]){

    // Creating calculator
    Calculator calc;

    // Creating MainView
    QApplication a(argc, argv);
    MainWindow w(&calc);
    w.show();

    // Creating Database
    Database db("../../database.db");
    db.createProgram("test test");
    db.getPrograms();

    return a.exec();
}
