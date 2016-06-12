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

    /**
     * \fn on_checkBoxSound_stateChanged
     * \brief When the value of the checkBoxSound has changed
     * \param[in] arg1: the new value
     */
    void on_checkBoxSound_stateChanged(int arg1);

    /**
     * \fn on_checkBoxKeyboard_stateChanged
     * \brief When the value of the checkBoxKeyboard has changed
     * \param[in] arg1: the new value
     */
    void on_checkBoxKeyboard_stateChanged(int arg1);

    /**
     * \fn on_lineEdit_textChanged
     * \brief When the value of the textEdit "number of elements by stack" has changed
     * \param[in] &arg1: the new value
     */
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
