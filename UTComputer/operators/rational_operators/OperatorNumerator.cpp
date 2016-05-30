#include "OperatorNumerator.h"

// ===============================================================================================================
// ======================                 Implement Operator interface                  ==========================
// ===============================================================================================================
/* Tests done before in superclass :
 *      - test that pointer to stack is not null
 *      - test that stack contains enough Literal* (st.size() >= operator arity)
 *      - test that every Literal* unstacked isn't null
 *
 * OperatorNumerator applies to
 *      - a ComplexLiteral that is really only a rational
 *      - an ExpressionLiteral
 */
shared_ptr<Literal> OperatorNumerator::executeSpecificOperator() {
    try {
        Literal* a = arguments[0].get();
        ComplexLiteral* comp_a = dynamic_cast<ComplexLiteral*>(a);
        ExpressionLiteral* exp_a = dynamic_cast<ExpressionLiteral*>(a);

        // if a is instance of ComplexLiteral
        if (comp_a != nullptr ) {
            double num;
            if (comp_a->isRational() || comp_a->isInteger()) {
                num = comp_a->getReal().getNumerator();
                return shared_ptr<ComplexLiteral>(new ComplexLiteral(num));
            }
            else {
                throw UTComputerException("Error in OperatorNumerator::executeSpecificOperator : argument must be a rational or integer.");
            }
        }

        // if a is instance of ExpressionLiteral
        if (exp_a != nullptr) {
            string newExpresion = getKey();
            newExpresion += "(";
            newExpresion += exp_a->getValue();
            newExpresion += ")";
            return shared_ptr<ExpressionLiteral>(new ExpressionLiteral(newExpresion));
        }

        // Here we didn't return anything or throw any exception, so both arguments have invalid type.
        throw UTComputerException("Error in OperatorNumerator::executeSpecificOperator : invalid literal types") ;
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore(arguments[0]->toString());
        e1.insertBefore("Error in applying OperatorNumerator on ");
        throw e1;
    }
}
// ===============================================================================================================