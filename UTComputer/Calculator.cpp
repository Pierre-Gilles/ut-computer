#include "Calculator.h"
#include <regex>

// ===============================================================================================================
// ======================               Constructors and Destructors                    ==========================
// ===============================================================================================================

Calculator::Calculator() {
    // Classic Operators
    op_manager.addOperator(new OperatorPlus());
    op_manager.addOperator(new OperatorMinus());
    op_manager.addOperator(new OperatorMultiplication());
    op_manager.addOperator(new OperatorDivision());
    op_manager.addOperator(new OperatorIntegerDivision());
    op_manager.addOperator(new OperatorModulo());
    op_manager.addOperator(new OperatorNeg());

    // Logical Operators
    op_manager.addOperator(new OperatorAnd());
    op_manager.addOperator(new OperatorDifferent());
    op_manager.addOperator(new OperatorEqual());
    op_manager.addOperator(new OperatorInferior());
    op_manager.addOperator(new OperatorInferiorEqual());
    op_manager.addOperator(new OperatorNot());
    op_manager.addOperator(new OperatorOr());
    op_manager.addOperator(new OperatorSuperior());
    op_manager.addOperator(new OperatorSuperiorEqual());

    // Rational Operators
    op_manager.addOperator(new OperatorNumerator());
    op_manager.addOperator(new OperatorDenominator());

    // Complex Operators
    op_manager.addOperator(new OperatorDollar());
    op_manager.addOperator(new OperatorIM());
    op_manager.addOperator(new OperatorRE());

    // Stack Operators
    op_manager.addOperator(new OperatorCLEAR());
    op_manager.addOperator(new OperatorDROP());
    op_manager.addOperator(new OperatorDUP());
    op_manager.addOperator(new OperatorLASTARGS());
    op_manager.addOperator(new OperatorLASTOP());
    op_manager.addOperator(new OperatorREDO());
    op_manager.addOperator(new OperatorUNDO());
    op_manager.addOperator(new OperatorSWAP());
}








// ===============================================================================================================
// ======================                      Class main service                        =========================
// ===============================================================================================================


void Calculator::calculate(const vector<string> &tokens) {

    try {
        // save initial state before iterating through the tokens
        st.createMemento();

        for (auto it = tokens.cbegin(); it != tokens.cend(); ++it) {

            // Special case for Operator EVAL
            if (*it == "EVAL") {
                executeEvalOperator();
            }


            // Special case for Operator EDIT
            else if (*it == "EDIT") {
                throw UTComputerException("Sorry, operator EDIT is not implemented yet.");
            }


            // If it's an atom literal : string with capital letters and number beginning
            else if (std::regex_match(*it, regex(AtomLiteral::getAtomRegex()))) {
                handleAtom(*it);
            }


            else if (op_manager.operatorExists(*it)) {
                op_manager.getOperator(*it)->execute(&st);
            }

            else {
                /* Appeler LiteralFactory qui créera soit un Complex, soit une Expression, soit un Program.
                 * Si le string *it passé à la factory ne permet pas de créer une Literal, alors c'est qu'il y a une erreur
                 * dans le string (mauvaise saisie) qui est lancée par la factory et attrapée ici.
                 * */
                shared_ptr<Literal> newLit = lf.createLiteral(*it);
                st.push(newLit);
            }

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
// ======================                    Class other services                        =========================
// ===============================================================================================================




// methods used in main service calculate(const vector<string> &tokens)
void Calculator::executeEvalOperator() {
    ExpressionLiteral *exp = dynamic_cast<ExpressionLiteral*>(st.top().get());
    ProgramLiteral *prgm = dynamic_cast<ProgramLiteral*>(st.top().get());

    if (exp != nullptr) { // if exp is indeed an ExpressionLiteral
        // vector<string> infix_tokens = lx.tokenize(exp->getValue()); // here we have a vector of string containing infix expression tokens
        // string postfix_expression = lx.infixToPostfix(infix_tokens);
        // vector<string> postfix_tokens = lx.tokenize(postfix_expression);

        /* Need to check constraints before evaluating expression :
        *  - Si la littérale expression comprend au moins un atome qui ne correspond pas au nom d’une variable, l’évaluation n’a aucune effet et un message en informe l’utilisateur.
        *  - Si la littérale expression comprend au moins un atome qui correspond à l’identificateur d’un programme, l’évaluation n’a aucun effet et un message d’erreur informe l’utilisateur.
         * - Si tous les atomes de la littérales expression sont des identificateurs de variable, l’expression est évaluée numériquement.
         *  */
        // calculate(postfix_tokens); // recursive call to calculate
    }
    else if (prgm != nullptr) {
        // vector<string> postfix_tokens = lx.tokenize(prgm->getValue());
        // calculate(postfix_tokens); // recursive call to calculate
    }
    else {
        throw UTComputerException("Error Calculator::executeEvalOperator() : call to EVAL and stack top isn't an Expression or Program.");
    }
}


void Calculator::handleAtom(const string& s) {
    unordered_map<string, shared_ptr<Literal>>::const_iterator found = atom_map.find(s);

    // If we found the atom in the atom_map
    if (found != atom_map.cend()) {

        ComplexLiteral *comp = dynamic_cast<ComplexLiteral*>(atom_map[s].get());
        ProgramLiteral *prgm = dynamic_cast<ProgramLiteral*>(atom_map[s].get());

        // if it's a variable (ComplexLiteral), we need to stack it
        if (comp != nullptr) {
            st.push(atom_map[s]);
        }

            // if it's a program, we need to evaluate it
        else if (prgm != nullptr) {
            // calculate(lx.tokenize(prgm->getValue()));
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



