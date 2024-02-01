//
// Created by Or on 12/21/2023.
//

#include "headers/FName.h"
#include <iostream>

using namespace std;

FName::FName() : named(false) {}

FName::FName(const string& fname) : ifstream(fname.c_str()), fileName(fname), named(true) {
    assure(*this, fileName);
}

string FName::name() const {
    return fileName;
}

void FName::name(const string& newName) {
    if (named) return;
    fileName = newName;
    named = true;
}

void FName::assure(ifstream& fs, const string& filename) {
    if (!fs) {
        cerr << "Cannot open file " << filename << endl;
    }
}

void testFNameClass() {
    FName file("../examples_ch14/FName.cpp");
    FName::assure(file, "FName.cpp");
    cout << "name: " << file.name() << endl;
    string s;
    getline(file, s); // These work too!
    file.seekg(-200, ios::end);
    file.close();
}
