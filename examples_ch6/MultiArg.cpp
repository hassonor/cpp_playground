//
// Created by Or on 12/13/2023.
//

#include "headers/MultiArg.h"
#include <iostream>


Z::Z(int ii, int jj) {
    i = ii;
    j = jj;
}

void Z::print() {
    std::cout << " i = " << i << ", j = " << j << std::endl;
}

void testMultiArg() {
    Z zz[] = {Z(1, 2), Z(3, 4), Z(5, 6), Z(7, 8)};
    for (int i = 0; i < sizeof zz / sizeof *zz; i++) {
        zz[i].print();
    }

    double t[3] = {0.1, 0.2};

    for (int i = 0; i < sizeof t / sizeof *t; i++) {
        std::cout << "d = " << t[i] << std::endl;
    }


}
