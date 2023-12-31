//
// Created by Or on 12/23/2023.
//

#include "headers/PrivateInheritance.h"

class Pet {
public:
    char eat() const { return 'a'; }

    int speak() const { return 2; }

    float sleep() const { return 3.0; }

    float sleep(int) const { return 4.0; }
};

class Goldfish : Pet { // Private inheritance
public:
    using Pet::eat; // Name publicizes member
    using Pet::sleep; // Both overload members exposed

};

void testPrivateInheritance() {
    Goldfish bob;
    bob.eat();
    bob.sleep();
    bob.sleep(1);
    //! bob.speak(); // Error: private member function
}
