//
// Created by Or on 12/14/2023.
//

#include "headers/Reference.h"

int* f(int* x) {
    (*x)++;
    return x; // Safe, x is outside this scope
}

int& g(int& x) {
    x++; // Same effect as in f()
    return x; // Safe, outside this scope
}
//
//int& h() {
//    int q;
//    //! return q; // Error
//    static int x;
//    return x; // Safe, x lives outside this scope
//}


void referenceDemo() {
    int a = 0;
    f(&a); // Ugly (but explicit)
    g(a); // Clean (but hidden)
}
