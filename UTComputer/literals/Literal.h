//
// Created by Raphael on 13/05/2016.
//

#ifndef TESTLO21CLION_LITERAL_H
#define TESTLO21CLION_LITERAL_H

#include <string>
#include "../exceptions/UTComputerException.h"

using namespace std;
class Literal {
protected:
    Literal() { }
public:
    virtual ~Literal() {  }

    /* toString() will be used by subclasses in const method but we cannot declare it as const and at the same time
     * as virtual pure */
    virtual string toString() = 0;
};


#endif //TESTLO21CLION_LITERAL_H
