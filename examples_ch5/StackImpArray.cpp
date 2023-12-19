////
//// Created by Or on 12/12/2023.
////
//
//#include <cassert>
//#include <algorithm>
//#include <iostream>
//#include "headers/StackOfInt.h"
//
//const int SIZE_OF_ARRAY = 100;
//
//class StackOfInt::StackImp {
//public:
//    int* arr;
//    int size;
//    int topIndex;
//
//    void init(int arraySize) {
//        arr = new int[arraySize];
//        size = arraySize;
//        topIndex = 0;
//    }
//};
//
//StackOfInt::StackOfInt() {
//    pImpl = new StackImp;
//    pImpl->init(SIZE_OF_ARRAY);
//}
//
//StackOfInt::StackOfInt(int arraySize) {
//    pImpl = new StackImp;
//    pImpl->init(arraySize);
//}
//
//StackOfInt::StackOfInt(const StackOfInt& stackOfInt) {
//    pImpl = new StackImp;
//    pImpl->init(stackOfInt.pImpl->size);
//    for (int i = 0; i < pImpl->size; i++)
//        pImpl->arr[i] = stackOfInt.elementAt(i);
//
//    pImpl->topIndex = stackOfInt.numberOfElements();
//}
//
//StackOfInt& StackOfInt::operator=(const StackOfInt& stackOfInt) {
//    if (this != &stackOfInt) {
//        delete[] pImpl->arr;
//        pImpl->init(stackOfInt.getSize());
//        for (int i = 0; i < stackOfInt.getSize(); i++) {
//            push(stackOfInt.elementAt(i));
//        }
//    }
//    return *this;
//}
//
//
//void StackOfInt::push(int value) {
//    if (!isFull())
//        pImpl->arr[pImpl->topIndex++] = value;
//    else {
//        int* newArray = new int[pImpl->size + SIZE_OF_ARRAY];
//        for (int i = 0; i < pImpl->size; i++) {
//            newArray[i] = pImpl->arr[i];
//        }
//
//        newArray[pImpl->topIndex++] = value;
//        pImpl->size = pImpl->size + SIZE_OF_ARRAY;
//        delete pImpl->arr;
//        pImpl->arr = newArray;
//
//    }
//
//
//}
//
//int StackOfInt::pop() {
//    if (isEmpty())
//        return -1;
//    return pImpl->arr[--pImpl->topIndex];
//}
//
//int StackOfInt::top() const {
//    if (isEmpty())
//        return -1;
//    return pImpl->arr[(pImpl->topIndex)];
//}
//
//bool StackOfInt::isEmpty() const {
//    return pImpl->topIndex == 0;
//}
//
//bool StackOfInt::isFull() const {
//    return pImpl->topIndex == pImpl->size;
//}
//
//void StackOfInt::inflate(int increase) {
//    assert(increase > 0);
//
//    int currentSize = pImpl->size;
//    int newMaxSize = pImpl->size + increase;
//    int* newData = new int[newMaxSize];
//
//    std::copy(pImpl->arr, pImpl->arr + currentSize, newData);
//
//    delete[] pImpl->arr;
//    pImpl->arr = newData;
//    pImpl->size = newMaxSize;
//}
//
//int StackOfInt::elementAt(int k) const {
//    // Check if k is within the bounds of the vector
//    if (k >= 0 && k < pImpl->size) {
//        return pImpl->arr[k]; // Safe to access
//    } else {
//        std::cerr << "Index out of bounds.\n";
//        return -1;
//    }
//}
//
//int StackOfInt::getSize() const {
//    return pImpl->size;
//}
//
//int StackOfInt::numberOfElements() const {
//    return pImpl->topIndex;
//}
//
//StackOfInt::~StackOfInt() {
//    delete[] pImpl->arr;
//}
//
//
//
