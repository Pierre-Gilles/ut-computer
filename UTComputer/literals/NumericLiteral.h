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
        // si le numerateur est 0, le denominateur prend la valeur 1
        if (numerator == 0) {
            denominator=1;
            return;
        }

        /* un denominateur ne devrait pas être 0, si c’est le cas, on sort de la méthode */
        if (denominator == 0) {
            return;
        }

        /* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun
         Denominateur (PGCD) entre le numerateur et le denominateur */
        double a=numerator, b=denominator;

        // on ne travaille qu’avec des valeurs positives...
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

        // on divise le numerateur et le denominateur par le PGCD=a
        numerator /= a;
        denominator /= a;

        // si le denominateur est négatif, on fait passer le signe - au numérateur
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

public:
    NumericLiteral(double numerator = 0, double denominator = 1) :
            Literal(),
            numerator(numerator),
            denominator(denominator) {
        double intpart;
        if (modf(numerator, &intpart) == 0.0) { // then numerator is an int and we can apply simplification to it
            simplification();
        }
    }


    double getNumerator() const {
        return numerator;
    }

    void setNumerator(double numerator) {
        NumericLiteral::numerator = numerator;
    }

    double getDenominator() const {
        return denominator;
    }

    void setDenominator(double denominator) {
        NumericLiteral::denominator = denominator;
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


    NumericLiteral * operator+(NumericLiteral &l) const {
        /* if one is a real literal and the other a rational literal, we must return a
         * real literal with the result of the operation in the numerator attribute
         * and set the denominator to 1 */
        if ( (isReal() && l.isRational()) || (isRational() && l.isReal()) ) {
            NumericLiteral *tmp = new NumericLiteral(
                    numerator*l.denominator + l.numerator*denominator,
                    denominator * l.denominator
            );
            /* if the result is still a rational (or an integer after simplification) (2.5 + 1/2 gives 6/2 = 3)
             * then we return the tmp result */
            if (tmp->isRational()) {
                return tmp;
            }
            /* But if we have a result looking like 8.5/2, then we must return a real literal with the numerator
             * set to numerator/denominator*/
            else {
                tmp->numerator = tmp->numerator/tmp->denominator;
                tmp->denominator = 1;
                return tmp;
            }
        }

        /* In general, we return a new numeric literal with the normal plus operation */
        return new NumericLiteral(
                numerator*l.denominator + l.numerator*denominator,
                denominator * l.denominator
        );
    }




};


#endif //TESTLO21CLION_NUMERICLITERAL_H
