//
// Created by Or on 12/25/2023.
//

#include "headers/NameHiding2.h"
#include <iostream>

using namespace std;

class BaseC {
public:
    virtual int f() const {
        cout << "BaseC::f()\n";
        return 1;
    }

    virtual void f(string) const {}

    virtual void g() const {}
};

class Derived_1 : public BaseC {
public:
    void g() const {}
};

class Derived_2 : public BaseC {
public:
    // Overriding a virtual function:
    int f() const {
        cout << "Derived_2::f()\n";
        return 2;
    }
};

class Derived_3 : public BaseC {
public:
    // Cannot change return type:
    //! void f() const { cout<< "Derived_3::f()\n";}
};

class Derived_4 : public BaseC {
public:
    // Change argument list:
    int f(int) const {
        cout << "Derived_4::f()\n";
        return 4;
    }
};

void testNameHiding2() {
    string s("hello");
    Derived_1 d1;
    int x = d1.f();
    d1.f(s);

    Derived_2 d2;
    //! d2.f(s); // string version hidden

    Derived_4 d4;
    x = d4.f(1);
    //! x = d4.f(); // f() version hidden
    //! d4.f(s); // string version hidden

    BaseC& br = d4; // Upcast
    //! br.f(1); // Derived version unavailable
    br.f(); // BaseC version available
    br.f(s); // BaseC version available


}