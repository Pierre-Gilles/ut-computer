#include "ComplexLiteral.h"


string ComplexLiteral::toString() const {
    ostringstream sting_stream;
    if (im.getNumerator() == 0.0) { // then it's not a complex but a NumericLiteral
        return real.toString();
    }
    else {
        sting_stream << real.toString() << "$" << im.toString();
        return sting_stream.str();
    }
}




// ===============================================================================================================
// ======================                       Operators overload                      ==========================
// ===============================================================================================================

// Classic operators

shared_ptr<ComplexLiteral> ComplexLiteral::operator+(ComplexLiteral &l) const {
    return shared_ptr<ComplexLiteral>(new ComplexLiteral(
            real + l.real,
            im + l.im
//            real + l.real,
//            im + l.im
    ));
}

shared_ptr<ComplexLiteral> ComplexLiteral::operator+(NumericLiteral &l) const {
    return shared_ptr<ComplexLiteral>(new ComplexLiteral(
            real + l, // call to NumericLiteral::operator+(NumericLiteral &l) const that returns a new NumericLiteral
            im
    ));
}

shared_ptr<ComplexLiteral> ComplexLiteral::operator-(ComplexLiteral &l) const {
    return shared_ptr<ComplexLiteral>(new ComplexLiteral(
            real - l.real,
            im - l.im
    ));
}

shared_ptr<ComplexLiteral> ComplexLiteral::operator*(ComplexLiteral &l) const {

    // if both complex are not really complex numbers
    if (im.getNumerator() == 0 && l.im.getNumerator() == 0)
        return shared_ptr<ComplexLiteral>(new ComplexLiteral(real * l.real));


    // Formula :  { (reall.real) - (iml.im) }   +   { i(reall.im +iml.real) }

    // Calculate real part

    NumericLiteral part_real_tmp1 =  real * l.real; // return au new NumericLiteral because of operator*() overload in NumericLiteral
    NumericLiteral part_real_tmp2 =  im * l.im; // return au new NumericLiteral because of operator*() overload in NumericLiteral
    NumericLiteral real_part_result = part_real_tmp1 - part_real_tmp2; // return au new NumericLiteral because of operator-() overload in NumericLiteral

    // Calculate imaginary part
    NumericLiteral part_im_tmp1 =  real * l.im; // return au new NumericLiteral because of operator*() overload in NumericLiteral
    NumericLiteral part_im_tmp2 =  im * l.real; // return au new NumericLiteral because of operator*() overload in NumericLiteral
    NumericLiteral im_part_result = part_im_tmp1 + part_im_tmp2; // return au new NumericLiteral because of operator+() overload in NumericLiteral

    // return new Complex
    return shared_ptr<ComplexLiteral>(new ComplexLiteral(real_part_result, im_part_result));
}

shared_ptr<ComplexLiteral> ComplexLiteral::operator/(ComplexLiteral &l) const {
    // if both complex are not really complex numbers
    if (im.getNumerator() == 0 && l.im.getNumerator() == 0)
        return shared_ptr<ComplexLiteral>(new ComplexLiteral(real / l.real));

    /* Formula :
     *  - real part : (reall.real + iml.im) / (l.reall.real + l.iml.im)
     *  - im part   : (iml.real - reall.im) / (l.reall.real + l.iml.im)
     *  */

    // Calculate common denominator
    NumericLiteral common_den_tmp1 =  l.real * l.real; // return au new NumericLiteral because of operator*() overload in NumericLiteral
    NumericLiteral common_den_tmp2 =  l.im * l.im; // return au new NumericLiteral because of operator*() overload in NumericLiteral
    NumericLiteral common_den_result =  common_den_tmp1 + common_den_tmp2; // return au new NumericLiteral because of operator+() overload in NumericLiteral

    // throw exception if common denominator value is 0
    if (common_den_result.getNumerator() == 0 || common_den_result.getDenominator() == 0) {
        throw UTComputerException("Error ComplexLiteral::operator/(ComplexLiteral &l : common denominator is 0.");
    }

    // Calculate real part
    NumericLiteral real_part_tmp1 =  real * l.real; // return au new NumericLiteral because of operator*() overload in NumericLiteral
    NumericLiteral real_part_tmp2 =  im * l.im; // return au new NumericLiteral because of operator*() overload in NumericLiteral
    NumericLiteral real_part_num_tmp = real_part_tmp1 + real_part_tmp2; // return au new NumericLiteral because of operator+() overload in NumericLiteral
    NumericLiteral real_part_result = real_part_num_tmp / common_den_result; // return au new NumericLiteral because of operator/() overload in NumericLiteral

    // Calculate imaginary part
    NumericLiteral im_part_tmp1 =  im * l.real; // return au new NumericLiteral because of operator*() overload in NumericLiteral
    NumericLiteral im_part_tmp2 =  real * l.im; // return au new NumericLiteral because of operator*() overload in NumericLiteral
    NumericLiteral im_part_num_tmp = im_part_tmp1 - im_part_tmp2; // return au new NumericLiteral because of operator-() overload in NumericLiteral
    NumericLiteral im_part_result = im_part_num_tmp / common_den_result; // return au new NumericLiteral because of operator/() overload in NumericLiteral

    // return new Complex
    return shared_ptr<ComplexLiteral>(new ComplexLiteral(real_part_result, im_part_result));
}


shared_ptr<ComplexLiteral> ComplexLiteral::negOperator() const {
    return shared_ptr<ComplexLiteral>(new ComplexLiteral(real.negOperator(), im.negOperator()));
}


// Logical Operators apply only on non complex numbers : im and l.im must be 0
bool ComplexLiteral::operator<(const ComplexLiteral &l) const {
    if (!isComplex() && !l.isComplex())
        return real < l.real;
    throw UTComputerException("Error ComplexLiteral::operator< : comparing two complex numbers is impossible.");
}

bool ComplexLiteral::operator==(const ComplexLiteral &l) const {
    return real == l.real && im == l.im;
}

bool ComplexLiteral::operator>(const ComplexLiteral &l) const {
    if (!isComplex() && !l.isComplex())
        return real > l.real;
    throw UTComputerException("Error ComplexLiteral::operator> : comparing two complex numbers is impossible.");
}

bool ComplexLiteral::operator<=(const ComplexLiteral &l) const {
    if (!isComplex() && !l.isComplex())
        return real <= l.real;
    throw UTComputerException("Error ComplexLiteral::operator<= : comparing two complex numbers is impossible.");
}

bool ComplexLiteral::operator>=(const ComplexLiteral &l) const {
    if (!isComplex() && !l.isComplex())
        return real >= l.real;
    throw UTComputerException("Error ComplexLiteral::operator>= : comparing two complex numbers is impossible.");
}

bool ComplexLiteral::operator!=(const ComplexLiteral &l) const {
    return !(*this == l);
}

bool ComplexLiteral::operator&&(const ComplexLiteral &l) const {
    if (!isComplex() && !l.isComplex())
        return real && l.real;
    throw UTComputerException("Error ComplexLiteral::operator&&: comparing two complex numbers is impossible.");
}

bool ComplexLiteral::operator||(const ComplexLiteral &l) const {
    if (!isComplex() && !l.isComplex())
        return real || l.real;
    throw UTComputerException("Error ComplexLiteral::operator|| : comparing two complex numbers is impossible.");
}

bool ComplexLiteral::operator!() const {
    if (im.getNumerator() == 0)
        return !(real);
    throw UTComputerException("Error ComplexLiteral::operator! : what is a NOT complex number ?.");
}

// ===============================================================================================================









// ===============================================================================================================
// ======================                       Useful class functions                  ==========================
// ===============================================================================================================
bool ComplexLiteral::isComplex() const {
    return im.getNumerator() != 0.0;
}

bool ComplexLiteral::isInteger() const {
    return (  !isComplex() && real.isInteger()  );
}

bool ComplexLiteral::isRational() const {
    return (  !isComplex() && real.isRational()  );
}

bool ComplexLiteral::isReal() const {
    return (  !isComplex() && real.isReal()  );
}

// ===============================================================================================================