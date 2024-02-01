//
// Created by Or on 12/20/2023.
//

#ifndef CPP_PLAYGROUND_PSTASH_H
#define CPP_PLAYGROUND_PSTASH_H


class PStash {
    int quantity; // Number of storage spaces
    int next; // Next empty space
    // Pointer storage:
    void** storage;

    void inflate(int increase);

public:
    PStash() : quantity(0), storage(nullptr), next(0) {}

    ~PStash();

    int add(void* element);

    void* operator[](int index) const; // Fetch

    // Remove the reference from this PStash:
    void* remove(int index);

    // Number of elements in Stash:
    int cout() const { return next; };
};


#endif //CPP_PLAYGROUND_PSTASH_H
