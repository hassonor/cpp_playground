//
// Created by Or on 12/27/2023.
//

#include "headers/FilterPerimeter.h"

FilterPerimeter::FilterPerimeter(int min, int max) : minPerimeter(min), maxPerimeter(max) {};

bool FilterPerimeter::applies(Shape2* s) {
    return (s->getPerimeter() >= minPerimeter && s->getPerimeter() <= maxPerimeter);
}
