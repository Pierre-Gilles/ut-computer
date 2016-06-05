#include "Database.h"

int Database::createProgram(string text){
    openDatabase();
    QSqlQuery query;
    query.prepare("INSERT INTO program (text) "
                  "VALUES (:text)");
    QString qs = QString::fromStdString(text);
    query.bindValue(0, qs);
    bool result = query.exec();
    if(result){
        qDebug() << "Successfully inserted program" <<endl;
    } else {
       qDebug() << "Error while inserting program" <<endl;
    }
    qDebug() << db.lastError().text() ;
    closeDatabase();
}

void Database::getPrograms(){
    openDatabase();
    QSqlQuery query("SELECT * FROM program");
    int fieldNo = query.record().indexOf("text");
    while (query.next()) {
            QString text = query.value(fieldNo).toString();
            qDebug() << "Row : " << text << endl;
    }
    qDebug() << db.lastError().text();
    closeDatabase();
}
