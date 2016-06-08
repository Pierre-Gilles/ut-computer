/**
 * \file NumericLiteral.h
 * \brief File containing the declaration of the class NumericLiteral
 */

#ifndef TESTLO21CLION_NUMERICLITERAL_H
#define TESTLO21CLION_NUMERICLITERAL_H

#include <iostream>
#include <math.h>
#include <sstream> // for ostringstream
#include "Literal.h"


using namespace std;

/**
 * \class NumericLiteral
 * \brief Subclass of Literal
 *
 * Class that modelize integer, real and rational values with two attributes of type double :
 * one for the numerator and one for the denominator
 */

class NumericLiteral : public Literal {

    double numerator;
    double denominator;
    const static string numericRegex; /*!< String containing the regex specific to NumericLiteral */
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================

    /**
     * \fn NumericLiteral(double num = 0, double den = 1)
     * \brief Constructor that takes zero, one or two \a double as arguments
     * \param[in] num : double for the numerator
     * \param[in] den : double for the denominator (default value is 1)
     * \return An instance of NumericLiteral
     */
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

    /**
     * \fn double getNumerator() const
     * \brief Getter for the private attribute numerator
     * \return The private attribute numerator
     */
    double getNumerator() const {
        return numerator;
    }

    /**
     * \fn void setNumerator(double num)
     * \brief Setter for the private attribute numerator
     * \param[in] num : double used to set the private attribute numerator
     */
    void setNumerator(double num) {
        NumericLiteral::numerator = num;
    }

    /**
     * \fn double getDenominator() const
     * \brief Getter for the private attribute denominator
     * \return The private attribute denominator
     */
    double getDenominator() const {
        return denominator;
    }

    /**
     * \fn void setDenominator(double den)
     * \brief Setter for the private attribute denominator
     * \param[in] den : double used to set the private attribute denominator
     */
    void setDenominator(double den) {
        if (den == 0.0)
            throw UTComputerException("Error NumericLiteral::setNumerator :  denominator can't be 0.");
        NumericLiteral::denominator = den;
    }

    /**
     * \fn static const string &getNumericRegex()
     * \brief Static function to get the static attribute numericRegex
     * \return The static private attribute numericRegex
     */
    static const string &getNumericRegex() {
        return numericRegex;
    }

    // ===============================================================================================================









    // ===============================================================================================================
    // ======================                         Override Methods                      ==========================
    // ===============================================================================================================
    /**
     * \fn virtual string toString() const override
     * \brief Redefinition of the superclass virtual pure toString() method
     * \return The a string to display the NumericLiteral in different ways : integer, real or rational
     */
    virtual string toString() const override;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Operators overload                      ==========================
    // ===============================================================================================================
    // Classic operators
    /**
     * \fn NumericLiteral operator+(const NumericLiteral &l) const
     * \brief Overload of operator+ between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return A new NumericLiteral, result of the operation
     */
    NumericLiteral operator+(const NumericLiteral &l) const;
    /**
     * \fn NumericLiteral operator-(const NumericLiteral &l) const
     * \brief Overload of operator- between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return A new NumericLiteral, result of the operation
     */
    NumericLiteral operator-(const NumericLiteral &l) const;
    /**
     * \fn NumericLiteral operator*(const NumericLiteral &l) const
     * \brief Overload of operator* between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return A new NumericLiteral, result of the operation
     */
    NumericLiteral operator*(const NumericLiteral &l) const;
    /**
     * \fn NumericLiteral operator/(const NumericLiteral &l) const
     * \brief Overload of operator/ between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return A new NumericLiteral, result of the operation
     */
    NumericLiteral operator/(const NumericLiteral &l) const;
    /**
     * \fn NumericLiteral negOperator() const;
     * \brief Apply negation on the implicit parameter NumericLiteral
     * \return A new NumericLiteral, result of the operation
     */
    NumericLiteral negOperator() const;

    // Logical operators
    /**
     * \fn bool operator<(const NumericLiteral &l) const;
     * \brief Overload of operator< between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return True if implicit parameter is inferior to the parameter l, otherwise return false
     */
    bool operator<(const NumericLiteral &l) const;

    /**
     * \fn bool operator==(const NumericLiteral &l) const;
     * \brief Overload of operator== between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return True if implicit parameter is equal to the parameter l, otherwise return false
     */
    bool operator==(const NumericLiteral &l) const;

    /**
     * \fn bool operator>(const NumericLiteral &l) const;
     * \brief Overload of operator> between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return True if implicit parameter is superior to the parameter l, otherwise return false
     */
    bool operator>(const NumericLiteral &l) const;

    /**
     * \fn bool operator<=(const NumericLiteral &l) const;
     * \brief Overload of operator<= between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return True if implicit parameter is inferior or equal to the parameter l, otherwise return false
     */
    bool operator<=(const NumericLiteral &l) const;

    /**
     * \fn bool operator>=(const NumericLiteral &l) const;
     * \brief Overload of operator>= between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return True if implicit parameter is superior or equal to the parameter l, otherwise return false
     */
    bool operator>=(const NumericLiteral &l) const;

    /**
     * \fn bool operator!=(const NumericLiteral &l) const;
     * \brief Overload of operator!= between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return True if implicit parameter is different from the parameter l, otherwise return false
     */
    bool operator!=(const NumericLiteral &l) const;

    /**
     * \fn bool operator&&(const NumericLiteral &l) const;
     * \brief Overload of operator&& between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return True if both NumericLiteral are true, otherwise return false
     */
    bool operator&&(const NumericLiteral &l) const;

    /**
     * \fn bool operator||(const NumericLiteral &l) const;
     * \brief Overload of operator|| between two NumericLiteral
     * \param[in] l : const NumericLiteral &
     * \return True if at least one of the two NumericLiteral is true, otherwise return false
     */
    bool operator||(const NumericLiteral &l) const;

    /**
     * \fn bool operator!() const
     * \brief Overload of operator!
     * \return True if implicit parameter is false and return false if implicit parameter is true
     */
    bool operator!() const;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Useful class functions                  ==========================
    // ===============================================================================================================
    /**
     * \fn bool isInteger() const
     * \brief Test if a NumericLiteral is an integer number
     * \return True if the denominator is 1 and the numerator is an "integer"
     */
    bool isInteger() const;

    /**
     * \fn bool isRational() const
     * \brief Test if a NumericLiteral is a rational number
     * \return True if the denominator is different from 1 and the numerator is an "integer"
     */
    bool isRational() const;

    /**
     * \fn bool isReal() const
     * \brief Test if a NumericLiteral is a real number
     * \return True if the denominator is 1 and the numerator is a "real" number
     */
    bool isReal() const;

private:
    /**
     * \fn void simplification()
     * \brief If possible, simplify the numerator and the denominator using
     * Euclide algorithm to find the greatest common divisor
     */
    void simplification();

    // ===============================================================================================================


};


#endif //TESTLO21CLION_NUMERICLITERAL_H
