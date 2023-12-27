//
// Created by Or on 12/27/2023.
//

#include <math.h>
#include "headers/Circle2.h"

Circle2::Circle2(Point2 p, int r) : center(p), radius(r) {}

Point2 Circle2::getCenter() { return center; }

int Circle2::getRadius() { return radius; }

double Circle2::getPerimeter() { return 2 * M_PI * radius; }