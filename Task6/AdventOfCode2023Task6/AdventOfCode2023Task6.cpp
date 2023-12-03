#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string>* getInput(std::string filePath);
int solve(std::vector<std::string>* lines);
int gearRatio(std::vector<std::string>* lines, int lineIndex, int startIndex);
bool number(char c);
int getNumber(std::string line, int index);

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
            if (lines->at(i).at(j) == '*'){
                sum += gearRatio(lines, i, j);
            }
        }
    }

    delete lines;
    return sum;
}

int gearRatio(std::vector<std::string>* lines, int lineIndex, int startIndex) {
    std::vector<int> numbers;
    if (number(lines->at(lineIndex - 1).at(startIndex - 1))) {
        numbers.push_back(getNumber(lines->at(lineIndex - 1), startIndex - 1));
        if (!number(lines->at(lineIndex - 1).at(startIndex)) && number(lines->at(lineIndex - 1).at(startIndex + 1))) {
            numbers.push_back(getNumber(lines->at(lineIndex - 1), startIndex + 1));
        }
    }
    else if (number(lines->at(lineIndex - 1).at(startIndex + 1))) {
        numbers.push_back(getNumber(lines->at(lineIndex - 1), startIndex + 1));
    }
    if (number(lines->at(lineIndex).at(startIndex - 1))) {
        numbers.push_back(getNumber(lines->at(lineIndex), startIndex - 1));
    }
    if (number(lines->at(lineIndex).at(startIndex + 1))) {
        numbers.push_back(getNumber(lines->at(lineIndex), startIndex + 1));
    }
    if (number(lines->at(lineIndex + 1).at(startIndex - 1))) {
        numbers.push_back(getNumber(lines->at(lineIndex + 1), startIndex - 1));
        if (!number(lines->at(lineIndex + 1).at(startIndex)) && number(lines->at(lineIndex + 1).at(startIndex + 1))) {
            numbers.push_back(getNumber(lines->at(lineIndex + 1), startIndex + 1));
        }
    }
    else if (number(lines->at(lineIndex + 1).at(startIndex + 1))) {
        numbers.push_back(getNumber(lines->at(lineIndex + 1), startIndex + 1));
    }
    if (!number(lines->at(lineIndex - 1).at(startIndex - 1)) && !number(lines->at(lineIndex - 1).at(startIndex + 1)) && number(lines->at(lineIndex - 1).at(startIndex))) {
        numbers.push_back(lines->at(lineIndex - 1).at(startIndex) - '0');
    }
    if (!number(lines->at(lineIndex + 1).at(startIndex - 1)) && !number(lines->at(lineIndex + 1).at(startIndex + 1)) && number(lines->at(lineIndex + 1).at(startIndex))) {
        numbers.push_back(lines->at(lineIndex + 1).at(startIndex) - '0');
    }
    if (numbers.size() == 2) {
        return numbers.at(0) * numbers.at(1);
    }
    return 0;
}

bool number(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

int getNumber(std::string line, int index) {
    int start = index;
    int value = 0;
    while (start >= 0 && number(line.at(start)))
    {
        start--;
    }
    start++;
    if (start + 1 >= line.size()) {
        value = (line.at(start) - '0');
    }
    else if (!number(line.at(start + 1))) {
        value = (line.at(start) - '0');
    }
    else if (start + 2 >= line.size()) {
        value = 10 * (line.at(start) - '0');
        value += (line.at(start + 1) - '0');
    }
    else if (!number(line.at(start + 2))) {
        value = 10 * (line.at(start) - '0');
        value += (line.at(start + 1) - '0');
    }
    else {
        value = 100 * (line.at(start) - '0');
        value += 10 * (line.at(start + 1) - '0');
        value += (line.at(start + 2) - '0');
    }
    return value;
}