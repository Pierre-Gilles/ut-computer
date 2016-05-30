#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/logical_operators/OperatorInferior.h"
#include "../../../literals/ExpressionLiteral.h"
using namespace std;

class Test_Operator_Inferior : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorInferior op_inf;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};


/* ========================================================== */
/*                  test between two integers                 */
/* ========================================================== */

TEST_F(Test_Operator_Inferior, Integer_Inf_Integer_Gives_True) {
    /* integer < integer = 1 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Integer_Sup_Integer_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Integer_Equal_Integer_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}



/* ========================================================== */
/*                  test between two real                     */
/* ========================================================== */

TEST_F(Test_Operator_Inferior, Real_Inf_Real_Gives_True) {
    /* integer < integer = 1 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Real_Sup_Real_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Real_Equal_Real_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}




/* ========================================================== */
/*                  test between two rational                 */
/* ========================================================== */

TEST_F(Test_Operator_Inferior, Rational_Inf_Rational_Gives_True) {
    /* integer < integer = 1 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(7,2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Rational_Sup_Rational_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(7,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Rational_Equal_Rational_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}



/* ========================================================== */
/*         test between integers and real / rational         */
/* ========================================================== */


TEST_F(Test_Operator_Inferior, Integer_Inf_Real_Gives_True) {
    /* integer < integer = 1 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Integer_Sup_Real_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Integer_Inf_Rational_Gives_True) {
    /* integer < integer = 1 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(7,2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Integer_Sup_Rational_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}



/* ========================================================== */
/*         test between real and integer / rational           */
/* ========================================================== */

TEST_F(Test_Operator_Inferior, Real_Inf_Integer_Gives_True) {
    /* integer < integer = 1 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Real_Sup_Integer_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Real_Inf_Rational_Gives_True) {
    /* integer < integer = 1 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(7,2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Real_Sup_Rational_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1,2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}



/* ========================================================== */
/*         test between rational and integer / real           */
/* ========================================================== */

TEST_F(Test_Operator_Inferior, Rational_Inf_Integer_Gives_True) {
    /* integer < integer = 1 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(4))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Rational_Sup_Integer_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Rational_Inf_Real_Gives_True) {
    /* integer < integer = 1 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(7.2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("1", st.top()->toString());
}

TEST_F(Test_Operator_Inferior, Rational_Sup_Real_Gives_False) {
    /* integer > integer = 0 */
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5,2))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(1.2))));
    op_inf.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("0", st.top()->toString());
}




/* ========================================================== */
/*                   TEST THROWN EXCEPTIONS                   */
/* ========================================================== */

TEST_F(Test_Operator_Inferior, Throw_Exception_Null_Arguments) {
    st.push(shared_ptr<ComplexLiteral>());
    st.push(shared_ptr<ComplexLiteral>());
    try {
        //op_inf.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_inf.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Inferior, Throw_Exception_First_Argument_Is_Null) {
    st.push(shared_ptr<ComplexLiteral>());
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    try {
        //op_inf.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_inf.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Inferior, Throw_Exception_Second_Argument_Is_Null) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    st.push(shared_ptr<ComplexLiteral>());
    try {
        //op_inf.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_inf.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Inferior, Throw_Exception_Two_Arguments_Invalid) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5), NumericLiteral(5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5), NumericLiteral(5))));
    try {
        //op_inf.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_inf.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Inferior, Throw_Exception_Two_Arguments_Invalid_2) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5), NumericLiteral(5))));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    try {
        //op_inf.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_inf.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Inferior, Throw_Exception_First_Argument_Invalid) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5), NumericLiteral(5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    try {
        //op_inf.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_inf.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Inferior, Throw_Exception_First_Argument_Invalid_1) {
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    try {
        //op_inf.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_inf.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Inferior, Throw_Exception_Second_Argument_Invalid) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5), NumericLiteral(5))));
    try {
        //op_inf.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_inf.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_Operator_Inferior, Throw_Exception_Second_Argument_Invalid_2) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(5))));
    st.push(shared_ptr<ExpressionLiteral>(new ExpressionLiteral("1+1")));
    try {
        //op_inf.execute(&st); // uncomment to get error message
        ASSERT_THROW(op_inf.execute(&st), UTComputerException);
    } catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}