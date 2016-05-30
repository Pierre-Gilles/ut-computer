#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/stack_operators/OperatorLASTARGS.h"
#include "../../../operators/classic_operators/OperatorPlus.h"
#include "../../../literals/ComplexLiteral.h"

using namespace std;

class Test_Operator_LASTARGS : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorLASTARGS op_LASTARGS;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};



/* ========================================================== */
/*                        classic tests                       */
/* ========================================================== */


TEST_F(Test_Operator_LASTARGS, Test_Last_Args_Works) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3.1))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(34))));
        EXPECT_EQ(3, st.size());

        OperatorPlus op_plus;
        op_plus.execute(&st);
        EXPECT_EQ(2, st.size());
        EXPECT_EQ("37.1", st.top()->toString());

        op_LASTARGS.execute(&st);
        EXPECT_EQ(4, st.size());
        EXPECT_EQ("34", st.top()->toString());
        st.pop();
        EXPECT_EQ(3, st.size());
        EXPECT_EQ("3.1", st.top()->toString());
        st.pop();
        EXPECT_EQ(2, st.size());
        EXPECT_EQ("37.1", st.top()->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}



/* ========================================================== */
/*                    Thrown exceptions                       */
/* ========================================================== */




