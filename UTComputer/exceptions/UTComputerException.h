/**
 * \file UTComputerException.h
 * \brief File containing the declaration of the UTComputerException class.
 */

#ifndef TESTLO21CLION_UTCOMPUTEREXCEPTION_H
#define TESTLO21CLION_UTCOMPUTEREXCEPTION_H

#include <iostream>
#include <string>

using namespace std;

/**
 * \class UTComputerException
 * \brief Class used to manage raised exceptions and display messages
 */
class UTComputerException {
    string message;
    string message_for_user;

public:

    /**
     * \fn UTComputerException(const string &message) : message(message) {
     * \brief Constructor
     * \param[in] message : string used to construct the new object
     * \return An instance of UTComputerException
     */
    UTComputerException(const string &message) : message(message) { }


    /**
     * \fn const string &getMessage() const
     * \brief Getter for the private attribute message
     * \return The private attribute message
     */
    const string &getMessage() const {
        return message;
    }


    /**
     * \fn void setMessage(const string &message)
     * \brief Setter for the private attribute message
     * \param[in] mes : string used to set the private attribute message
     */
    void setMessage(const string &mes) {
        message = mes;
    }

    /**
     * \fn const string &get_message_for_user() const
     * \brief Getter for the private attribute message_for_user
     * \return The private attribute message_for_user
     */
    const string &get_message_for_user() const {
        return message_for_user;
    }



    /**
     * \fn void set_message_for_user(const string &message)
     * \brief Setter for the private attribute message_for_user
     * \param[in] message : string used to set the private attribute message_for_user
     */
    void set_message_for_user(const string &message) {
        message_for_user = message;
    }



    /**
     * \fn void insertBefore(const string &s)
     * \brief Method that insert a string at the beginning of the private attribute message
     * \param[in] s : the string to insert
     */
    void insertBefore(const string &s) {
        message.insert(0,s);
    }
};


#endif //TESTLO21CLION_UTCOMPUTEREXCEPTION_H
