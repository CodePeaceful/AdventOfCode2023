#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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
    std::vector<std::string> lineTimes = split(split(lines->at(0), ':').at(1), ' ');
    std::vector<std::string> lineDistances = split(split(lines->at(1), ':').at(1), ' ');
    std::string timeString = "";
    std::string distaceString = "";
    for (std::string s : lineTimes) {
        timeString += s;
    }
    for (std::string s : lineDistances) {
        distaceString += s;
    }
    long long time = std::stoll(timeString);
    long long distance = std::stoll(distaceString);
    for (int j = 0; j < time; j++) {
        if ((time - j) * j > distance) {
            sum++;
        }
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