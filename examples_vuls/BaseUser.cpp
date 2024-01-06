//
// Created by Or on 1/6/2024.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include "BaseUser.h"

using namespace std;


void BaseUser::gainAccess() {
    cout << "Access gained" << endl;
}

void BaseUser::denyAccess() {
    cout << "Access denied" << endl;
}

void BaseUser::checkAccess(char pw[]) {
    if (strcmp(pw, "abc") == 0)
        this->gainAccess();
    else
        this->denyAccess();
}

void testBaseUserClass() {
    // Example 1
//    BaseUser base;
//    char pw[10];
//
//    BaseUser* b = &base;

//    cout << "Enter password" << endl;
//    gets(pw);

//    int* vptrB = (int*) b;
//
//    cout << "Before: " << hex << vptrB << endl;
//    cout << "After: " << hex << reinterpret_cast<int*>(*vptrB - 8) << endl;
//
//
//    *vptrB = *vptrB - 8;
//
//
//    b->checkAccess(pw);

    // Example 2
    BaseUser base2;
    char pw2[10];
    BaseUser* b = &base2;
    cout << "Enter password: " << endl;
    fgets(pw2, 10, stdin);

    cout << pw2 << endl;

    b->checkAccess(pw2);


}


