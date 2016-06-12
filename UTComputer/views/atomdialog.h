#ifndef ATOMDIALOG_H
#define ATOMDIALOG_H

#include <QDialog>
#include <QDebug>
#include <vector>
#include <QListWidgetItem>
#include "../Calculator.h"

namespace Ui {
class AtomDialog;
}

class AtomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AtomDialog(Calculator *calc, QWidget *parent = 0);
    ~AtomDialog();

private slots:

    /**
     * \fn on_pushButtonCreateAtom_clicked
     * \brief Triggered when the createAtom button is clicked
     */
    void on_pushButtonCreateAtom_clicked();

    /**
     * \fn on_textEdit_textChanged
     * \brief Triggered when the text changed
     */
    void on_textEdit_textChanged();

    /**
     * \fn on_pushButtonDeleteAtom_clicked
     * \brief Triggered when the delete button is clicked
     */
    void on_pushButtonDeleteAtom_clicked();

    /**
     * \fn on_listWidget_itemSelectionChanged
     * \brief Triggered when the selection changed
     */
    void on_listWidget_itemSelectionChanged();

private:
    Ui::AtomDialog *ui;
    Calculator *calc;
    vector<vector<string>> atoms;

    /**
     * \fn updateList
     * \brief Update the atom list
     */
    void updateList();

    /**
     * \fn displayError
     * \brief Display an error
     */
    void displayError(string e);
};

#endif // ATOMDIALOG_H
