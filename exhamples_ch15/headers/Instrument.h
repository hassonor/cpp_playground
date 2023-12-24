//
// Created by Or on 12/24/2023.
//

#ifndef CPP_PLAYGROUND_INSTRUMENT_H
#define CPP_PLAYGROUND_INSTRUMENT_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

enum note {
    middleC, Csharp, Eflat
};

class Instrument {
public:
    virtual void play(note) const;

    virtual string what() const;

    virtual void adjust(int);
};

class Wind : public Instrument {
public:
    void play(note) const override;

    string what() const override;

    void adjust(int) override;
};

class Percussion : public Instrument {
public:
    void play(note) const override;

    string what() const override;

    void adjust(int) override;
};

class Stringed : public Instrument {
public:
    void play(note) const override;

    string what() const override;

    void adjust(int) override;
};

class Brass : public Wind {
public:
    void play(note) const override;

    string what() const override;
};

class Woodwind : public Wind {
public:
    void play(note) const override;

    string what() const override;
};

void tune(Instrument&);

void f(Instrument&);


#endif //CPP_PLAYGROUND_INSTRUMENT_H
