#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string>* getInput(std::string filePath);
int solve(std::vector<std::string>* lines);
int checkNumber(std::vector<std::string>* lines, int lineIndex, int &startIndex);

int main()
{
    std::cout << solve(getInput(".\\input.txt"));
    std::string get;
    std::cin >> get;
}

std::vector<std::string>* getInput(std::string filePath) {
    std::fstream input;
    input.open(filePath, std::ios::in);
    std::vector<std::string>* file = new std::vector<std::string>();
    std::string line;
    while (std::getline(input, line)) {
        file->push_back(line);
    }
    input.close();
    return file;
}

int solve(std::vector<std::string>* lines) {
    int sum = 0;
    for (int i = 0; i < lines->size(); i++) {
        for (int j = 0; j < lines->at(i).size(); j++) {
            if (lines->at(i).at(j) >= '0' && lines->at(i).at(j) <= '9') {
                sum += checkNumber(lines, i, j);
            }
        }
    }

    delete lines;
    return sum;
}

int checkNumber(std::vector<std::string>* lines, int lineIndex, int &startIndex) {
    int solidIndex = startIndex;
    int value = 0;
    if (startIndex + 1 >= lines->at(lineIndex).size()) {
        value = (lines->at(lineIndex).at(startIndex) - '0');
        startIndex += 1;
    }
    else if (lines->at(lineIndex).at(startIndex + 1) < '0' || lines->at(lineIndex).at(startIndex + 1) > '9') {
        value = (lines->at(lineIndex).at(startIndex) - '0');
        startIndex += 1;
    }
    else if (startIndex + 2 >= lines->at(lineIndex).size()) {
        value = 10 * (lines->at(lineIndex).at(startIndex) - '0');
        value += (lines->at(lineIndex).at(startIndex + 1) - '0');
        startIndex += 2;
    }
    else if (lines->at(lineIndex).at(startIndex + 2) < '0' || lines->at(lineIndex).at(startIndex + 2) > '9') {
        value = 10 * (lines->at(lineIndex).at(startIndex) - '0');
        value += (lines->at(lineIndex).at(startIndex + 1) - '0');
        startIndex += 2;
    }
    else {
        value = 100 * (lines->at(lineIndex).at(startIndex) - '0');
        value += 10 * (lines->at(lineIndex).at(startIndex + 1) - '0');
        value += (lines->at(lineIndex).at(startIndex + 2) - '0');
        startIndex += 3;
    }
    if (lineIndex > 0) {
        if (solidIndex > 0) {
            if (lines->at(lineIndex - 1).at(solidIndex - 1) != '.') {
                return value;
            }  
        }
        for (int i = solidIndex; i < startIndex; i++) {
            if (lines->at(lineIndex - 1).at(i) != '.') {
                return value;
            }
        }
        if (startIndex < lines->at(lineIndex).size()) {
            if (lines->at(lineIndex - 1).at(startIndex) != '.') {
                return value;
            }
        }
    }
    if (solidIndex > 0) {
        if (lines->at(lineIndex).at(solidIndex - 1) != '.') {
            return value;
        }
    }
    if (startIndex < lines->at(lineIndex).size()) {
        if (lines->at(lineIndex).at(startIndex) != '.') {
            return value;
        }
    }
    if ((lineIndex + 1) < lines->size()) {
        if (solidIndex > 0) {
            if (lines->at(lineIndex + 1).at(solidIndex - 1) != '.') {
                return value;
            }
        }
        for (int i = solidIndex; i < startIndex; i++) {
            if (lines->at(lineIndex + 1).at(i) != '.') {
                return value;
            }
        }
        if (startIndex < lines->at(lineIndex).size()) {
            if (lines->at(lineIndex + 1).at(startIndex) != '.') {
                return value;
            }
        }
    }

    return 0;
}