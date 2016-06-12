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

    void on_pushButtonDeleteProgram_clicked();

    void on_listPrograms_itemSelectionChanged();

private:
    Ui::ProgramDialog *ui;
    Calculator *calc;
    vector<vector<string>> programs;

    /**
     * \fn updateList
     * \brief Update the program list
     */
    void updateList();

    /**
     * \fn displayError
     * \brief Display an error
     * \param[in] e: the error to display
     */
    void displayError(string e);
};

#endif // PROGRAMDIALOG_H
