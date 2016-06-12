#include "paramdialog.h"
#include "ui_paramdialog.h"
#include "mainwindow.h"

ParamDialog::ParamDialog(Calculator *calc, bool keyboardState, bool soundState, int nbElementStack, QWidget *parent) :
    calc(calc),
    QDialog(parent),
    ui(new Ui::ParamDialog)
{
    ui->setupUi(this);
    ui->checkBoxKeyboard->setChecked(keyboardState);
    ui->checkBoxSound->setChecked(soundState);
    ui->lineEdit->setText(QString::number(nbElementStack));
}

ParamDialog::~ParamDialog()
{
    delete ui;
}

void ParamDialog::on_checkBoxSound_stateChanged(int arg1){
    bool activated = arg1;
    emit soundStateChanged(activated);
}

void ParamDialog::on_checkBoxKeyboard_stateChanged(int arg1){
    bool activated = arg1;
    emit keyboardStateChanged(activated);
}

void ParamDialog::on_lineEdit_textChanged(const QString &arg1){
    try{
        int value = std::stoi(arg1.toStdString());
        emit nbElementChanged(value);
    } catch(std::invalid_argument e){
        qDebug() << "Invalid number";
    }
}
