//
// Created by Or on 12/18/2023.
//

#include "headers/PointerToMemberFunction.h"
#include <iostream>

void Widget1::f(int) const { std::cout << "Widget1::f()\n"; };

void Widget1::g(int) const { std::cout << "Widget1::g()\n"; };

void Widget1::h(int) const { std::cout << "Widget1::h()\n"; };

void Widget1::i(int) const { std::cout << "Widget1::i()\n"; };

void testWidget1() {
    Widget1 w1;
    Widget1* wp1 = &w1;

    void (Widget1::*pmem)(int) const = &Widget1::h;
    (w1.*pmem)(1);
    (wp1->*pmem)(2);
}
