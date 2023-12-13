//
// Created by Or on 12/12/2023.
//

#include "headers/Tree.h"
#include <iostream>

using namespace std;


Tree::Tree(int initialHeight) {
    height = initialHeight;
}

Tree::~Tree() {
    cout << "inside Tree destructor" << endl;
    printSize();
}

void Tree::grow(int years) {
    height += years;
}


void Tree::printSize() const {
    cout << "Tree height is " << height << endl;
}

void testTreeClass() {
    cout << "before opening brace" << endl;
    {
        Tree t(12);
        cout << "after Tree creation" << endl;
        t.printSize();
        t.grow(4);
        cout << "before closing brace" << endl;
    }
    cout << "after closing brace" << endl;
}
