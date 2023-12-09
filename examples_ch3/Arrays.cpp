//
// Created by Or on 12/9/2023.
//

#include "headers/Arrays.h"
#include <iostream>

void structArrayDemo() {
    typedef struct {
        int i, j, k;
    } ThreeDPoint;

    ThreeDPoint points[10];
    for (int i = 0; i < 10; ++i) {
        points[i].i = i;
        points[i].j = i * i;
        points[i].k = i * i * i;
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << "points[" << i << "].i = " << points[i].i << std::endl;
        std::cout << "points[" << i << "].j = " << points[i].j << std::endl;
        std::cout << "points[" << i << "].k = " << points[i].k << std::endl;
    }
}

void arrayAddressesDemo() {
    int a[10];
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << "&a[" << i << "] = " << &a[i] << std::endl;
    }
}

void arrayIdentifierDemo() {
    int a[10];
    std::cout << "a = " << a << std::endl;
    std::cout << "&a[0] = " << &a[0] << std::endl;
}

void pointersAndBracketsDemo() {
    int a[10];
    int *ip = a;
    for (int i = 0; i < 10; i++) {
        ip[i] = i * 10;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }
}

