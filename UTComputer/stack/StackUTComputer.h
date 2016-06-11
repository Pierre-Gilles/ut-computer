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


/**
 * \class StackUTComputer
 * \brief Special stack for the application
 */
class StackUTComputer {
    friend class StackUTComputerMemento; /*!< Class used to manage memento */
    deque<shared_ptr<Literal>> st; /*!< The container used to store Literal */
    deque<shared_ptr<Literal>> lastArguments; /*!< The container used to store the previous elements */
    Operator *lastOperator; /*!< Used to store the adress of the previous operator */

    // memento
    deque<StackUTComputerMemento *> mementoStack; /*!< deque of StackUTComputerMemento* used to store memento instances */
    StackUTComputerMemento *temporaryMemento;
    int mementoCurrentSize;
    int mementoPosition;
    static int maxMementoSize; /*!< parameter to fix a size of possible mementos being accessible at the same time */





public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================

    /**
     * \fn StackUTComputer()
     * \brief Constructor with no arguments
     *
     * Constructor that set the attributes :
     *      - \a lastOperator is set to nullptr
     *      - \a mementoCurrentSize is set to 0
     *      - \a mementoPosition is set to 0
     */
    StackUTComputer() : lastOperator(nullptr), mementoCurrentSize(0), mementoPosition(0), temporaryMemento(nullptr)  { }

    /**
     * \fn virtual ~StackUTComputer()
     * \brief Destructor
     *
     * Destructor that makes sure everything is properly destroyed
     *      - clear \a st and \a lastArguments that contains shared_ptr so no need for delete
     *      - call StackUTComputer::clearMemento(), method that will delete all memento pointers stored in \a mementoStack
     */
    virtual ~StackUTComputer();
    // ===============================================================================================================







    // ===============================================================================================================
    // ======================                   Getters and Setters                         ==========================
    // ===============================================================================================================


    /**
     * \fn const deque<shared_ptr<Literal>> &getSt() const
     * \brief Getter for \a st attribute
     * \return The private attribute \a st
     */
    const deque<shared_ptr<Literal>> &getSt() const;

    /**
     * \fn Operator *getLastOperator() const
     * \brief Getter for \a lastOperator
     * \return The private attribute \a lastOperator
     */
    Operator *getLastOperator() const;

    /**
     * \fn const deque<shared_ptr<Literal>> &getLastArguments() const
     * \brief Getter for \a lastArguments
     * \return The private attribute \a lastArguments
     */
    const deque<shared_ptr<Literal>> &getLastArguments() const;

    /**
     * \fn void setLastOperator(Operator *lastOp)
     * \brief Setter for \a lastOperator
     * \param laspOp : the pointer to Operator used to set the private attribute \a lastOperator
     */
    void setLastOperator(Operator *lastOp);

    /**
     * \fn void void setLastArguments(int operatorArity);
     * \brief Setter for \a lastArguments
     * \param operatorArity : arity of the Operator being used in order to store the right number of Literal
     * in \a lastArguments
     */
    void setLastArguments(int operatorArity);

    /**
     * \fn static void setMaxMementoSize(int nb)
     * \brief Setter for the static attribute maxMementoSize
     * \param[] nb : the number used to set the static attribute maxMementoSize
     */
    static void setMaxMementoSize(int nb);

    /**
     * \fn vector<string> getLastElementsString(int nb) const
     * \brief Function used to get the \a nb last inserted Literal in stack
     * \param[in] nb : the number of Literal we want to extract from the stack
     * \return A vector of string containing the toString() result of the \a nb last inserted Literal in stack
     */
    vector<string> getLastElementsString(int nb) const;
    // ===============================================================================================================









    // ===============================================================================================================
    // ======================        Implement Stack Interface and Stack Operators          ==========================
    // ===============================================================================================================


    /**
     * \fn int size() const
     * \return The size of the private attribute \a st
     */
    unsigned long int size() const;


    /**
     * \fn shared_ptr<Literal> top() const
     * \return the first element of the private attribute \a st
     */
    shared_ptr<Literal> top() const;


    /**
     * \fn void pop()
     * \brief Remove the first argument of the private attribute \a st
     */
    void pop();


    /**
     * \fn void clear()
     * \brief Remove all element from the private attribute \a st
     */
    void clear();


    /**
     * \fn void clearMemento()
     * \brief Remove all elements from the private attribute \a mementoStack
     */
    void clearMemento();


    /**
     * \fn void push(shared_ptr<Literal> l)
     * \brief Method that add an element to the private attribute \a st
     * \param[in] l : the shared_ptr<Literal> to push on top of the private attribute \a st
     */
    void push(shared_ptr<Literal> l);


    /**
     * \fn void pushLastArgs()
     * \brief Method that push the Literal contained in \a mementoStack back into \a st
     */
    void pushLastArgs();


    // ===============================================================================================================







    // ===============================================================================================================
    // ======================                            Class services                     ==========================
    // ===============================================================================================================

    /**
     * \fn void getArguments(int arity, vector<shared_ptr<Literal>> &arguments)
     * \brief Method used to set a vector of <shared_ptr<Literal>> with the right number of arguments depending on the
     * operator being used and set this vector in the right order (first argument is the last one to be unstacked)
     * \param[in] arity : arity of the operator being used
     * \param[inout] arguments : vector of <shared_ptr<Literal>> in which are stored the \a arity first elements of the stack
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

    /**
     * \fn void undo()
     * \brief Method that set the stack to its previous state if possible
     */
    void undo();



    /**
     * \fn void redo()
     * \brief Method that get back the stack to its "future" state if possible
     */
    void redo();

    /**
     * \fn void createMemento()
     * \brief Method that create a memento of the StackUTComputer
     */
    void createMemento();

    /**
     * \fn void createTemporaryMemento()
     * \brief Method that create a temporarry memento of the StackUTComputer
     */
    void createTemporaryMemento();

    /**
     * \fn void reinstateTemporaryMemento()
     * \brief Method that get the stack back to the temporary memento
     */
    void reinstateTemporaryMemento();

private:
    /**
     * \fn void reinstateMemento(StackUTComputerMemento * memento)
     * \brief Method that get the StackUTComputer instance back to the state of the \a memento parameter
     * \param[] memento : StackUTComputerMemento containing the state of the StackUTComputer we want to go back to
     */
    void reinstateMemento(StackUTComputerMemento * memento);

    // ===============================================================================================================

};









// ===============================================================================================================
// ===================     Class StackUTComputerMemento used in Memento Pattern         ==========================
// ===============================================================================================================

/**
 * \class StackUTComputerMemento
 * \brief Class used to implement the Memento design pattern
 */
class StackUTComputerMemento {
    friend class StackUTComputer;

    deque<shared_ptr<Literal>> st_memento; /*!< Used to duplicate the StackUTComputer::st attribute */
    deque<shared_ptr<Literal>> lastArguments_memento; /*!< Used to duplicate the StackUTComputer::lastArguments attribute */
    Operator *lastOperator_memento; /*!< Used to duplicate the StackUTComputer::lastOperator attribute */


public:

    /**
     * \fn StackUTComputerMemento(StackUTComputer * myStack)
     * \brief Constructor
     * \param[in] myStack : pointer to the StackUTComputer instance
     * \return A StackUTComputerMemento instance with all the StackUTComputer instance information we want to save
     */
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
