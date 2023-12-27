//
// Created by Or on 12/27/2023.
//

#ifndef CPP_PLAYGROUND_FILTER_H
#define CPP_PLAYGROUND_FILTER_H

#include "Shape2.h"


class Filter {
public:
    bool virtual applies(Shape2* s) = 0;
};


#endif //CPP_PLAYGROUND_FILTER_H
