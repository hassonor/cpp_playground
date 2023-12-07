//
// Created by Or on 06/12/2023.
//

#include <iostream>
#include "headers/ch3Examples.h"

using namespace std;

extern int globe;

char cfunc(int i) {
    if (i == 0)
        return 'a';
    if (i == 1)
        return 'b';
    if (i == 5)
        return 'z';
    return 'c';
}

void ansiPrinter() {
    for (int i = 0; i < 256; i++) {
        cout << "value: " << i << " character: " << char(i) << endl;
    }
    std::cout << std::endl;
}

void simpleMenu() {
    char c;
    while (true) {
        cout << "MAIN MENU:" << endl;
        cout << "l: left, r: right, q: quit -> ";
        cin >> c;
        if (c == 'q')
            break; // Out of "while(1)"
        if (c == 'l') {
            cout << "LEFT MENU:" << endl;
            cout << "select a or b: ";
            cin >> c;
            if (c == 'a') {
                cout << "you chose 'a'" << endl;
                continue; // Back to main menu
            }
            if (c == 'b') {
                cout << "you chose 'b'" << endl;
                continue;
            } else {
                cout << "you didn't choose a or b!" << endl;
                continue; // Back to main menu
            }
        }
        if (c == 'r') {
            cout << "RIGHT MENU:" << endl;
            cout << "select c or d: ";
            cin >> c;
            if (c == 'c') {
                cout << "you chose 'c'" << endl;
                continue; // Back to main menu
            }
            if (c == 'd') {
                cout << "you chose 'd'" << endl;
                continue;
            } else {
                cout << "you didn't choose c or d!" << endl;
                continue; // Back to main menu
            }
        }
        cout << "you must type l or r or q!" << endl;
    }
    cout << "quitting menu..." << endl;
}

void simpleMenuWithSwitch() {
    bool quit = false; // Flag for quitting
    while (!quit) {
        cout << "Select a,b,c, or q to quit: ";
        char response;
        cin >> response;
        switch (response) {
            case 'a' :
                cout << "you chose 'a'" << endl;
                break;
            case 'b' :
                cout << "you chose 'b'" << endl;
                break;
            case 'c' :
                cout << "you chose 'c'" << endl;
                break;
            case 'q' :
                cout << "quitting menu..." << endl;
                quit = true;
                break;
            default:
                cout << "Please choose a valid option: a/b/c/q" << endl;
                break;
        }
    }
}

void removeHat(char cat) {
    for (char c = 'A'; c < cat; c++)
        cout << " ";
    if (cat <= 'Z') {
        cout << "cat " << cat << endl;
        removeHat(cat + 1); // Recursive call
    } else
        cout << "VOOM!!!" << endl;
}

void specifiers() {
    char c;
    unsigned char cu;

    int i;
    unsigned int iu;

    short int is;
    short iis; // same as short int
    unsigned short int isu;
    unsigned short iisu; // same as unsigned short int

    long int il;
    long iil; // same as long int
    unsigned long int ilu;
    unsigned long iilu; // same as unsigned long int

    float f;

    double d;

    long double ld;
    cout << "\n char = " << sizeof(c) << " bytes"
         << "\n unsigned char = " << sizeof(cu) << " bytes"
         << "\n int = " << sizeof(i) << " bytes"
         << "\n unsigned int = " << sizeof(iu) << " bytes"
         << "\n short = " << sizeof(is) << " bytes"
         << "\n unsigned short = " << sizeof(isu) << " bytes"
         << "\n long = " << sizeof(il) << " bytes"
         << "\n unsigned long = " << sizeof(ilu) << " bytes"
         << "\n float = " << sizeof(f) << " bytes"
         << "\n double = " << sizeof(d) << " bytes"
         << "\n long double = " << sizeof(ld) << " bytes"
         << endl;
    globe = 47;
}


void explicitOperatorsDemo() {
    int a = 10, b = 5;

    // Example of 'and' (&&)
    if (a > 0 and b > 0) {
        std::cout << "Both a and b are positive (using 'and')." << std::endl;
    }

    // Example of 'or' (||)
    if (a > 0 or b < 0) {
        std::cout << "Either a is positive or b is negative (using 'or')." << std::endl;
    }

    // Example of 'not' (!)
    if (not(a < 0)) {
        std::cout << "a is not negative (using 'not')." << std::endl;
    }

    // Example of 'bitand' (&)
    int c = a bitand b; // Bitwise AND
    std::cout << "Bitwise AND of a and b is " << c << " (using 'bitand')." << std::endl;

    // Example of 'bitor' (|)
    c = a bitor b; // Bitwise OR
    std::cout << "Bitwise OR of a and b is " << c << " (using 'bitor')." << std::endl;

    // Example of 'xor' (^)
    c = a xor b; // Bitwise XOR
    std::cout << "Bitwise XOR of a and b is " << c << " (using 'xor')." << std::endl;

    // Example of 'compl' (~)
    c = compl a; // Bitwise NOT
    std::cout << "Bitwise NOT of a is " << c << " (using 'compl')." << std::endl;

    // Example of 'and_eq' (&=)
    c and_eq b; // c = c & b
    std::cout << "Result of c and_eq b is " << c << " (using 'and_eq')." << std::endl;

    // Example of 'or_eq' (|=)
    c or_eq a; // c = c | a
    std::cout << "Result of c or_eq a is " << c << " (using 'or_eq')." << std::endl;

    // Example of 'xor_eq' (^=)
    c xor_eq b; // c = c ^ b
    std::cout << "Result of c xor_eq b is " << c << " (using 'xor_eq')." << std::endl;

    // Example of 'not_eq' (!=)
    if (a not_eq b) {
        std::cout << "a is not equal to b (using 'not_eq')." << std::endl;
    }
}



