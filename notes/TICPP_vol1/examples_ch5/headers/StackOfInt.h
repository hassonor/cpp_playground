#ifndef CPP_PLAYGROUND_STACKOFINT_H
#define CPP_PLAYGROUND_STACKOFINT_H


class StackOfInt {
    class StackImp;

    StackImp* pImpl{};

public:
    StackOfInt();

    StackOfInt(int size);

    StackOfInt(const StackOfInt& stackOfInt);

    StackOfInt& operator=(const StackOfInt& stackOfInt);


    void push(int value);

    void inflate(int);

    int pop();

    int top() const;

    bool isEmpty() const;

    bool isFull() const;

    int elementAt(int k) const;

    int getSize() const;

    int numberOfElements() const;

    virtual ~StackOfInt();

};

#endif // CPP_PLAYGROUND_STACKOFINT_H
