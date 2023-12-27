//
// Created by Or on 12/25/2023.
//

#include "headers/VariantReturn.h"
#include <iostream>
#include <string>

using namespace std;

class PetFood {
public:
    virtual string foodType() const = 0;
};

class Pett {
public:
    virtual string type() const = 0;

    virtual PetFood* eats() = 0;
};

class Bird : public Pett {
public:
    string type() const { return "Bird"; }

    class BirdFood : public PetFood {
    public:
        string foodType() const {
            return "Bird food";
        }
    };

    // Upcast to base type:
    PetFood* eats() { return &bf; }

private:
    BirdFood bf;
};

class Cat : public Pett {
public:
    string type() const { return "Cat"; }

    class CatFood : public PetFood {
    public:
        string foodType() const { return "Birds"; }
    };

    // Return exact type instead;
    CatFood* eats() { return &cf; }

private:
    CatFood cf;
};

void testVariantReturn() {
    Bird b;
    Cat c;
    Pett* p[] = {&b, &c};
    for (int i = 0; i < sizeof p / sizeof *p; i++) {
        cout << p[i]->type() << " eats " << p[i]->eats()->foodType() << endl;
    }
    // Can return the exact type;
    Cat::CatFood* cf = c.eats();
    Bird::BirdFood* bf;
    // Cannot return the exact type:
    //! bf = b.eats();
    // Must downcast:
    bf = dynamic_cast<Bird::BirdFood*>(b.eats());


}