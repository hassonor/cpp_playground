//
// Created by Or on 12/27/2023.
//

#include "headers/ShapesContainer.h"
#include "headers/Point2.h"
#include "headers/Line2.h"
#include "headers/Circle2.h"
#include "headers/Polygon2.h"
#include "headers/FilterPerimeter.h"
#include <iostream>

using namespace std;

void ShapesContainer::insert(Shape2* s) {
    shapes.push_back(s);
}

void ShapesContainer::printPerimeters() {
    for (int i = 0; i < shapes.size(); i++) {
        cout << "Perimeter of shape " << i << " is: " << shapes[i]->getPerimeter() << endl;
    }
}

ShapesContainer ShapesContainer::filter(Filter* f) {
    ShapesContainer filteredShapes;
    for (int i = 0; i < shapes.size(); i++) {
        if (f->applies(shapes[i]))
            filteredShapes.insert(shapes[i]);
    }

    return filteredShapes;
}

void testShapesProgram() {
    Point2 p1(90, 10);
    Point2 p2(100, 10);
    Point2 p3(100, 20);

    Line2 ln1(p1, p2);
    Line2 ln2(p2, p3);
    Line2 ln3(p3, p1);

    Circle2* cir1 = new Circle2(p1, 5);
    Circle2* cir2 = new Circle2(p2, 10);

    Polygon2* pol1 = new Polygon2();
    pol1->addLine(ln1);
    pol1->addLine(ln2);
    pol1->addLine(ln3);

    ShapesContainer shapes;
    shapes.insert(cir1);
    shapes.insert(cir2);
    shapes.insert(pol1);
    cout << "Shapes container perimeters" << endl;
    shapes.printPerimeters();

    Filter* filter = new FilterPerimeter(30, 40);
    ShapesContainer newContainer = shapes.filter(filter);
    cout << "Filtered shapes perimeters" << endl;
    newContainer.printPerimeters();


}



