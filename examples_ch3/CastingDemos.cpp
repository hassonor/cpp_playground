//
// Created by Or on 12/7/2023.
//

#include "headers/CastingDemos.h"
#include <iostream>

void staticCastDemo() {
    int i = 0x7fff; // max positive value
    long l;
    float f;

    // (1) Typical castless conversions:
    l = i;
    f = i;

    // Also works:
    l = static_cast<long>(i);
    f = static_cast<float>(i);

    // (2) Narrowing conversions:
    i = l; // May lost digits
    i = f; // May lost info

    // (3) Forcing a conversion from void* :
    void *vp = &i;
    // Old way produces a dangerous conversion:
    float *fp = (float *) vp;
    // The new way is equally dangerous:
    fp = static_cast<float *>(vp);

    // (4) Implicit type conversions, normally performed by the compiler:
    double d = 0.0;
    int x = d; // Automatic type conversion
    x = static_cast<int>(d); // More explicit
    // someFunc(int);
    // someFunc(d) // Automatic type conversion
    // someFunc(static_cast<int>(d)) // More explicit
}

void constCastDemo() {
    const int i = 0;
    int *j = const_cast<int *>(&i);
    *j = 8;
    volatile int k = 0;
    int *u = const_cast<int *>(&k);
}

const int sz = 100;
struct X {
    int a[sz];
};

void print(X *x) {
    for (int i = 0; i < sz; i++)
        std::cout << x->a[i] << ' ';
    std::cout << std::endl << "------------------" << std::endl;
}

void reinterpretCastDemo() {
    X x{};
    print(&x);
    int *xp = reinterpret_cast<int *>(&x);
    for (int *i = xp; i < xp + sz; i++) {
        *i = 1;
    }
    // Can't use xp as an X* at this point
    // unless you cast it back:
    print(reinterpret_cast<X *>(xp));
    // In this example, you can also just use
    // the original identifier:
    print(&x);
}


