//
// Created by Or on 12/27/2023.
//

#ifndef CPP_PLAYGROUND_FILTERPERIMETER_H
#define CPP_PLAYGROUND_FILTERPERIMETER_H


#include "Filter.h"

class FilterPerimeter : public Filter {
    int minPerimeter;
    int maxPerimeter;
public:
    FilterPerimeter(int min, int max);

    bool applies(Shape2* s);
};


#endif //CPP_PLAYGROUND_FILTERPERIMETER_H
