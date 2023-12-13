//
// Created by Or on 12/13/2023.
//

#include "headers/Stack3.h"
#include <iostream>
#include <cassert>

using namespace std;

Stack3::Link::Link(void* _data, Link* _next) {
    data = _data;
    next = _next;
}

Stack3::Link::~Link() {};

Stack3::Stack3() { head = nullptr; }

void Stack3::push(void* _data) {
    head = new Link(_data, head);
}

void* Stack3::peek() {
    assert(head != nullptr);
    return head->data;
}

void* Stack3::pop() {
    if (head == nullptr) return nullptr;
    void* result = head->data;
    Link* oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
}

Stack3::~Stack3() {
    while (head != nullptr) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }
}

void testStack3() {
    Stack3 stack;

    // Array of strings
    std::string stringArray[] = {"Hello", "World", "C++", "Programming", "Stack"};

    // Dynamically allocate memory for strings and push their pointers onto the stack
    for (const std::string &str: stringArray) {
        auto* strPtr = new std::string(str);
        stack.push(static_cast<void*>(strPtr));
    }

    // Pop strings off the stack and print each one
    void* element;
    while ((element = stack.pop()) != nullptr) {
        auto* strPtr = static_cast<std::string*>(element);
        std::cout << *strPtr << std::endl;
        delete strPtr;
    }
}


