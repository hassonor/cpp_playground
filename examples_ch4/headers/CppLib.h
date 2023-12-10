//
// Created by Or on 12/10/2023.
//

#ifndef CPP_PLAYGROUND_CPPLIB_H
#define CPP_PLAYGROUND_CPPLIB_H


struct Stash {
    int size; // Size of each space
    int quantity; // Number of storage spaces
    int next; // Next empty space
    // Dynamically allocated array of bytes:
    unsigned char *storage;

    // Functions
    void initialize(int size);

    void cleanup();

    int add(const void *element);

    void *fetch(int index);

    int count();

    void inflate(int icrease);
};

void testCppLib();

void testStructSizes();


#endif //CPP_PLAYGROUND_CPPLIB_H
