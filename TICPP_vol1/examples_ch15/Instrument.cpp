//
// Created by Or on 12/24/2023.
//

#include "headers/Instrument.h"

void Instrument::play(note) const {
    cout << "Instrument::play" << endl;
}

string Instrument::what() const {
    return "Instrument";
}

void Instrument::adjust(int) {}

void Wind::play(note) const {
    cout << "Wind::play" << endl;
}

string Wind::what() const {
    return "Wind";
}

void Wind::adjust(int) {}

void Percussion::play(note) const {
    cout << "Percussion::play" << endl;
}

string Percussion::what() const {
    return "Percussion";
}

void Percussion::adjust(int) {}

void Stringed::play(note) const {
    cout << "Stringed::play" << endl;
}

string Stringed::what() const {
    return "Stringed";
}

void Stringed::adjust(int) {}

void Brass::play(note) const {
    cout << "Brass::play" << endl;
}

string Brass::what() const {
    return "Brass";
}

void Woodwind::play(note) const {
    cout << "Woodwind::play" << endl;
}

string Woodwind::what() const {
    return "Woodwind";
}

void tune(Instrument& i) {
    i.play(middleC);
}

void f(Instrument& i) {
    i.adjust(1);
}

