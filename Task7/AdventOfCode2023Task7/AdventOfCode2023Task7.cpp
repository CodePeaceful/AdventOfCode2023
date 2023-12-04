#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

std::vector<std::string>* getInput(std::string filePath);
int solve(std::vector<std::string>* lines);
std::vector<std::string> split(std::string line, char seperator);

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
        std::vector<std::string> lineNameSplit = split(line, ':');
        std::vector<std::string> partSplit = split(lineNameSplit[1], '|');
        std::vector<std::string> part1 = split(partSplit[0], ' ');
        std::vector<std::string> part2 = split(partSplit[1], ' ');

        int same = 0;

        for (std::string value : part1) {
            for (std::string winner : part2) {
                if (value == winner) {
                    same++;
                }
            }
        }

        if ( same > 0) {
            sum += (int)std::pow(2, same - 1);
        }
    }

    delete lines;
    return sum;
}

std::vector<std::string> split(std::string line, char seperator) {
    std::stringstream fullString(line);
    std::vector<std::string> segList;
    std::string segment;

    while (std::getline(fullString, segment, seperator))
    {
        if ("" != segment) {
            segList.push_back(segment);
        }
    }

    return segList;
}