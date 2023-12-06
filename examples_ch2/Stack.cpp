
#include <algorithm>
#include <stdexcept>
#include "headers/Stack.h"

Stack::Stack() : _data(nullptr), _size(0), _maxsize(10) {
    _data = new int[_maxsize];
}

Stack::Stack(const Stack &other) : _data(nullptr), _size(other._size), _maxsize(other._maxsize) {
    _data = new int[_maxsize];
    std::copy(other._data, other._data + _size, _data);
}

Stack &Stack::operator=(const Stack &other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _maxsize = other._maxsize;
        _data = new int[_maxsize];
        std::copy(other._data, other._data + _size, _data);
    }
    return *this;
}

Stack::~Stack() {
    delete[] _data;
}

void Stack::Push(int val) {
    resizeIfNeeded();
    _data[_size++] = val;
}

int Stack::Pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return _data[--_size];
}

bool Stack::isEmpty() const {
    return _size == 0;
}

void Stack::print() const {
    std::cout << "print Stack\n";
}

void Stack::resizeIfNeeded() {
    if (_size >= _maxsize) {
        int newMaxSize = _maxsize + 20;
        int *newData = new int[newMaxSize];
        std::copy(_data, _data + _size, newData);
        delete[] _data;
        _data = newData;
        _maxsize = newMaxSize;
    }
}


void Stack::show() const {
    std::cout << "show Stack\n";
}

SecureStack::SecureStack() : Stack(), _secretkey(0x55) {}

void SecureStack::print() const {
    std::cout << "print SecureStack\n";
}

void SecureStack::show() const {
    std::cout << "show SecureStack\n";
}

