/**
 * \file Literal.h
 * \brief File containing the Literal class, super class for all specific literals.
 */

#ifndef TESTLO21CLION_LITERAL_H
#define TESTLO21CLION_LITERAL_H

#include <string>
#include "../exceptions/UTComputerException.h"
#include <memory>

using namespace std;

/**
 * \class Literal
 * \brief Abstract class for all literals
 */
class Literal {
protected:
    Literal() { }
public:
    virtual ~Literal() {  }

    /**
     * \fn virtual string toString() const
     * \brief Virtual pure method that will be redefined by each subclass
     * \return A string that will depend on the subclass implementing this method
     */
    virtual string toString() const = 0;
};


#endif //TESTLO21CLION_LITERAL_H
