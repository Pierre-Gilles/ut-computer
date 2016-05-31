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
    unordered_map<string, shared_ptr<Literal>> atom_map;


public:
    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================

    Calculator();

    virtual ~Calculator() { }


    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================




    const OperatorManager &getOp_manager() const {
        return op_manager;
    }

    const StackUTComputer &getSt() {
        return st;
    }

    const LexerUTComputer &getLx() const {
        return lx;
    }

    const unordered_map<string, shared_ptr<Literal>> &getAtom_map() const {
        return atom_map;
    }






    // ===============================================================================================================
    // ======================                      Class main service                        =========================
    // ===============================================================================================================


    void calculate(const vector<string> &tokens);






    // ===============================================================================================================
    // ======================                    Class other services                        =========================
    // ===============================================================================================================

    // methods used in main service calculate(const vector<string> &tokens)
    void executeEvalOperator();
    void handleAtom(const string& s);


    bool addOperator(Operator* o) {
        return op_manager.addOperator(o);
    }


    bool addAtom(const string &key, shared_ptr<Literal> l) {
        if (atomExists(key))
            throw UTComputerException("Error in Calculator::addAtom : atom already exists.");

        pair<string, shared_ptr<Literal>> atom_pair (key, l);
        atom_map.insert(atom_pair);
        return true;
    }

    bool atomExists(const string &key) const {
        unordered_map<string, shared_ptr<Literal>>::const_iterator found = atom_map.find(key);
        return !(found == atom_map.cend());
    }



};


#endif //UTCOMPUTER_CALCULATOR_H
