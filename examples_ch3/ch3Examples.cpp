//
// Created by Or on 06/12/2023.
//

#include <iostream>
#include "headers/ch3Examples.h"

using namespace std;

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
}
