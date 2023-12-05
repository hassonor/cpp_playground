#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "../headers/FillingString.h"

const std::string SOURCE_FILE = "../examples/Scopy.cpp";
const std::string TARGET_FILE = "../examples/Scopy3.cpp";

void fillFileString(const std::string &sourcePath, const std::string &targetPath) {
    std::ifstream in(sourcePath);
    if (!in) {
        throw std::runtime_error("Failed to open " + sourcePath + " for reading.");
    }

    std::ofstream out(targetPath);
    if (!out) {
        throw std::runtime_error("Failed to open " + targetPath + " for writing.");
    }

    std::string s;
    while (std::getline(in, s)) {
        out << s << "\n";
        if (!out) {
            throw std::runtime_error("Failed to write to " + targetPath + ".");
        }
    }

    // Note: The file streams are automatically closed when they go out of scope
    // due to the RAII principle. This releases the file descriptors and other
    // system resources used for the file operations.
}

void fillString() {
    try {
        fillFileString(SOURCE_FILE, TARGET_FILE);
        std::cout << "File copied successfully." << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
