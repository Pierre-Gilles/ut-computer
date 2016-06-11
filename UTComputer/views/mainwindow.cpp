#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(Calculator *calc, Database *db, QWidget *parent) :
        calc(calc),
        db(db),
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    // init with data in database
    vector<vector<string>> progs = db->getPrograms();
    qDebug() << "Get programs from DB = " << progs.size() <<endl;

    try{
        calc->init_program_map(progs);
        calc->init_atom_map(db->getAtoms());
    } catch(UTComputerException e){
        qDebug() << QString::fromStdString(e.getMessage());
    }


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    db->sync(calc->save_program_map(), calc->save_atom_map());
    delete ui;
}

void MainWindow::updateValueLineEdit(string s){
    QString qs = QString::fromStdString(s);
    ui->lineEdit->setText(qs);
}

void MainWindow::addToLineEdit(string s){

    // add the text at the end of the line
    QString qs = QString::fromStdString(s);
    ui->lineEdit->setText(ui->lineEdit->text() + qs);

    // test if it was a
    //QCharRef c = s[qs.length()-1];
}

string MainWindow::getLineEditValue(){
    QString qs = ui->lineEdit->text();
    string utf8_text = qs.toUtf8().constData();
    return utf8_text;
}

void MainWindow::displayError(string s){
    QString qs = QString::fromStdString(s);
    ui->errorTextArea->setText(qs);
    qDebug() << qs << endl;
}

void MainWindow::refreshView(){
    vector<string> elements = calc->getSt().getLastElementsString(5);
    updateValueLineEdit("");
    updateStackDisplay(elements);
}

void MainWindow::updateStackDisplay(vector<string> elems){
    ui->listWidget->clear();

    for(int i = 0; i < elems.size(); i++){
        QString qs = QString::fromStdString(elems[i]);
        ui->listWidget->addItem(qs);
    }
}

void MainWindow::calculate(){
    try{
       calc->run(getLineEditValue());
       refreshView();
    } catch(UTComputerException e){
        displayError(e.getMessage());
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1) {
    try{
        string text = arg1.toUtf8().constData();
        vector<string> tokens = calc->getLx().tokenize(text);
        string last;
        if (!tokens.empty()){
            last = tokens.back();
            if(calc->getLx().isOperator(last)){
                calculate();
            }
        }
    } catch(UTComputerException e){
        displayError(e.getMessage());
    }

}

/**
 * NUMBER BUTTON SLOTS
 */

void MainWindow::on_pushButton0_clicked(){
    addToLineEdit("0");
}

void MainWindow::on_pushButton1_clicked(){
    addToLineEdit("1");
}

void MainWindow::on_pushButton2_clicked(){
    addToLineEdit("2");
}

void MainWindow::on_pushButton3_clicked(){
    addToLineEdit("3");
}

void MainWindow::on_pushButton4_clicked(){
    addToLineEdit("4");
}

void MainWindow::on_pushButton5_clicked(){
    addToLineEdit("5");
}

void MainWindow::on_pushButton6_clicked(){
    addToLineEdit("6");
}

void MainWindow::on_pushButton7_clicked(){
    addToLineEdit("7");
}

void MainWindow::on_pushButton8_clicked(){
    addToLineEdit("8");
}

void MainWindow::on_pushButton9_clicked(){
    addToLineEdit("9");
}

/**
  * OPERATOR BUTTON
  */

void MainWindow::on_pushButtonPlus_clicked(){
     addToLineEdit("+");
}

void MainWindow::on_pushButtonMinus_clicked(){
    addToLineEdit("-");
}

void MainWindow::on_pushButtonDivide_clicked(){
    addToLineEdit("/");
}

void MainWindow::on_pushButtonMultiply_clicked(){
    addToLineEdit("*");
}

void MainWindow::on_pushButtonNeg_clicked(){
    addToLineEdit("NEG");
}

void MainWindow::on_pushButtonDollar_clicked(){
    addToLineEdit("$");
}

void MainWindow::on_pushButtonAnd_clicked(){
    addToLineEdit("AND");
}

void MainWindow::on_pushButtonOr_clicked(){
    addToLineEdit("OR");
}

void MainWindow::on_pushButtonNot_clicked(){
    addToLineEdit("NOT");
}

void MainWindow::on_pushButtonNum_clicked(){
    addToLineEdit("NUM");
}

void MainWindow::on_pushButtonDen_clicked(){
    addToLineEdit("DEN");
}

void MainWindow::on_pushButtonRe_clicked(){
    addToLineEdit("RE");
}

void MainWindow::on_pushButtonIm_clicked(){
    addToLineEdit("IM");
}

void MainWindow::on_pushButtonLeftParenthesis_clicked(){
    addToLineEdit("(");
}

void MainWindow::on_pushButtonRightParenthesis_clicked(){
    addToLineEdit(")");
}

void MainWindow::on_pushButtonPoint_clicked(){
    addToLineEdit(".");
}

void MainWindow::on_pushButtonEval_clicked(){
    addToLineEdit("EVAL");
}


/**
 * ENTER BUTTON SLOT
 */

void MainWindow::on_pushButtonEnter_clicked(){
    calculate();
}

// UNDO
void MainWindow::on_pushButtonUndo_clicked(){
    addToLineEdit("UNDO");
}

// REDO
void MainWindow::on_pushButtonRedo_clicked(){
    addToLineEdit("REDO");
}

void MainWindow::on_lineEdit_returnPressed(){
    calculate();
}

void MainWindow::on_pushButtonEdit_clicked(){
    addToLineEdit("EDIT");
}

void MainWindow::on_pushButtonClear_clicked(){
    addToLineEdit("CLEAR");
}

void MainWindow::on_pushButtonSwap_clicked(){
    addToLineEdit("SWAP");
}

void MainWindow::on_pushButtonLastOp_clicked(){
    addToLineEdit("LASTOP");
}

void MainWindow::on_pushButtonDrop_clicked(){
    addToLineEdit("DROP");
}

void MainWindow::on_pushButtonDup_clicked(){
    addToLineEdit("DUP");
}

void MainWindow::on_pushButtonLastArgs_clicked(){
    addToLineEdit("LASTARGS");
}


/**
 * Open windows
 */

void MainWindow::on_toolButtonProgram_clicked(){
    if(progDial != 0) delete progDial;
    progDial = new ProgramDialog(calc);
    progDial->show();
}

void MainWindow::on_toolButtonVariable_clicked(){
    if(atomDial != 0) delete atomDial;
    atomDial = new AtomDialog(calc);
    atomDial->show();
}
