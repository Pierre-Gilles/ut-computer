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

TEST_F(Test_StackUTComputer_Class, Test_shared_ptd_usage) {
    shared_ptr<ComplexLiteral> test(new ComplexLiteral(NumericLiteral(2)));
    EXPECT_EQ(1, test.use_count()); // pointer used by test only

    st.push(test);
    EXPECT_EQ(2, test.use_count()); // pointer used by test and stack

    EXPECT_EQ(3, st.top().use_count()); // pointer used by test, stack and st.top()

    EXPECT_EQ(2, test.use_count()); // pointer used by test and stack and no more by st.top()

    st.pop();
    EXPECT_EQ(1, test.use_count()); // pointer used by test because delete from stack

    test.reset(); // say we don't want to use test anymore
    EXPECT_EQ(0, test.use_count()); // pointer used by no one
}



TEST_F(Test_StackUTComputer_Class, Test_size_Function) {
    shared_ptr<ComplexLiteral> test(new ComplexLiteral(NumericLiteral(2)));
    st.push(test);
    EXPECT_EQ(1, st.size());
}

TEST_F(Test_StackUTComputer_Class, Test_pop_Function) {
    shared_ptr<ComplexLiteral> test(new ComplexLiteral(NumericLiteral(2)));
    st.push(test);
    EXPECT_EQ(1, st.size());
    st.pop();
    EXPECT_EQ(0, st.size());
}


TEST_F(Test_StackUTComputer_Class, Test_top_Function) {
    shared_ptr<ComplexLiteral> test(new ComplexLiteral(NumericLiteral(2)));
    st.push(test);
    EXPECT_EQ("2", st.top()->toString());
    EXPECT_EQ(test, st.top());
}



TEST_F(Test_StackUTComputer_Class, Test_clear_Function) {
    shared_ptr<ComplexLiteral> test1(new ComplexLiteral(NumericLiteral(2)));
    shared_ptr<ComplexLiteral> test2(new ComplexLiteral(NumericLiteral(2)));
    shared_ptr<ComplexLiteral> test3(new ComplexLiteral(NumericLiteral(2)));
    shared_ptr<ComplexLiteral> test4(new ComplexLiteral(NumericLiteral(2)));
    st.push(test1);
    st.push(test2);
    st.push(test3);
    st.push(test4);
    EXPECT_EQ(4, st.size());
    EXPECT_EQ(2, test1.use_count());
    EXPECT_EQ(2, test2.use_count());
    EXPECT_EQ(2, test3.use_count());
    EXPECT_EQ(2, test4.use_count());
    st.clear();
    EXPECT_EQ(0, st.size());
    EXPECT_EQ(1, test1.use_count());
    EXPECT_EQ(1, test2.use_count());
    EXPECT_EQ(1, test3.use_count());
    EXPECT_EQ(1, test4.use_count());
}

TEST_F(Test_StackUTComputer_Class, Test_getArguments_Function) {
    try {
        vector<shared_ptr<Literal>> arguments;
        arguments.reserve(10);

        // should pass and raise no error or crash
        EXPECT_NO_THROW(st.getArguments(0, arguments));
        EXPECT_NO_FATAL_FAILURE(st.getArguments(0, arguments));

        // Stack is empty, so getArguments with 2 as arity should raise exception
        //st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);

        // Stack.size() is two, but both arguments are null => exception raised
        st.push(shared_ptr<Literal>());
        st.push(shared_ptr<Literal>());
        // st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);

        // Stack.size() is two, but one argument is null => exception raised
        st.clear();
        st.push(shared_ptr<Literal>(new ComplexLiteral(NumericLiteral(2))));
        st.push(shared_ptr<Literal>());
        //st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);

        // Stack.size() is two, but one argument is null => exception raised
        st.clear();
        st.push(shared_ptr<Literal>());
        st.push(shared_ptr<Literal>(new ComplexLiteral(NumericLiteral(2))));
        //st.getArguments(2,arguments); // uncomment to get exception message
        EXPECT_THROW(st.getArguments(2,arguments),UTComputerException);

        //Stack.size() is two, and no null arguments
        st.clear();
        st.push(shared_ptr<Literal>(new ComplexLiteral(NumericLiteral(1))));
        st.push(shared_ptr<Literal>(new ComplexLiteral(NumericLiteral(2))));
        EXPECT_NO_THROW(st.getArguments(2,arguments));
        EXPECT_EQ("1", arguments.at(0)->toString());
        EXPECT_EQ("2", arguments[1]->toString());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}

TEST_F(Test_StackUTComputer_Class, Test_deleteArguments_Function) {
    try {
        // should pass and raise no error or crash
        EXPECT_NO_THROW(st.deleteArguments(0));
        EXPECT_NO_FATAL_FAILURE(st.deleteArguments(0));

        // Stack is empty, so deleteArguments with 2 as arity should raise exception
        //st.deleteArguments(2); // uncomment to get exception message
        EXPECT_THROW(st.deleteArguments(2),UTComputerException);

        // Stack.size() is two, but both arguments are null => no exception raised
        st.push(shared_ptr<Literal>());
        st.push(shared_ptr<Literal>());
        EXPECT_NO_THROW(st.deleteArguments(2));

        // Stack.size() is two, but one argument is null => no exception raised
        st.clear();
        st.push(shared_ptr<Literal>(new ComplexLiteral(NumericLiteral(2))));
        st.push(shared_ptr<Literal>());
        EXPECT_NO_THROW(st.deleteArguments(2));

        // Stack.size() is two, but one argument is null => no exception raised
        st.clear();
        st.push(shared_ptr<Literal>());
        st.push(shared_ptr<Literal>(new ComplexLiteral(NumericLiteral(2))));
        EXPECT_NO_THROW(st.deleteArguments(2));

        // Stack.size() is two, and no null arguments
        st.clear();
        shared_ptr<ComplexLiteral> test1(new ComplexLiteral(NumericLiteral(2)));
        shared_ptr<ComplexLiteral> test2(new ComplexLiteral(NumericLiteral(2)));
        st.push(test1);
        st.push(test2);
        EXPECT_EQ(2, test1.use_count());
        EXPECT_EQ(2, test2.use_count());

        EXPECT_NO_THROW(st.deleteArguments(2));

        EXPECT_EQ(1, test1.use_count());
        EXPECT_EQ(1, test2.use_count());
    }
    catch (UTComputerException e) {
        cerr << e.getMessage() << endl;
    }
}