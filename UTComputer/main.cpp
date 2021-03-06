#include <iostream>
#include "views/mainwindow.h"
#include <QApplication>
#include "stack/StackUTComputer.h"
#include "db/Database.h"
#include "Calculator.h"
#include "sounds/sound.h"
#include <QDebug>

using namespace std;


int main(int argc, char *argv[]){

    // Creating calculator
    Calculator calc;

    // Creating Database
    Database db;

    // Creating sound system
    Sound sound;

    // Creating MainView
    QApplication a(argc, argv);
    MainWindow w(&calc, &db, &sound);
    w.show();



    return a.exec();
}
