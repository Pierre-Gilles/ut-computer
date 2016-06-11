
#include "NumericLiteral.h"



const string NumericLiteral::numericRegex = "(^[0-9]+$)|(^([0-9]*|-*[0-9]*)(\\.[0-9]+)?$)";


// ===============================================================================================================
// ======================                         Override Methods                      ==========================
// ===============================================================================================================
string NumericLiteral::toString() const {
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
// ===============================================================================================================


// ===============================================================================================================
// ======================                       Operators overload                      ==========================
// ===============================================================================================================

// Classic operators

NumericLiteral NumericLiteral::operator+(const NumericLiteral &l) const {
    /* if one is a real literal and the other a rational literal, we must return a
         * real literal with the result of the operation in the numerator attribute
         * and set the denominator to 1 */
    if (isReal() || l.isReal()) {
        NumericLiteral tmp = NumericLiteral(
                numerator*l.denominator + l.numerator*denominator,
                denominator * l.denominator
        );
        tmp.numerator = tmp.numerator/tmp.denominator;
        tmp.denominator = 1;
        return tmp;

/* It was also possible to return a rational or an integer (after simplification)
 * but the it's clearly specified in the project that addition with real always return a real literal */
    }

/* In general, we return a new numeric literal with the normal plus operation */
    return NumericLiteral(
            numerator*l.denominator + l.numerator*denominator,
            denominator * l.denominator
    );
}

NumericLiteral NumericLiteral::operator-(const NumericLiteral &l) const {
    /* if one is a real literal and the other a rational literal, we must return a
         * real literal with the result of the operation in the numerator attribute
         * and set the denominator to 1 */
    if (isReal() || l.isReal()) {
        NumericLiteral tmp = NumericLiteral(
                numerator*l.denominator - l.numerator*denominator,
                denominator * l.denominator
        );
        tmp.numerator = tmp.numerator/tmp.denominator;
        tmp.denominator = 1;
        return tmp;

        /* It was also possible to return a rational or an integer (after simplification)
         * but the it's clearly specified in the project that difference with real always return a real literal */
    }

    /* In general, we return a new numeric literal with the normal plus operation */
    return NumericLiteral(
            numerator*l.denominator - l.numerator*denominator,
            denominator * l.denominator
    );
}

NumericLiteral NumericLiteral::operator*(const NumericLiteral &l) const {
    /* if one of the arguments is real, we must return a
         * real literal with the result of the operation in the numerator attribute
         * and set the denominator to 1 */
    if (isReal() || l.isReal()) {
        NumericLiteral tmp = NumericLiteral(
                numerator*l.numerator,
                denominator * l.denominator
        );
        tmp.numerator = tmp.numerator/tmp.denominator;
        tmp.denominator = 1;
        return tmp;
    }

    /* In general, we return a new numeric literal with the normal multiplication operation */
    return NumericLiteral(
            numerator*l.numerator,
            denominator * l.denominator
    );
}

NumericLiteral NumericLiteral::operator/(const NumericLiteral &l) const {
    if (denominator == 0.0 || l.denominator == 0.0)
        throw UTComputerException("Error NumericLiteral::operator/(NumericLiteral &l) : one of the denominators is 0.");

    if (l.numerator == 0.0)
        throw UTComputerException("Error NumericLiteral::operator/(NumericLiteral &l) : l is 0 and division by zero is impossible.");

    /* if one of the arguments is real, we must return a
     * real literal with the result of the operation in the numerator attribute
     * and set the denominator to 1 */
    if (isReal() || l.isReal()) {
        NumericLiteral tmp = NumericLiteral(
                numerator*l.denominator,
                denominator * l.numerator
        );
        tmp.numerator = tmp.numerator/tmp.denominator;
        tmp.denominator = 1;
        return tmp;
    }

    /* In general, we return a new numeric literal with the normal division operation */
    return NumericLiteral(
            numerator*l.denominator,
            denominator * l.numerator
    );
}

NumericLiteral NumericLiteral::negOperator() const {
    return NumericLiteral(-numerator, denominator);
}


// Logical operators

bool NumericLiteral::operator<(const NumericLiteral &l) const {
    return ( (numerator/denominator) < (l.numerator/l.denominator) );
}

bool NumericLiteral::operator==(const NumericLiteral &l) const {
    return (
            (numerator == l.numerator && denominator == l.denominator)
            || ((numerator/denominator) == (l.numerator/l.denominator))
    );
}

bool NumericLiteral::operator>(const NumericLiteral &l) const {
    return ( !(*this<l) && !(*this==l) );
}

bool NumericLiteral::operator<=(const NumericLiteral &l) const {
    return ( (*this<l) || (*this==l) );
}

bool NumericLiteral::operator>=(const NumericLiteral &l) const {
    return ( (*this>l) || (*this==l) );
}

bool NumericLiteral::operator!=(const NumericLiteral &l) const {
    return ( !(*this==l) );
}

bool NumericLiteral::operator&&(const NumericLiteral &l) const {
    // if one of the NumericLiteral is 0, then AND return false
    if (numerator == 0.0 || l.numerator == 0.0)
        return false;
    else
        return true;
}

bool NumericLiteral::operator||(const NumericLiteral &l) const {
    // if one of the NumericLiteral is not 0, then AND return true
    if (numerator != 0.0 || l.numerator != 0.0)
        return true;
    else
        return false;
}

bool NumericLiteral::operator!() const {
    if (numerator == 0.0) // then !false = true
        return true;
    else // !true = false
        return false;
}




// ===============================================================================================================
// ======================                       Useful class functions                  ==========================
// ===============================================================================================================

void NumericLiteral::simplification() {
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

    /* Use of Euclide algorithm to find the greatest common divisor */
    double a=numerator, b=denominator;

    // we only works with positive values
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

    // division of numerator and denominator by a, the greatest common divisor
    numerator /= a;
    denominator /= a;

    // if denominator is negative, pass the negation to the numerator
    if (denominator < 0) {
        denominator = -denominator;
        numerator = -numerator;
    }
}

bool NumericLiteral::isInteger() const {
    double intpart;
    return (modf(numerator, &intpart) == 0.0
            && denominator == 1
    );
}

bool NumericLiteral::isRational() const {
    double intpart;
    return ( modf(numerator, &intpart) == 0.0
             && modf(denominator, &intpart) == 0.0
             && denominator!= 1
    );
}

bool NumericLiteral::isReal() const {
    double intpart;
    return ( modf(numerator, &intpart) != 0.0
             && denominator == 1
    );
}