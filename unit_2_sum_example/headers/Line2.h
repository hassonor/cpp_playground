//
// Created by Or on 12/27/2023.
//

#ifndef CPP_PLAYGROUND_LINE2_H
#define CPP_PLAYGROUND_LINE2_H


#include "Point2.h"

class Line2 {
    Point2 p1;
    Point2 p2;
public:
    Line2(Point2 start, Point2 end);

    Point2 getStart() const;

    Point2 getEnd() const;

    double getLength();
};


#endif //CPP_PLAYGROUND_LINE2_H
