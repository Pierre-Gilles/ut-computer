#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateValueLineEdit(string s){
    QString qs = QString::fromStdString(s);
    ui->lineEdit->setText(qs);
}

void MainWindow::addToLineEdit(string s){
    QString qs = QString::fromStdString(s);
    ui->lineEdit->setText(ui->lineEdit->text() + qs);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1) {

}

/**
 * NUMBER BUTTON SLOTS
 */

void MainWindow::on_pushButton0_clicked(){
    addToLineEdit("0");
}

void MainWindow::on_pushButton1_clicked(){
    addToLineEdit("1");
}

void MainWindow::on_pushButton2_clicked(){
    addToLineEdit("2");
}

void MainWindow::on_pushButton3_clicked(){
    addToLineEdit("3");
}

void MainWindow::on_pushButton4_clicked(){
    addToLineEdit("4");
}

void MainWindow::on_pushButton5_clicked(){
    addToLineEdit("5");
}

void MainWindow::on_pushButton6_clicked(){
    addToLineEdit("6");
}

void MainWindow::on_pushButton7_clicked(){
    addToLineEdit("7");
}

void MainWindow::on_pushButton8_clicked(){
    addToLineEdit("8");
}

void MainWindow::on_pushButton9_clicked(){
    addToLineEdit("9");
}

/**
 * ENTER BUTTON SLOT
 */

void MainWindow::on_pushButtonEnter_clicked(){

}
