//
// Created by Or on 12/11/2023.
//

#include "headers/Stack.h"
#include <stdexcept>


void Stack::Link::initialize(void* _data, Stack::Link* _next) {
    data = _data;
    next = _next;
}

void Stack::initialize() {
    head = nullptr;
}

void Stack::push(void* _data) {
    Link* newLink = new Link;
    newLink->initialize(_data, head);
    head = newLink;
}

void* Stack::peek() {
    if (head == nullptr) {
        throw std::runtime_error("Stack empty");
    }
    return head->data;
}

void* Stack::pop() {
    if (head == nullptr) return nullptr;
    void* result = head->data;
    Link* oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
}

void Stack::cleanup() {
    if (head == nullptr) {
        throw std::runtime_error("Stack not empty");
    }
}

int Stack::size() const {
    int count = 0;
    Link* current = head;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}