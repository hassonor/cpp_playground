// Point.cpp
// Created by Or on 30/11/2023.

#include "../headers/Point.h"
#include <cmath>

int Point::distance(const Point &p) const {
    int dx = _x - p._x;
    int dy = _y - p._y;
    return std::sqrt(dx * dx + dy * dy);
}

int Point::distance(int x, int y) const {
    int dx = _x - x;
    int dy = _y - y;
    return std::sqrt(dx * dx + dy * dy);
}

Point& Point::operator=(const Point& other){
    if(this == &other)
        return *this;

    _x = other._x;
    _y = other._y;

    return *this;
}

Point Point::operator+(const Point& other) const {
    Point p;
    p._x = _x + other._x;
    p._y = _y + other._y;

    return p;
}
