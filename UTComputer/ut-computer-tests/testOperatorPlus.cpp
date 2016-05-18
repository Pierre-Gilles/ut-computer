#include <iostream>
#include <gtest/gtest.h>

#include "../operators/Operator.h"
#include "../operators/PlusOperator.h"

StackUTComputer st;
PlusOperator op_plus(2);

TEST(OperatorPlus, Integer_Plus_Integer) {
    /* integer + integer = integer */
    st.push(new ComplexLiteral(new NumericLiteral(2)));
    st.push(new ComplexLiteral(new NumericLiteral(3)));
    op_plus.execute(&st);
    ASSERT_TRUE(st.size() == 1
                 && st.top()->toString() == "5");
    st.clear();
}

TEST(OperatorPlus, Integer_Plus_Rational) {
    /* integer + rational = rational */
    st.push(new ComplexLiteral(new NumericLiteral(5)));
    st.push(new ComplexLiteral(new NumericLiteral(2, 3)));
    op_plus.execute(&st);
    ASSERT_TRUE(st.size() == 1
                && st.top()->toString() == "17/3");
    st.clear();
}
