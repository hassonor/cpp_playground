//
// Created by Or on 12/23/2023.
//

#include "headers/OperatorInheritance.h"
#include "headers/Byte.h"

#include <fstream>

using namespace std;

extern ofstream out;

class Byte2 : public Byte {
public:
    // Constructors don't inherit:
    Byte2(unsigned char bb = 0) : Byte(bb) {}

    /*
     * operator= does not inherit, but
     * is synthesized for member wise assignment.
     * However, only the SameType = SameType
     * operator= is synthesized, so you have to
     * make the others explicitly:
     */
    Byte2& operator=(const Byte& right) {
        Byte::operator=(right);
        return *this;
    }

    Byte2& operator=(int i) {
        Byte::operator=(i);
        return *this;
    }
};

void k(Byte2& b1, Byte2& b2) {
    b1 = b1 * b2 + b2 % b1;

#define TRY2(OP) \
 out << "b1 = "; b1.print(out); \
 out << ", b2 = "; b2.print(out); \
 out << "; b1 " #OP " b2 produces "; \
 (b1 OP b2).print(out); \
 out << endl;

    b1 = 9;
    b2 = 47;
    TRY2(+)
    TRY2(-)
    TRY2(*)
    TRY2(/)
    TRY2(%)
    TRY2(^)
    TRY2(&)
    TRY2(|)
    TRY2(<<)
    TRY2(>>)
    TRY2(+=)
    TRY2(-=)
    TRY2(*=)
    TRY2(/=)
    TRY2(%=)
    TRY2(^=)
    TRY2(&=)
    TRY2(|=)
    TRY2(>>=)
    TRY2(<<=)
    TRY2(=) // Assignment operator


    // Conditionals:
#define TRYC2(OP) \
 out << "b1 = "; b1.print(out); \
 out << ", b2 = "; b2.print(out); \
 out << "; b1 " #OP " b2 produces "; \
 out << (b1 OP b2); \
 out << endl;
    b1 = 9;
    b2 = 47;
    TRYC2(<)
    TRYC2(>)
    TRYC2(==)
    TRYC2(!=)
    TRYC2(<=)
    TRYC2(>=)
    TRYC2(&&)
    TRYC2(||)
    // Chained assignment:
    Byte2 b3 = 92;
    b1 = b2 = b3;
}

void testByte2() {
    out << "member functions:" << endl;
    Byte2 b1(47), b2(9);
    k(b1, b2);
};
