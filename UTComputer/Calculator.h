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
    unordered_map<string, shared_ptr<Literal>> atom_map;


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
     * \fn vector<vector<string>> save_program_map() const
     * \brief Method that save the \a program_map attribute in a vector of vector of string
     * \return A vector of a vector of string containing the \a program_map attribute
     */
    vector<vector<string>> save_program_map() const;


    /**
     * \fn void init_atom_map(vector<vector<string>> list)
     * \brief Method that init the \a atom_map attribute with the information stored in the SQLite database
     * \param[in] list : vector of a vector of string
     */
    void init_atom_map(vector<vector<string>> list);

    /**
     * \fn vector<vector<string>> save_atom_map() const
     * \brief Method that save the \a atom_map attribute in a vector of vector of string
     * \return A vector of a vector of string containing the \a atom_map attribute
     */
    vector<vector<string>> save_atom_map() const;

    /**
     * \fn void init_stack(vector<string> list)
     * \brief Method that init the \a st attribute with the information stored in the SQLite database
     * \param[in] list : vector of string
     */
    void init_stack(vector<string> list);

    /**
     * \fn vector<string> save_stack() const
     * \brief Method that save the \a st attribute in a vector of string
     * \return A vector of string containing the \a st attribute
     */
    vector<string> save_stack() const;
    // ===============================================================================================================








    // ===============================================================================================================
    // ======================                      Class main service                        =========================
    // ===============================================================================================================

    /**
     * \fn void run(const string &s)
     * \brief Main function of the Calculator class that calculate the result of the operations contained in the string parameter
     * \param[in] s : string containing the operations to calculate
     */
    void run(const string &s);

    /**
     * \fn void calculate(const vector<string> &tokens)
     * \brief Method that will process each token
     * \param[in] tokens : a vector of string containing the tokens to process
     */
    void calculate(const vector<string> &tokens);
    // ===============================================================================================================







    // ===============================================================================================================
    // ======================                    Class other services                        =========================
    // ===============================================================================================================

    // methods used in main service calculate(const vector<string> &tokens)

    /**
     * \fn void executeEvalOperator()
     * \brief Method dedicated to run the EVAL operator
     */
    void executeEvalOperator();

    /**
     * \fn void handleAtom(const string& s);
     * \brief Method dedicated to process an Atom
     * \param[in] s : the string containing the atom
     */
    void handleAtom(const string& s);

    /**
     * \fn bool checkExpressionCorrectForEval(vector<string> &tokens)
     * \brief Method that check if an ExpressionLiteral is correct before evaluating it
     * \param[in] tokens : all tokens of the ExpressionLiteral to evaluate
     * \return True if the ExpressionLiteral is correct, false otherwise
     *
     * Rules :
     * If there is an atom in "postfix_tokens"
     *  - if it's not present in the atom_mat --> fail
     *  - if it's a program --> fail
     *  - if it's not a complex --> fail
     * - otherwise --> continue
     */
    bool checkExpressionCorrectForEval(vector<string> &tokens);
    // ===============================================================================================================







    // ===============================================================================================================
    // =================              MANAGING PROGRAMS ANS ATOMS(variables)                        ==================
    // ===============================================================================================================

    /**
     * \fn bool atomFound(const string &s) const
     * \brief Method that check if an atom exists in the private attribute \a atom_map
     * \param[in] s : the key of the atom
     * \return True if the atom exists in \a atom_map , false otherwise
     */
    bool atomFound(const string &s) const;


    /**
     * \fn bool programFound(const string &s) const
     * \brief Method that check if an Atom exists in the private attribute \a program_map
     * \param[in] s : the key of the program
     * \return True if the ProgramLiteral exists in \a program_map, false otherwise
     */
    bool programFound(const string &s) const;


    /**
     * \fn bool atomIsNumeric(const string &s) const
     * \brief Check if an atom contained in \a atom_map is instance of ComplexLiteral
     * \param[in] s : the key of the atom
     * \return True if the atom is in fact a ComplexLiteral, false otherwise
     */
//    bool atomIsNumeric(const string &s) const;


    /**
     * \fn bool atomIsProgram(const string &s) const
     * \brief Check if an atom contained in \a atom_map is instance of ProgramLiteral
     * \param[in] s : the key of the atom
     * \return True if the atom is in fact a ProgramLiteral, false otherwise
     */
//    bool atomIsProgram(const string &s) const;


    /**
     * \fn bool addOperator(Operator* o)
     * \brief Method that add an Operator to the Calculator
     * \param[in] o : the pointer to the Operator to add
     * \return True if the Operator can be added, false otherwise
     *
     * This method add an Operator to the OperatorManager and the Lexer attributes of the Calculator :
     * this new Operator can now be used in all the application
     */
    bool addOperator(Operator* o);


    /**
     * \fn bool addAtom(const string &key, const string &value)
     * \brief Method that add an atom to the \a atom_map attribute
     * \param[in] key : the key of the atom
     * \param[in] value : the value of the atom
     * \return True if atom can be added, false otherwise
     */
    bool addAtom(const string &key, const string &value);


    /**
     * \fn bool addProgram(const string &key, const string &value)
     * \brief Method that add a program to the \a program_map attribute
     * \param[in] key : the key of the program
     * \param[in] value : the value of the program
     * \return True if program can be added, false otherwise
     */
    bool addProgram(const string &key, const string &value);

    /**
     * \fn bool updateProgram(const string &key, const string &value)
     * \brief Method that update a program in the \a program_map attribute
     * \param[in] key : the key of the program
     * \param[in] value : the value of the program
     * \return True if program can be updated, false otherwise
     */
    bool updateProgram(const string &key, const string &value);

    /**
     * \fn bool updateAtom(const string &key, const string &value)
     * \brief Method that update an atom in the \a atom_map attribute
     * \param[in] key : the key of the atom
     * \param[in] value : the value of the atom
     * \return True if atom can be updated, false otherwise
     */
     bool updateAtom(const string &key, const string &value);

    /**
     * \fn bool deleteAtom(const string &key)
     * \brief Method that delete an atom in the \a atom_map attribute
     * \param[in] key : the key of the atom to delete
     * \return True if atom has been deleted, false otherwise
     */
    bool deleteAtom(const string &key);


    /**
     * \fn bool deleteProgram(const string &key)
     * \brief Method that update an atom in the \a program_map attribute
     * \param[in] key : the key of the program to delete
     * \return True if program has been deleted, false otherwise
     */
    bool deleteProgram(const string &key);




    // ===============================================================================================================
};


#endif //UTCOMPUTER_CALCULATOR_H
