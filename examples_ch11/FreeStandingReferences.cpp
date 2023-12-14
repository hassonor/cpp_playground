//
// Created by Or on 12/14/2023.
//

#include "headers/FreeStandingReferences.h"
#include <iostream>

void showFreeStandingReferenceDemo() {
    // Ordinary free-standing reference:
    int y;
    int &r = y;
    // When a reference is created, it must
    // be initialized to a live object.
    // However, you can also say:
    const int &q = 12; // (1)
    // References are tied to someone else's storage:
    int x = 0; // (2)
    int &a = x;

    std::cout << "x = " << x << ", a = " << a << std::endl;
    a++;
    std::cout << "x = " << x << ", a = " << a << std::endl;

}
