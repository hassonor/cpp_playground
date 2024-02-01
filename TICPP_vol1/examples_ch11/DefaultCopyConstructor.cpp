//
// Created by Or on 12/15/2023.
//

#include "headers/DefaultCopyConstructor.h"
#include <iostream>
#include <string>

// Implementations for WithCC
WithCC::WithCC() {}

WithCC::WithCC(const WithCC&) {
    std::cout << "WithCC(WithCC&)" << std::endl;
}

// Implementations for WoCC
WoCC::WoCC(const std::string& ident) : id(ident) {}

void WoCC::print(const std::string& msg) const {
    if (!msg.empty()) std::cout << msg << ": ";
    std::cout << id << std::endl;
}

// Implementations for Composite
Composite::Composite() : wocc("Composite()") {}

void Composite::print(const std::string& msg) const {
    wocc.print(msg);
}

void testComposite() {
    Composite c;
    c.print("Contents of c");
    std::cout << "Calling Composite copy-constructor" << std::endl;
    Composite c2 = c; // Calls copy-constructor
    c2.print("Contents of c2");
}