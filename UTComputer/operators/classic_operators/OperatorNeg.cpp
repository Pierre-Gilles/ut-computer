#include "OperatorNeg.h"




// ===============================================================================================================
// ======================                 Implement Operator interface                  ==========================
// ===============================================================================================================
/* Tests done before in superclass :
 *      - test that pointer to stack is not null
 *      - test that stack contains enough Literal* (st.size() >= operator arity)
 *      - test that every Literal* unstacked isn't null
 *
 * OperatorNeg applies to
 *      - one ComplexLiteral
 *      - one ExpressionLiteral
 */
shared_ptr<Literal> OperatorNeg::executeSpecificOperator() {
    try {
        Literal* a = arguments[0].get();
        ComplexLiteral* comp_a = dynamic_cast<ComplexLiteral*>(a);
        ExpressionLiteral* exp_a = dynamic_cast<ExpressionLiteral*>(a);

        // if instance of ComplexLiteral
        if (comp_a != nullptr) {
            return comp_a->negOperator();
        }

        //if instance of ExpressionLiteral
        if (exp_a != nullptr) {
            string newExpresion = "NEG(";
            newExpresion += exp_a->getValue();
            newExpresion += ")";
            return shared_ptr<ExpressionLiteral>(new ExpressionLiteral(newExpresion));
        }

        // Here we didn't return anything or throw any exception, so both arguments have invalid type.
        throw UTComputerException("Error in OperatorNeg::executeSpecificOperator : invalid literal type for argument");

    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore(arguments[1]->toString());
        e1.insertBefore(" and ");
        e1.insertBefore(arguments[0]->toString());
        e1.insertBefore("Error in applying OperatorNeg on ");
        throw e1;
    }
}

// ===============================================================================================================

