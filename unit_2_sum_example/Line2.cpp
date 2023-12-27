//
// Created by Or on 12/27/2023.
//

#include "headers/Line2.h"
#include <math.h>

Line2::Line2(Point2 start, Point2 end) : p1(start), p2(end) {}

Point2 Line2::getStart() const {
    return p1;
}

Point2 Line2::getEnd() const {
    return p2;
}

/* Length calculation using Pythagoras */
double Line2::getLength() {
    return sqrt((p2.getX() - p1.getX()) * (p2.getX() - p1.getX()) + (p2.getY() - p1.getY()) * (p2.getY() - p1.getY()));
}
