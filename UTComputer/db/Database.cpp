#include "Database.h"

void Database::createProgram(string name, string value){
    openDatabase();
    QSqlQuery query;
    query.prepare("INSERT INTO program (name, text) "
                  "VALUES (:name, :text)");
    QString qsValue = QString::fromStdString(value);
    QString qsName = QString::fromStdString(name);
    query.bindValue(0, qsName);
    query.bindValue(1, qsValue);
    bool result = query.exec();
    if(result){
        qDebug() << "Successfully inserted program" <<endl;
    } else {
       qDebug() << "Error while inserting program" << query.lastError() <<endl;
    }
    qDebug() << db.lastError().text();
    query.finish();
    closeDatabase();
}

void Database::createAtom(string name, string value){
    openDatabase();
    QSqlQuery query;
    query.prepare("INSERT INTO atom (name, text) "
                  "VALUES (:name, :text)");
    QString qsValue = QString::fromStdString(value);
    QString qsName = QString::fromStdString(name);
    query.bindValue(0, qsName);
    query.bindValue(1, qsValue);
    bool result = query.exec();
    if(result){
        qDebug() << "Successfully inserted program" <<endl;
    } else {
       qDebug() << "Error while inserting program" << query.lastError() <<endl;
    }
    qDebug() << db.lastError().text();
    query.finish();
    closeDatabase();
}

void Database::cleanDatabase(){
    openDatabase();
    QSqlQuery query("DELETE FROM program;");
    bool result = query.exec();
    query.finish();
    closeDatabase();
}

vector<vector <string>> Database::getPrograms(){
    openDatabase();
    QSqlQuery query("SELECT * FROM program;");
    bool result = query.exec();
    if(result){
        qDebug() << "Successfully get program" <<endl;
    } else {
       qDebug() << "Error while getting program" << query.lastError() <<endl;
    }
    vector<vector <string>> array;
    int fieldValue = query.record().indexOf("value");
    int fieldName = query.record().indexOf("name");
    int i = 0;
    while (query.next()) {
            array[i][0] = query.value(fieldName).toString().toStdString();
            array[i][1] = query.value(fieldValue).toString().toStdString();
            i++;
    }
    qDebug() << db.lastError().text();
    query.finish();
    closeDatabase();
    return array;
}

void Database::sync(vector<vector<string>> programs, vector<vector <string>> atoms){

    cleanDatabase();


    // create all programs
    for (auto line = programs.cbegin(); line != programs.cend(); ++line) {
        createProgram(line->at(0), line->at(1));
    }

    // create all atoms
    for (auto line = atoms.cbegin(); line != atoms.cend(); ++line) {
        createAtom(line->at(0), line->at(1));
    }
}

vector<vector <string>> Database::getAtoms(){
    openDatabase();
    QSqlQuery query("SELECT * FROM atom;");
    bool result = query.exec();
    if(result){
        qDebug() << "Successfully get atoms" <<endl;
    } else {
       qDebug() << "Error while getting atoms" << query.lastError() <<endl;
    }
    vector<vector <string>> array;
    int fieldValue = query.record().indexOf("value");
    int fieldName = query.record().indexOf("name");
    int i = 0;
    while (query.next()) {
            array[i][0] = query.value(fieldName).toString().toStdString();
            array[i][1] = query.value(fieldValue).toString().toStdString();
            i++;
    }
    qDebug() << db.lastError().text();
    query.finish();
    closeDatabase();
    return array;
}
