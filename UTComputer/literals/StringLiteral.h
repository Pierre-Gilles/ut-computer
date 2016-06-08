/**
 * \file StringLiteral.h
 * \brief File containing the declaration of the class StringLiteral
 */

#ifndef TESTLO21CLION_STRINGLITERAL_H
#define TESTLO21CLION_STRINGLITERAL_H

#include "Literal.h"

/**
 * \class StringLiteral
 * \brief Abstract subclass of Literal
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
    /**
     * \fn StringLiteral(const string &value)
     * \brief ExpressionLiteral constructor
     * \param[in] value : string from which the StringLiteral is created (subclasses will call this constructor)
     * \return \a Nothing because the class is abstract and can't beinstantiated
     */
    StringLiteral(const string &value) : value(value) { }
    virtual ~StringLiteral() { } /*!< virtual destructor is necessary with inheritance */
    // ===============================================================================================================




    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================
    /**
     * \fn const string &getValue() const
     * \brief Getter for the protected attribute value
     * \return The protected attribute value
     */
    const string &getValue() const {
        return value;
    }
    /**
     * \fn void setValue(const string &val)
     * \brief Setter for the protected attribute value
     * \param[in] val : the string used to set the protected attribute value
     */
    void setValue(const string &val) {
        value = val;
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                         Override Methods                      ==========================
    // ===============================================================================================================
    /**
     * \fn virtual string toString() const
     * \brief Virtual pure method that will be redefined by each subclass
     * \return A string that will depend on the subclass implementing this method
     */
    virtual string toString() const override = 0;
    // ===============================================================================================================

};


#endif //TESTLO21CLION_STRINGLITERAL_H
