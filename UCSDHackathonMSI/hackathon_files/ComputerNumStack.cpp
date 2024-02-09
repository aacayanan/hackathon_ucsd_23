#include <iostream>
#include <string>
#include "ComputerNumStack.h"
using namespace std;

ComputerNumStack::~ComputerNumStack() {
    StackNode *nodePtr = nullptr, *nextNode = nullptr;

    nodePtr = top;

    while (nodePtr != nullptr) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void ComputerNumStack::push(string id) {
    StackNode *newNode = nullptr;

    newNode = new StackNode;
    newNode->value = id;

    if (isEmpty()) {
        top = newNode;
        newNode->next = nullptr;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

void ComputerNumStack::pop(string &id) {
    StackNode *temp = nullptr;

    if (isEmpty()) {
        cout << "The stack is empty." << endl;
    } else {
        id = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

bool ComputerNumStack::isEmpty() {
    bool status;

    if (!top) {
        status = true;
    } else {
        status = false;
    }
    return status;
}

void ComputerNumStack::displayStack() const {
    StackNode *nodePtr;      // To move through the stack

    // Position nodePtr at the top of the stack
    nodePtr = top;

    cout << "Here is your stack: " << endl;

    // While nodePtr points to a node, traverse the stack
    while (nodePtr) {
        // Display string
        cout << nodePtr->value << endl;

        // Move to the next node
        nodePtr = nodePtr->next;
    }
}

