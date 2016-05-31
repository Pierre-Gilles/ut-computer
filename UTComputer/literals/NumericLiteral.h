#ifndef TESTLO21CLION_NUMERICLITERAL_H
#define TESTLO21CLION_NUMERICLITERAL_H

#include <iostream>
#include <math.h>
#include <sstream> // for ostringstream
#include "Literal.h"


using namespace std;

class NumericLiteral : public Literal {

    double numerator;
    double denominator;
    const static string numericRegex;
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================

    NumericLiteral(double num = 0, double den = 1) :
            Literal(),
            numerator(num),
            denominator(den) {
        if (den == 0.0)
            throw UTComputerException("Error NumericLiteral::constructor :  denominator can't be 0.");

        if (isRational()) // then numerator and denominator have "int" value and we can apply simplification to it
            simplification();
    }

    virtual ~NumericLiteral() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================

    double getNumerator() const {
        return numerator;
    }

    void setNumerator(double num) {
        NumericLiteral::numerator = num;
    }

    double getDenominator() const {
        return denominator;
    }

    void setDenominator(double den) {
        if (den == 0.0)
            throw UTComputerException("Error NumericLiteral::setNumerator :  denominator can't be 0.");
        NumericLiteral::denominator = den;
    }

    static const string &getNumericRegex() {
        return numericRegex;
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
    NumericLiteral operator+(const NumericLiteral &l) const;
    NumericLiteral operator-(const NumericLiteral &l) const;
    NumericLiteral operator*(const NumericLiteral &l) const;
    NumericLiteral operator/(const NumericLiteral &l) const;
    NumericLiteral negOperator() const;

    // Logical operators
    bool operator<(const NumericLiteral &l) const;
    bool operator==(const NumericLiteral &l) const;
    bool operator>(const NumericLiteral &l) const;
    bool operator<=(const NumericLiteral &l) const;
    bool operator>=(const NumericLiteral &l) const;
    bool operator!=(const NumericLiteral &l) const;
    bool operator&&(const NumericLiteral &l) const;
    bool operator||(const NumericLiteral &l) const;
    bool operator!() const;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Useful class functions                  ==========================
    // ===============================================================================================================
    bool isInteger() const;
    bool isRational() const;
    bool isReal() const;
private:
    void simplification();

    // ===============================================================================================================


};


#endif //TESTLO21CLION_NUMERICLITERAL_H
