#ifndef PARAMDIALOG_H
#define PARAMDIALOG_H

#include <QDialog>
#include <QDebug>
#include <vector>
#include <QListWidgetItem>
#include "../Calculator.h"

namespace Ui {
class ParamDialog;
}

class ParamDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ParamDialog(Calculator *calc, bool keyboardState, bool soundState, int nbElementStack, QWidget *parent = 0);
    ~ParamDialog();

private slots:
    void on_checkBoxSound_stateChanged(int arg1);

    void on_checkBoxKeyboard_stateChanged(int arg1);
    void on_lineEdit_textChanged(const QString &arg1);

signals:
    void soundStateChanged(bool b);
    void keyboardStateChanged(bool b);
    void nbElementChanged(int nb);
private:
    Ui::ParamDialog *ui;
    Calculator *calc;
};

#endif // PARAMDIALOG_H
