//
// Created by Or on 12/14/2023.
//

#include "headers/HowMany2.h"
#include <iostream>
#include <string>
#include <utility>


std::ofstream out("../examples_ch11/HowMany2.out");

int HowMany2::objectCount = 0; // Static member initialization

// Constructor
HowMany2::HowMany2(std::string id) : name(std::move(id)) {
    ++objectCount;
    print("HowMany2()");
}

// Copy Constructor
HowMany2::HowMany2(const HowMany2& h) : name(h.name) {
    name += " copy";
    ++objectCount;
    print("HowMany2(const HowMany2&)");
}

// Print function
void HowMany2::print(const std::string& msg) const {
    if (!msg.empty()) {
        out << msg << std::endl;
    }
    out << '\t' << name << ": " << "objectCount = " << objectCount << std::endl;
}

//Destructor
HowMany2::~HowMany2() {
    --objectCount;
    print("~HowMany2");
}

// Pass and return BY VALUE:
HowMany2 f(HowMany2 x) {
    x.print("x argument inside f()");
    out << "Returning from f()" << std::endl;
    return x;
}

void testHowMany2() {
    HowMany2 h("h");
    out << "Entering f()" << std::endl;
    HowMany2 h2 = f(h);
    h2.print("h2 after call to f()");
    out << "Call f(), no return value" << std::endl;
    f(h);
    out << "After call to f()" << std::endl;
}


