//
// Created by Or on 12/23/2023.
//

#include "headers/CopyConstructorUpCastingDemo.h"

#include <iostream>

using namespace std;

class Parent {
    int i;
public:
    Parent(int ii) : i(ii) {
        cout << "Parent(int ii)\n";
    }

    Parent(const Parent& b) : i(b.i) {
        cout << "Parent(const Parent&)\n";
    }

    Parent() : i(0) { cout << "Parent()\n"; }

    friend ostream& operator<<(ostream& os, const Parent& b) {
        return os << "Parent: " << b.i << endl;
    }
};

class Member {
    int i;
public:
    Member(int ii) : i(ii) {
        cout << "Member(int ii)\n";
    }

    Member(const Member& m) : i(m.i) {
        cout << "Member(const Member&)\n";
    }

    friend ostream& operator<<(ostream& os, const Member& m) {
        return os << "Member: " << m.i << endl;
    }
};

class Child : public Parent {
    int i;
    Member m;
public:
    Child(int ii) : Parent(ii), i(ii), m(ii) {
        cout << "Child(int ii)\n";
    }

    Child(const Child& c)
            : Parent(c), i(c.i), m(c.m) {
        cout << "Child(Child&)\n";
    }

    friend ostream& operator<<(ostream& os, const Child& c) {
        return os << (Parent&) c << c.m << "Child: " << c.i << endl;
    }
};

void testCCUpCastingDemo() {
    Child c(2);
    cout << "calling copy-constructor: " << endl;
    Child c2 = c; // Call copy-constructor
    cout << "values in c2:\n" << c2;
}
