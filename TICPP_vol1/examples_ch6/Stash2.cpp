//
// Created by Or on 12/13/2023.
//

#include "headers/Stash2.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

const int INCREMENT = 100;


Stash2::Stash2(int _size) {
    size = _size;
    quantity = 0;
    storage = nullptr;
    next = 0;
}

int Stash2::add(void* element) {
    if (next >= quantity) // Enough space left?
        inflate(INCREMENT); // Double the storage size
    // Copy element into storage,
    // starting at next empty space:
    int startBytes = next * size;
    auto* e = (unsigned char*) element;
    for (int i = 0; i < size; i++)
        storage[startBytes + i] = e[i];
    next++;
    return (next - 1); // Index number
}

void* Stash2::fetch(int index) {
    // Check index boundaries:
    assert(0 <= index);

    if (index >= next)
        return nullptr; // To indicate the end;

    // Produce pointer to desired element:
    return &(storage[index * size]);
}

int Stash2::count() const {
    return next; // Number of elements in CStash
}

void Stash2::inflate(int increase) {
    assert(0 < increase);

    int newQuantity = quantity + increase;
    int newBytes = newQuantity * size;
    int oldBytes = quantity * size;

    auto* b = new unsigned char[newBytes];

    for (int i = 0; i < oldBytes; i++) {
        b[i] = storage[i]; // Copy old to new
    }
    delete[] (storage); // Old Storage;
    storage = b;
    quantity = newQuantity;
}

Stash2::~Stash2() {
    if (storage != nullptr) {
        cout << "freeing storage" << endl;
        delete[] storage;
    }
}

void testStash3() {
    Stash2 intStash(sizeof(int));
    for (int i = 0; i < 100; i++)
        intStash.add(&i);
    for (int j = 0; j < intStash.count(); j++) {
        cout << "intStash.fetch(" << j << ") = " << *(int*) intStash.fetch(j) << endl;
    }

    const int bufferSize = 80;
    Stash2 stringStash(sizeof(char) * bufferSize);
    ifstream in("../examples_ch6/Stash2.cpp");
    assert(in);

    string line;
    while (getline(in, line))
        stringStash.add((char*) line.c_str());
    int k = 0;
    char* cp;
    while ((cp = (char*) stringStash.fetch(k++)) != nullptr) {
        cout << "stringStash.fetch(" << k << ") = " << cp << endl;
    }

}





