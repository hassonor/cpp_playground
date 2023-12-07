//
// Created by Or on 12/7/2023.
//

#include <iostream>
#include "headers/StructExamples.h"


void selfReferentialStructDemo() {
    typedef struct SelfReferentialStruct {
        int i;
        SelfReferentialStruct *sr;
    } SelfReferentialStruct;

    SelfReferentialStruct sr1, sr2;
    sr1.sr = &sr2;
    sr2.sr = &sr1;
    sr1.i = 45;
    sr2.i = 1024;
}

void simpleStruct() {
    // Using pointers to structs
    typedef struct Structure3 {
        char c;
        int i;
        float f;
        double d;
    } Structure3;

    Structure3 s1, s2;
    Structure3 *sp = &s1;
    sp->c = 'd';
    sp->i = 1;
    sp->f = 3.14;
    sp->d = 0.00093;
    sp = &s2; // Point to a different struct object
    sp->c = 'a';
    sp->i = 1;
    sp->f = 3.14;
    sp->d = 0.00093;
    std::cout << "s1.c = " << s1.c << std::endl;
    std::cout << "sp->c = " << sp->c << std::endl;
}