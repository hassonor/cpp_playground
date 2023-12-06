#include "headers/StreamExamples.h"
#include "headers/FormatWithCommas.h"
#include <iostream>
#include <limits>

void showStreamExamples() {
    std::cout << "Max signed int: " << formatWithCommas(std::numeric_limits<int>::max()) << std::endl;
    std::cout << "Min signed int: " << std::numeric_limits<int>::min() << std::endl;

    std::cout << "Max unsigned int: " << formatWithCommas(std::numeric_limits<unsigned int>::max()) << std::endl;
    // Min unsigned int is always 0

    std::cout << "Max signed long: " << formatWithCommas(std::numeric_limits<long>::max()) << std::endl;
    std::cout << "Min signed long: " << std::numeric_limits<long>::min() << std::endl;

    std::cout << "Max unsigned long: " << formatWithCommas(std::numeric_limits<unsigned long>::max()) << std::endl;
    // Min unsigned long is always 0

    std::cout << "Max signed long long: " << formatWithCommas(std::numeric_limits<long long>::max()) << std::endl;
    std::cout << "Min signed long long: " << std::numeric_limits<long long>::min() << std::endl;

    std::cout << "Max unsigned long long: " << formatWithCommas(std::numeric_limits<unsigned long long>::max())
              << std::endl;
    // Min unsigned long long is always 0

    std::cout << "Max float: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Min float: " << std::numeric_limits<float>::min()
              << std::endl;  // Note: This is the smallest positive normalized value

    std::cout << "Max double: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Min double: " << std::numeric_limits<double>::min() << std::endl;

    std::cout << "Max long double: " << std::numeric_limits<long double>::max() << std::endl;
    std::cout << "Min long double: " << std::numeric_limits<long double>::min() << std::endl;
}
