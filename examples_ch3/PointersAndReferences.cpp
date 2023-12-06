//
// Created by Or on 06/12/2023.
//
#include <iostream>
#include "headers/PointersAndReferences.h"

using namespace std;

void passValue(int a) {
    cout << "Inside passValue, before modification: a = " << a << endl;
    a = 5;
    cout << "Inside passValue, after modification: a = " << a << endl;
}

void passAddress(int *p) {
    cout << "Inside passAddress, address of p: " << p << endl;
    cout << "Inside passAddress, value pointed by p before modification: " << *p << endl;
    *p = 5;
    cout << "Inside passAddress, value pointed by p after modification: " << *p << endl;
}

void passReference(int &r) {
    cout << "Inside passReference, value of r before modification: " << r << endl;
    cout << "Inside passReference, address of r: " << &r << endl;
    r = 5;
    cout << "Inside passReference, value of r after modification: " << r << endl;
}

void demonstratePassingMethods() {
    // Pass by Value
    int a = 47;
    cout << "Before passValue: a = " << a << endl;
    passValue(a);
    cout << "After passValue: a = " << a << endl << endl;

    // Pass by Address
    int x = 47;
    cout << "Before passAddress: x = " << x << endl;
    cout << "Address of x: " << &x << endl;
    passAddress(&x);
    cout << "After passAddress: x = " << x << endl << endl;

    // Pass by Reference
    int y = 47;
    cout << "Before passReference: y = " << y << endl;
    cout << "Address of y: " << &y << endl;
    passReference(y); // Looks like pass-by-value, is actually pass-by-reference
    cout << "After passReference: y = " << y << endl;
}
