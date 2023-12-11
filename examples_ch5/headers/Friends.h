//
// Created by Or on 12/11/2023.
//

#ifndef CPP_PLAYGROUND_FRIENDS_H
#define CPP_PLAYGROUND_FRIENDS_H


struct X;

struct Y {
    void f(X*);
};

struct X {
private:
    int i;
public:
    void initialize();

    friend void g(X*, int); // Global friend
    friend void Y::f(X*); // Struct member friend
    friend struct Z; // Entire struct is a friend
    friend void h();
};

struct Z {
private:
    int j;
public:
    void initialize();

    void g(X* x);
};

void test();


#endif //CPP_PLAYGROUND_FRIENDS_H
