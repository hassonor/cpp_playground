//
// Created by Or on 12/11/2023.
//

// Nested structs via linked list
#ifndef CPP_PLAYGROUND_STACKV2_H
#define CPP_PLAYGROUND_STACKV2_H

class StackV2 {
    struct Link {
        void* data;
        Link* next;

        void initialize(void* _data, Link* _next);
    } * head;

public:
    void initialize();

    void push(void* _data);

    void* peek();

    void* pop();

    void cleanup();

    int size() const;
};

#endif //CPP_PLAYGROUND_STACKV2_H
