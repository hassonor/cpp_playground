//
// Created by Or on 12/11/2023.
//

#include "headers/ClassVsStruct.h"


int A::f() const {
    return i + j + k;
}

void A::g() {
    i = j = k = 0;
}

int B::f() const {
    return i + j + k;
}

void B::g() {
    i = j = k = 0;
}

void testClassVsStruct() {
    A a;
    B b;
    a.f();
    a.g();
    b.f();
    b.g();
}

