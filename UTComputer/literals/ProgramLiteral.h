#ifndef UTCOMPUTER_PROGRAMLITERAL_H
#define UTCOMPUTER_PROGRAMLITERAL_H


#include "StringLiteral.h"

/*
 * Les séparateurs utilisés dans un programmes peuvent être l’espace, la tabulation ou le retour chariot.
 * Lors de l’affichage d’un programme dans la pile, on utilisera cependant le caractère espace à la place de la
 * tabulation et du retour chariot. Le retour chariot et la tabulation pouront être utilisés dans une fenêtre
 * spacieuse dédiée spécifiquement à l’édition des programmes.
 */

class ProgramLiteral : public StringLiteral {

    const static string programRegex;
public:

    ProgramLiteral(const string &value) : StringLiteral(value) { }
    ProgramLiteral(const ProgramLiteral &l) : StringLiteral(l.value) { }
    virtual ~ProgramLiteral() { }

    virtual string toString() const override {
        /* replace all \t or \n by spaces for the toString method (use the getValue() to get the program with \t and \n */
        string tmp = value;
        replace(tmp.begin(), tmp.end(), '\t', ' ');
        replace(tmp.begin(), tmp.end(), '\n', ' ');
        return "[" + tmp + "]";
    }


    static const string &getProgramRegex() {
        return programRegex;
    }
};


#endif //UTCOMPUTER_PROGRAMLITERAL_H
