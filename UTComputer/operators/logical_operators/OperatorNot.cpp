#include "OperatorNot.h"



// ===============================================================================================================
// ======================                 Implement Operator interface                  ==========================
// ===============================================================================================================
/* Tests done before in superclass :
 *      - test that pointer to stack is not null
 *      - test that stack contains enough Literal* (st.size() >= operator arity)
 *      - test that every Literal* unstacked isn't null
 *
 * OperatorNot applies to
 *      - a ComplexLiteral with no imaginary part
 *      - one ExpressionLiteral returning NOT(exp1)
 */
shared_ptr<Literal> OperatorNot::executeSpecificOperator() {
    try {
        Literal* a = arguments[0].get();
        ComplexLiteral* comp_a = dynamic_cast<ComplexLiteral*>(a);
        ExpressionLiteral* exp_a = dynamic_cast<ExpressionLiteral*>(a);

        // if a is instance of ComplexLiteral
        if (comp_a != nullptr ) {
            if (!(*comp_a)) // then return a ComplexLiteral set to "integer" with a value of 1
                return shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1.0)));
            else // then return a ComplexLiteral set to "integer" with a value of 0
                return shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.0)));
        }
        /* Note that the ComplexLiteral class throw exception if imaginary parts the
         * arguments is different from 0*/

        // if a is instance of ExpressionLiteral
        if (exp_a != nullptr) {
            string newExpresion = getKey();
            newExpresion += "(";
            newExpresion += exp_a->getValue();
            newExpresion += ")";
            return shared_ptr<ExpressionLiteral>(new ExpressionLiteral(newExpresion));
        }

        // Here we didn't return anything or throw any exception, so both arguments have invalid type.
        throw UTComputerException("Error in OperatorNot::executeSpecificOperator : invalid literal types") ;
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore(arguments[0]->toString());
        e1.insertBefore("Error in applying OperatorNot on ");
        throw e1;
    }

}
// ===============================================================================================================
