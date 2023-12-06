//
// Created by Or on 05/12/2023.
//
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "headers/Scopy.h"

const std::string SOURCE_FILE = "../examples_ch2/Scopy.cpp";
const std::string TARGET_FILE = "../examples_ch2/Scopy2.cpp";

void copyFileContent(const std::string &sourcePath, const std::string &targetPath) {
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
}

void scopy() {
    try {
        copyFileContent(SOURCE_FILE, TARGET_FILE);
        std::cout << "File copied successfully." << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}