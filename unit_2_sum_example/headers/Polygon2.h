//
// Created by Or on 12/27/2023.
//

#ifndef CPP_PLAYGROUND_POLYGON2_H
#define CPP_PLAYGROUND_POLYGON2_H

#include <vector>
#include "Shape2.h"
#include "Line2.h"

class Polygon2 : public Shape2 {
    std::vector<Line2> vec;
public:
    void addLine(Line2 ln);

    double getPerimeter();
};


#endif //CPP_PLAYGROUND_POLYGON2_H
