//
// Created by Or on 12/11/2023.
//

#ifndef CPP_PLAYGROUND_HANDLE_H
#define CPP_PLAYGROUND_HANDLE_H


class Handle {
    struct Cheshire;
    Cheshire* smile;
public:
    Handle();

    ~Handle();

    void cleanup();

    int read();

    void change(int);
};


#endif //CPP_PLAYGROUND_HANDLE_H
