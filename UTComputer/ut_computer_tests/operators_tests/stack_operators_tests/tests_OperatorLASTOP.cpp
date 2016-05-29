#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/stack_operators/OperatorLASTOP.h"
#include "../../../operators/classic_operators/OperatorPlus.h"
#include "../../../operators/classic_operators/OperatorMultiplication.h"

using namespace std;

class Test_Operator_LASTOP : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorLASTOP op_LASTOP;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};



/* ========================================================== */
/*                        classic tests                       */
/* ========================================================== */


TEST_F(Test_Operator_LASTOP, Test_Last_Op_is_Plus) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(34))));
        EXPECT_EQ(3, st.size());

        OperatorPlus op_plus;
        op_plus.execute(&st);
        EXPECT_EQ(2, st.size());
        EXPECT_EQ("37.1", st.top()->toString());

        op_LASTOP.execute(&st);
        EXPECT_EQ(1, st.size());
        EXPECT_EQ("39.2", st.top()->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


TEST_F(Test_Operator_LASTOP, Test_Last_Op_is_Mult) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(34))));
        EXPECT_EQ(3, st.size());

        OperatorMultiplication op_mult;
        op_mult.execute(&st);
        EXPECT_EQ(2, st.size());
        EXPECT_EQ("105.4", st.top()->toString());

        op_LASTOP.execute(&st);
        EXPECT_EQ(1, st.size());
        EXPECT_EQ("221.34", st.top()->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


/* ========================================================== */
/*                    Thrown exceptions                       */
/* ========================================================== */

TEST_F(Test_Operator_LASTOP, Exception_if_LastOP_Is_Null) {
    try {
        //op_LASTOP.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_LASTOP.execute(&st), UTComputerException);
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

