//
// Created by Or on 12/13/2023.
//

#ifndef CPP_PLAYGROUND_STACK3_H
#define CPP_PLAYGROUND_STACK3_H


class Stack3 {
    struct Link {
        void* data;
        Link* next;

        Link(void* _data, Link* _next);

        ~Link();

    };

    Link* head;

public:
    Stack3();

    ~Stack3();

    void push(void* _data);

    void* peek();

    void* pop();
};

void testStack3();


#endif //CPP_PLAYGROUND_STACK3_H
