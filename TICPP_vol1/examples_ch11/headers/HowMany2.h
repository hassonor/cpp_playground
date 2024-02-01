//
// Created by Or on 12/14/2023.
//

#ifndef CPP_PLAYGROUND_HOWMANY2_H
#define CPP_PLAYGROUND_HOWMANY2_H

#include <string>
#include <fstream>

class HowMany2 {
    std::string name; // Object identifier
    static int objectCount;
public:
    HowMany2(std::string id = "");

    ~HowMany2();

    HowMany2(const HowMany2& h);

    void print(const std::string& msg = "") const;

};

void testHowMany2();


#endif //CPP_PLAYGROUND_HOWMANY2_H
