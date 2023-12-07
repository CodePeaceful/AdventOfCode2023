#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "CardSet.h"

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
    std::vector<std::pair<CardSet, int>> bets;
    for (std::string line : *lines) {
        std::vector<std::string> splitLine = split(line, ' ');
        bets.push_back(std::make_pair(CardSet(splitLine[0]), stoi(splitLine[1])));
    }
    std::sort(bets.begin(), bets.end());
    for (int i = 0; i < bets.size(); i++) {
        sum += ((1 + i) * bets[i].second);
    }


    delete lines;
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