#include <string>
#include <iostream>
#include "../headers/HelloStrings.h"


void helloStrings() {
    std::string s1, s2; // Empty strings
    std::string s3 = "Hello, World."; // Initialized
    std::string s4("I am"); // Also initialized
    s2 = "Today"; // Assigning to a string
    s1 = s3 + " " + s4; // Combining strings
    s1 += " 8 "; // Appending to a string+
    s1 = s2;
    s2 = "Another Day";
    std::cout << s1 << std::endl;
    std::cout << s1 + s2 + "!" << std::endl;
}