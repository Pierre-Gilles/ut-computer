
#ifndef TESTLO21CLION_COMPLEXLITERAL_H
#define TESTLO21CLION_COMPLEXLITERAL_H

#include "NumericLiteral.h"

class ComplexLiteral : public Literal {
    NumericLiteral *real;
    NumericLiteral *im;
public:


    ComplexLiteral(NumericLiteral *r, NumericLiteral *i = new NumericLiteral(0)) : Literal(), real(r), im(i) {
        if (r == nullptr)
            throw "Error in ComplexLiteral constructor : real part is null";
        if (i == nullptr)
            throw "Error in ComplexLiteral constructor : im part is null";
    }

    ComplexLiteral(ComplexLiteral &l) {
        real = new NumericLiteral(*l.real); // default copy constructor OK for NumericLiteral
        im = new NumericLiteral(*l.im); // default copy constructor OK for NumericLiteral
    }


    virtual ~ComplexLiteral() {
        delete real;
        delete im;
    }

    NumericLiteral *getReal() const {
        return real;
    }

    void setReal(NumericLiteral *real) {
        ComplexLiteral::real = real;
    }

    NumericLiteral *getIm() const {
        return im;
    }

    void setIm(NumericLiteral *im) {
        ComplexLiteral::im = im;
    }

    virtual string toString() override {
        ostringstream sting_stream;
        if (im->getNumerator() == 0.0) { // then it's not a complex but a NumericLiteral
            return real->toString();
        }
        else {
            sting_stream << real->toString() << "$" << im->toString();
            return sting_stream.str();
        }
    }

    ComplexLiteral * operator+(ComplexLiteral &l) const {
        return new ComplexLiteral(
                *(real) + *(l.real),
                *(im) + *(l.im)
        );
    }
    ComplexLiteral * operator+(NumericLiteral &l) const {
        return new ComplexLiteral(
                *(real) + l, // call to NumericLiteral::operator+(NumericLiteral &l) const that returns a new NumericLiteral
                new NumericLiteral(*im) // default copy constructor OK for NumericLiteral
        );
    }
};


#endif //TESTLO21CLION_COMPLEXLITERAL_H
