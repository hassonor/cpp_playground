//
// Created by Or on 12/12/2023.
//

#include "headers/StackOfInt.h"
#include <vector>

using namespace std;

class StackOfInt::StackImp {
public:
    vector<int> v_intStack;
};

StackOfInt::StackOfInt() {
    pImpl = new StackImp;
}

StackOfInt::StackOfInt(int size) {
    pImpl = new StackImp;
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



