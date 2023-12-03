#include "headers/Stack.h"
#include "headers/Point.h"
#include <iostream>
#include <limits>
#include <string>
#include <cmath>

template<typename T>
std::string formatWithCommas(T value) {
    static_assert(std::is_integral<T>::value, "formatWithCommas requires an integral type.");

    bool isNegative = value < 0;
    T absVal = isNegative ? -value : value;  // Manually compute absolute value for integral types

    std::string number = std::to_string(absVal);
    int insertPosition = static_cast<int>(number.length()) - 3;

    while (insertPosition > 0) {
        number.insert(insertPosition, ",");
        insertPosition -= 3;
    }

    return isNegative ? "-" + number : number;
}

int main() {
    Stack s1; // Stack memory

    SecureStack s3;
    s3.print();

    Stack *sptr;
    sptr = &s3;

    // Virtual function, binding at runtime
    sptr->print();

    // Non-virtual function, binding at compile time
    sptr->show();

    int index = 0;
    while (index < 15) {
        s1.Push(index);
        index++;
    }


    Stack *s2 = new Stack(); // Heap memory
    s2->Push(14);
    delete s2;

/*
    Point p1(5, 7);
    Point p2(1, 2);
    Point p3;
    p3 = p1 + p2;
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

    std::cout << "Max unsigned long long: " << formatWithCommas(std::numeric_limits<unsigned long long>::max()) << std::endl;
    // Min unsigned long long is always 0

    std::cout << "Max float: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Min float: " << std::numeric_limits<float>::min() << std::endl;  // Note: This is the smallest positive normalized value

    std::cout << "Max double: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Min double: " << std::numeric_limits<double>::min() << std::endl;

    std::cout << "Max long double: " << std::numeric_limits<long double>::max() << std::endl;
    std::cout << "Min long double: " << std::numeric_limits<long double>::min() << std::endl;

*/
    return 0;
}





