#include "OperatorEqual.h"



// ===============================================================================================================
// ======================                 Implement Operator interface                  ==========================
// ===============================================================================================================
/* Tests done before in superclass :
 *      - test that pointer to stack is not null
 *      - test that stack contains enough Literal* (st.size() >= operator arity)
 *      - test that every Literal* unstacked isn't null
 *
 * OperatorEqual applies to
 *      - two ComplexLiterals with no imaginary parts
 */
shared_ptr<Literal> OperatorEqual::executeSpecificOperator() {
    try {
        Literal* a = arguments[0].get();
        Literal* b = arguments[1].get();
        ComplexLiteral* comp_a = dynamic_cast<ComplexLiteral*>(a);
        ComplexLiteral* comp_b = dynamic_cast<ComplexLiteral*>(b);

        // if the two literals are instance of ComplexLiteral
        if (comp_a != nullptr && comp_b != nullptr) {
            if (*comp_a == *comp_b) // then return a ComplexLiteral set to "integer" with a value of 1
                return shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1.0)));
            else // then return a ComplexLiteral set to "integer" with a value of 0
                return shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(0.0)));
        }

        // Here we didn't return anything or throw any exception, so both arguments have invalid type.
        throw UTComputerException("Error in OperatorInferior::executeSpecificOperator : invalid literal types") ;
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore(arguments[1]->toString());
        e1.insertBefore(" and ");
        e1.insertBefore(arguments[0]->toString());
        e1.insertBefore("Error in applying OperatorPlus on ");
        throw e1;
    }

}
// ===============================================================================================================
