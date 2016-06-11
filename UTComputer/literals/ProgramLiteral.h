/**
 * \file ProgramLiteral.h
 * \brief File containing the declaration of the class ProgramLiteral
 */

#ifndef UTCOMPUTER_PROGRAMLITERAL_H
#define UTCOMPUTER_PROGRAMLITERAL_H


#include "StringLiteral.h"


/**
 * \class ProgramLiteral
 * \brief Subclass of StringLiteral
 *
 * Class used to managed programs
 */
class ProgramLiteral : public StringLiteral {

    const static string programRegex; /*!< String containing the regex specific to ProgramLiteral */
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================

    /**
     * \fn ProgramLiteral(const string &value)
     * \brief Constructor taking a string to construct a new ProgramLiteral
     * \param[in] value : string from which the ProgramLiteral is created
     * \return An instance of ProgramLiteral.
     */
    ProgramLiteral(const string &value) : StringLiteral(value) { }

    /**
     * \fn ProgramLiteral(const ProgramLiteral &l)
     * \brief Constructor taking a ProgramLiteral to construct a new ProgramLiteral
     * \param[in] l : ProgramLiteral copied
     * \return An instance of ProgramLiteral, copy of parameter l.
     */
    ProgramLiteral(const ProgramLiteral &l) : StringLiteral(l.value) { }
    virtual ~ProgramLiteral() { }

    // ===============================================================================================================






    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================

    /**
     * \fn static const string &getProgramRegex()
     * \brief Static function to get the static attribute programRegex
     * \return The static private attribute programRegex
     */
    static const string &getProgramRegex() {
        return programRegex;
    }

    // ===============================================================================================================






    // ===============================================================================================================
    // ======================                         Override Methods                      ==========================
    // ===============================================================================================================
    /**
     * \fn virtual string toString() const override
     * \brief Override of the virtual pure toString() function
     * \return The protected attribute \a value surrounded by [] : [value].
     * Replace all \\t or \\n by spaces for the toString method
     */
    virtual string toString() const override;
    // ===============================================================================================================



};


#endif //UTCOMPUTER_PROGRAMLITERAL_H
