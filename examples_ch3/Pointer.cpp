//
// Created by Or on 12/9/2023.
//
#include <iostream>
#include "headers/Pointer.h"

using namespace std;

#define P(EX) cout << #EX << ": " << EX << endl;


void pointerArithmeticDemo() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i; // Give it index values
    }
    int *ip = a; // ip points to array a[0]
    P(*ip);
    P(*++ip); // Increments ip, then dereferences it
    P(*(ip + 5)); // Increments ip by 5 elements, then dereferences it
    int *ip2 = ip + 5;
    P(*ip2);
    P(*(ip2 - 4));
    P(*--ip2);
    P(ip2 - ip); // Yields difference between the addresses
}

void func() {
    cout << "func() called..." << endl;
};

void pointerToFunction() {
    void (*fp)(); // Declare a function pointer
    fp = func;
    (*fp)(); // Call the function

    void (*fp2)() = func; // Declare and initialize
    (*fp2)();
}

void functionTable() {
    void (*func_table[])() = {
            func,
            func,
            func,
            func,
            func,
            func,
            func,
            func,
            func,
            func
    };
    for (int i = 0; i < 10; i++) {
        (*func_table[i])();
    }
}

#define DF(N) void N(){ \
    cout << "function " #N " called..." << endl; }

DF(a);

DF(b);

DF(c);

DF(d);

DF(e);

DF(f);

DF(g);


void functionTable2() {
    void (*func_table[])() = {a, b, c, d, e, f, g};
    while (true) {
        cout << "press a key from 'a' to 'g' or 'q' to quit" << endl;
        char c, cr;
        cin.get(c);
        cin.get(cr); // second one for CR
        if (c == 'q')
            break;  // Out of while(1)
        if (c < 'a' || c > 'g')
            continue;
        (*func_table[c - 'a'])();
    }
}
