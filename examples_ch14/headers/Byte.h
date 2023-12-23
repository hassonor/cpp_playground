//
// Created by Or on 12/23/2023.
//

#ifndef CPP_PLAYGROUND_BYTE_H
#define CPP_PLAYGROUND_BYTE_H

#include <iostream>
#include <cassert>

class Byte {
    unsigned char b;
public:
    Byte(unsigned char bb = 0) : b(bb) {}

    // No side effects: const member function:
    const Byte
    operator+(const Byte& right) const {
        return Byte(b + right.b);
    }

    const Byte
    operator-(const Byte& right) const {
        return Byte(b - right.b);
    }

    const Byte
    operator*(const Byte& right) const {
        return Byte(b * right.b);
    }

    const Byte
    operator/(const Byte& right) const {
        assert(right.b != 0);
        return Byte(b / right.b);
    }

    const Byte
    operator%(const Byte& right) const {
        return Byte(b % right.b);
    }

    const Byte
    operator^(const Byte& right) const {
        return Byte(b ^ right.b);
    }

    const Byte
    operator&(const Byte& right) const {
        return Byte(b & right.b);
    }

    const Byte
    operator|(const Byte& right) const {
        return Byte(b | right.b);
    }

    const Byte
    operator<<(const Byte& right) const {
        return Byte(b << right.b);
    }

    const Byte
    operator>>(const Byte& right) const {
        return Byte(b >> right.b);
    }

    // Assignments modify & return lvalue.
    // operator= can only be a member function:
    Byte& operator=(const Byte& right) {
        // Handle self-assignment:
        if (this == &right) return *this;
        b = right.b;
        return *this;
    }

    Byte& operator+=(const Byte& right) {
        if (this == &right) {/* self-assignment */}
        b += right.b;
        return *this;
    }

    Byte& operator-=(const Byte& right) {
        if (this == &right) {/* self-assignment */}
        b -= right.b;
        return *this;
    }

    Byte& operator*=(const Byte& right) {
        if (this == &right) {/* self-assignment */}
        b *= right.b;
        return *this;
    }

    Byte& operator/=(const Byte& right) {
        assert(right.b != 0);
        if (this == &right) {/* self-assignment */}
        b /= right.b;
        return *this;
    }

    Byte& operator%=(const Byte& right) {
        assert(right.b != 0);
        if (this == &right) {/* self-assignment */}
        b %= right.b;
        return *this;
    }

    Byte& operator^=(const Byte& right) {
        if (this == &right) {/* self-assignment */}
        b ^= right.b;
        return *this;
    }

    Byte& operator&=(const Byte& right) {
        if (this == &right) {/* self-assignment */}
        b &= right.b;
        return *this;
    }

    Byte& operator|=(const Byte& right) {
        if (this == &right) {/* self-assignment */}
        b |= right.b;
        return *this;
    }

    Byte& operator>>=(const Byte& right) {
        if (this == &right) {/* self-assignment */}
        b >>= right.b;
        return *this;
    }

    Byte& operator<<=(const Byte& right) {
        if (this == &right) {/* self-assignment */}
        b <<= right.b;
        return *this;
    }

    // Conditional operators return true/false:
    int operator==(const Byte& right) const {
        return b == right.b;
    }

    int operator!=(const Byte& right) const {
        return b != right.b;
    }

    int operator<(const Byte& right) const {
        return b < right.b;
    }

    int operator>(const Byte& right) const {
        return b > right.b;
    }

    int operator<=(const Byte& right) const {
        return b <= right.b;
    }

    int operator>=(const Byte& right) const {
        return b >= right.b;
    }

    int operator&&(const Byte& right) const {
        return b && right.b;
    }

    int operator||(const Byte& right) const {
        return b || right.b;
    }

    // Write the contents to an ostream:
    void print(std::ostream& os) const {
        os << "0x" << std::hex << int(b) << std::dec;
    }
};


#endif //CPP_PLAYGROUND_BYTE_H
