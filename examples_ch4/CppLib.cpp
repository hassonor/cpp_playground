//
// Created by Or on 12/10/2023.
//

#include "headers/CppLib.h"
#include "headers/CLib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <fstream>

using namespace std;

// Quantity of elements to add when increasing storage:
const int increment = 100;

void Stash::initialize(int _size) {
    this->size = _size;
    this->quantity = 0;
    this->storage = nullptr;
    this->next = 0;
}

int Stash::add(const void *element) {
    if (next >= quantity) // Enough space left?
        inflate(increment);

    // Copy element into storage,
    // starting at next empty space:
    int startBytes = next * size;
    auto *e = (unsigned char *) element;

    for (int i = 0; i < size; i++) {
        storage[startBytes + i] = e[i];
    }

    next++;
    return (next - 1); // Index number
}

void *Stash::fetch(int index) {
    // Check index boundaries:
    assert(0 <= index);

    if (index >= next)
        return nullptr; // To indicate the end

    // Produce pointer to desired element:
    return &(storage[index * size]);
}

int Stash::count() {
    return next; // Elements in Stash
}

void Stash::inflate(int increase) {
    assert(increase > 0);

    int newQuantity = quantity + increase;
    int newBytes = newQuantity * size;
    int oldBytes = quantity * size;

    auto *b = new unsigned char[newBytes];

    for (int i = 0; i < oldBytes; i++) {
        b[i] = storage[i]; // Copy old to new
    }

    delete[] storage; // Old storage
    storage = b;
    quantity = newQuantity;
}

void Stash::cleanup() {
    if (storage != nullptr) {
        cout << "freeing storage" << endl;
        delete[] storage;
    }
}

void testCppLib() {
    Stash intStash{};
    intStash.initialize(sizeof(int));

    for (int i = 0; i < 100; i++) {
        intStash.add(&i);
    }

    for (int j = 0; j < intStash.count(); j++) {
        cout << "intStash.fetch (" << j << ") = " << *(int *) intStash.fetch(j) << endl;
    }

    // Holds 80-characters strings:
    Stash stringStash{};
    const int bufferSize = 80;

    stringStash.initialize(sizeof(char) * bufferSize);

    ifstream in("../examples_ch4/CppLib.cpp");
    assert(in);

    string line;
    while (getline(in, line))
        stringStash.add(line.c_str());

    int k = 0;
    char *cp;
    while ((cp = (char *) stringStash.fetch(k++)) != nullptr)
        cout << "stringStash.fetch(" << k << " ) = " << cp << endl;

    intStash.cleanup();
    stringStash.cleanup();
}

void testStructSizes() {
    struct A {
        int i[100];
    };
    struct B {
        void f();
    };

    cout << "sizeof struct A = " << sizeof(A) << " bytes" << endl; // 400 bytes
    cout << "sizeof struct B = " << sizeof(B) << " bytes" << endl; // 1 byte
    cout << "sizeof CStash in C = " << sizeof(CStash) << " bytes" << endl; // 24 bytes
    cout << "sizeof Stash in C++ = " << sizeof(Stash) << " bytes" << endl; // 24 bytes

}




