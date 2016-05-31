
#ifndef TESTLO21CLION_COMPLEXLITERAL_H
#define TESTLO21CLION_COMPLEXLITERAL_H

#include "NumericLiteral.h"
#include <memory>
#include <cstddef>

using namespace std;

class ComplexLiteral : public Literal {
    NumericLiteral real;
    NumericLiteral im;
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    ComplexLiteral(const string &s) {
        real = NumericLiteral(stod(s));
        im = NumericLiteral(0);
    }

    ComplexLiteral(NumericLiteral r, NumericLiteral i = NumericLiteral(0.0)) :
            Literal(), real(r), im(i) { }

    ComplexLiteral(ComplexLiteral &l) : Literal() {
        real = l.real; // default copy constructor OK for NumericLiteral
        im = l.im; // default copy constructor OK for NumericLiteral
    }

    virtual ~ComplexLiteral() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================

    const NumericLiteral & getReal() const {
        return real;
    }

    void setReal(const NumericLiteral &r) {
        real = r;
    }

    const NumericLiteral & getIm() const {
        return im;
    }

    void setIm(const NumericLiteral &i) {
        im = i;
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                         Override Methods                      ==========================
    // ===============================================================================================================
    virtual string toString() const override;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Operators overload                      ==========================
    // ===============================================================================================================

    // Classic operators
    shared_ptr<ComplexLiteral> operator+(ComplexLiteral &l) const;
    shared_ptr<ComplexLiteral> operator+(NumericLiteral &l) const;
    shared_ptr<ComplexLiteral> operator-(ComplexLiteral &l) const;
    shared_ptr<ComplexLiteral> operator*(ComplexLiteral &l) const;
    shared_ptr<ComplexLiteral> operator/(ComplexLiteral &l) const;
    shared_ptr<ComplexLiteral> negOperator() const;

    // Logical operators
    bool operator<(const ComplexLiteral &l) const;
    bool operator==(const ComplexLiteral &l) const;
    bool operator>(const ComplexLiteral &l) const;
    bool operator<=(const ComplexLiteral &l) const;
    bool operator>=(const ComplexLiteral &l) const;
    bool operator!=(const ComplexLiteral &l) const;
    bool operator&&(const ComplexLiteral &l) const;
    bool operator||(const ComplexLiteral &l) const;
    bool operator!() const;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Useful class functions                  ==========================
    // ===============================================================================================================
    bool isComplex() const;
    bool isInteger() const;
    bool isRational() const;
    bool isReal() const;
    // ===============================================================================================================
};


#endif //TESTLO21CLION_COMPLEXLITERAL_H
