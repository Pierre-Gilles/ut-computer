#include "programdialog.h"
#include "ui_programdialog.h"

ProgramDialog::ProgramDialog(Calculator *calc, QWidget *parent) :
    calc(calc),
    QDialog(parent),
    ui(new Ui::ProgramDialog)
{
    programs = calc->save_program_map();
    ui->setupUi(this);
    ui->textEditError->setText("");
    updateList();
}

ProgramDialog::~ProgramDialog()
{
    delete ui;
}

void ProgramDialog::displayError(string e){
    QString qs = QString::fromStdString(e);
    ui->textEditError->setText(qs);
    qDebug() << qs;
}

void ProgramDialog::updateList(){
//    ui->listPrograms->clearSelection();
//    ui->listPrograms->clearFocus();
    ui->listPrograms->clear(); // TODO crash quand on ajoute un programme alors qu'un item de la liste des programmes est sélectionné
    //qDebug() << programs.size() <<endl;
    for(int i = 0; i < programs.size(); i++){
        QString qs = QString::fromStdString(programs[i][0]);
        ui->listPrograms->addItem(qs);
    }
}

void ProgramDialog::on_pushButtonCreateProgram_clicked(){
    ui->textEditError->setText("");
    try{
        calc->addProgram(ui->textEditNewProgName->toPlainText().toStdString(), "");
        vector<string> prog = {ui->textEditNewProgName->toPlainText().toStdString(), ""};
        programs.push_back(prog);
        updateList();
        ui->textEditNewProgName->setText("");
    } catch(UTComputerException e){
        displayError(e.getMessage());
    }

}

void ProgramDialog::on_textEdit_textChanged(){
    int row = ui->listPrograms->currentRow();
    programs[row][1] = ui->textEdit->toPlainText().toStdString();
    calc->updateProgram(programs[row][0], programs[row][1]);
}

void ProgramDialog::on_listPrograms_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous){
    int row = ui->listPrograms->currentRow();
    QString qs = QString::fromStdString(programs[row][1]);
    ui->textEdit->setText(qs);
}
