#include <iostream>
#include "IntegerLiteral.h"
#include <stringlist.h>
#include "LiteralFactory.h"
#include <exception>
using namespace std;


int main() {

    try {

        IntegerLiteral i1(1);
        Literal* i2 = nullptr;
        cout << i2 << endl;
        i2 = IntegerLiteral::create("2");
        if (i2 == nullptr) {
            cout << "false" << endl;
        }
        else {
            i2->print_literal();
        }

        cout << "je suis là" << endl;
        i1.print_literal();

        delete i2;


        cout << endl << endl << endl << endl << endl;


        // ============================================================================



        string test[3] = {"1", "2", "3"};
        LiteralFactory lf;

        Literal* testLit = nullptr;
        for (int i=0; i<3; i++) {
            testLit = lf.createLiteral(test[i]);

            cout << "string = " << test[i] << " et literal->affiche() : ";
            if (testLit == nullptr) cout << " le Literal* est null.";
            else testLit->print_literal();
            cout << endl;
        }

    }
    catch (char* e) {
        cout << e << endl;
    }


    return 0;
}