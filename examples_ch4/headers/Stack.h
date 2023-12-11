// Created by Or on 12/11/2023.

#ifndef CPP_PLAYGROUND_STACK_H
#define CPP_PLAYGROUND_STACK_H

// Stack structure definition
struct Stack {
    // Nested Link structure within Stack
    struct Link {
        void* data; // Pointer to data, can point to any data type
        Link* next; // Pointer to the next Link in the stack

        // Function to initialize a Link with data and next pointer
        void initialize(void* data, Link* next);
    };

    Link* head;

    // Function to initialize the Stack
    void initialize();

    // Function to add an element to the top of the stack
    void push(void* data);

    // Function to return the element at the top of the stack without removing it
    void* peek();

    // Function to remove and return the top element of the stack
    void* pop();

    // Function to clean up the stack, deallocating any dynamic memory
    void cleanup();

    int size() const;
};

#endif //CPP_PLAYGROUND_STACK_H
