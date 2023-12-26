//
// Created by Or on 12/25/2023.
//

#ifndef CPP_PLAYGROUND_OSTACK_H
#define CPP_PLAYGROUND_OSTACK_H


class Object {
public:
    virtual ~Object() = 0;
};

// Required definition:
inline Object::~Object() {}

class OStack {
    struct Link {
        Object* data;
        Link* next;

        Link(Object* _data, Link* _next) : data(_data), next(_next) {}
    } * head;

public:
    OStack() : head(nullptr) {};

    ~OStack() {
        while (head) {
            delete pop();
        }
    }

    void push(Object* _data) {
        head = new Link(_data, head);
    }

    Object* peek() const {
        return head ? head->data : nullptr;
    }

    Object* pop() {
        if (head == nullptr) return nullptr;
        Object* result = head->data;
        Link* oldHead = head;
        head = head->next;
        delete oldHead;
        return result;
    }

};


#endif //CPP_PLAYGROUND_OSTACK_H
