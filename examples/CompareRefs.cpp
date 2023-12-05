#include <iostream>

using namespace std;

void compare_refs() {
    int a = 5;
    int &c = a; // c is a reference to a

    c = 6;

    cout << "Address of a: " << &a << endl;
    cout << "Address of c: " << &c << endl;

    // Comparing addresses
    if (&a == &c) {
        cout << "a and c reference the same memory location." << endl;
    } else {
        cout << "a and c reference different memory locations." << endl;
    }

    int *b = new int[5];

    delete[] b;
}

