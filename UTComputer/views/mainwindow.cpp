#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(Calculator *calc, Database *db, Sound *sound, QWidget *parent) :
        calc(calc),
        db(db),
        QMainWindow(parent),
        sound(sound),
        ui(new Ui::MainWindow)
{
    // init with data in database
    vector<vector<string>> progs = db->getPrograms();
    qDebug() << "Get programs from DB = " << progs.size() <<endl;

    try{
        calc->init_program_map(progs);
        calc->init_atom_map(db->getAtoms());
        calc->init_stack(db->getStack());
    } catch(UTComputerException e){
        qDebug() << QString::fromStdString(e.getMessage());
    }
    ui->setupUi(this);
    refreshView();
}

MainWindow::~MainWindow()
{
    db->sync(calc->save_program_map(), calc->save_atom_map(), calc->save_stack());
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
    sound->play();
}

void MainWindow::refreshView(){
    vector<string> elements = calc->getSt().getLastElementsString(120);
    updateValueLineEdit("");
    updateStackDisplay(elements);
}

void MainWindow::updateStackDisplay(vector<string> elems){
    ui->listWidget->clear();

    for(int i = 0; i < elems.size(); i++){
        QString qs = QString::fromStdString(elems[i]);

        /* Test to display only what the QListWidget can contains, not conclusive */
        /*
        QFontMetrics metrics(ui->listWidget->font());
        int textInPixeles = metrics.width(qs);

        if (qs.length() > textInPixeles) {
            QString new_qs = qs.mid(0,textInPixeles-5) + "..." + qs.mid(qs.length()-1,qs.length()-1);
            ui->listWidget->addItem(new_qs);
        }
        else {
            ui->listWidget->addItem(qs);
        }
        */

        ui->listWidget->addItem(qs);
    }
}

void MainWindow::calculate(){
    try{
       ui->errorTextArea->setText("");
       calc->run(getLineEditValue());
       refreshView();
    } catch(UTComputerException e){
        displayError(e.getMessage());
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1) {
    try{
        string text = arg1.toUtf8().constData();
        if(text.size() > 0){
            char lastElement = text[text.size()-1];
            if(!expressionLocked && !programLocked){
                if(lastElement == '+' || lastElement == '-' || lastElement == '/' || lastElement == '*' || lastElement == '$'){
                    calculate();
                }

                if(lastElement == '\''){
                    expressionLocked = true;
                }

                if(lastElement == '['){
                    programLocked = true;
                }
            } else if(expressionLocked){
                if(lastElement == '\''){
                    expressionLocked = false;
                }
            } else if(programLocked){
                if(lastElement == ']'){
                    programLocked = false;
                }
            } else {

                if(lastElement == '\''){
                    expressionLocked = true;
                }

                if(lastElement == '['){
                    programLocked = true;
                }
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
     addToLineEdit(" +");
     calculate();
}

void MainWindow::on_pushButtonMinus_clicked(){
    addToLineEdit(" -");
    calculate();
}

void MainWindow::on_pushButtonDivide_clicked(){
    addToLineEdit(" /");
    calculate();
}

void MainWindow::on_pushButtonMultiply_clicked(){
    addToLineEdit(" *");
    calculate();
}

void MainWindow::on_pushButtonNeg_clicked(){
    addToLineEdit(" NEG");
    calculate();
}

void MainWindow::on_pushButtonDollar_clicked(){
    addToLineEdit(" $");
    calculate();
}

void MainWindow::on_pushButtonAnd_clicked(){
    addToLineEdit(" AND");
    calculate();
}

void MainWindow::on_pushButtonOr_clicked(){
    addToLineEdit(" OR");
    calculate();
}

void MainWindow::on_pushButtonNot_clicked(){
    addToLineEdit(" NOT");
    calculate();
}

void MainWindow::on_pushButtonIFThen_clicked(){
    addToLineEdit(" IFT");
    calculate();
}

void MainWindow::on_pushButtonNum_clicked(){
    addToLineEdit(" NUM");
    calculate();
}

void MainWindow::on_pushButtonDen_clicked(){
    addToLineEdit(" DEN");
    calculate();
}

void MainWindow::on_pushButtonRe_clicked(){
    addToLineEdit(" RE");
    calculate();
}

void MainWindow::on_pushButtonIm_clicked(){
    addToLineEdit(" IM");
    calculate();
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
    addToLineEdit(" EVAL");
    calculate();
}


/**
 * ENTER BUTTON SLOT
 */

void MainWindow::on_pushButtonEnter_clicked(){
    calculate();
}

// UNDO
void MainWindow::on_pushButtonUndo_clicked(){
    addToLineEdit(" UNDO");
    calculate();
}

// REDO
void MainWindow::on_pushButtonRedo_clicked(){
    addToLineEdit(" REDO");
    calculate();
}

void MainWindow::on_lineEdit_returnPressed(){
    calculate();
}

void MainWindow::on_pushButtonEdit_clicked(){
    addToLineEdit(" EDIT");
    calculate();
}

void MainWindow::on_pushButtonClear_clicked(){
    addToLineEdit(" CLEAR");
    calculate();
}

void MainWindow::on_pushButtonSwap_clicked(){
    addToLineEdit(" SWAP");
    calculate();
}

void MainWindow::on_pushButtonLastOp_clicked(){
    addToLineEdit(" LASTOP");
    calculate();
}

void MainWindow::on_pushButtonDrop_clicked(){
    addToLineEdit(" DROP");
    calculate();
}

void MainWindow::on_pushButtonDup_clicked(){
    addToLineEdit(" DUP");
    calculate();
}

void MainWindow::on_pushButtonLastArgs_clicked(){
    addToLineEdit(" LASTARGS");
    calculate();
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
