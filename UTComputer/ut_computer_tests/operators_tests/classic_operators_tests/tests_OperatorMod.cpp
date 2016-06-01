#include <iostream>
#include <gtest/gtest.h>

#include "../../../operators/classic_operators/OperatorModulo.h"

using namespace std;

class Test_Operator_Mod : public ::testing::Test {
protected:
    StackUTComputer st;
    OperatorModulo op_mod;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};


TEST_F(Test_Operator_Mod, Modulo_Of_Two_Integer) {
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(11))));
    st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(3))));
    op_mod.execute(&st);
    EXPECT_EQ(1, st.size());
    EXPECT_EQ("2", st.top()->toString());
}


TEST_F(Test_Operator_Mod, Modulo_Applies_Only_To_Integers) {
    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(8))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
        //op_mod.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_mod.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(8))));
        //op_mod.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_mod.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(8))));
        //op_mod.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_mod.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(8))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
        //op_mod.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_mod.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2,3))));
        //op_mod.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_mod.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }

    try {
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
        st.push(shared_ptr<ComplexLiteral>(new ComplexLiteral(NumericLiteral(2.1))));
        //op_mod.execute(&st); // uncomment to see error message
        EXPECT_THROW(op_mod.execute(&st),UTComputerException);
        st.clear();
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}


// TODO : MOD sur des nombres négatifs ??