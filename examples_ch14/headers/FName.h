//
// Created by Or on 12/21/2023.
//

#ifndef CPP_PLAYGROUND_FNAME_H
#define CPP_PLAYGROUND_FNAME_H

#include <fstream>
#include <string>

using namespace std;


class FName : public ifstream {
    string fileName;
    bool named;
public:
    FName();

    FName(const string& fname);

    string name() const;

    void name(const string& newName);

    static void assure(ifstream& fs, const string& filename);
};

void testFNameClass();


#endif //CPP_PLAYGROUND_FNAME_H
