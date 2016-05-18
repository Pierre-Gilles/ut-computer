//
// Created by Raphael on 15/05/2016.
//

#include "tests.h"
#include <vector>

using namespace std;

void testLexer() {
    LexerUTComputer lx;
    string test = "1 1 + 'une expression' 2 -";
    vector<string> tokens, tokensExpected;

    tokens = lx.splitPG(test);
    tokensExpected = {"1", "1", "+", "une",  "expression", "2", "-"};

    //assert(tokens == tokensExpected);
    for(int i = 0; i < tokens.size(); i++){
        cout << tokens[i] <<endl;
    }


}

void testNumericLiteral() {

    // test of toString function

    {
        NumericLiteral rational(1,2);
        NumericLiteral real(1.1);
        NumericLiteral integer(1);
        assert(rational.toString() == "1/2");
        assert(real.toString() == "1.1");
        assert(integer.toString() == "1");
        // cout << rational.toString() <<  " " << real.toString() << " " << integer.toString() << endl;
    }

    // test of simplification function
    {
        NumericLiteral r1(12, 6);
        NumericLiteral r2(6, 12);
        assert(r1.getNumerator() == 2 && r1.getDenominator() == 1);
        assert(r2.getNumerator() == 1 && r2.getDenominator() == 2);
        assert(r1.toString() == "2");
        assert(r2.toString() == "1/2");
    }


    // test of operator+ overload
    NumericLiteral r1(2,3);
    NumericLiteral r2(2,3);

}


void testOperatorClass() {

}
void testPlusOpertor() {
    StackUTComputer st;
    PlusOperator op_plus(2);


    /* ========================================================== */
    /* ========================================================== */
    /* addition between two ComplexLiteral without imaginary part */
    /* ========================================================== */
    /* ========================================================== */

    /* integer + integer = integer */
    try {
        st.push(new ComplexLiteral(new NumericLiteral(2)));
        st.push(new ComplexLiteral(new NumericLiteral(3)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && st.top()->toString() == "5"
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }

    /* integer + rational = rational */
    try {
        st.push(new ComplexLiteral(new NumericLiteral(2,3)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && st.top()->toString() == "17/3"
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }

    /* rational + integer = rational */
    try {
        st.push(new ComplexLiteral(new NumericLiteral(1)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && st.top()->toString() == "20/3"
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }

    /* rational + rational = rational */
    try {
        st.push(new ComplexLiteral(new NumericLiteral(2,3)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && st.top()->toString() == "22/3"
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }

    /* rational + rational = integer (by simplification) */
    try {
        st.push(new ComplexLiteral(new NumericLiteral(2,3)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && st.top()->toString() == "8"
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }

    /* rational + real = real */
    st.clear();
    try {
        st.push(new ComplexLiteral(new NumericLiteral(2,3)));
        st.push(new ComplexLiteral(new NumericLiteral(2.5)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && dynamic_cast<ComplexLiteral*>(st.top())->getReal()->getNumerator() == (2.0/3.0 + 2.5)
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }

    /* real + rational = real */
    try {
        // here stack top value is (2.0/3.0 + 2.5)
        st.push(new ComplexLiteral(new NumericLiteral(1,2)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && dynamic_cast<ComplexLiteral*>(st.top())->getReal()->getNumerator() == (2.0/3.0 + 2.5) + 0.5
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }

    /* real + real = real */
    try {
        // here stack top value is ((2.0/3.0 + 2.5) + 0.5)
        st.push(new ComplexLiteral(new NumericLiteral(1.5)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && dynamic_cast<ComplexLiteral*>(st.top())->getReal()->getNumerator() == (2.0/3.0 + 2.5) + 0.5 + 1.5
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }

    /* integer + real = real */
    st.clear();
    try {
        st.push(new ComplexLiteral(new NumericLiteral(1)));
        st.push(new ComplexLiteral(new NumericLiteral(1.5)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && dynamic_cast<ComplexLiteral*>(st.top())->getReal()->getNumerator() == 2.5
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }

    /* real + integer = real */
    try {
        st.push(new ComplexLiteral(new NumericLiteral(1)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && dynamic_cast<ComplexLiteral*>(st.top())->getReal()->getNumerator() == 3.5
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }




    /* ========================================================== */
    /* ========================================================== */
    /*   addition between two ComplexLiteral with imaginary part  */
    /* ========================================================== */
    /* ========================================================== */

    /* Addition of two complex with integer parts */
    st.clear();
    try {
        st.push(new ComplexLiteral(new NumericLiteral(1), new NumericLiteral(3)));
        st.push(new ComplexLiteral(new NumericLiteral(2), new NumericLiteral(1)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && st.top()->toString() == "3$4"
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }

    /* Addition of two complex with real parts */
    st.clear();
    try {
        st.push(new ComplexLiteral(new NumericLiteral(1.1), new NumericLiteral(3.1)));
        st.push(new ComplexLiteral(new NumericLiteral(2.1), new NumericLiteral(1.1)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && st.top()->toString() == "3.2$4.2"
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }

    /* Addition of two complex with rational parts */
    st.clear();
    try {
        st.push(new ComplexLiteral(new NumericLiteral(1,3), new NumericLiteral(3,4)));
        st.push(new ComplexLiteral(new NumericLiteral(1,3), new NumericLiteral(2,4)));
        op_plus.execute(&st);
        assert(st.size() == 1
               && st.top()->toString() == "2/3$5/4"
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }


    /* ========================================================== */
    /* ========================================================== */
    /* addition between a ComplexLiteral and an ExpressionLiteral */
    /* ========================================================== */
    /* ========================================================== */


    st.push(new ExpressionLiteral("1+1"));
    try {
        op_plus.execute(&st);
        cout << st.top()->toString() << endl;
        assert(st.size() == 1
               && st.top()->toString() == "(1+1)+(6)"
        );
    }
    catch (UTComputerException e){
        cout << e.getMessage() << endl;
    }


}

