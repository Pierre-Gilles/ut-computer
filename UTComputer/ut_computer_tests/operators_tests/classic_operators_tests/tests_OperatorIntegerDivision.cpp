#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/classic_operators/OperatorIntegerDivision.h"

using namespace std;

class Test_Operator_Int_Div : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorIntegerDivision op_int_div;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};


TEST_F(Test_Operator_Int_Div, Integer_Division_Two_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(8))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_int_div.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("2", st.top()->toString());
}


TEST_F(Test_Operator_Int_Div, Integer_Division_Applies_Only_To_Integers) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(8))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
        //op_int_div.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_int_div.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(8))));
        //op_int_div.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_int_div.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(8))));
        //op_int_div.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_int_div.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(8))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
        //op_int_div.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_int_div.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
        //op_int_div.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_int_div.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }

    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
        //op_int_div.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_int_div.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}