/**
 * \file AtomLiteral.h
 * \brief File containing the declaration of the class AtomLiteral
 */
#ifndef UTCOMPUTER_ATOMLITERAL_H
#define UTCOMPUTER_ATOMLITERAL_H


#include "StringLiteral.h"

/**
 * \class AtomLiteral
 * \brief Subclass of StringLiteral
 */
class AtomLiteral : public StringLiteral {

    const static string atomRegex; /*!< String containing the regex specific to AtomLiteral */

public:
    /**
     * \fn AtomLiteral(const string &value)
     * \brief AtomLiteral constructor taking a string to construct a new AtomLiteral
     * \param[in] value : string from which the AtomLiteral is created
     * \return An AtomLiteral instance
     */
    AtomLiteral(const string &value) : StringLiteral(value) { }

    virtual ~AtomLiteral() { }


    /**
     * \fn static const string &getAtomRegex()
     * \brief Static function to get the static attribute atomRegex
     * \return The static private attribute atomRegex
     */
    static const string &getAtomRegex() {
        return atomRegex;
    }

    /**
     * \fn virtual string toString() const override
     * \brief Redefinition of the superclass virtual pure toString() method
     * \return The protected attribute \a value
     */
    virtual string toString() const override {
        return value;
    }


};


#endif //UTCOMPUTER_ATOMLITERAL_H
