//
// Created by Or on 12/15/2023.
//

#ifndef CPP_PLAYGROUND_DEFAULTCOPYCONSTRUCTOR_H
#define CPP_PLAYGROUND_DEFAULTCOPYCONSTRUCTOR_H

#include <string>

class WithCC { // With copy-constructor
public:
    WithCC();

    WithCC(const WithCC&);
};

class WoCC { // Without copy-constructor
    std::string id;
public:
    WoCC(const std::string& ident = "");

    void print(const std::string& msg = "") const;
};

class Composite {
    WithCC withcc; // Embedded objects
    WoCC wocc;
public:
    Composite();

    void print(const std::string& msg = "") const;
};

void testComposite();


#endif //CPP_PLAYGROUND_DEFAULTCOPYCONSTRUCTOR_H
