//
// Created by Or on 12/20/2023.
//

#ifndef CPP_PLAYGROUND_MALLOCCLASS_H
#define CPP_PLAYGROUND_MALLOCCLASS_H


class MallocClass {
    int i, j, k;
    enum {
        sz = 100
    };
    char buf[sz];
public:
    void initialize();

    void destroy() const;
};

void testMallocClass();


#endif //CPP_PLAYGROUND_MALLOCCLASS_H
