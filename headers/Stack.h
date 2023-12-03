#ifndef DEFENSIVE_PROGRAMMING_V2_STACK_H
#define DEFENSIVE_PROGRAMMING_V2_STACK_H

#include <iostream>

class Stack {
private:
    int *_data;
    int _size;
    int _maxsize;

    void resizeIfNeeded();

public:
    Stack();

    Stack(const Stack &other); // Copy constructor
    Stack &operator=(const Stack &other); // Copy assignment
    virtual ~Stack(); // Virtual destructor

    void Push(int val);

    int Pop();

    bool isEmpty() const;

    void show() const;

    virtual void print() const;
};

class SecureStack : public Stack {
private:
    int _secretkey;

public:
    SecureStack();

    void print() const override;

    void show() const;

};

#endif //DEFENSIVE_PROGRAMMING_V2_STACK_H
