//
// Created by Or on 12/27/2023.
//

#ifndef CPP_PLAYGROUND_SHAPESCONTAINER_H
#define CPP_PLAYGROUND_SHAPESCONTAINER_H

#include <vector>
#include "Shape2.h"
#include "Filter.h"

class ShapesContainer {
    std::vector<Shape2*> shapes;
public:
    void insert(Shape2* s);

    void printPerimeters();

    ShapesContainer filter(Filter* f);
};

void testShapesProgram();


#endif //CPP_PLAYGROUND_SHAPESCONTAINER_H
