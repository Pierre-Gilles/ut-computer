#include "ComplexLiteral.h"


string ComplexLiteral::toString() const {
    ostringstream sting_stream;
    if (im->getNumerator() == 0.0) { // then it's not a complex but a NumericLiteral
        return real->toString();
    }
    else {
        sting_stream << real->toString() << "$" << im->toString();
        return sting_stream.str();
    }
}




// ===============================================================================================================
// ======================                       Operators overload                      ==========================
// ===============================================================================================================

// Classic operators

shared_ptr<ComplexLiteral> ComplexLiteral::operator+(ComplexLiteral &l) const {
    return shared_ptr<ComplexLiteral>(new ComplexLiteral(
            *(real) + *(l.real),
            *(im) + *(l.im)
    ));
}

shared_ptr<ComplexLiteral> ComplexLiteral::operator+(NumericLiteral &l) const {
    return shared_ptr<ComplexLiteral>(new ComplexLiteral(
            *(real) + l, // call to NumericLiteral::operator+(NumericLiteral &l) const that returns a new NumericLiteral
            im
    ));
}

shared_ptr<ComplexLiteral> ComplexLiteral::operator-(ComplexLiteral &l) const {
    return shared_ptr<ComplexLiteral>(new ComplexLiteral(
            *(real) - *(l.real),
            *(im) - *(l.im)
    ));
}

shared_ptr<ComplexLiteral> ComplexLiteral::operator*(ComplexLiteral &l) const {

    // if both complex are not really complex numbers
    if (im->getNumerator() == 0 && l.im->getNumerator() == 0)
        return shared_ptr<ComplexLiteral>(new ComplexLiteral(*real * *l.real));


    // Formula :  { (real*l.real) - (im*l.im) }   +   { i(real*l.im +im*l.real) }

    // Calculate real part

    shared_ptr<NumericLiteral> part_real_tmp1 =  *(real) * *(l.real); // return au new NumericLiteral because of operator*() overload in NumericLiteral
    shared_ptr<NumericLiteral> part_real_tmp2 =  *(im) * *(l.im); // return au new NumericLiteral because of operator*() overload in NumericLiteral
    shared_ptr<NumericLiteral> real_part_result = *part_real_tmp1 - *part_real_tmp2; // return au new NumericLiteral because of operator-() overload in NumericLiteral

    // Calculate imaginary part
    shared_ptr<NumericLiteral> part_im_tmp1 =  *(real) * *(l.im); // return au new NumericLiteral because of operator*() overload in NumericLiteral
    shared_ptr<NumericLiteral> part_im_tmp2 =  *(im) * *(l.real); // return au new NumericLiteral because of operator*() overload in NumericLiteral
    shared_ptr<NumericLiteral> im_part_result = *part_im_tmp1 + *part_im_tmp2; // return au new NumericLiteral because of operator+() overload in NumericLiteral

    // return new Complex
    return shared_ptr<ComplexLiteral>(new ComplexLiteral(real_part_result, im_part_result));
}

shared_ptr<ComplexLiteral> ComplexLiteral::operator/(ComplexLiteral &l) const {
    // if both complex are not really complex numbers
    if (im->getNumerator() == 0 && l.im->getNumerator() == 0)
        return shared_ptr<ComplexLiteral>(new ComplexLiteral(*real / *l.real));

    /* Formula :
     *  - real part : (real*l.real + im*l.im) / (l.real*l.real + l.im*l.im)
     *  - im part   : (im*l.real - real*l.im) / (l.real*l.real + l.im*l.im)
     *  */

    // Calculate common denominator
    shared_ptr<NumericLiteral> common_den_tmp1 =  *(l.real) * *(l.real); // return au new NumericLiteral because of operator*() overload in NumericLiteral
    shared_ptr<NumericLiteral> common_den_tmp2 =  *(l.im) * *(l.im); // return au new NumericLiteral because of operator*() overload in NumericLiteral
    shared_ptr<NumericLiteral> common_den_result =  *common_den_tmp1 + *common_den_tmp2; // return au new NumericLiteral because of operator+() overload in NumericLiteral

    // throw exception if common denominator value is 0
    if (common_den_result->getNumerator() == 0 || common_den_result->getDenominator() == 0) {
        throw UTComputerException("Error ComplexLiteral::operator/(ComplexLiteral &l : common denominator is 0.");
    }

    // Calculate real part
    shared_ptr<NumericLiteral> real_part_tmp1 =  *(real) * *(l.real); // return au new NumericLiteral because of operator*() overload in NumericLiteral
    shared_ptr<NumericLiteral> real_part_tmp2 =  *(im) * *(l.im); // return au new NumericLiteral because of operator*() overload in NumericLiteral
    shared_ptr<NumericLiteral> real_part_num_tmp = *real_part_tmp1 + *real_part_tmp2; // return au new NumericLiteral because of operator+() overload in NumericLiteral
    shared_ptr<NumericLiteral> real_part_result = *real_part_num_tmp / *common_den_result; // return au new NumericLiteral because of operator/() overload in NumericLiteral

    // Calculate imaginary part
    shared_ptr<NumericLiteral> im_part_tmp1 =  *(im) * *(l.real); // return au new NumericLiteral because of operator*() overload in NumericLiteral
    shared_ptr<NumericLiteral> im_part_tmp2 =  *(real) * *(l.im); // return au new NumericLiteral because of operator*() overload in NumericLiteral
    shared_ptr<NumericLiteral> im_part_num_tmp = *im_part_tmp1 - *im_part_tmp2; // return au new NumericLiteral because of operator-() overload in NumericLiteral
    shared_ptr<NumericLiteral> im_part_result = *im_part_num_tmp / *common_den_result; // return au new NumericLiteral because of operator/() overload in NumericLiteral

    // return new Complex
    return shared_ptr<ComplexLiteral>(new ComplexLiteral(real_part_result, im_part_result));
}



// Logical Operators
bool ComplexLiteral::operator<(const ComplexLiteral &l) const {
    if (im->getNumerator() == 0 && l.im->getNumerator() == 0)
        return *real < *l.real;
    throw UTComputerException("Error ComplexLiteral::operator< : comparing two complex numbers is impossible.");
}

bool ComplexLiteral::operator==(const ComplexLiteral &l) const {
    if (im->getNumerator() == 0 && l.im->getNumerator() == 0)
        return *real == *l.real;
    throw UTComputerException("Error ComplexLiteral::operator== : comparing two complex numbers is impossible.");
}

bool ComplexLiteral::operator>(const ComplexLiteral &l) const {
    if (im->getNumerator() == 0 && l.im->getNumerator() == 0)
        return *real > *l.real;
    throw UTComputerException("Error ComplexLiteral::operator> : comparing two complex numbers is impossible.");
}

bool ComplexLiteral::operator<=(const ComplexLiteral &l) const {
    if (im->getNumerator() == 0 && l.im->getNumerator() == 0)
        return *real <= *l.real;
    throw UTComputerException("Error ComplexLiteral::operator<= : comparing two complex numbers is impossible.");
}

bool ComplexLiteral::operator>=(const ComplexLiteral &l) const {
    if (im->getNumerator() == 0 && l.im->getNumerator() == 0)
        return *real >= *l.real;
    throw UTComputerException("Error ComplexLiteral::operator>= : comparing two complex numbers is impossible.");
}

bool ComplexLiteral::operator!=(const ComplexLiteral &l) const {
    if (im->getNumerator() == 0 && l.im->getNumerator() == 0)
        return *real != *l.real;
    throw UTComputerException("Error ComplexLiteral::operator!= : comparing two complex numbers is impossible.");
}
// ===============================================================================================================