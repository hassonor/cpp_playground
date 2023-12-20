//
// Created by Or on 12/20/2023.
//

#include "headers/PStash.h"
#include <iostream>
#include <cstring> // 'mem' functions
#include <cassert>

int PStash::add(void* element) {
    const int inflateSize = 10;
    if (next >= quantity)
        inflate(inflateSize);
    storage[next++] = element;
    return (next - 1); // Index number
}

PStash::~PStash() {
    for (int i = 0; i < next; i++) {
        assert(storage[i] == nullptr);
    }
    delete[]storage;
}

// Operator overloading replacement for fetch
void* PStash::operator[](int index) const {
    assert(index >= 0);

    if (index >= next)
        return nullptr; // To indicate the end

    // Produce pointer to desired element:
    return storage[index];
}

void* PStash::remove(int index) {
    void* v = operator[](index);

    // "Remove" the pointer:
    if (v != nullptr) storage[index] = nullptr;
    return v;
}

void PStash::inflate(int increase) {
    const int psz = sizeof(void*);
    void** st = new void* [quantity + increase];
    memset(st, 0, (quantity + increase) * psz);
    memcpy(st, storage, quantity * psz);
    quantity += increase;
    delete[] storage; // Delete old storage
    storage = st; // Point to new memory
}
