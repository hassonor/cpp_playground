//
// Created by Or on 12/11/2023.
//

#include "headers/StackV2.h"
#include <stdexcept>

void StackV2::Link::initialize(void* _data, StackV2::Link* _next) {
    data = _data;
    next = _next;
}

void StackV2::initialize() {
    head = nullptr;
}

void StackV2::push(void* _data) {
    Link* newLink = new Link;
    newLink->initialize(_data, head);
    head = newLink;
}

void* StackV2::peek() {
    if (head == nullptr)
        throw std::runtime_error("Stack is empty");
    return head->data;
}

void* StackV2::pop() {
    if (head == nullptr) return nullptr;
    void* result = head->data;
    Link* oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
}

void StackV2::cleanup() {
    if (head == nullptr) {
        throw std::runtime_error("Stack is not empty");
    }
}

int StackV2::size() const {
    int count = 0;
    Link* current = head;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }

    return count;
}
