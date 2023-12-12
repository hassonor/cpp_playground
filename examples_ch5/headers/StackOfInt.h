#ifndef CPP_PLAYGROUND_STACKOFINT_H
#define CPP_PLAYGROUND_STACKOFINT_H


class StackOfInt {
    class StackImp;

    StackImp* pImpl{};

public:
    StackOfInt();

    StackOfInt(int size);

    void push(int value);

    void inflate(int);

    int pop();

    int top() const;

    bool isEmpty() const;

    bool isFull() const;

};

#endif // CPP_PLAYGROUND_STACKOFINT_H
