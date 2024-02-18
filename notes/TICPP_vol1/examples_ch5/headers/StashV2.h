//
// Created by Or on 12/11/2023.
//

#ifndef CPP_PLAYGROUND_STASHV2_H
#define CPP_PLAYGROUND_STASHV2_H


class StashV2 {
    int size; // Size of each space
    int quantity; // Number of storage spaces
    int next; // Next empty space

    // Dynamically allocated array of bytes:
    unsigned char* storage;

    void inflate(int increase);

public:
    void initialize(int size);

    void cleanup();

    int add(void* element);

    void* fetch(int index);

    int count();
};


#endif //CPP_PLAYGROUND_STASHV2_H
