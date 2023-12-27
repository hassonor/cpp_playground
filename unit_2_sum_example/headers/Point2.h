//
// Created by Or on 12/27/2023.
//

#ifndef CPP_PLAYGROUND_POINT2_H
#define CPP_PLAYGROUND_POINT2_H


class Point2 {
    int x;
    int y;
public:
    Point2(int x_coordinate, int y_coordinate);

    bool operator==(const Point2& p) const;

    int getX() const;

    int getY() const;
};


#endif //CPP_PLAYGROUND_POINT2_H
