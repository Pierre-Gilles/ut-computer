
#ifndef TESTLO21CLION_COMPLEXLITERAL_H
#define TESTLO21CLION_COMPLEXLITERAL_H

#include "NumericLiteral.h"
#include <memory>
#include <cstddef>

using namespace std;

class ComplexLiteral : public Literal {
    shared_ptr<NumericLiteral> real;
    shared_ptr<NumericLiteral> im;
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    ComplexLiteral(shared_ptr<NumericLiteral> r, shared_ptr<NumericLiteral> i = make_shared<NumericLiteral>(new NumericLiteral(0.0))) :
            Literal(), real(r), im(i) {
        if (r == nullptr)
            throw "Error in ComplexLiteral constructor : real part is null";
    }

    ComplexLiteral(ComplexLiteral &l) {
        real = shared_ptr<NumericLiteral>(new NumericLiteral(*l.real)); // default copy constructor OK for NumericLiteral
        im = shared_ptr<NumericLiteral>(new NumericLiteral(*l.im)); // default copy constructor OK for NumericLiteral
    }

    virtual ~ComplexLiteral() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================

    shared_ptr<NumericLiteral> getReal() const {
        return real;
    }

    void setReal(const shared_ptr<NumericLiteral> r) {
        real = r;
    }

    shared_ptr<NumericLiteral> getIm() const {
        return im;
    }

    void setIm(const shared_ptr<NumericLiteral> i) {
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
};


#endif //TESTLO21CLION_COMPLEXLITERAL_H
