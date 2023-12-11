//
// Created by Or on 12/11/2023.
//

#include "headers/Friends.h"

void X::initialize() {
    i = 0;
}

void g(X* x, int i) {
    x->i = i;
}

void Y::f(X* x) {
    x->i = 47;
}

void Z::initialize() {
    j = 99;
}

void Z::g(X* x) {
    x->i += j;
}

void h() {
    X x;
    x.i = 100; // Direct data manipulation
}

void test() {
    X x;
    Z z;
    z.g(&x);
}



