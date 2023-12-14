//
// Created by Or on 12/14/2023.
//

#include "headers/ReferenceToPointer.h"
#include <iostream>

void increment(int*& i) { i++; }

void referenceToPointerDemo() {
    int* i = 0;
    std::cout << "i = " << i << std::endl;
    increment(i);
    std::cout << "i = " << i << std::endl;
}
