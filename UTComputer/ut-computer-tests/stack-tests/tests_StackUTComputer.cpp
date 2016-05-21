#include <iostream>
#include <gtest/gtest.h>

#include "../../stack/StackUTComputer.h"
#include "../../literals/ComplexLiteral.h"




class Test_StackUTComputer_Class : public ::testing::Test {
protected:
    StackUTComputer st;

public:
    virtual void SetUp() { }
    virtual void TearDown() {
        st.clear();
    }
};


TEST_F(Test_StackUTComputer_Class, Test_Size_Function) {
    ComplexLiteral *test = new ComplexLiteral(new NumericLiteral(2));
    st.push(test);
    EXPECT_EQ(1, st.size());
}


TEST_F(Test_StackUTComputer_Class, Test_Top_Function) {
    ComplexLiteral *test = new ComplexLiteral(new NumericLiteral(2));
    st.push(test);
    EXPECT_EQ("2", st.top()->toString());
    EXPECT_EQ(test, st.top());
}

TEST_F(Test_StackUTComputer_Class, Test_Pop_Function) {
    ComplexLiteral *test = new ComplexLiteral(new NumericLiteral(2));
    ComplexLiteral *test2 = nullptr;
    st.push(test);
    EXPECT_EQ(1, st.size());
    st.pop();
    EXPECT_EQ(0, st.size());
    // expect death when accessing a deleted pointer
    EXPECT_DEATH(test->toString(), ".*"); // ".*" match any error code
}

TEST_F(Test_StackUTComputer_Class, Test_getArguments_Function) {

}