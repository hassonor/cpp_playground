// Created by Or on 30/11/2023.

#ifndef DEFENSIVE_PROGRAMMING_V2_METHOD_HIDING_H
#define DEFENSIVE_PROGRAMMING_V2_METHOD_HIDING_H

#include <iostream>

struct InkPrinter {
    void print();
};

struct LaserPrinter : public InkPrinter {
    void print();
};

#endif //DEFENSIVE_PROGRAMMING_V2_METHOD_HIDING_H