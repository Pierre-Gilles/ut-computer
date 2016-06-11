#include "atomdialog.h"
#include "ui_atomdialog.h"

AtomDialog::AtomDialog(Calculator *calc, QWidget *parent) :
    calc(calc),
    QDialog(parent),
    ui(new Ui::AtomDialog)
{
    atoms = calc->save_atom_map();
    ui->setupUi(this);
    ui->textEditError->setText("");
    updateList();
}

AtomDialog::~AtomDialog()
{
    delete ui;
}

void AtomDialog::displayError(string e){
    QString qs = QString::fromStdString(e);
    ui->textEditError->setText(qs);
    qDebug() << qs;
}

void AtomDialog::updateList(){
    ui->listWidget->clear();
    for(int i = 0; i < atoms.size(); i++){
        QString qs = QString::fromStdString(atoms[i][0]);
        ui->listWidget->addItem(qs);
    }
}

void AtomDialog::on_pushButtonCreateAtom_clicked(){
    ui->textEditError->setText("");
    try{
        calc->addAtom(ui->lineEditNewAtomeName->text().toStdString(), ui->lineEditNewAtomeValue->text().toStdString());
        vector<string> atom = {ui->lineEditNewAtomeName->text().toStdString(),  ui->lineEditNewAtomeValue->text().toStdString()};
        atoms.push_back(atom);
        updateList();
        ui->lineEditNewAtomeName->setText("");
    } catch(UTComputerException e){
        displayError(e.getMessage());
    }
}

void AtomDialog::on_textEdit_textChanged(){
    ui->textEditError->setText("");
    try{
        int row = ui->listWidget->currentRow();
        atoms[row][1] = ui->textEdit->toPlainText().toStdString();
        calc->updateAtom(atoms[row][0], atoms[row][1]);
    } catch(UTComputerException e){
        displayError(e.getMessage());
    }

}

void AtomDialog::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous){
    int row = ui->listWidget->currentRow();
    QString qs = QString::fromStdString(atoms[row][1]);
    ui->textEdit->setText(qs);
}
