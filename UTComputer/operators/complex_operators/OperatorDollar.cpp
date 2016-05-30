#include "OperatorDollar.h"


// ===============================================================================================================
// ======================                 Implement Operator interface                  ==========================
// ===============================================================================================================
/* Tests done before in superclass :
 *      - test that pointer to stack is not null
 *      - test that stack contains enough Literal* (st.size() >= operator arity)
 *      - test that every Literal* unstacked isn't null
 *
 * OperatorDollar applies to
 *      - two ComplexLiterals with no imaginary parts
 *      - NOT ON ExpressionLiteral : a complex can't have other complex numbers as imaginary or real part and we don't know
 *          what is in an ExpressionLiteral before we apply EVAL on it : maybe the ExpressionLiteral, once evaluated, will be
 *          a complex number...
 */
shared_ptr<Literal> OperatorDollar::executeSpecificOperator() {

    try {
        Literal* a = arguments[0].get();
        Literal* b = arguments[1].get();
        ComplexLiteral* comp_a = dynamic_cast<ComplexLiteral*>(a);
        ComplexLiteral* comp_b = dynamic_cast<ComplexLiteral*>(b);

        // if the two literals are instance of ComplexLiteral
        if (comp_a != nullptr && comp_b != nullptr) {
            if (comp_a->isComplex() || comp_b->isComplex())
                throw UTComputerException("Error in OperatorDollar::executeSpecificOperator : both arguments can't be complex.") ;

            return shared_ptr<ComplexLiteral>(new ComplexLiteral(
                    comp_a->getReal(),
                    comp_b->getReal()
            ));
        }

        // Here we didn't return anything or throw any exception, so both arguments have invalid type.
        throw UTComputerException("Error in OperatorDollar::executeSpecificOperator : arguments must be ComplexLiteral without imaginary part.") ;
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore(arguments[1]->toString());
        e1.insertBefore(" and ");
        e1.insertBefore(arguments[0]->toString());
        e1.insertBefore("Error in applying OperatorDollar on ");
        throw e1;
    }

}
// ===============================================================================================================

