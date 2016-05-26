#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/logical_operators/OperatorSuperior.h"

using namespace std;

class Test_Operator_Superior : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorSuperior op_sup;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};


/* ========================================================== */
/*                  test between two integers                 */
/* ========================================================== */

TEST_F(Test_Operator_Superior, Integer_Inf_Integer_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Integer_Sup_Integer_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Integer_Equal_Integer_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}



/* ========================================================== */
/*                  test between two real                     */
/* ========================================================== */

TEST_F(Test_Operator_Superior, Real_Inf_Real_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Real_Sup_Real_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Real_Equal_Real_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}




/* ========================================================== */
/*                  test between two rational                 */
/* ========================================================== */

TEST_F(Test_Operator_Superior, Rational_Inf_Rational_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(7,2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Rational_Sup_Rational_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(7,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Rational_Equal_Rational_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}



/* ========================================================== */
/*         test between integers and real / rational         */
/* ========================================================== */


TEST_F(Test_Operator_Superior, Integer_Inf_Real_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Integer_Sup_Real_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Integer_Inf_Rational_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(7,2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Integer_Sup_Rational_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}



/* ========================================================== */
/*         test between real and integer / rational           */
/* ========================================================== */

TEST_F(Test_Operator_Superior, Real_Inf_Integer_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Real_Sup_Integer_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Real_Inf_Rational_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(7,2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Real_Sup_Rational_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}



/* ========================================================== */
/*         test between rational and integer / real           */
/* ========================================================== */

TEST_F(Test_Operator_Superior, Rational_Inf_Integer_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Rational_Sup_Integer_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Rational_Inf_Real_Gives_False) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(7.2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Superior, Rational_Sup_Real_Gives_True) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1.2))));
    op_sup.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}