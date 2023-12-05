//
// Created by Or on 05/12/2023.
//

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

#include "../headers/Vector.h"


void fillVector() {
    vector<string> v;
    ifstream in("../examples/Vector.cpp");
    string line;
    while (getline(in, line)) {
        v.push_back(line); // Add the line to the end
    }
    for (int i = 0; i < v.size(); i++) {
        cout << i << ": " << v[i] << endl;
    }
}

void fillVectorWaitForEnterForEachLine() {
    vector<string> v;
    ifstream in("../examples/Vector.cpp");
    string line;
    while (getline(in, line)) {
        v.push_back(line); // Add the line to the end
    }
    for (int i = 0; i < v.size(); i++) {
        cout << i << ": " << v[i];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void getWords() {
    vector<string> words;
    ifstream in("../examples/Vector.cpp");
    string word;
    while (in >> word) {
        words.push_back(word);
    }
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }
}

void intVector() {
    vector<int> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for (int i: v)
        cout << i << ", ";
    cout << endl;

    for (int i = 0; i < v.size(); i++)
        v[i] = v[i] * 10; // Assignment


    // Way 2:
//    for (int &i: v)
//        i = i * 10;

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ", ";
    cout << endl;

}
