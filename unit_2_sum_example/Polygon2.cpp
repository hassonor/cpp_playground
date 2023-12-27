//
// Created by Or on 12/27/2023.
//

#include "headers/Polygon2.h"

/*
 * A function for gradually constructing the polygon, by adding one line at a time
 */

void Polygon2::addLine(Line2 ln) {
    if (vec.size() == 0)
        vec.push_back(ln);
    else if (vec[vec.size() - 1].getEnd() == ln.getStart())
        /* make sure the polygon is continuous */
        vec.push_back(ln);
}

double Polygon2::getPerimeter() {
    double result = 0;
    for (int i = 0; i < vec.size(); i++) {
        result += vec[i].getLength();
    }

    return result;
}

