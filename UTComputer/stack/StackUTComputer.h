#ifndef TESTLO21CLION_STACKUTCOMPUTER_H
#define TESTLO21CLION_STACKUTCOMPUTER_H

#include <iostream>
#include <deque>
#include <memory>
#include <vector>

#include "../exceptions/UTComputerException.h"
#include "../literals/Literal.h"
using namespace std;


class Operator; // we need Operator class but we can't include the header file because Operator also need StackUTComputer for its function execute()
class StackUTComputerMemento;


class StackUTComputer {
    friend class StackUTComputerMemento;

    deque<shared_ptr<Literal>> st;
    deque<shared_ptr<Literal>> lastArguments;
    Operator *lastOperator;

    // memento
    deque<StackUTComputerMemento *> mementoStack;
    int mementoCurrentSize;
    int mementoPosition;
    static int maxMementoSize;





public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================

    StackUTComputer() : lastOperator(nullptr), mementoCurrentSize(0), mementoPosition(0)  { }
    virtual ~StackUTComputer();
    // ===============================================================================================================







    // ===============================================================================================================
    // ======================                   Getters and Setters                         ==========================
    // ===============================================================================================================

    void setLastOperator(Operator *lastOp) {
        lastOperator = lastOp;
    }

    Operator *getLastOperator() const {
        return lastOperator;
    }


    const deque<shared_ptr<Literal>> &getLastArguments() const {
        return lastArguments;
    }

    void setLastArguments(int operatorArity) {
        if (st.size() < operatorArity)
            throw UTComputerException("Error in StackUTComputer::setLastArguments : arity superior to stack size");


        lastArguments.clear(); // clear old arguments
        /*
         * Put arguments in a reverse order :
         *  if stack contains a then b, lastArguments will contains b than a
         *  This way, when we want to get lastArguments back in stack, we just have to
         *  unstack x from lastArguments and stack it directly in stack "st".
         */
        for (int i=0; i<operatorArity; i++) {
            lastArguments.push_front(st[i]); // save last arguments
        }
    }


    static void setMaxMementoSize(int nb) {
        StackUTComputer::maxMementoSize = nb;
    }

    // ===============================================================================================================









    // ===============================================================================================================
    // ======================        Implement Stack Interface and Stack Operators          ==========================
    // ===============================================================================================================


    int size() {
        return (int)st.size(); // cast from "unsigned long int" in "int"
    }

    shared_ptr<Literal> top() {
        return st[0];
    }

    void pop() {
        st.pop_front(); // remove top element from the container
    }

    void clear() {
        st.clear(); // remove all elements from the container
    }

    void clearMemento();

    void push(shared_ptr<Literal> l) {
        st.push_front(l); // add element on top of the container
    }

    void pushLastArgs() {
        for (int i=0; i<lastArguments.size(); i++)
            st.push_front(lastArguments[i]);
    }

    // ===============================================================================================================







    // ===============================================================================================================
    // ======================                            Class services                     ==========================
    // ===============================================================================================================
    /**
     * Function that fill the Literal* table arguments with the right ones and in
     * the right order : first argument is the last one to be unstacked
     */
    void getArguments(int arity, vector<shared_ptr<Literal>> &arguments);

    /**
     * Function that delete the right number of elements from the container by calling
     * its function pop(). This function will take care of deleting the dynamically created objects
     * and remove the pointer element from the container.
     */
    void deleteArguments(int arity);
    // ===============================================================================================================






    // ===============================================================================================================
    // ======================                         Implement Memento                     ==========================
    // ===============================================================================================================

    void createMemento();

    void reinstateMemento(StackUTComputerMemento * memento);

    void undo();

    void redo();
    // ===============================================================================================================


};









// ===============================================================================================================
// ===================     Class StackUTComputerMemento used in Memento Pattern         ==========================
// ===============================================================================================================


class StackUTComputerMemento {
    friend class StackUTComputer;

    deque<shared_ptr<Literal>> st_memento;
    deque<shared_ptr<Literal>> lastArguments_memento;
    Operator *lastOperator_memento;


public:

    StackUTComputerMemento(StackUTComputer * myStack) {

        for (auto it = myStack->st.rbegin(); it!=myStack->st.rend(); ++it) {
            st_memento.push_front(*it);
        }

        for (auto it = myStack->lastArguments.rbegin(); it!=myStack->lastArguments.rend(); ++it)
            lastArguments_memento.push_front(*it);

        lastOperator_memento =  myStack->lastOperator;
    }


    virtual ~StackUTComputerMemento() { }
};


#endif //TESTLO21CLION_STACKUTCOMPUTER_H
