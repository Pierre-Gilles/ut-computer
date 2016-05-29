#include "StackUTComputer.h"

int StackUTComputer::maxMementoSize = 10;


// ===============================================================================================================
// ======================               Constructors and Destructors                    ==========================
// ===============================================================================================================

StackUTComputer::~StackUTComputer() {
    st.clear(); // remove all elements from the container
    lastArguments.clear();
    clearMemento();
}
// ===============================================================================================================





void StackUTComputer::clearMemento() {
    for (auto it = mementoStack.begin(); it != mementoStack.end(); ++it)
        delete *it;
    mementoStack.clear();
}


// ===============================================================================================================
// ======================                            Class services                     ==========================
// ===============================================================================================================
/**
    * Function that fill the Literal* table arguments with the right ones and in
    * the right order : first argument is the last one to be unstacked
    */
void StackUTComputer::getArguments(int arity, vector<shared_ptr<Literal>> &arguments) {
    if (st.size() < arity)
        throw UTComputerException("Error in StackUTComputer::getArguments : arity superior to stack size");

    for (int it=0; it<arity; it++) {
        if (!st[arity-1-it]) { // means that st[arity-1-i] is null
            arguments.clear(); // in case we have insert items before having the exception
            throw UTComputerException("Error StackUTComputer::getArguments : at least one argument is null.");
        }

        arguments.insert(arguments.begin()+it, st[arity-1-it]);
    }
}

/**
    * Function that delete the right number of elements from the container by calling
    * its function pop(). This function will take care of deleting the dynamically created objects
    * and remove the pointer element from the container.
    */
void StackUTComputer::deleteArguments(int arity) {
    if (st.size() < arity) {
        throw UTComputerException("Error in StackUTComputer::deleteArguments : arity superior to stack size");
    }
    for (int i=0; i<arity; i++) {
        pop();
    }
}
// ===============================================================================================================








// ===============================================================================================================
// ======================                         Implement Memento                     ==========================
// ===============================================================================================================

void StackUTComputer::createMemento() {
    if (mementoCurrentSize == maxMementoSize) {
        delete mementoStack[maxMementoSize-1]; // delete the pointer that will be removed
        mementoStack.pop_back();
        mementoCurrentSize--;
    }
    mementoStack.push_front(new StackUTComputerMemento(this));
    mementoCurrentSize++;
}

void StackUTComputer::reinstateMemento(StackUTComputerMemento * memento) {
    if (memento == nullptr)
        throw UTComputerException("Error StackUTComputer::reinstateMemento : argument memento is null.");

    st.clear();
    lastArguments.clear();

    for (auto it = memento->st_memento.rbegin(); it!=memento->st_memento.rend(); ++it) {
        st.push_front(*it);
    }
    for (auto it = memento->lastArguments_memento.rbegin(); it!=memento->lastArguments_memento.rend(); ++it) {
        lastArguments.push_front(*it);
    }

    lastOperator = memento->lastOperator_memento;
}

void StackUTComputer::undo() {
    // we do nothing if there is nothing in mementoStack
    if (mementoCurrentSize != 0) {

        // we do nothing if there is no previous state to go to
        if (mementoPosition < mementoCurrentSize-1)
            reinstateMemento(mementoStack[++mementoPosition]);
    }
}


void StackUTComputer::redo() {
    // we do nothing if there is nothing in mementoStack
    if (mementoCurrentSize != 0) {

        // we do nothing if there is no future state to go to
        if (mementoPosition != 0) {
            reinstateMemento(mementoStack[--mementoPosition]);
        }
    }
}