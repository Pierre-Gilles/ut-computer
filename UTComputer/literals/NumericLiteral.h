//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_NUMERICLITERAL_H
#define TESTLO21CLION_NUMERICLITERAL_H

#include <iostream>
#include <math.h>
#include <sstream> // for ostringstream
#include "Literal.h"


using namespace std;

class NumericLiteral : public Literal {
private:
    double numerator;
    double denominator;
    void simplification() {
        if (!isRational())
            throw UTComputerException("Error NumericLiteral::simplification : simplifiaction on non retional literal is impossible.");

        // if numerator is 0, then set denominator to 1
        if (numerator == 0) {
            denominator = 1;
            return;
        }

        // denominator can't be 0
        if (denominator == 0) {
            throw UTComputerException("Error NumericLiteral::simplification : denominator can't be 0.");
        }

        /* Use of Euclide algorithm to find // TODO PGCD en anglais ? */
        double a=numerator, b=denominator;

        // we only works with positiv values
        if (a<0)
            a=-a;
        if (b<0)
            b=-b;

        while(a != b) {
            if (a>b)
                a = a - b;
            else
                b = b - a;
        }

        // division of numerator and denominator by a, the PGCD
        numerator /= a;
        denominator /= a;

        // if denominator is negative, pass the negation to the numerator
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

public:



    NumericLiteral(double num = 0, double den = 1) :
            Literal(),
            numerator(num),
            denominator(den) {
        if (den == 0.0)
            throw UTComputerException("Error NumericLiteral::constructor :  denominator can't be 0.");

        if (isRational()) // then numerator and denominator have "int" value and we can apply simplification to it
            simplification();
    }

    NumericLiteral(const NumericLiteral* l) :
            Literal(),
            numerator(l->numerator),
            denominator(l->denominator) { }


    virtual ~NumericLiteral() { }

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


    bool isInteger() const {
        double intpart;
        return (modf(numerator, &intpart) == 0.0
                && denominator == 1
        );
    }
    bool isRational() const {
        double intpart;
        return ( modf(numerator, &intpart) == 0.0
                && modf(denominator, &intpart) == 0.0
                && denominator!= 1
        );
    }
    bool isReal() const {
        double intpart;
        return ( modf(numerator, &intpart) != 0.0
                && denominator == 1
        );
    }


    virtual string toString() override {
        ostringstream sting_stream;
        if (isInteger()) {
            sting_stream << (int) numerator;
            return sting_stream.str();
        }
        if (isRational()) {
            sting_stream << numerator << "/" << denominator;
            return sting_stream.str();
        }
        if (isReal()) {
            sting_stream << numerator;
            return sting_stream.str();
        }
        throw UTComputerException("Error NumericLiteral::toString() : literal isn't integer nor rational nor real");
    }


    shared_ptr<NumericLiteral> operator+(NumericLiteral &l) const {
        /* if one is a real literal and the other a rational literal, we must return a
         * real literal with the result of the operation in the numerator attribute
         * and set the denominator to 1 */
        if (isReal() || l.isReal()) {
            shared_ptr<NumericLiteral> tmp(new NumericLiteral(
                    numerator*l.denominator + l.numerator*denominator,
                    denominator * l.denominator
            ));
            tmp->numerator = tmp->numerator/tmp->denominator;
            tmp->denominator = 1;
            return tmp;

            /* It was also possible to return a rational or an integer (after simplification)
             * but the it's clearly specified in the project that addition with real always return a real literal */
        }

        /* In general, we return a new numeric literal with the normal plus operation */
        return shared_ptr<NumericLiteral>(new NumericLiteral(
                numerator*l.denominator + l.numerator*denominator,
                denominator * l.denominator
        ));
    }

    shared_ptr<NumericLiteral> operator-(NumericLiteral &l) const {
        /* if one is a real literal and the other a rational literal, we must return a
         * real literal with the result of the operation in the numerator attribute
         * and set the denominator to 1 */
        if (isReal() || l.isReal()) {
            shared_ptr<NumericLiteral> tmp(new NumericLiteral(
                    numerator*l.denominator - l.numerator*denominator,
                    denominator * l.denominator
            ));
            tmp->numerator = tmp->numerator/tmp->denominator;
            tmp->denominator = 1;
            return tmp;

            /* It was also possible to return a rational or an integer (after simplification)
             * but the it's clearly specified in the project that difference with real always return a real literal */
        }

        /* In general, we return a new numeric literal with the normal plus operation */
        return shared_ptr<NumericLiteral>(new NumericLiteral(
                numerator*l.denominator - l.numerator*denominator,
                denominator * l.denominator
        ));
    }

    shared_ptr<NumericLiteral> operator*(NumericLiteral &l) const {
        /* if one of the arguments is real, we must return a
         * real literal with the result of the operation in the numerator attribute
         * and set the denominator to 1 */
        if (isReal() || l.isReal()) {
            shared_ptr<NumericLiteral> tmp(new NumericLiteral(
                    numerator*l.numerator,
                    denominator * l.denominator
            ));
            tmp->numerator = tmp->numerator/tmp->denominator;
            tmp->denominator = 1;
            return tmp;
        }

        /* In general, we return a new numeric literal with the normal multiplication operation */
        return shared_ptr<NumericLiteral>(new NumericLiteral(
                numerator*l.numerator,
                denominator * l.denominator
        ));
    }

    shared_ptr<NumericLiteral> operator/(NumericLiteral &l) const {
        if (denominator == 0.0 || l.denominator == 0.0)
            throw UTComputerException("Error NumericLiteral::operator/(NumericLiteral &l) : one of the denominators is 0.");
        
        if (l.numerator == 0.0)
            throw UTComputerException("Error NumericLiteral::operator/(NumericLiteral &l) : l is 0 and division by zero is impossible.");

        /* if one of the arguments is real, we must return a
         * real literal with the result of the operation in the numerator attribute
         * and set the denominator to 1 */
        if (isReal() || l.isReal()) {
            shared_ptr<NumericLiteral> tmp(new NumericLiteral(
                    numerator*l.denominator,
                    denominator * l.numerator
            ));
            tmp->numerator = tmp->numerator/tmp->denominator;
            tmp->denominator = 1;
            return tmp;
        }

        /* In general, we return a new numeric literal with the normal division operation */
        return shared_ptr<NumericLiteral>(new NumericLiteral(
                numerator*l.denominator,
                denominator * l.numerator
        ));
    }


};


#endif //TESTLO21CLION_NUMERICLITERAL_H
