//
// Created by Or on 12/11/2023.
//

#ifndef CPP_PLAYGROUND_CLASSVSSTRUCT_H
#define CPP_PLAYGROUND_CLASSVSSTRUCT_H


struct A {
private:
    int i, j, k;
public:
    int f() const;

    void g();
};

// Identical results are produced with:
class B {
    int i, j, k;
public:
    int f() const;

    void g();
};

void testClassVsStruct();


#endif //CPP_PLAYGROUND_CLASSVSSTRUCT_H
