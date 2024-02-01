//
// Created by Or on 12/18/2023.
//

#ifndef CPP_PLAYGROUND_POINTERTOMEMBERFUNCTION2_H
#define CPP_PLAYGROUND_POINTERTOMEMBERFUNCTION2_H

#include <iostream>

class Widget2 {
    // Declaration of member functions
    void f(int) const;

    void g(int) const;

    void h(int) const;

    void i(int) const;

    enum {
        cnt = 4
    };

    void (Widget2::*fptr[cnt])(int) const;

public:
    Widget2();

    void select(int i, int j);

    int count() const;
};

void testWidget2();


#endif //CPP_PLAYGROUND_POINTERTOMEMBERFUNCTION2_H
