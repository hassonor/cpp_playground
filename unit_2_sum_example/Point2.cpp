//
// Created by Or on 12/27/2023.
//

#include "headers/Point2.h"

/* constructor performs initialization using member initializer lists */
Point2::Point2(int x_coordinate, int y_coordinate) : x(x_coordinate), y(y_coordinate) {}

bool Point2::operator==(const Point2& p) const {
    return (x == p.getX() && y == p.getY());
}

int Point2::getX() const {
    return x;
}

int Point2::getY() const {
    return y;
}
