#include <iostream>
using namespace std;
#include "Stack.h"

template<typename StackItemType>
Stack<StackItemType>::Stack() {
    topPtr = NULL;
}

template<typename StackItemType>
Stack<StackItemType>::Stack(const Stack<StackItemType>& aStack) {
}

template<typename StackItemType>
Stack<StackItemType>::~Stack() {
    while(!isEmpty()) {
        pop();
    }
}

template<typename StackItemType>
bool Stack<StackItemType>::isEmpty() const {
    return topPtr == NULL;
}

template<typename StackItemType>
bool Stack<StackItemType>::push(StackItemType newItem) {
    StackNode* newNode = new StackNode;
    newNode->item = newItem;

    newNode->next = topPtr;
    topPtr = newNode;
    return true;
}

template<typename StackItemType>
bool Stack<StackItemType>::pop() {
    if(isEmpty())
        return false;

    StackNode* temp = topPtr;
    topPtr = topPtr->next;

    temp->next = NULL;
    delete temp;
    return true;
}

template<typename StackItemType>
bool Stack<StackItemType>::pop(StackItemType& stackTop) {
    if(isEmpty())
        return false;

    stackTop = topPtr->item;
    StackNode* temp = topPtr;
    topPtr = topPtr->next;

    temp->next = NULL;
    delete temp;
    return true;
}

template<typename StackItemType>
bool Stack<StackItemType>::getTop(StackItemType& stackTop) const {
    if(isEmpty())
        return false;
    stackTop = topPtr->item;
    return true;
}


