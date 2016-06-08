// TOTO doc
#ifndef UTCOMPUTER_CALCULATOR_H
#define UTCOMPUTER_CALCULATOR_H

#include "exceptions/UTComputerException.h"
#include "operators/OperatorManager.h"
#include "stack/StackUTComputer.h"
#include "lexer/Lexer.h"
#include "literals/LiteralFactory.h"


class Calculator {

    OperatorManager op_manager;
    LiteralFactory lf;
    StackUTComputer st;
    LexerUTComputer lx;
    unordered_map<string, shared_ptr<AtomLiteral>> atom_map;
    unordered_map<string, shared_ptr<ProgramLiteral>> program_map;


public:


    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    Calculator();
    virtual ~Calculator() { }
    // ===============================================================================================================






    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================

    const OperatorManager &getOp_manager() const;

    const StackUTComputer &getSt();

    const LexerUTComputer &getLx() const;

    void init_program_map(vector<vector<string>> list);

    vector<vector<string>> save_program_map() const;

    void init_atom_map(vector<vector<string>> list);

    vector<vector<string>> save_atom_map() const;

    // ===============================================================================================================






    // ===============================================================================================================
    // ======================                      Class main service                        =========================
    // ===============================================================================================================




    void run(const string &s);
    void calculate(const vector<string> &tokens);
    // ===============================================================================================================







    // ===============================================================================================================
    // ======================                    Class other services                        =========================
    // ===============================================================================================================

    // methods used in main service calculate(const vector<string> &tokens)
    void executeEvalOperator();
    void handleAtom(const string& s);
    bool checkExpressionCorrectForEval(vector<string> &tokens);
    // ===============================================================================================================







    // ===============================================================================================================
    // ======================                  Class useful functions                        =========================
    // ===============================================================================================================
    bool atomFound(const string &s) const;
    bool programFound(const string &s) const;
    bool atomIsNumeric(const string &s);
    bool atomIsProgram(const string &s);
    bool addOperator(Operator* o);
    bool addAtom(const string &key, const string &value);
    bool addProgram(const string &key, const string &value);
    // ===============================================================================================================
};


#endif //UTCOMPUTER_CALCULATOR_H
