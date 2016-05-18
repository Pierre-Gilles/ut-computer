//
// Created by Raphael on 15/05/2016.
//

#ifndef TESTLO21CLION_EXPRESSIONLITERAL_H
#define TESTLO21CLION_EXPRESSIONLITERAL_H

#include <sstream>
#include <string>
#include "StringLiteral.h"
#include "NumericLiteral.h"
#include "ComplexLiteral.h"

class ExpressionLiteral : public StringLiteral {

public:

    ExpressionLiteral(const string &value) : StringLiteral(value) { }

    virtual ~ExpressionLiteral() { }

    bool samePriority(const string &op, const string &expression) const {
        /* TODO gérer la priorité des opérateurs pour les operations sur les ExpressionLiteral
         * Trouver tous les opérateurs non parenthésés dans "expression"
         *      S'ils ont la même priorité que "op", retourner vrai
         *      Sinon retourner faux
         * */
        size_t found;
        if (op == "+" || op == "-") {
            found = expression.find_first_of("*/$");
            return (found == std::string::npos);
        }
        if (op == "*" || op == "/") {
            found = expression.find_first_of("+-");
            return (found == std::string::npos);
        }


        // TODO gérer l'aplication répétée de l'opérateur $ sur des expressions :
        //  Par exemple, est-ce que 2$3$43$2 est correct ?
        //      ou encore (2$3)$(43$2) ? (un complexe peut-il avoir des complexes comme partie réelle et imaginaire) ?
        return false;
    }

    ExpressionLiteral* operator+(ExpressionLiteral &l) const {
        // use of const_cast<ExpressionLiteral*>(this)->toString() in order to use a non const method (toString) in a const method
        string newExpression = "";

        if ( samePriority("+", const_cast<ExpressionLiteral*>(this)->toString()) ) {

        }
        newExpression = "(" + const_cast<ExpressionLiteral*>(this)->toString() + ")+(" + l.toString() + ")";
        return new ExpressionLiteral(newExpression);
    }

    ExpressionLiteral* operator+(ComplexLiteral &l) const {
        string newExpression = "";
        // const_cast<ExpressionLiteral*>(this)->toString() in order to use a non const method (toString) in a const method
        newExpression = "(" + const_cast<ExpressionLiteral*>(this)->toString() + ")+(" + l.toString() + ")";
        return new ExpressionLiteral(newExpression);
    }
};


#endif //TESTLO21CLION_EXPRESSIONLITERAL_H
