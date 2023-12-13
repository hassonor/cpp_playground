//
// Created by Or on 12/13/2023.
//

#ifndef CPP_PLAYGROUND_STASH2_H
#define CPP_PLAYGROUND_STASH2_H


class Stash2 {
    int size; // Size of each space
    int quantity; // Number of storage spaces
    int next; // Next empty space

    // Dynamically allocated array of bytes:
    unsigned char* storage;

    void inflate(int increase);

public:
    Stash2(int size);

    ~Stash2();

    int add(void* element);

    void* fetch(int index);

    int count() const;
};

void testStash3();


#endif //CPP_PLAYGROUND_STASH2_H
