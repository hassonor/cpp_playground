//
// Created by Or on 12/21/2023.
//

#include "headers/SynthesizeFunctions.h"
#include <iostream>

using namespace std;


class GameBoard {
public:
    GameBoard() { cout << "GameBoard()\n"; }

    GameBoard(const GameBoard&) {
        cout << "Gameboard(const Gameboard&)\n";
    }

    GameBoard& operator=(const GameBoard&) {
        cout << "GameBoard::operator=()\n";
        return *this;
    }

    ~GameBoard() { cout << "~GameBoard()\n"; }
};

class Game {
    GameBoard gb; // Composition
public:
    // Default GameBoard constructor called:
    Game() { cout << "Game()\n"; }

    // You must explicitly call the GameBoard
    // copy-constructor or the default constructor
    // is automatically called instead:
    Game(const Game& g) : gb(g.gb) {
        cout << "Game(const Game&)\n";
    }

    Game(int) { cout << "Game(int)\n"; }

    Game& operator=(const Game& g) {
        // You must explicitly call the GameBoard
        // assignment operator or no assignment at all happens for gb!
        gb = g.gb;
        cout << "Game::operator=()\n";
        return *this;
    }

    class Other {
    }; // Nested class
    // Automatic type conversion:
    explicit operator Other() const {
        cout << "Game::operator Other()\n";
        return Other();
    }

    ~Game() { cout << "~Game()\n"; }
};

class Chess : public Game {
};

void f(Game::Other) {}

class Checkers : public Game {
public:
    // Default base-class constructor called:
    Checkers() { cout << "Checkers()\n"; }

    // You must explicitly call the base-class
    // copy constructor or the default constructor
    // will be automatically called instead:
    Checkers(const Checkers& c) : Game(c) {
        cout << "Checkers(const Checkers& c)\n";
    }

    Checkers& operator=(const Checkers& c) {
        // You must explicitly call the base-class
        // version of operator=() or no base-class
        // assignment will happen:
        Game::operator=(c);
        cout << "Checkers::operator=()\n";
        return *this;
    }
};

void testSynthesizeFunctions() {
    Chess d1; // Default constructor
    Chess d2(d1); // Copy-constructor

    //! Chess d3(1); // Error: no int constructor

    d1 = d2; // Operator= synthesized
    Game::Other go;
    //! d1 = go; // Operator= not synthesized for differing types

    Checkers c1, c2(c1);
    c1 = c2;
}

