//
// Created by Or on 12/12/2023.
//

#include "headers/StackOfInt.h"
#include <vector>
#include <iostream>


class StackOfInt::StackImp {
public:
    std::vector<int> v_intStack;
};

StackOfInt::StackOfInt() {
    pImpl = new StackImp;
}

StackOfInt::StackOfInt(int size) {
    pImpl = new StackImp;
}

StackOfInt::StackOfInt(const StackOfInt& stackOfInt) {
    pImpl = new StackImp;
    pImpl->v_intStack = stackOfInt.pImpl->v_intStack;
}

StackOfInt& StackOfInt::operator=(const StackOfInt& stackOfInt) {
    if (this != &stackOfInt) {
        delete pImpl;

        pImpl = new StackImp;
        pImpl->v_intStack = stackOfInt.pImpl->v_intStack;
    }
    return *this;
}

void StackOfInt::push(int value) {
    pImpl->v_intStack.push_back(value);
}

int StackOfInt::pop() {
    if (isEmpty())
        return -1;
    int val = pImpl->v_intStack.back();
    pImpl->v_intStack.pop_back();
    return val;
}

int StackOfInt::top() const {
    return pImpl->v_intStack.front();
}

bool StackOfInt::isEmpty() const {
    return pImpl->v_intStack.empty();
}

bool StackOfInt::isFull() const {
    return false; // Vector cannot be full.
}

int StackOfInt::elementAt(int k) const {
    // Check if k is within the bounds of the vector
    if (k >= 0 && k < pImpl->v_intStack.size()) {
        return pImpl->v_intStack[k]; // Safe to access
    } else {
        std::cerr << "Index out of bounds.\n";
        return -1;
    }
}

int StackOfInt::getSize() const {
    return -1;
}

int StackOfInt::numberOfElements() const {
    return pImpl->v_intStack.size();
}

StackOfInt::~StackOfInt() {
    delete pImpl;
}



