//
// Created by Or on 12/24/2023.
//

#include "headers/AddingVirtuals.h"

Pet::Pet(const std::string& petName) : pname(petName) {}

std::string Pet::name() const {
    return pname;
}

std::string Pet::speak() const {
    return "";
}

Dog::Dog(const std::string& petName) : Pet(petName) {}

std::string Dog::sit() const {
    return Pet::name() + " sits";
}

std::string Dog::speak() const {
    return Pet::name() + " says 'Bark!'";
}


void testAddingVirtualsClass() {
    Pet* p[] = {new Pet("generic"), new Dog("Pistuk")};
    cout << "p[0] -> speak() = " << p[0]->speak() << endl;
    cout << "p[1] -> speak() = " << p[1]->speak() << endl;
    cout << "p[1]->sit() = " << ((Dog*) p[1])->sit() << endl;
}