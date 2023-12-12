////
//// Created by Or on 12/12/2023.
////
//
//#include <cassert>
//#include <algorithm>
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
//void StackOfInt::push(int value) {
//    if (!isFull())
//        pImpl->arr[pImpl->topIndex++] = value;
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
//}
//
