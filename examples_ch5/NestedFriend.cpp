// Created by Or on 12/11/2023.

#include "headers/NestedFriend.h"
#include <iostream>
#include <cstring>

using namespace std;

void Holder::initialize() {
    memset(a, 0, sz * sizeof(int));
}

void Holder::Pointer::initialize(Holder* rv) {
    h = rv;
    p = rv->a;
}

void Holder::Pointer::next() {
    if (p < &(h->a[sz - 1])) p++;
}

void Holder::Pointer::previous() {
    if (p > &(h->a[0])) p--;
}

void Holder::Pointer::top() {
    p = &(h->a[0]);
}

void Holder::Pointer::end() {
    p = &(h->a[sz - 1]);
}

int Holder::Pointer::read() {
    return *p;
}

void Holder::Pointer::set(int i) {
    *p = i;
}

void testNestedFriend() {
    Holder h{};
    Holder::Pointer hp{}, hp2{};
    h.initialize();
    hp.initialize(&h);
    hp2.initialize(&h);

    for (int i = 0; i < sz; i++) {
        hp.set(i);
        hp.next();
    }

    hp.top();
    hp2.end();

    for (int i = 0; i < sz; i++) {
        cout << "hp = " << hp.read() << ", hp2 = " << hp2.read() << endl;
        hp.next();
        hp2.previous();
    }
}
