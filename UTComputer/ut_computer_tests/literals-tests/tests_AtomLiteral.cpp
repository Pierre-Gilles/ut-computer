#include <iostream>
#include <gtest/gtest.h>

#include "../../literals/AtomLiteral.h"
#include <regex>



class Test_Atom_Literal : public ::testing::Test {

public:
    virtual void SetUp() { }
    virtual void TearDown() {

    }
};



TEST_F(Test_Atom_Literal, Test_Regex) {

    regex r(AtomLiteral::getAtomRegex());

    EXPECT_TRUE(regex_match("X", r));
    EXPECT_TRUE(regex_match("XDS", r));
    EXPECT_TRUE(regex_match("X1", r));
    EXPECT_TRUE(regex_match("CDH21", r));
    EXPECT_TRUE(regex_match("X1X1X1X1", r));
    EXPECT_TRUE(regex_match("X1X1X", r));
    EXPECT_TRUE(regex_match("X2GYH2832BSD", r));
    EXPECT_TRUE(regex_match("X22212121", r));

    EXPECT_FALSE(regex_match("1", r));
    EXPECT_FALSE(regex_match("1X", r));
    EXPECT_FALSE(regex_match("1DEEKNDE", r));
    EXPECT_FALSE(regex_match("s2ZS2.", r));
    EXPECT_FALSE(regex_match("sdezdz.", r));
    EXPECT_FALSE(regex_match("1sdez.", r));

}