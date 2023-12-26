//
// Created by Or on 12/26/2023.
//

#include "headers/DynamicCast.h"
#include <iostream>

using namespace std;

class dcPet {
public:
    virtual ~dcPet() {}
};

class dcDog : public dcPet {
};

class dcCat : public dcPet {
};

void testDynamicCast() {
    dcPet* b = new dcCat; // Upcast

    // Try to cast it to dcDog*:
    dcDog* d1 = dynamic_cast<dcDog*>(b); //invalid results.

    // Try to cast it to dcCat*:
    dcCat* d2 = dynamic_cast<dcCat*>(b);

    cout << "d1 = " << (long long) d1 << endl;
    cout << "d2 = " << (long long) d2 << endl;

}