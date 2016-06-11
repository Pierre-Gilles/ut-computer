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
    ui->textEditError->setText("");
}

ProgramDialog::~ProgramDialog()
{
    delete ui;
}

void ProgramDialog::displayError(string e){
    QString qs = QString::fromStdString(e);
    ui->textEditError->setText(qs);
}

void ProgramDialog::updateList(){
    qDebug() << programs.size() <<endl;
    for(int i = 0; i < programs.size(); i++){
        QString qs = QString::fromStdString(programs[i][0]);
        ui->listPrograms->addItem(qs);
    }
}

void ProgramDialog::injectPrograms(){
    try{
        calc->init_program_map(programs);
    } catch(UTComputerException e){
        displayError(e.getMessage());
    }
}

void ProgramDialog::on_pushButtonCreateProgram_clicked(){
    ui->textEditError->setText("");
    vector<string> prog = {ui->textEditNewProgName->toPlainText().toStdString(), ""};
    programs.push_back(prog);
    //updateList();
    injectPrograms();
}
