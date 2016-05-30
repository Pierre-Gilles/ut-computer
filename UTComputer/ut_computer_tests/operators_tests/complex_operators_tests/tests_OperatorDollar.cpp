#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/complex_operators/OperatorDollar.h"
#include "../../../literals/ExpressionLiteral.h"

using namespace std;

class Test_Operator_Dollar : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorDollar op_dollar;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};



/* ========================================================== */
/*                       CLASSIC TESTS                        */
/* ========================================================== */
TEST_F(Test_Operator_Dollar, Works_With_Two_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_dollar.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3$3", st.top()->toString());
}

TEST_F(Test_Operator_Dollar, Works_With_Integer_and_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    op_dollar.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3$3.1", st.top()->toString());
}

TEST_F(Test_Operator_Dollar, Works_With_Integer_and_Rational) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,2))));
    op_dollar.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3$3/2", st.top()->toString());
}

TEST_F(Test_Operator_Dollar, Works_With_Two_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    op_dollar.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3.1$3.1", st.top()->toString());
}

TEST_F(Test_Operator_Dollar, Works_With_Real_and_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_dollar.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3.1$3", st.top()->toString());
}

TEST_F(Test_Operator_Dollar, Works_With_Real_and_Rational) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,2))));
    op_dollar.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3.1$3/2", st.top()->toString());
}

TEST_F(Test_Operator_Dollar, Works_With_Two_Rational) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    op_dollar.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3/2$5/2", st.top()->toString());
}


TEST_F(Test_Operator_Dollar, Works_With_Rational_and_Real) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    op_dollar.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3/2$3.1", st.top()->toString());
}

TEST_F(Test_Operator_Dollar, Works_With_Rational_and_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_dollar.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("3/2$3", st.top()->toString());
}






/* ========================================================== */
/*                   TEST THROWN EXCEPTIONS                   */
/* ========================================================== */

TEST_F(Test_Operator_Dollar, Exception_if_two_complex) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3), NumericLiteral(3))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3), NumericLiteral(3))));
        //op_dollar.execute(&st); // Uncomment to see error message
        EXPECT_THROW(op_dollar.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Dollar, Exception_if_first_argument_complex) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3), NumericLiteral(3))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
        //op_dollar.execute(&st); // Uncomment to see error message
        EXPECT_THROW(op_dollar.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


TEST_F(Test_Operator_Dollar, Exception_if_second_argument_complex) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3), NumericLiteral(3))));
        //op_dollar.execute(&st); // Uncomment to see error message
        EXPECT_THROW(op_dollar.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


TEST_F(Test_Operator_Dollar, Exception_if_two_ExpressionLiteral) {
    try {
        st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
        st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
        //op_dollar.execute(&st); // Uncomment to see error message
        EXPECT_THROW(op_dollar.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Dollar, Exception_if_two_first_argument_ExpressionLiteral) {
    try {
        st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
        //op_dollar.execute(&st); // Uncomment to see error message
        EXPECT_THROW(op_dollar.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Dollar, Exception_if_two_second_argument_ExpressionLiteral) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
        st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
        //op_dollar.execute(&st); // Uncomment to see error message
        EXPECT_THROW(op_dollar.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

