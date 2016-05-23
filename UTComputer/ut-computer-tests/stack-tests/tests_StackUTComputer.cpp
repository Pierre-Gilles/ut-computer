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
    st.push(test);
    EXPECT_EQ(1, st.size());
    st.pop();
    EXPECT_EQ(0, st.size());
    // expect death when accessing a deleted pointer
    EXPECT_DEATH(test->toString(), ".*"); // ".*" match any error code
}

TEST_F(Test_StackUTComputer_Class, Test_clear_Function) {
    ComplexLiteral *test1 = new ComplexLiteral(new NumericLiteral(2));
    ComplexLiteral *test2 = new ComplexLiteral(new NumericLiteral(2));
    ComplexLiteral *test3 = new ComplexLiteral(new NumericLiteral(2));
    ComplexLiteral *test4 = new ComplexLiteral(new NumericLiteral(2));
    st.push(test1);
    st.push(test2);
    st.push(test3);
    st.push(test4);
    EXPECT_EQ(4, st.size());
    st.clear();
    EXPECT_EQ(0, st.size());

    // expect death when accessing a deleted pointer
    EXPECT_DEATH(test1->toString(), ".*"); // ".*" match any error code
    EXPECT_DEATH(test2->toString(), ".*"); // ".*" match any error code
    EXPECT_DEATH(test3->toString(), ".*"); // ".*" match any error code
    EXPECT_DEATH(test4->toString(), ".*"); // ".*" match any error code
}

TEST_F(Test_StackUTComputer_Class, Test_getArguments_Function) {
    try {
        Literal **arguments = new Literal*[10];

        // should pass and raise no error or crash
        EXPECT_NO_THROW(st.getArguments(0, arguments));
        EXPECT_NO_FATAL_FAILURE(st.getArguments(0, arguments));

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

        // should pass and raise no error or crash
        EXPECT_NO_THROW(st.deleteArguments(0));
        EXPECT_NO_FATAL_FAILURE(st.deleteArguments(0));

        // Stack is empty, so deleteArguments with 2 as arity should raise exception
        //st.deleteArguments(2); // uncomment to get exception message
        EXPECT_THROW(st.deleteArguments(2),UTComputerException);

        // Stack.size() is two, but both arguments are null => no exception raised
        st.push(nullptr);
        st.push(nullptr);
        EXPECT_NO_THROW(st.deleteArguments(2));

        // Stack.size() is two, but one argument is null => no exception raised
        st.clear();
        st.push(new ComplexLiteral(new NumericLiteral(2)));
        st.push(nullptr);
        EXPECT_NO_THROW(st.deleteArguments(2));

        // Stack.size() is two, but one argument is null => no exception raised
        st.clear();
        st.push(nullptr);
        st.push(new ComplexLiteral(new NumericLiteral(2)));
        EXPECT_NO_THROW(st.deleteArguments(2));

        // Stack.size() is two, and no null arguments
        st.clear();
        ComplexLiteral *test1 = new ComplexLiteral(new NumericLiteral(2));
        ComplexLiteral *test2 = new ComplexLiteral(new NumericLiteral(2));
        st.push(test1);
        st.push(test2);
        EXPECT_NO_THROW(st.deleteArguments(2));
        // expect death when accessing a deleted pointer
        EXPECT_DEATH(test1->toString(), ".*"); // ".*" match any error code
        EXPECT_DEATH(test2->toString(), ".*"); // ".*" match any error code
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }


}