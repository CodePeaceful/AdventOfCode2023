#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string>* getInput(std::string filePath);
int solve(std::vector<std::string>* lines);

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
            char c = line.at(i);
            if (c >= '0' && c <= '9') {
                first = c - '0';
                break;
            }
        }
        for (int i = line.size() - 1; i >= 0; i--) {
            char c = line.at(i);
            if (c >= '0' && c <= '9') {
                second = c - '0';
                break;
            }
        }
        sum += (10 * first + second);
    }
    delete lines;
    return sum;
}

