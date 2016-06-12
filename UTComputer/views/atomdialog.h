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
    void on_pushButtonCreateAtom_clicked();

    void on_textEdit_textChanged();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listWidget_clicked(const QModelIndex &index);

    void on_pushButtonDeleteAtom_clicked();

private:
    Ui::AtomDialog *ui;
    Calculator *calc;
    vector<vector<string>> atoms;
    void updateList();
    void displayError(string e);
};

#endif // ATOMDIALOG_H
