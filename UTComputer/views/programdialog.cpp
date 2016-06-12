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
    qDebug() << "UL 1" << endl;
    ui->listPrograms->clear();
    qDebug() << "UL 2" << endl;
    QStringList listeOfItems;
    qDebug() << "UL 3" << endl;
    for (auto it = programs.cbegin(); it != programs.cend(); ++it) {
        listeOfItems.push_back(QString::fromStdString(it->at(0)));
        //ui->listPrograms->addItem(QString::fromStdString(it->at(0)));
    }
    qDebug() << "UL 4" << endl;
    // test adding with a QStringList but on_listPrograms_currentItemChanged still make the application crash
    ui->listPrograms->addItems(listeOfItems);
    qDebug() << "UL 5" << endl;
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

    if(row >= 0){
        programs[row][1] = ui->textEdit->toPlainText().toStdString();
        calc->updateProgram(programs[row][0], programs[row][1]);
    }
}






void ProgramDialog::on_pushButtonDeleteProgram_clicked(){
    if (ui->listPrograms->count() > 0) {
        int row = ui->listPrograms->currentRow();
        if (row != -1) {
            ui->listPrograms->setCurrentRow(0); // set current row here in case of the program deleted is the last of the list -> evoid crash
            calc->deleteProgram(programs[row][0]);
            programs.erase(programs.begin()+row);
            updateList();
            ui->textEdit->setText("");
            if (ui->listPrograms->count() > 0){
                ui->listPrograms->setCurrentRow(0);
            }
        }
    }
}

void ProgramDialog::on_listPrograms_itemSelectionChanged() {
    if (ui->listPrograms->count() > 0) {
        int row = ui->listPrograms->currentRow();
        if (row != -1) {
            if (programs.size() > row) {
                QString qs = QString::fromStdString(programs[row][1]);
                ui->textEdit->setText(qs);
            }

        }
    }
}
