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


TEST_F(Test_StackUTComputer_Class, Test_size_Function) {
    ComplexLiteral *test = new ComplexLiteral(new NumericLiteral(2));
    st.push(test);
    EXPECT_EQ(1, st.size());
}


TEST_F(Test_StackUTComputer_Class, Test_top_Function) {
    ComplexLiteral *test = new ComplexLiteral(new NumericLiteral(2));
    st.push(test);
    EXPECT_EQ("2", st.top()->toString());
    EXPECT_EQ(test, st.top());
}

TEST_F(Test_StackUTComputer_Class, Test_pop_Function) {
    ComplexLiteral *test = new ComplexLiteral(new NumericLiteral(2));
    ComplexLiteral *test2 = nullptr;
    st.push(test);
    EXPECT_EQ(1, st.size());
    st.pop();
    EXPECT_EQ(0, st.size());
    // expect death when accessing a deleted pointer
    EXPECT_DEATH(test->toString(), ".*"); // ".*" match any error code
}

TEST_F(Test_StackUTComputer_Class, Test_clear_Function) {

}

TEST_F(Test_StackUTComputer_Class, Test_getArguments_Function) {

    try {
        Literal **arguments = new Literal*[10];
        st.getArguments(0, arguments); // should pass and raise no error or crash



        // Stack is empty, so getArguments with 2 as arity should raise exception
        //st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);



        // Stack.size() is two, but both arguments are null => exception raised
        st.push(nullptr);
        st.push(nullptr);
        // st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);


        // Stack.size() is two, but one argument is null => exception raised
        st.clear();
        st.push(new ComplexLiteral(new NumericLiteral(2)));
        st.push(nullptr);
        // st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);


        // Stack.size() is two, but one argument is null => exception raised
        st.clear();
        st.push(nullptr);
        st.push(new ComplexLiteral(new NumericLiteral(2)));
        // st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);


        // Stack.size() is two, and no null arguments
        st.clear();
        st.push(new ComplexLiteral(new NumericLiteral(1)));
        st.push(new ComplexLiteral(new NumericLiteral(2)));
        EXPECT_NO_THROW(st.getArguments(2,arguments));
        EXPECT_EQ("1", arguments[0]->toString());
        EXPECT_EQ("2", arguments[1]->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_StackUTComputer_Class, Test_deleteArguments_Function) {

    try {
        Literal **arguments = new Literal*[10];
        st.getArguments(0, arguments); // should pass and raise no error or crash



        // Stack is empty, so getArguments with 2 as arity should raise exception
        //st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);



        // Stack.size() is two, but both arguments are null => exception raised
        st.push(nullptr);
        st.push(nullptr);
        // st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);


        // Stack.size() is two, but one argument is null => exception raised
        st.clear();
        st.push(new ComplexLiteral(new NumericLiteral(2)));
        st.push(nullptr);
        // st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);


        // Stack.size() is two, but one argument is null => exception raised
        st.clear();
        st.push(nullptr);
        st.push(new ComplexLiteral(new NumericLiteral(2)));
        // st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);


        // Stack.size() is two, and no null arguments
        st.clear();
        st.push(new ComplexLiteral(new NumericLiteral(1)));
        st.push(new ComplexLiteral(new NumericLiteral(2)));
        EXPECT_NO_THROW(st.getArguments(2,arguments));
        EXPECT_EQ("1", arguments[0]->toString());
        EXPECT_EQ("2", arguments[1]->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


}