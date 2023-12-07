//
// Created by Or on 12/7/2023.
//

#include "headers/bitwiseOperators.h"


#include <iostream>

void bitwiseOperatorsDemo() {
    // Example 1: Bitwise AND (&)
    // 12 (decimal) is 1100 in binary
    // 10 (decimal) is 1010 in binary
    // 1100
    // 1010
    // ---- (AND)
    // 1000 (8 in decimal)
    int a = 12;
    int b = 10;
    int result = a & b;
    std::cout << "Bitwise AND of 12 and 10 is " << result << std::endl;

    // Example 2: Bitwise OR (|)
    // 12 (decimal) is 1100 in binary
    // 10 (decimal) is 1010 in binary
    // 1100
    // 1010
    // ---- (OR)
    // 1110 (14 in decimal)
    a = 12;
    b = 10;
    result = a | b;
    std::cout << "Bitwise OR of 12 and 10 is " << result << std::endl;

    // Example 3: Bitwise XOR (^)
    // 12 (decimal) is 1100 in binary
    // 10 (decimal) is 1010 in binary
    // 1100
    // 1010
    // ---- (XOR)
    // 0110 (6 in decimal)
    a = 12;
    b = 10;
    result = a ^ b;
    std::cout << "Bitwise XOR of 12 and 10 is " << result << std::endl;

    // Example 4: Bitwise NOT (~)
    // 12 (decimal) is 00001100 in binary (assuming 8-bit representation)
    // ~00001100
    //  11110011 (in decimal, this depends on the system's integer size and representation)
    a = 12;
    result = ~a;
    std::cout << "Bitwise NOT of 12 is " << result << std::endl;

    // Example 5: Bitwise Left Shift (<<)
    // 5 (decimal) is 0101 in binary
    // 0101 << 1
    // 1010 (10 in decimal)
    a = 5;
    result = a << 1;
    std::cout << "5 shifted left by 1 bit is " << result << std::endl;

    // Example 6: Bitwise Right Shift (>>)
    // 20 (decimal) is 10100 in binary
    // 10100 >> 2
    // 0101 (5 in decimal)
    a = 20;
    result = a >> 2;
    std::cout << "20 shifted right by 2 bits is " << result << std::endl;

    // Example 7: Bitwise AND Assignment (&=)
    // Initially, a is 1100 and b is 1010 in binary
    // After a &= b, a becomes 1000 (8 in decimal)
    a = 12;
    b = 10;
    a &= b;
    std::cout << "Result of 12 &= 10 is " << a << std::endl;

    // Example 8: Bitwise OR Assignment (|=)
    // Initially, a is 1100 and b is 1010 in binary
    // After a |= b, a becomes 1110 (14 in decimal)
    a = 12;
    b = 10;
    a |= b;
    std::cout << "Result of 12 |= 10 is " << a << std::endl;

    // Example 9: Bitwise XOR Assignment (^=)
    // Initially, a is 1100 and b is 1010 in binary
    // After a ^= b, a becomes 0110 (6 in decimal)
    a = 12;
    b = 10;
    a ^= b;
    std::cout << "Result of 12 ^= 10 is " << a << std::endl;

}
