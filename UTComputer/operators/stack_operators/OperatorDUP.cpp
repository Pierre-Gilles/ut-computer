#include "OperatorDUP.h"




// ===============================================================================================================
// ======================                 Implement superclass interface                ==========================
// ===============================================================================================================
/*
 * Address of stack must not be changed, but "st" do not point to a const stack : we use a constant pointer
 * and not a pointer to constant
 */

void OperatorDUP::execute(StackUTComputer * const st) {
    StackOperator::execute(st); // check usual possible errors

    try {
        Literal* a = st->top().get();
        ComplexLiteral* comp_a = dynamic_cast<ComplexLiteral*>(a);
        ExpressionLiteral* exp_a = dynamic_cast<ExpressionLiteral*>(a);
        ProgramLiteral* prm_a = dynamic_cast<ProgramLiteral*>(a);

        // if first stack element is a ComplexLiteral
        if (comp_a != nullptr) {
            st->push(shared_ptr<ComplexLiteral>(new ComplexLiteral(*comp_a)));
        }
        else if (exp_a != nullptr) {
            st->push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral(*exp_a)));
        }
        else if (prm_a != nullptr) {
            st->push(shared_ptr<ProgramLiteral>(new ProgramLiteral(*prm_a)));
        }
        else {
            // This should not happen because Stack only contains Complex, Expression or Program Literals
            throw UTComputerException("Error OperatorDUP::executeSpecificOperator : problem in stack because argument isn't Complex nor Expression nor Program.");
        }
    }
    catch (UTComputerException e) {
        UTComputerException e1(e.getMessage());
        e1.insertBefore(" --> ");
        e1.insertBefore("Error in applying OperatorDUP ");
        throw e1;
    }


}
// ===============================================================================================================