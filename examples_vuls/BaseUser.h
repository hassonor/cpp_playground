//
// Created by Or on 1/6/2024.
//

#ifndef CPP_PLAYGROUND_BASEUSER_H
#define CPP_PLAYGROUND_BASEUSER_H


class BaseUser {
public:
    virtual void gainAccess();

    virtual void denyAccess();

    void checkAccess(char pw[]);
};

void testBaseUserClass();


#endif //CPP_PLAYGROUND_BASEUSER_H
