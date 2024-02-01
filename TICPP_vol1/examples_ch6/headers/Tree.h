//
// Created by Or on 12/12/2023.
//

#ifndef CPP_PLAYGROUND_TREE_H
#define CPP_PLAYGROUND_TREE_H


class Tree {
    int height;
public:
    Tree(int initialHeight);

    ~Tree();

    void grow(int years);

    void printSize() const;
};

void testTreeClass();


#endif //CPP_PLAYGROUND_TREE_H
