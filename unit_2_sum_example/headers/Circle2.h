//
// Created by Or on 12/27/2023.
//

#ifndef CPP_PLAYGROUND_CIRCLE2_H
#define CPP_PLAYGROUND_CIRCLE2_H

#include "Shape2.h"
#include "Point2.h"

class Circle2 : public Shape2 {
    Point2 center;
    int radius;
public:
    Circle2(Point2 p, int r);

    Point2 getCenter();

    int getRadius();

    double getPerimeter();
};


#endif //CPP_PLAYGROUND_CIRCLE2_H
