#include "headers/NumConv.h"
#include <iostream>

void convertNumber() {
    int number;
    std::cout << "Enter a decimal number: ";
    std::cin >> number;
    std::cout << "value in octal = 0" << std::oct << number << std::endl;
    std::cout << "value in hex = 0x" << std::hex << number << std::endl;
}
