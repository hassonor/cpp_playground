//
// Created by Or on 12/11/2023.
//

#ifndef CPP_PLAYGROUND_EX3_H
#define CPP_PLAYGROUND_EX3_H


class Ex3 {
    int i = 3; // Private member variable initialized to 3
public:
    // Friend function declarations
    friend void changeValue(Ex3* ex3, int newValue);

    friend int showValue(Ex3* ex3);
};


#endif //CPP_PLAYGROUND_EX3_H
