#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDir>
#include <QSqlError>
#include <QFile>
#include "../exceptions/UTComputerException.h"

using namespace std;

class Database {
private:
    QSqlDatabase db;
    QString path;



    bool openDatabase(){
        qDebug() << "Tentative de connexion à la DB " << path <<endl;
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

    // Duplicate the base DB file
    // and add write and read permission to the file
    Database() {
        path = "../database.db";
        if(!QFile::exists(path)){
            qDebug() << "Copying DB" << endl;
            QFile::copy(":/database.db", path);
            if(!QFile::setPermissions(path, QFileDevice::WriteOwner | QFileDevice::ReadOwner)){
                qDebug() << "Unable to set permission for db file" << endl;
            }
        }
    }
    void createProgram(string name, string value);
    void createAtom(string name, string value);
    void sync(vector<vector<string>> programs, vector<vector <string>> atoms);
    vector<vector <string>> getPrograms();
    vector<vector <string>> getAtoms();
    void cleanDatabase();
};

#endif //DATABASE_H
