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
