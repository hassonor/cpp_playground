//
// Created by Or on 12/10/2023. Created by Or on 12/10/2024. Created by Or on 12/10/2025. Created by Or on 12/10/2026.
//
// Implementation of example C-like library
// Declare structure and functions:

#include "headers/CLib.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

// Quantity of elements to add when increasing storage:
const int increment = 100;

void initialize(CStash *s, int size) {
    s->size = size;
    s->quantity = 0;
    s->storage = nullptr;
    s->next = 0;
}

int add(CStash *s, const void *element) {
    if (s->next >= s->quantity) // Enough space left?
        inflate(s, increment);
    // Copy element into storage,
    // starting at next empty space:
    int startBytes = s->next * s->size;
    auto *e = (unsigned char *) element;
    for (int i = 0; i < s->size; i++) {
        s->storage[startBytes + i] = e[i];
    }
    s->next++;
    return (s->next - 1); // Index number
}

void *fetch(CStash *s, int index) {
    // Check index boundaries:
    assert(0 <= index);

    if (index >= s->next)
        return nullptr; // To indicate the end

    // Produce pointer to desired element:
    return &(s->storage[index * s->size]);
}

int count(CStash *s) {
    return s->next; // Elements in CStash
}

void inflate(CStash *s, int increase) {
    assert(increase > 0);

    int newQuantity = s->quantity + increase;
    int newBytes = newQuantity * s->size;
    int oldBytes = s->quantity * s->size;

    auto *b = new unsigned char[newBytes];

    for (int i = 0; i < oldBytes; i++) {
        b[i] = s->storage[i]; // Copy old to new
    }
    delete[](s->storage); // Old storage
    s->storage = b;
    s->quantity = newQuantity;
}

void cleanup(CStash *s) {
    if (s->storage != nullptr) {
        cout << "freeing storage" << endl;
        delete[] s->storage;
    }
}

void testCLib() {
    // Define variables at the beginning of the block,
    // as in C:
    CStash intStash, stringStash;
    int i;
    char *cp;
    ifstream in;
    string line;
    const int bufferSize = 80;

    // Now remember to initialize the variables:
    initialize(&intStash, sizeof(int));

    for (i = 0; i < 100; i++) {
        add(&intStash, &i);
    }

    for (i = 0; i < count(&intStash); i++) {
        cout << "fetch(&intStash, " << i << " ) = " << *(int *) fetch(&intStash, i) << endl;
    }

    // Holds 80-character strings:
    initialize(&stringStash, sizeof(char) * bufferSize);

    in.open("../examples_ch4/CLib.cpp");
    assert(in);

    while (getline(in, line)) {
        size_t start = 0;
        while (start < line.length()) {
            size_t endLength = line.length() - start;
            size_t length = (endLength > bufferSize) ? bufferSize : endLength;
            std::string part = line.substr(start, length);
            add(&stringStash, part.c_str());
            start += length;
        }
    }
    i = 0;
    while ((cp = (char *) fetch(&stringStash, i++)) != nullptr)
        cout << "fetch(&stringStash, " << i << ") = " << cp << endl;

    cleanup(&intStash);
    cleanup(&stringStash);

}


