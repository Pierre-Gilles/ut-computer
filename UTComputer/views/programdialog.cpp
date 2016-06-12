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
    ui->listPrograms->clear();

    QStringList listeOfItems;
    for (auto it = programs.cbegin(); it != programs.cend(); ++it) {
        listeOfItems.push_back(QString::fromStdString(it->at(0)));
        //ui->listPrograms->addItem(QString::fromStdString(it->at(0)));
    }
    // test adding with a QStringList but on_listPrograms_currentItemChanged still make the application crash
    ui->listPrograms->addItems(listeOfItems);
}

void ProgramDialog::on_pushButtonCreateProgram_clicked(){
    string program_key = ui->textEditNewProgName->toPlainText().toStdString();
    ui->textEditError->setText("");
    try{
        calc->addProgram(program_key, "");
        vector<string> prog = {program_key, ""};
        programs.push_back(prog);
        updateList();

        /* Update view : select last program added and focus on the edition box */
        ui->textEditNewProgName->setText("");
        ui->listPrograms->setCurrentRow(ui->listPrograms->count() - 1);
        ui->textEdit->setFocus();

    } catch(UTComputerException e){
        displayError(e.getMessage());
    }

}

void ProgramDialog::on_textEdit_textChanged(){
    int row = ui->listPrograms->currentRow();
    programs[row][1] = ui->textEdit->toPlainText().toStdString();
    calc->updateProgram(programs[row][0], programs[row][1]);
}



/* Make the program crash when update of the list */
void ProgramDialog::on_listPrograms_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous){
    if (ui->listPrograms->count() != 0) {
//        int row = ui->listPrograms->currentRow();
//        QString qs = QString::fromStdString(programs[row][1]);
//        ui->textEdit->setText(qs);
    }
}


void ProgramDialog::on_listPrograms_clicked(const QModelIndex &index)
{
    if (ui->listPrograms->count() > 0) {
        int row = ui->listPrograms->currentRow();
        QString qs = QString::fromStdString(programs[row][1]);
        ui->textEdit->setText(qs);
    }
}
