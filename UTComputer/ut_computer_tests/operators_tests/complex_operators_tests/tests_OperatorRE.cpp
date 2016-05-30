#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/complex_operators/OperatorRE.h"
#include "../../../literals/ProgramLiteral.h"

using namespace std;

class Test_Operator_RE : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorRE op_re;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};



/* ========================================================== */
/*                       CLASSIC TESTS                        */
/* ========================================================== */
TEST_F(Test_Operator_RE, Works_With_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_re.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3", st.top()->toString());
}

TEST_F(Test_Operator_RE, Works_With_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    op_re.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3.1", st.top()->toString());
}

TEST_F(Test_Operator_RE, Works_With_Rational) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,2))));
    op_re.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3/2", st.top()->toString());
}

TEST_F(Test_Operator_RE, Works_With_Integer_Imaginary_Part) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3), NumericLiteral(4))));
    op_re.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3", st.top()->toString());
}

TEST_F(Test_Operator_RE, Works_With_Real_Imaginary_Part) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1), NumericLiteral(3))));
    op_re.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3.1", st.top()->toString());
}

TEST_F(Test_Operator_RE, Works_With_Rational_Imaginary_Part) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,2), NumericLiteral(3))));
    op_re.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3/2", st.top()->toString());
}




/* ========================================================== */
/*                  TESTS ON EXPRESSION                       */
/* ========================================================== */


TEST_F(Test_Operator_RE, Works_With_Expression) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    op_re.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'RE(1+1)'", st.top()->toString());
}

TEST_F(Test_Operator_RE, Works_With_Expression_2) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("(1+1)*2")));
    op_re.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("'RE((1+1)*2)'", st.top()->toString());
}


/* ========================================================== */
/*                   TEST THROWN EXCEPTIONS                   */
/* ========================================================== */

TEST_F(Test_Operator_RE, Exception_if_Invalid_arguments) {
    try {
        st.push(shared_ptr<ProgramLiteral>(new ProgramLiteral("(1+1)*2")));
        //op_re.execute(&st); // Uncomment to see error message
        EXPECT_THROW(op_re.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


