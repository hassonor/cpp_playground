//
// Created by Or on 12/18/2023.
//

#include "headers/PointerToMemberFunction2.h"
#include <iostream>

void Widget2::f(int) const { std::cout << "Widget2::f()\n"; }

void Widget2::g(int) const { std::cout << "Widget2::g()\n"; }

void Widget2::h(int) const { std::cout << "Widget2::h()\n"; }

void Widget2::i(int) const { std::cout << "Widget2::i()\n"; }

void Widget2::select(int i, int j) {
    if (i < 0 || i >= cnt) return;
    (this->*fptr[i])(j);
}

int Widget2::count() const {
    return cnt;
}

