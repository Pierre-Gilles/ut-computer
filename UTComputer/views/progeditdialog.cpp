#include "progeditdialog.h"
#include "ui_progeditdialog.h"

ProgEditDialog::ProgEditDialog(ProgramLiteral *pl, QWidget *parent) :
    pl(pl),
    QDialog(parent),
    ui(new Ui::ProgEditDialog)
{
    ui->setupUi(this);
    ui->textEdit->setText(QString::fromStdString(pl->getValue()));
}

ProgEditDialog::~ProgEditDialog()
{
    delete ui;
}

void ProgEditDialog::on_buttonBox_accepted(){
    pl->setValue(ui->textEdit->toPlainText().toStdString());
    emit textChanged();
}
