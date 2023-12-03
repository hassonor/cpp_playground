//
// Created by Or on 30/11/2023.
//

#ifndef DEFENSIVE_PROGRAMMING_V2_POINT_H
#define DEFENSIVE_PROGRAMMING_V2_POINT_H


class Point {
    int _x{};
    int _y{};
public:
    Point() = default;
    Point(int x, int y) : _x(x), _y(y) {}
    ~Point() = default;

    // Calculate Euclidean distance to another point
    int distance(const Point& p) const;

    // Calculate Euclidean distance to specific coordinates
    int distance(int x, int y) const;

    // Overload assignment operator
    Point& operator=(const Point& other);

    // Overload addition operator
    Point operator+(const Point& other) const;

};


#endif //DEFENSIVE_PROGRAMMING_V2_POINT_H
