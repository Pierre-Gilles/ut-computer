#include <iostream>
#include <gtest/gtest.h>

#include "../../literals/ExpressionLiteral.h"



class Test_Expression_Literal : public ::testing::Test {
protected:

public:
    virtual void SetUp() { }
    virtual void TearDown() {

    }
};


TEST_F(Test_Expression_Literal, hasSamePriority) {
    /*
     * Le résultat de l’opérateur binaire utilisant un symbole (+, -, /, *, $) appliqué entre la littérale expression
     * ’EXP1’ et la littérale expression ’EXP2’ renvoie un littérale expression composée des deux littérales initiales,
     * chacune entre parenthèses, les deux littérales étant séparées par le symbole.
     *      Par exemple, on obtient ’(EXP1 )+(EXP2)’ si l’opérateur est +. Les parenthèses autour des expressions
     *      EXP1 et/ou EXP2 sont omises dans le résultat si tous les opérateurs non parenthésés dans l’expression ont
     *      la même priorité que l’opérateur.
     *      Les opérateurs *, / ont une priorité supérieure à + et -.
     *      Les opérateurs *, / ont la même priorité entre eux.
     *      Les opérateurs + et - ont la même priorité entre eux.
     *      Les opérateurs numériques ont priorité sur les opérateurs logiques.
     *      Deux opérateurs qui ont la même priorité sont toujours évalués de la gauche vers la droite.
     *          Par exemple, la ligne de commande ’3+X’’9*Y’* a pour résultat ’(3+X)*9*Y’.
     * */



    /* Function hasSamePriority will be use to determine whether including an expression between parenthesis
     * (when applying an operator on it) is necessary or not :
     *      - if hasSamePriority return true, then no need of parenthesis
     *      - if hasSamePriority return false, then need of parenthesis */
    ExpressionLiteral e("");
    vector<string> all_operators = {"<", ">", "<=", ">=", "=", "!=", "+", "-", "*", "/", "$", "AND", "OR", "NOT"};
    vector<string> priority0 = {"<", ">", "<=", ">=", "=", "!=", "AND", "OR", "NOT"};
    vector<string> priority1 = {"+", "-"};
    vector<string> priority2 = {"*", "/"};
    vector<string> priority3 = {"$"};
    vector<string> all_but_0 = {"+", "-", "*", "/", "$"};
    vector<string> all_but_1 = {"<", ">", "<=", ">=", "=", "!=", "AND", "OR", "NOT", "*", "/", "$"};
    vector<string> all_but_2 = {"<", ">", "<=", ">=", "=", "!=", "AND", "OR", "NOT", "+", "-", "$"};
    vector<string> all_but_3 = {"<", ">", "<=", ">=", "=", "!=", "AND", "OR", "NOT", "+", "-", "*", "/"};

    /* ========================================================== */
    /*                         BASIC TESTS                        */
    /* ========================================================== */

    // Basic tests for operators with priority equals to 0
    for (int i=0; i<priority0.size(); i++) {
        // test for all operators in priority0[] with expression of type 1<1, 1>1, ...
        e.setValue("1" + priority0[i] + "1");

        // for every operator in all_but_0[], assert that hasSamePriority return false
        for (int j=0; j<all_but_0.size(); j++)
            EXPECT_FALSE(e.hasSamePriority(all_but_0[j], e.toString()));

        // for every operator in priority0[], assert that hasSamePriority return true
        for (int k=0; k<priority0.size(); k++)
            EXPECT_TRUE(e.hasSamePriority(priority0[k], e.toString()));
    }

    // Basic tests for operators with priority equals to 1
    for (int i=0; i<priority1.size(); i++) {
        // test for all operators in priority0[] with expression of type 1+1 and 1-1
        e.setValue("1" + priority1[i] + "1");

        // for every operator in all_but_1[], assert that hasSamePriority return false
        for (int j=0; j<all_but_1.size(); j++)
            EXPECT_FALSE(e.hasSamePriority(all_but_1[j], e.toString()));

        // for every operator in priority1[], assert that hasSamePriority return true
        for (int k=0; k<priority1.size(); k++)
            EXPECT_TRUE(e.hasSamePriority(priority1[k], e.toString()));
    }

    // Basic tests for operators with priority equals to 2
    for (int i=0; i<priority2.size(); i++) {
        // test for all operators in priority2[] with expression of type 1*1 and 1/1
        e.setValue("1" + priority2[i] + "1");

        // for every operator in all_but_2[], assert that hasSamePriority return false
        for (int j=0; j<all_but_2.size(); j++)
            EXPECT_FALSE(e.hasSamePriority(all_but_2[j], e.toString()));

        // for every operator in priority2[], assert that hasSamePriority return true
        for (int k=0; k<priority2.size(); k++)
            EXPECT_TRUE(e.hasSamePriority(priority2[k], e.toString()));
    }

    // Basic tests for operators with priority equals to 3
    for (int i=0; i<priority3.size(); i++) {
        // test for all operators in priority2[] with expression of type 1*1 and 1/1
        e.setValue("1" + priority3[i] + "1");

        // for every operator in all_but_2[], assert that hasSamePriority return false
        for (int j=0; j<all_but_3.size(); j++)
            EXPECT_FALSE(e.hasSamePriority(all_but_3[j], e.toString()));

        // for every operator in priority2[], assert that hasSamePriority return true
        for (int k=0; k<priority3.size(); k++)
            EXPECT_TRUE(e.hasSamePriority(priority3[k], e.toString()));
    }




    /* ========================================================== */
    /*                 TEST WITH PARENTHESIS                      */
    /* ========================================================== */

    /* Les parenthèses autour des expressions EXP1 et/ou EXP2 sont omises dans le résultat si tous les opérateurs
     * non parenthésés dans l’expression ont la même priorité que l’opérateur appliqué. */


    /* hasSamePriority retournera toujours vrai si l'expression est entourée de parenthères */
    for (int i=0; i<all_operators.size(); i++) {
        e.setValue("(1" + all_operators[i] + "1)");

        // for every operator in all_operators[], assert that hasSamePriority return true
        for (int j=0; j<all_operators.size(); j++)
            EXPECT_TRUE(e.hasSamePriority(all_operators[j], e.toString()));
    }

    /* Test with two parenthesis and operator[i] between*/
    for (int i=0; i<all_operators.size(); i++) {
        e.setValue("(1" + all_operators[i] + "1)" + all_operators[i] + "(1" + all_operators[i] + "1)");
        EXPECT_TRUE(e.hasSamePriority(all_operators[i], e.toString()));
    }



    // Basic tests for operators with priority equals to 0
    for (int i=0; i<priority0.size(); i++) {
        // test for all operators in priority0[] with expression of type 1<1, 1>1, ...
        e.setValue("(1" + priority0[i] + "1)" + priority0[i] + "(1" + priority0[i] + "1)");

        // for every operator in all_but_0[], assert that hasSamePriority return false
        for (int j=0; j<all_but_0.size(); j++)
            EXPECT_FALSE(e.hasSamePriority(all_but_0[j], e.toString()));

        // for every operator in priority0[], assert that hasSamePriority return true
        for (int k=0; k<priority0.size(); k++)
            EXPECT_TRUE(e.hasSamePriority(priority0[k], e.toString()));
    }

    // Basic tests for operators with priority equals to 1
    for (int i=0; i<priority1.size(); i++) {
        // test for all operators in priority0[] with expression of type 1+1 and 1-1
        e.setValue("(1" + priority1[i] + "1)" + priority1[i] + "(1" + priority1[i] + "1)");

        // for every operator in all_but_1[], assert that hasSamePriority return false
        for (int j=0; j<all_but_1.size(); j++)
            EXPECT_FALSE(e.hasSamePriority(all_but_1[j], e.toString()));

        // for every operator in priority1[], assert that hasSamePriority return true
        for (int k=0; k<priority1.size(); k++)
            EXPECT_TRUE(e.hasSamePriority(priority1[k], e.toString()));
    }

    // Basic tests for operators with priority equals to 2
    for (int i=0; i<priority2.size(); i++) {
        // test for all operators in priority2[] with expression of type 1*1 and 1/1
        e.setValue("(1" + priority2[i] + "1)" + priority2[i] + "(1" + priority2[i] + "1)");

        // for every operator in all_but_2[], assert that hasSamePriority return false
        for (int j=0; j<all_but_2.size(); j++)
            EXPECT_FALSE(e.hasSamePriority(all_but_2[j], e.toString()));

        // for every operator in priority2[], assert that hasSamePriority return true
        for (int k=0; k<priority2.size(); k++)
            EXPECT_TRUE(e.hasSamePriority(priority2[k], e.toString()));
    }

    // Basic tests for operators with priority equals to 3
    for (int i=0; i<priority3.size(); i++) {
        // test for all operators in priority2[] with expression of type 1*1 and 1/1
        e.setValue("(1" + priority3[i] + "1)" + priority3[i] + "(1" + priority3[i] + "1)");

        // for every operator in all_but_2[], assert that hasSamePriority return false
        for (int j=0; j<all_but_3.size(); j++)
            EXPECT_FALSE(e.hasSamePriority(all_but_3[j], e.toString()));

        // for every operator in priority2[], assert that hasSamePriority return true
        for (int k=0; k<priority3.size(); k++)
            EXPECT_TRUE(e.hasSamePriority(priority3[k], e.toString()));
    }



    /* ========================================================== */
    /*               TEST OF THROWN EXCEPTIONS                    */
    /* ========================================================== */


    // test that invalid operator "op" throws exception
    EXPECT_THROW(e.hasSamePriority("",e.toString()),UTComputerException);
    EXPECT_THROW(e.hasSamePriority("--",e.toString()),UTComputerException);


    // test that invalid expression with no closing parenthesis throw exception
    EXPECT_THROW(e.hasSamePriority("-","(1+1)+(1+1"),UTComputerException);
    EXPECT_NO_THROW(e.hasSamePriority("-","(1+1)+(1+1)"));
    EXPECT_THROW(e.hasSamePriority("-","(1+1"),UTComputerException);
    EXPECT_NO_THROW(e.hasSamePriority("-","(1+1)"));

}

TEST_F(Test_Expression_Literal, infixToPostix) {
    ExpressionLiteral e("");
    string result = e.infixToPostfix("(3 + 3) * 5 - 12");
    ASSERT_EQ(result, "3  3 +  5  * 12 -");

    // TODO faire marcher infixToPostfix with this : let the test crash to see the result of the infixtopostfix function
    string result2 = e.infixToPostfix("((1+2)*40)+SIN(3.2) - POW(5,X2)");
    ASSERT_EQ(result2, "");
}



