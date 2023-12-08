#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <array>

std::vector<std::string>* getInput(std::string filePath);
int solve(std::vector<std::string>* lines);
std::vector<std::string> split(std::string line, char seperator);

int main() {
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
    std::string instruction = lines->at(0);
    std::map<std::string, std::pair<std::string, std::string>> nodes;
    for (int i = 2; i < lines->size(); i++) {
        std::vector<std::string> splitString = split(lines->at(i), ' ');
        std::array<std::string, 3> mapData;
        mapData[0] = splitString[0];
        mapData[1] = split(split(splitString[2], ',')[0], '(')[0];
        mapData[2] = split(splitString[3], ')')[0];
        nodes.insert(std::make_pair(mapData[0], std::make_pair(mapData[1], mapData[2])));
    }
    std::string value = "AAA";
    while ("ZZZ" != value)
    {
        if (instruction[sum % instruction.size()] == 'L') {
            value = std::get<0>(nodes[value]);
        }
        else {
            value = std::get<1>(nodes[value]);
        }
        sum++;
    }

    return sum;
}

std::vector<std::string> split(std::string line, char seperator) {
    std::vector<std::string> splitString;
    std::string stringPart;
    std::stringstream input(line);
    while (std::getline(input, stringPart, seperator))
    {
        if (stringPart != "") {
            splitString.push_back(stringPart);
        }
    }
    return splitString;
}