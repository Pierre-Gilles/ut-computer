//
// Created by Raphael on 17/05/2016.
//

#ifndef TESTLO21CLION_UTCOMPUTEREXCEPTION_H
#define TESTLO21CLION_UTCOMPUTEREXCEPTION_H

#include <iostream>
#include <string>

using namespace std;

class UTComputerException {
    string message;

public:

    UTComputerException(const string &message) : message(message) { }

    const string &getMessage() const {
        return message;
    }

    void setMessage(const string &message) {
        UTComputerException::message = message;
    }

    void insertBefore(const string &s) {
        message.insert(0,s);
    }
};


#endif //TESTLO21CLION_UTCOMPUTEREXCEPTION_H
