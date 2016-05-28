#include "OperatorRE.h"



// ===============================================================================================================
// ======================                 Implement Operator interface                  ==========================
// ===============================================================================================================
/* Tests done before in superclass :
 *      - test that pointer to stack is not null
 *      - test that stack contains enough Literal* (st.size() >= operator arity)
 *      - test that every Literal* unstacked isn't null
 *
 * OperatorRE applies to
 *      - one ComplexLiteral with or without imaginary part
 *      - an ExpressionLiteral
 */
shared_ptr<Literal> OperatorRE::executeSpecificOperator() {
    try {
        Literal* a = arguments[0].get();
        ComplexLiteral* comp_a = dynamic_cast<ComplexLiteral*>(a);
        ExpressionLiteral* exp_a = dynamic_cast<ExpressionLiteral*>(a);

        // if the two literals are instance of ComplexLiteral
        if (comp_a != nullptr)
            return shared_ptr<ComplexLiteral>(new ComplexLiteral(comp_a->getReal()));


        // if a is instance of ExpressionLiteral
        if (exp_a != nullptr) {
            string newExpresion = getKey();
            newExpresion += "(";
            newExpresion += exp_a->getValue();
            newExpresion += ")";
            return shared_ptr<ExpressionLiteral>(new ExpressionLiteral(newExpresion));
        }

        // Here we didn't return anything or throw any exception, so both arguments have invalid type.
        throw UTComputerException("Error in OperatorRE::executeSpecificOperator : argument must be a ComplexLiteral or an ExpressionLiteral.");
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore(arguments[0]->toString());
        e1.insertBefore("Error in applying OperatorRE on ");
        throw e1;
    }
}
// ===============================================================================================================

