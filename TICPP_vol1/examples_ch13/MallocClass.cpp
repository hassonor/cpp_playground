//
// Created by Or on 12/20/2023.
//

#include "headers/MallocClass.h"
#include <cstdlib> // malloc() & free()
#include <cstring> // memset()
#include <iostream>
#include <cassert>

void MallocClass::initialize() {
    std::cout << "initializing Obj" << std::endl;
    i = j = k = 0;
    memset(buf, 0, sz);
}

void MallocClass::destroy() const {
    std::cout << "destroying Obj" << std::endl;
}

void testMallocClass() {
    MallocClass* obj = (MallocClass*) malloc(sizeof(MallocClass));
    assert(obj != nullptr);
    obj->initialize();
    obj->destroy();
    free(obj);
}
