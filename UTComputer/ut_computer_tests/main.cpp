#include <gtest/gtest.h>

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
//    ::testing::GTEST_FLAG(filter) = "Test_Operator_Class*:";
    //::testing::GTEST_FLAG(filter) += "Test_Operator_Minus*:";
    return RUN_ALL_TESTS();
}