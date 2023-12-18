//
// Created by Or on 12/18/2023.
//

#include "headers/PointerToMemberData.h"
#include <iostream>

void Data::print() const {
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
}


void testDataClass() {
    Data d, * dp = &d;
    int Data::*pmInt = &Data::a;
    dp->*pmInt = 47;
    pmInt = &Data::b;
    d.*pmInt = 48;
    pmInt = &Data::c;
    dp->*pmInt = 49;
    dp->print();
}