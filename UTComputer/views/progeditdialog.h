#ifndef PROGEDITDIALOG_H
#define PROGEDITDIALOG_H

#include <QDialog>
#include <string>
#include "../literals/ProgramLiteral.h"

using namespace std;

namespace Ui {
class ProgEditDialog;
}

class ProgEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgEditDialog(ProgramLiteral *pl, QWidget *parent = 0);
    ~ProgEditDialog();

private slots:
    void on_buttonBox_accepted();

signals:
    void textChanged();

private:
    Ui::ProgEditDialog *ui;
    ProgramLiteral* pl;
};

#endif // PROGEDITDIALOG_H
