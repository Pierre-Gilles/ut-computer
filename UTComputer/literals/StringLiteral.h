/**
 * \file StringLiteral.h
 * \brief File containing the declaration of the class StringLiteral
 */

#ifndef TESTLO21CLION_STRINGLITERAL_H
#define TESTLO21CLION_STRINGLITERAL_H

#include "Literal.h"

/**
 * \class StringLiteral
 * \brief subclass of Literal
 *
 * Superclass for all string type literals (AtomLiteral, ProgramLiteral and ExpressionLiteral)
 */
class StringLiteral : public Literal {
protected:
    string value;
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    StringLiteral(const string &value) : value(value) { }
    virtual ~StringLiteral() { }
    // ===============================================================================================================




    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================
    const string &getValue() const {
        return value;
    }

    void setValue(const string &val) {
        value = val;
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                         Override Methods                      ==========================
    // ===============================================================================================================
    virtual string toString() const override = 0;
    // ===============================================================================================================

};


#endif //TESTLO21CLION_STRINGLITERAL_H
