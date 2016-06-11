#include "Database.h"

void Database::createProgram(string name, string value){
    openDatabase();
    QSqlQuery query;
    query.prepare("INSERT INTO program (name, value) "
                  "VALUES (:name, :value)");
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
    query.prepare("INSERT INTO atom (name, value) "
                  "VALUES (:name, :value)");
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

void Database::saveStack(vector<string> elements){
    openDatabase();
    for(int i = 0; i < elements.size();i++){
        QSqlQuery query;
        query.prepare("INSERT INTO stack (value) "
                      "VALUES (:value)");
         QString qsValue = QString::fromStdString(elements[i]);
         query.bindValue(0, qsValue);
         bool result = query.exec();
         if(result){
             qDebug() << "Successfully inserted stack element " << QString::fromStdString(elements[i]) <<endl;
         } else {
            qDebug() << "Error while inserting stack" << query.lastError() <<endl;
         }
         qDebug() << db.lastError().text();
         query.finish();
    }
    closeDatabase();
}

void Database::cleanDatabase(){
    openDatabase();

    QSqlQuery query("DELETE FROM program;");
    bool result = query.exec();
    query.finish();

    QSqlQuery query2("DELETE FROM atom;");
    result = query2.exec();
    query2.finish();

    QSqlQuery query3("DELETE FROM stack;");
    result = query3.exec();
    query3.finish();

    closeDatabase();
}

vector<vector <string>> Database::getPrograms(){
    openDatabase();
    QSqlQuery query("SELECT * FROM program;");
    bool result = query.exec();
    if(result){
        qDebug() << "Successfully get program " <<endl;
    } else {
       qDebug() << "Error while getting program" << query.lastError() <<endl;
    }
    vector<vector <string>> array;
    int fieldValue = query.record().indexOf("value");
    int fieldName = query.record().indexOf("name");
    while (query.next()) {
            vector<string> row = {  query.value(fieldName).toString().toStdString(), query.value(fieldValue).toString().toStdString()};
            array.push_back(row);
    }
    qDebug() << db.lastError().text();
    query.finish();
    closeDatabase();
    return array;
}

void Database::sync(vector<vector<string>> programs, vector<vector <string>> atoms, vector<string> stack){

    cleanDatabase();


    // create all programs
    for (auto line = programs.cbegin(); line != programs.cend(); ++line) {
        createProgram(line->at(0), line->at(1));
    }

    // create all atoms
    for (auto line = atoms.cbegin(); line != atoms.cend(); ++line) {
        createAtom(line->at(0), line->at(1));
    }


    // save the stack
    saveStack(stack);
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
    while (query.next()) {
            vector<string> row = {query.value(fieldName).toString().toStdString(),query.value(fieldValue).toString().toStdString()};
            array.push_back(row);
    }
    qDebug() << db.lastError().text();
    query.finish();
    closeDatabase();
    return array;
}

vector<string> Database::getStack(){
    openDatabase();
    QSqlQuery query("SELECT * FROM stack ORDER BY id;");
    bool result = query.exec();
    if(result){
        qDebug() << "Successfully get stack" <<endl;
    } else {
       qDebug() << "Error while getting stack" << query.lastError() <<endl;
    }
    vector <string> array;
    int fieldValue = query.record().indexOf("value");
    while (query.next()) {
       array.push_back(query.value(fieldValue).toString().toStdString());
    }
    qDebug() << db.lastError().text();
    query.finish();
    closeDatabase();
    return array;
}
