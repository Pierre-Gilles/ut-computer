#ifndef PROGRAMDIALOG_H
#define PROGRAMDIALOG_H

#include <QDialog>
#include <QDebug>
#include <vector>
#include <QListWidgetItem>
#include "../Calculator.h"

namespace Ui {
class ProgramDialog;
}

class ProgramDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgramDialog(Calculator *calc, QWidget *parent = 0);
    ~ProgramDialog();

private slots:
    void on_pushButtonCreateProgram_clicked();

    void on_textEdit_textChanged();

    void on_listPrograms_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);


    void on_listPrograms_clicked(const QModelIndex &index);

    void on_pushButtonDeleteProgram_clicked();

private:
    Ui::ProgramDialog *ui;
    Calculator *calc;
    vector<vector<string>> programs;
    void updateList();
    void displayError(string e);
    void injectPrograms();
};

#endif // PROGRAMDIALOG_H
