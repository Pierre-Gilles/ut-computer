#include "StackUTComputer.h"



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

    lastArguments.clear(); // drop previous last arguments
    for (int it=0; it<arity; it++) {
        if (!st[arity-1-it]) { // means that st[arity-1-i] is null
            arguments.clear(); // in case we have insert items before having the exception
            throw UTComputerException("Error StackUTComputer::getArguments : at least one argument is null.");
        }

        arguments.insert(arguments.begin()+it, st[arity-1-it]);
        //cerr << "insertion in arguments[" << it << "]" << " : st[" << arity-1-it << "] = " << st[arity-1-it]->toString() << endl;
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
