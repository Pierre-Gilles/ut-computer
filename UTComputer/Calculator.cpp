#include "Calculator.h"

// ===============================================================================================================
// ======================               Constructors and Destructors                    ==========================
// ===============================================================================================================

Calculator::Calculator() {
    // Classic Operators
    addOperator(new OperatorPlus());
    addOperator(new OperatorMinus());
    addOperator(new OperatorMultiplication());
    addOperator(new OperatorDivision());
    addOperator(new OperatorIntegerDivision());
    addOperator(new OperatorModulo());
    addOperator(new OperatorNeg());

    // Logical Operators
    addOperator(new OperatorAnd());
    addOperator(new OperatorDifferent());
    addOperator(new OperatorEqual());
    addOperator(new OperatorInferior());
    addOperator(new OperatorInferiorEqual());
    addOperator(new OperatorNot());
    addOperator(new OperatorOr());
    addOperator(new OperatorSuperior());
    addOperator(new OperatorSuperiorEqual());

    // Rational Operators
    addOperator(new OperatorNumerator());
    addOperator(new OperatorDenominator());

    // Complex Operators
    addOperator(new OperatorDollar());
    addOperator(new OperatorIM());
    addOperator(new OperatorRE());

    // Stack Operators
    addOperator(new OperatorCLEAR());
    addOperator(new OperatorDROP());
    addOperator(new OperatorDUP());
    addOperator(new OperatorLASTARGS());
    addOperator(new OperatorLASTOP());
    addOperator(new OperatorREDO());
    addOperator(new OperatorUNDO());
    addOperator(new OperatorSWAP());
}
// ===============================================================================================================










// ===============================================================================================================
// ======================                       Getters and Setters                     ==========================
// ===============================================================================================================

const OperatorManager & Calculator::getOp_manager() const {
    return op_manager;
}

const StackUTComputer & Calculator::getSt() {
    return st;
}

const LexerUTComputer & Calculator::getLx() const {
    return lx;
}
// ===============================================================================================================




// ===============================================================================================================
// ======================               Saving and initiating application                         ================
// ===============================================================================================================

void Calculator::init_program_map(vector<vector<string>> list) {
    for (auto line = list.cbegin(); line != list.cend(); ++line) {
        if (line->size() != 2)
            throw UTComputerException("Error in Calculator::init_program_map : Each line must contains two columns : key and value");

        addProgram(line->at(0), line->at(1));
    }
}

vector<vector<string>> Calculator::save_program_map() const {
    vector<vector<string>> lines;
    vector<string> one_line;
    for ( auto it = program_map.cbegin(); it != program_map.cend(); ++it ) {
        one_line.push_back(it->first);
        one_line.push_back(it->second.get()->getValue());
        lines.push_back(one_line);
        one_line.clear();
    }
    return lines;
}

void Calculator::init_atom_map(vector<vector<string>> list) {
    for (auto line = list.cbegin(); line != list.cend(); ++line) {
        if (line->size() != 2)
            throw UTComputerException("Error in Calculator::init_program_map : Each line must contains two columns : key and value");

        addAtom(line->at(0), line->at(1));
    }
}

vector<vector<string>> Calculator::save_atom_map() const {
    vector<vector<string>> lines;
    vector<string> one_line;
    for ( auto it = atom_map.cbegin(); it != atom_map.cend(); ++it ) {
        one_line.push_back(it->first);
        one_line.push_back(it->second.get()->toString());
        lines.push_back(one_line);
        one_line.clear();
    }
    return lines;
}


void Calculator::init_stack(vector<string> list) {
    /* List is an reverse replica of the stack, meaning the end of the stack is at the beginning of the vector "list" */

    for (auto it = list.cbegin(); it != list.cend(); ++it) {
        shared_ptr<Literal> newLit = lf.createLiteral(*it);
        st.push(newLit);
    }
}

vector<string> Calculator::save_stack() const {
    vector<string> result;
    result.reserve(st.size());
    /* Iterate through the stack from the end to the beginning  */
    for (auto it = st.getSt().crbegin(); it != st.getSt().crend(); ++it) {
        /* using push_back because of it's constant complexity (amortized time, reallocation may happen) */
        result.push_back(st.top()->toString());
    }

    /* Now result is an reverse replica of the stack, but it contains string instead of shared_ptr<Literal> */
    return result;
}
// ===============================================================================================================










// ===============================================================================================================
// ======================                      Class main service                        =========================
// ===============================================================================================================

void Calculator::run(const string &s) {
    calculate(lx.tokenize(s));
}

void Calculator::calculate(const vector<string> &tokens) {

    try {

        if(tokens.size() >= 1) {
            // save initial state before iterating through the tokens
            if (tokens[0] != "UNDO" && tokens[0] != "REDO") {
                st.createMemento();
            }
        }

        for (auto it = tokens.cbegin(); it != tokens.cend(); ++it) {

            // Special case for Operator EVAL
            if (*it == "EVAL") {
                executeEvalOperator(); /* TODO peut être dupliquer et lui passer l'adresse du memento créé avant de
                                        * rentrer dans la boucle : si erreur dans executeEvalOperator, le specifier
                                        * et remettre la stack dans l'état du memento*/
            }


            // Special case for Operator EDIT
            else if (*it == "EDIT") {
                throw UTComputerException("Sorry, operator EDIT is not implemented yet.");
            }


            else if (op_manager.operatorExists(*it)) {
                op_manager.getOperator(*it)->execute(&st);
            }


            // If it's an atom literal : string with capital letters and number beginning
            else if (std::regex_match(*it, regex(AtomLiteral::getAtomRegex()))) {
                handleAtom(*it);
            }


            else {
                /* Appeler LiteralFactory qui créera soit un Complex, soit une Expression, soit un Program.
                 * Si le string *it passé à la factory ne permet pas de créer une Literal, alors c'est qu'il y a une erreur
                 * dans le string (mauvaise saisie) qui est lancée par la factory et attrapée ici.
                 * */
                shared_ptr<Literal> newLit = lf.createLiteral(*it);
                st.push(newLit);
            }

            if(*it != "UNDO" && *it != "REDO" )
                // save new state after calculate is done for a token
                st.createMemento();
        }
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore("Error in applying Calculator::calculate() ");
        throw e1;
    }
}
// ===============================================================================================================







// ===============================================================================================================
// ======================                    Class other services                        =========================
// ===============================================================================================================


// methods used in main service calculate(const vector<string> &tokens)
void Calculator::executeEvalOperator() {
    ExpressionLiteral *exp = dynamic_cast<ExpressionLiteral*>(st.top().get());
    ProgramLiteral *prgm = dynamic_cast<ProgramLiteral*>(st.top().get());

    if (exp != nullptr) { // if exp is indeed an ExpressionLiteral
        /* Get the expression value into postfixe notation and in a vector<string> */
        vector<string> postfix_tokens = lx.tokenizeInfixToPostfix(exp->getValue());

        /* Need to check constraints before evaluating expression :
         * If there is an atom in "postfix_tokens"
         *  - if it's not present in the atom_mat --> fail
         *  - if it's a program --> fail
         *  - if it's a complex --> ok continue
         *  - if it's not a program or a complex --> fail
         *  */
        if (! checkExpressionCorrectForEval(postfix_tokens))
            throw UTComputerException("Error Calculator::executeEvalOperator() : the Expression contains invalid atom.");
        st.pop(); // delete the expression before eval //TODO peut être la sauvegarder quelque part si jamais y'a des erreurs dans l'evaluation
        calculate(postfix_tokens); // recursive call to calculate
    }
    else if (prgm != nullptr) {
        vector<string> postfix_tokens = lx.tokenize(prgm->getValue());
        st.pop(); // delete the program before eval //TODO peut être la sauvegarder quelque part si jamais y'a des erreurs dans l'evaluation
        calculate(postfix_tokens); // recursive call to calculate
    }
    else {
        throw UTComputerException("Error Calculator::executeEvalOperator() : call to EVAL and stack top isn't an Expression or Program.");
    }
}

void Calculator::handleAtom(const string& s) {
    // If we find the atom in the atom_map
    if (atomFound(s)) {

        // if it's a variable (ComplexLiteral), we need to stack it
        if (atomIsNumeric(s)) {
            st.pop(); // delete the atom before eval //TODO peut être la sauvegarder quelque part si jamais y'a des erreurs dans l'evaluation
            st.push(atom_map[s]);
        }

        // if it's a program, we need to evaluate it
        else if (atomIsProgram(s)) {
            vector<string> postfix_tokens = lx.tokenize(dynamic_cast<ProgramLiteral*>(atom_map[s].get())->getValue());
            st.pop(); // delete the atom before eval //TODO peut être la sauvegarder quelque part si jamais y'a des erreurs dans l'evaluation
            calculate(postfix_tokens); // recursive call to calculate
        }

        // it's not a variable nor a program, error because atom_map contains variable or program
        else {
            throw UTComputerException("Error Calculator::calculate() : atom_map contains an atom that is not a complex or a program.");
        }

    }
    // it's not a variable nor a program : we need to create a nex ExpressionLiteral and stack it
    else {
        st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral(s)));
    }
}


/*
* If there is an atom in "postfix_tokens"
*  - if it's not present in the atom_mat --> fail
*  - if it's a program --> fail
*  - if it's not a complex --> failcontinue
* - otherwise --> continue
*/
bool Calculator::checkExpressionCorrectForEval(vector<string> &tokens) {

    regex atomRegex(AtomLiteral::getAtomRegex());

    for (auto it = tokens.cbegin(); it != tokens.cend(); ++it) {
        if (regex_match(*it, atomRegex)) { // if it's an atom in the literal we have to evaluate

            // test first if the atom correspond to a known operator : if it's the case, go to next iteration
            if (!op_manager.operatorExists(*it)) {
                if (! atomFound(*it))
                    return false;

                if (atomIsProgram(*it))
                    return false;

                if (! atomIsNumeric(*it))
                    return false;
            }

        }
    }
    return true;
}
// ===============================================================================================================






// ===============================================================================================================
// ======================                  Class useful functions                        =========================
// ===============================================================================================================



bool Calculator::atomFound(const string &s) const {
    unordered_map<string, shared_ptr<Literal>>::const_iterator found = atom_map.find(s);
    return (found != atom_map.cend());
}

bool Calculator::programFound(const string &s) const {
    unordered_map<string, shared_ptr<ProgramLiteral>>::const_iterator found = program_map.find(s);
    return !(found == program_map.cend());
}


bool Calculator::atomIsNumeric(const string &s) const {
    ComplexLiteral *comp = dynamic_cast<ComplexLiteral*>(atom_map.at(s).get());
    return (comp != nullptr);
}

bool Calculator::atomIsProgram(const string &s) const {
    ProgramLiteral *prgm = dynamic_cast<ProgramLiteral*>(atom_map.at(s).get());
    return (prgm != nullptr);
}

bool Calculator::addOperator(Operator* o) {
    return op_manager.addOperator(o) && lx.addOperatorWeight(o);
}

bool Calculator::addAtom(const string &key, const string &value) {
    if (atomFound(key))
        throw UTComputerException("Error in Calculator::addAtom : atom already exists.");

    pair<string, shared_ptr<Literal>> atom_pair (key, lf.createLiteral(value));
    atom_map.insert(atom_pair);
    return true;
}

bool Calculator::addProgram(const string &key, const string &value) {
    if (programFound(key))
        throw UTComputerException("Error in Calculator::addProgram : program already exists.");

    pair<string, shared_ptr<ProgramLiteral>> program_pair (key, shared_ptr<ProgramLiteral>(new ProgramLiteral(value)));
    program_map.insert(program_pair);
    return true;
}

bool Calculator::updateAtom(const string &key, const string &value){
    if (!atomFound(key))
        throw UTComputerException("Error in Calculator::updateAtom : cant find atom.");

    atom_map[key] = shared_ptr<ProgramLiteral>(new ProgramLiteral(value));
    return true;
}

bool Calculator::updateProgram(const string &key, const string &value){
    if (!programFound(key))
        throw UTComputerException("Error in Calculator::updateProgram : cant find program.");

    program_map[key] = shared_ptr<ProgramLiteral>(new ProgramLiteral(value));
    return true;
}

// ===============================================================================================================




