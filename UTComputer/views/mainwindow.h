#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QString>
#include <string>

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void updateValueLineEdit(string s);
    void addToLineEdit(string s);
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

  // operator


  // enter
  void on_pushButtonEnter_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
