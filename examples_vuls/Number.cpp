//
// Created by Or on 1/6/2024.
//

#include "Number.h"
#include <iostream>

void testPrivateHackValue() {
    Number n;
    std::cout << n.getValue() << std::endl;

    int* nP = (int*) &n;
    *nP = 10;

    std::cout << n.getValue() << std::endl;
}
