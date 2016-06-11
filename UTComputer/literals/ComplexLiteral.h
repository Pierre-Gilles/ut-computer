/**
 * \file ComplexLiteral.h
 * \brief File containing the declaration of the class ComplexLiteral
 */
#ifndef TESTLO21CLION_COMPLEXLITERAL_H
#define TESTLO21CLION_COMPLEXLITERAL_H

#include "NumericLiteral.h"
#include <memory>
#include <cstddef>

using namespace std;


/**
 * \class ComplexLiteral
 * \brief Subclass of Literal
 *
 * Class that modelize all numeric value by containing two NumericLiteral, one for the real part and one for the
 * imaginary part
 */
class ComplexLiteral : public Literal {
    NumericLiteral real;
    NumericLiteral im;
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    /**
     * \fn ComplexLiteral(const string &s)
     * \brief Constructor taking a string to construct a new ComplexLiteral
     * \param[in] s : string from which the ComplexLiteral is created
     * \return An instance of ComplexLiteral with no imaginary part an a real part set according to the string parameter
     */
    ComplexLiteral(const string &s) {
        real = NumericLiteral(stod(s));
        im = NumericLiteral(0);
    }

    /**
     * \fn ComplexLiteral(NumericLiteral r, NumericLiteral i = NumericLiteral(0.0))
     * \brief Constructor taking one or two NumericLiteral
     * \param[in] r : NumericLiteral for the real part
     * \param[in] i : NumericLiteral for the imaginary part set by default to a value of 0
     * \return An instance of ComplexLiteral
     */
    ComplexLiteral(NumericLiteral r, NumericLiteral i = NumericLiteral(0.0)) :
            Literal(), real(r), im(i) { }

    /**
     * \fn ComplexLiteral(NumericLiteral r, NumericLiteral i = NumericLiteral(0.0))
     * \brief Copy Constructor
     * \param[in] l : ComplexLiteral being copied
     * \return An instance of ComplexLiteral having the same values than the ComplexLiteral parameter
     */
    ComplexLiteral(ComplexLiteral &l) : Literal() {
        real = l.real; // default copy constructor OK for NumericLiteral
        im = l.im; // default copy constructor OK for NumericLiteral
    }

    virtual ~ComplexLiteral() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================

    /**
     * \fn const NumericLiteral & getReal() const
     * \brief Getter for the private attribute real
     * \return The private attribute real, instance of NumericLiteral
     */
    const NumericLiteral & getReal() const {
        return real;
    }

    /**
     * \fn void setReal(const NumericLiteral &r)
     * \brief Setter for the private attribute real
     * \param[in] r : NumericLiteral
     */
    void setReal(const NumericLiteral &r) {
        real = r;
    }

    /**
     * \fn const NumericLiteral & getIm() const
     * \brief Getter for the private attribute im
     * \return The private attribute im, instance of NumericLiteral
     */
    const NumericLiteral & getIm() const {
        return im;
    }

    /**
     * \fn void setIm(const NumericLiteral &i)
     * \brief Setter for the private attribute im
     * \param[in] i : NumericLiteral
     */
    void setIm(const NumericLiteral &i) {
        im = i;
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                         Override Methods                      ==========================
    // ===============================================================================================================
    /**
     * \fn virtual string toString() const override
     * \brief Method that return the ComplexLiteral in a string
     * \return A string displaying the ComplexLiteral with the character $ separating the two parts
     * (display the imaginary part only if it's exists)
     */
    virtual string toString() const override;
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Operators overload                      ==========================
    // ===============================================================================================================

    // Classic operators
    /**
     * \fn shared_ptr<ComplexLiteral> operator+(ComplexLiteral &l) const
     * \brief Overload of operator+ between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return A new shared_ptr<ComplexLiteral>, result of the operation
     */
    shared_ptr<ComplexLiteral> operator+(const ComplexLiteral &l) const;

    /**
     * \fn shared_ptr<ComplexLiteral> operator-(ComplexLiteral &l) const
     * \brief Overload of operator- between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return A new shared_ptr<ComplexLiteral>, result of the operation
     */
    shared_ptr<ComplexLiteral> operator-(const ComplexLiteral &l) const;

    /**
     * \fn shared_ptr<ComplexLiteral> operator*(ComplexLiteral &l) const
     * \brief Overload of operator* between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return A new shared_ptr<ComplexLiteral>, result of the operation
     */
    shared_ptr<ComplexLiteral> operator*(const ComplexLiteral &l) const;

    /**
     * \fn shared_ptr<ComplexLiteral> operator/(const ComplexLiteral &l) const
     * \brief Overload of operator/ between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return A new shared_ptr<ComplexLiteral>, result of the operation
     */
    shared_ptr<ComplexLiteral> operator/(const ComplexLiteral &l) const;

    /**
     * \fn shared_ptr<ComplexLiteral> negOperator() const
     * \brief Apply negation on the implicit parameter ComplexLiteral
     * \return A new shared_ptr<ComplexLiteral>, result of the operation
     */
    shared_ptr<ComplexLiteral> negOperator() const;

    // Logical operators
    /**
     * \fn bool operator<(const ComplexLiteral &l) const
     * \brief Overload of operator< between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return True if implicit parameter is inferior to the parameter l, otherwise return false
     */
    bool operator<(const ComplexLiteral &l) const;

    /**
     * \fn bool operator==(const ComplexLiteral &l) const
     * \brief Overload of operator== between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return True if implicit parameter is equal to the parameter l, otherwise return false
     */
    bool operator==(const ComplexLiteral &l) const;

    /**
     * \fn bool operator>(const ComplexLiteral &l) const
     * \brief Overload of operator> between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return True if implicit parameter is superior to the parameter l, otherwise return false
     */
    bool operator>(const ComplexLiteral &l) const;

    /**
     * \fn bool operator<=(const ComplexLiteral &l) const
     * \brief Overload of operator<= between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return True if implicit parameter is inferior or equal to the parameter l, otherwise return false
     */
    bool operator<=(const ComplexLiteral &l) const;

    /**
     * \fn bool operator>=(const ComplexLiteral &l) const
     * \brief Overload of operator>= between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return True if implicit parameter is superior or equal to the parameter l, otherwise return false
     */
    bool operator>=(const ComplexLiteral &l) const;

    /**
     * \fn bool operator!=(const ComplexLiteral &l) const
     * \brief Overload of operator!= between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return True if implicit parameter is different from the parameter l, otherwise return false
     */
    bool operator!=(const ComplexLiteral &l) const;

    /**
     * \fn bool operator&&(const ComplexLiteral &l) const
     * \brief Overload of operator&& between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return True if both ComplexLiteral are true, otherwise return false
     */
    bool operator&&(const ComplexLiteral &l) const;

    /**
     * \fn bool operator||(const ComplexLiteral &l) const
     * \brief Overload of operator|| between two ComplexLiteral
     * \param[in] l : const ComplexLiteral &
     * \return True if at least one of the two ComplexLiteral is true, otherwise return false
     */
    bool operator||(const ComplexLiteral &l) const;

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
     * \fn bool isComplex() const
     * \brief Test if a ComplexLiteral is really a complex number
     * \return True if the numerator of the imaginiry part is different from 0, false otherwise
     */
    bool isComplex() const;

    /**
     * \fn bool isInteger() const
     * \brief Test if a ComplexLiteral is an integer number
     * \return True if the imaginary part is 0 dans if the real part is an integer only, otherwise return false
     */
    bool isInteger() const;

    /**
     * \fn bool isRational() const
     * \brief Test if a ComplexLiteral is a rational number
     * \return True if the imaginary part is 0 dans if the real part is a rational, otherwise return false
     */
    bool isRational() const;

    /**
     * \fn bool isReal() const
     * \brief Test if a ComplexLiteral is a real number
     * \return True if the imaginary part is 0 dans if the real part is a real number, otherwise return false
     */
    bool isReal() const;
    // ===============================================================================================================
};


#endif //TESTLO21CLION_COMPLEXLITERAL_H
