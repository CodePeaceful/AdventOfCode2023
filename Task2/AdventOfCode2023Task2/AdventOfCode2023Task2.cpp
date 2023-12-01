#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string>* getInput(std::string filePath);
int solve(std::vector<std::string>* lines);
int forewardSearch(std::string line, int index);
bool checkSubstringForeward(std::string line, int index, std::string substring);
int backwardSearch(std::string line, int index);
bool checkSubstringBackward(std::string line, int index, std::string substring);

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
    for (std::string line : *lines) {
        int first = 0;
        int second = 0;
        for (int i = 0; i < line.size(); i++) {
            if (first = forewardSearch(line, i)) {
                break;
            }
        }
        for (int i = line.size() - 1; i >= 0; i--) {
            if (second = backwardSearch(line, i)) {
                break;
            }
        }
        sum += (10 * first + second);
    }
    delete lines;
    return sum;
}

int forewardSearch(std::string line, int index) {
    char c = line.at(index);
    switch (c)
    {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return c - '0';
    case 'o':
        if (checkSubstringForeward(line, index, "one")) {
            return 1;
        }
        return 0;
    case 't':
        if (checkSubstringForeward(line, index, "two")) {
            return 2;
        }
        if (checkSubstringForeward(line, index, "three")) {
            return 3;
        }
        return 0;
    case 'f':
        if (checkSubstringForeward(line, index, "four")) {
            return 4;
        }
        if (checkSubstringForeward(line, index, "five")) {
            return 5;
        }
        return 0;
    case 's':
        if (checkSubstringForeward(line, index, "six")) {
            return 6;
        }
        if (checkSubstringForeward(line, index, "seven")) {
            return 7;
        }
        return 0;
    case 'e':
        if (checkSubstringForeward(line, index, "eight")) {
            return 8;
        }
        return 0;
    case 'n':
        if (checkSubstringForeward(line, index, "nine")) {
            return 9;
        }
        return 0;
    default:
        return 0;
    }
}

int backwardSearch(std::string line, int index) {
    char c = line.at(index);
    switch (c)
    {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return c - '0';
    case 'e':
        if (checkSubstringBackward(line, index, "one")) {
            return 1;
        }
        if (checkSubstringBackward(line, index, "three")) {
            return 3;
        }
        if (checkSubstringBackward(line, index, "five")) {
            return 5;
        }
        if (checkSubstringBackward(line, index, "nine")) {
            return 9;
        }
        return 0;
    case 'o':
        if (checkSubstringBackward(line, index, "two")) {
            return 2;
        }
        return 0;
    case 'r':
        if (checkSubstringBackward(line, index, "four")) {
            return 4;
        }
        return 0;
    case 'x':
        if (checkSubstringBackward(line, index, "six")) {
            return 6;
        }
        return 0;
    case 't':
        if (checkSubstringBackward(line, index, "eight")) {
            return 8;
        }
        return 0;
    case 'n':
        if (checkSubstringBackward(line, index, "seven")) {
            return 7;
        }
        return 0;
    default:
        return 0;
    }
}

bool checkSubstringForeward(std::string line, int index, std::string substring) {
    for (int i = 0; i < substring.size(); i++) {
        if (substring.at(i) != line.at(index + i)) {
            return false;
        }
    }
    return true;
}

bool checkSubstringBackward(std::string line, int index, std::string substring) {
    for (int i = substring.size() - 1; i >= 0; i--) {
        if (substring.at(i) != line.at(index + i - (substring.size() -1))) {
            return false;
        }
    }
    return true;
}