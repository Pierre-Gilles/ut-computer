#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QString>
#include <string>
#include <iostream>
#include <vector>
#include "../Calculator.h"
#include "../db/Database.h"

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Calculator *calc, Database *db, QWidget *parent = 0);

    ~MainWindow();

private slots:

  void on_lineEdit_textChanged(const QString &arg1);

  // number
  void on_pushButton0_clicked();
  void on_pushButton1_clicked();
  void on_pushButton2_clicked();
  void on_pushButton3_clicked();
  void on_pushButton4_clicked();
  void on_pushButton5_clicked();
  void on_pushButton6_clicked();
  void on_pushButton7_clicked();
  void on_pushButton8_clicked();
  void on_pushButton9_clicked();
  void on_pushButtonOr_clicked();

  // operator
  void on_pushButtonPlus_clicked();
  void on_pushButtonMinus_clicked();
  void on_pushButtonMultiply_clicked();
  void on_pushButtonDivide_clicked();
  void on_pushButtonNeg_clicked();
  void on_pushButtonAnd_clicked();
  void on_pushButtonNot_clicked();
  void on_pushButtonEval_clicked();
  void on_pushButtonNum_clicked();
  void on_pushButtonDen_clicked();
  void on_pushButtonRe_clicked();
  void on_pushButtonIm_clicked();
  void on_pushButtonDollar_clicked();
  void on_pushButtonLeftParenthesis_clicked();
  void on_pushButtonRightParenthesis_clicked();
  void on_pushButtonPoint_clicked();

  // enter
  void on_pushButtonEnter_clicked();

  void on_pushButtonUndo_clicked();

  void on_pushButtonRedo_clicked();

  void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;

    Calculator *calc;
    Database *db;

    void updateValueLineEdit(string s);
    void addToLineEdit(string s);
    void displayError(string s);
    void updateStackDisplay(vector<string> elems);
    string getLineEditValue();
    void refreshView();
    void calculate();
};

#endif // MAINWINDOW_H
