#include "programdialog.h"
#include "ui_programdialog.h"

ProgramDialog::ProgramDialog(Calculator *calc, QWidget *parent) :
    calc(calc),
    QDialog(parent),
    ui(new Ui::ProgramDialog)
{
    programs = calc->save_program_map();
    qDebug() << programs.size() <<endl;
    //updateList();
    ui->setupUi(this);
}

ProgramDialog::~ProgramDialog()
{
    delete ui;
}


void ProgramDialog::updateList(){
    ui->listWidget->clear();
    qDebug() << programs.size() <<endl;
    /*for(int i = 0; i < programs.size(); i++){
        QString qs = QString::fromStdString(programs[i][0]);
        ui->listWidget->addItem(qs);
    }*/
}
