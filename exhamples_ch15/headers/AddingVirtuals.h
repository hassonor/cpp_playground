//
// Created by Or on 12/24/2023.
//

#ifndef CPP_PLAYGROUND_ADDINGVIRTUALS_H
#define CPP_PLAYGROUND_ADDINGVIRTUALS_H

#include <iostream>
#include <string>

using namespace std;

class Pet {
    string pname;
public:
    Pet(const std::string& petName);

    virtual std::string name() const;

    virtual std::string speak() const;
};

class Dog : public Pet {
public:
    Dog(const std::string& petName);

    virtual std::string sit() const;

    std::string speak() const override;
};

void testAddingVirtualsClass();


#endif //CPP_PLAYGROUND_ADDINGVIRTUALS_H
