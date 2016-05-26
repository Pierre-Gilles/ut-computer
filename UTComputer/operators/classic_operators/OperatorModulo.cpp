#include "OperatorModulo.h"


// ===============================================================================================================
// ======================                 Implement Operator interface                  ==========================
// ===============================================================================================================
/* Tests done before in superclass :
 *      - test that pointer to stack is not null
 *      - test that stack contains enough Literal* (st.size() >= operator arity)
 *      - test that every Literal* unstacked isn't null
 *
 * OperatorModulo applies to
 *      - two ComplexLiterals that are of "type" integer : no complex, no real nor rational */
shared_ptr<Literal> OperatorModulo::executeSpecificOperator() {
    try {
        Literal* a = arguments[0].get();
        Literal* b = arguments[1].get();
        ComplexLiteral* comp_a = dynamic_cast<ComplexLiteral*>(a);
        ComplexLiteral* comp_b = dynamic_cast<ComplexLiteral*>(b);

        // if the two literals are instance of ComplexLiteral
        if (comp_a != nullptr && comp_b != nullptr) {
            if (comp_a->isInteger() && comp_b->isInteger()) {
                int result = (int)comp_a->getReal().getNumerator() % (int)comp_b->getReal().getNumerator();
                return shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(result)));
            }
            else {
                throw UTComputerException("Error in OperatorModulo::executeSpecificOperator : arguments must be integers.") ;
            }
        }



        // Here we didn't return anything or throw any exception, so both arguments have invalid type.
        throw UTComputerException("Error in OperatorModulo::executeSpecificOperator : invalid literal types for both arguments") ;
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore(arguments[1]->toString());
        e1.insertBefore(" and ");
        e1.insertBefore(arguments[0]->toString());
        e1.insertBefore("Error in applying OperatorModulo on ");
        throw e1;
    }
}
// ===============================================================================================================


