//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_PLUSOPERATOR_H
#define TESTLO21CLION_PLUSOPERATOR_H

#include "Operator.h"
#include "../literals/ComplexLiteral.h"
#include "../literals/ExpressionLiteral.h"


using namespace std;

class PlusOperator : public Operator {

public:
    PlusOperator(int nb) : Operator(nb, "+") { }

    virtual ~PlusOperator() { }

private:

    virtual Literal* executeSpecificOperator(StackUTComputer *st) override {
        /* test done before in superclass :
         *      - test that pointer to stack is not null
         *      - test that stack contains enough Literal* (st.size() >= operator arity)
         *      - test that every Literal* unstacked isn't null
         * */
        try {
            return applyOperator(arguments[0], arguments[1]);
        }
        catch (UTComputerException e) {
            UTComputerException e1(e.getMessage());
            e1.insertBefore(" --> ");
            e1.insertBefore(arguments[1]->toString());
            e1.insertBefore(" and ");
            e1.insertBefore(arguments[0]->toString());
            e1.insertBefore("Error in applying PlusOperator on ");
            throw e1;
        }
    }

    /* PlusOperator applies to
     *      - two ComplexLiterals
     *      - two ExpressionLiteral
     *      - an ExpressionLiteral and a ComplexLiteral */
    Literal* applyOperator(Literal* a, Literal* b) {
        ComplexLiteral* comp_a = dynamic_cast<ComplexLiteral*>(a);
        ComplexLiteral* comp_b = dynamic_cast<ComplexLiteral*>(b);
        ExpressionLiteral* exp_a = dynamic_cast<ExpressionLiteral*>(a);
        ExpressionLiteral* exp_b = dynamic_cast<ExpressionLiteral*>(b);

        // if the two literals are instance of ComplexLiteral
        if (comp_a != nullptr && comp_b != nullptr) {
            return *comp_a + *comp_b; // ComplexLiteral::operator+(ComplexLiteral &l) const
        }

        // if the two literals are instance of ExpressionLiteral
        else if (exp_a != nullptr && exp_b != nullptr) {
            return *exp_a + *exp_b; // ExpressionLiteral::operator+(ExpressionLiteral &l) const
        }

        // if one of the two elements is not instance of ComplexLiteral
        else if (comp_a != nullptr) {
            /* then b is not instance of ComplexLiteral and can only be instance of
                *  ExpressionLiteral. If not, then b is an illegal argument for PlusOperator */
            if (exp_b != nullptr)
                return *exp_b + *comp_a; // ExpressionLiteral::operator+(ComplexLiteral &l) const
            else {
                UTComputerException e(exp_b->toString());
                e.insertBefore("Error in PlusOperator::applyOperator : second argument has invalid type.");
                throw e;
            }
        }
        else if (comp_b != nullptr) {
            /* then a is not instance of ComplexLiteral and can only be instance of
                *  ExpressionLiteral. If not, then a is an illegal argument for PlusOperator */
            if (exp_a != nullptr)
                return *exp_a + *comp_b; // ExpressionLiteral::operator+(ComplexLiteral &l) const
            else {
                UTComputerException e(exp_a->toString());
                e.insertBefore("Error in PlusOperator::applyOperator : first argument is of invalid type.");
                throw e;
            }
        }
        else {
            UTComputerException e(a->toString());
            e.insertBefore(" and ");
            e.insertBefore(b->toString());
            e.insertBefore("Error in PlusOperator::applyOperator : invalid literal types for both arguments");
            throw e;
        }
    }
};
#endif //TESTLO21CLION_PLUSOPERATOR_H
