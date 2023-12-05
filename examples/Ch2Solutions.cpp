//
// Created by Or on 05/12/2023.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
#include "../headers/Ch2Solutions.h"

void countWordOccurrences(const std::string &filepath, const std::string &searchWord) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filepath << std::endl;
        return;
    }

    std::string word;
    int wordCount = 0;
    while (file >> word) {
        if (word == searchWord) {
            wordCount++;
        }
    }

    std::cout << "The word '" << searchWord << "' appears " << wordCount << " times in the file." << std::endl;
}

int countWhiteSeperatedWords(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return -1;
    }

    int wordCount = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            ++wordCount;
        }
    }

    file.close();
    return wordCount;
}

float roundToTwoDecimals(float num) {
    return std::round(num * 100.0f) / 100.0f;
}

// Function to print a vector
void printVector(const std::vector<float> &vec, const std::string &header) {
    std::cout << header << std::endl;
    for (float num: vec) {
        std::cout << std::fixed << std::setprecision(2) << num << ", ";
    }
    std::cout << std::endl << std::endl;
}

void floatVector(const float &start, const float &end, const int &size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(start, end);

    std::vector<float> v1(size), v2(size), v3(size), v4(size);

    for (int i = 0; i < size; i++) {
        v1[i] = roundToTwoDecimals(dis(gen));
        v2[i] = roundToTwoDecimals(dis(gen));
        v3[i] = v1[i] + v2[i];
        v4[i] = v3[i] * v3[i];
    }

    printVector(v1, "Vector v1:");
    printVector(v2, "Vector v2:");
    printVector(v3, "Sum Vector v3:");
    printVector(v4, "Squared Vector v4:");
}