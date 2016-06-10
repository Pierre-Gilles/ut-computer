#ifndef UTCOMPUTER_CALCULATOR_H
#define UTCOMPUTER_CALCULATOR_H

#include "exceptions/UTComputerException.h"
#include "operators/OperatorManager.h"
#include "stack/StackUTComputer.h"
#include "lexer/Lexer.h"
#include "literals/LiteralFactory.h"


/**
 * \class Calculator
 * \brief Main class of the application
 */
class Calculator {

    OperatorManager op_manager;
    LiteralFactory lf;
    StackUTComputer st;
    LexerUTComputer lx;
    unordered_map<string, shared_ptr<ProgramLiteral>> program_map;
    unordered_map<string, shared_ptr<AtomLiteral>> atom_map;


public:


    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    /**
     * \fn Calculator()
     * \brief Constructor
     * \return A new instance of Calculator
     *
     * The constructor is in charge of creating all the basic Operator used in this application by calling the method
     * Calculator::addOperator
     */
    Calculator();
    virtual ~Calculator() { }
    // ===============================================================================================================






    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================

    /**
     * \fn const OperatorManager &getOp_manager() const
     * \brief Getter for the private attribute \a op_manager
     * \return The private attribute
     */
    const OperatorManager &getOp_manager() const;


    /**
     * \fn const StackUTComputer &getSt()
     * \brief Getter for the private attribute \a st (instance of StackUTComputer)
     * \return The private attribute \a st (instance of StackUTComputer)
     */
    const StackUTComputer &getSt();


    /**
     * \fn const LexerUTComputer &getLx() const
     * \brief Getter for the private attribute \a lx (instance of LexerUTComputer)
     * \return The private attribute \a lx (instance of LexerUTComputer)
     */
    const LexerUTComputer &getLx() const;

    // ===============================================================================================================






    // ===============================================================================================================
    // ======================               Saving and initiating application                         ================
    // ===============================================================================================================

    /**
     * \fn void init_program_map(vector<vector<string>> list)
     * \brief Method that init the \a program_map attribute with the information stored in the SQLite database
     * \param[in] list : vector of a vector of string
     */
    void init_program_map(vector<vector<string>> list);

    /**
     * \fn void init_program_map(vector<vector<string>> list)
     * \brief Method that init the \a program_map attribute with the information stored in the SQLite database
     * \return
     */
    vector<vector<string>> save_program_map() const;


    // TODO continuer documentation
    /**
     * \fn void init_atom_map(vector<vector<string>> list)
     * \brief Method that init the \a atom_map attribute with the information stored in the SQLite database
     * \param[in] list : vector of a vector of string
     */
    void init_atom_map(vector<vector<string>> list);

    vector<vector<string>> save_atom_map() const;

    void init_stack(vector<string> list);

    vector<string> save_stack() const;
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
