#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDir>
#include <QSqlError>
#include "../exceptions/UTComputerException.h"

class Database {
private:
    QSqlDatabase db;
    QString path;



    bool openDatabase(){
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);
        bool result =  db.open();
        if(!result){
            qDebug() << "Impossible de se connecter a la DB";
        } else {
            qDebug() << "Connecté avec succès à la DB";
        }

        return result;
    }
    void closeDatabase() {
        db.close();
    }

public:
    Database(QString path): path(path) {}
    int createProgram(string text);
    void getPrograms();
};

#endif //DATABASE_H
