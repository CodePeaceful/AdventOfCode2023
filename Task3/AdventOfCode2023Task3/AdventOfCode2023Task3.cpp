#include <iostream>
#include <vector>
#include <fstream>
#include <string>

bool checkValue(std::string& line);

int solve(std::vector<std::string>*);
std::vector<std::string>* getInput(std::string filePath);

int main()
{
    std::cout << solve(getInput("input.txt"));
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

bool checkValue(std::string& line)
{
    int spaceCounter = 0;
    for (int i = 0; i < line.size(); i++) {
        
        if (' ' == line.at(i)) {
            spaceCounter++;
            if (spaceCounter % 2 && spaceCounter > 2) {
                int secondDidget = 0;
                if (line.at(i - 2) > '0' && line.at(i - 2) <= '9') {
                    secondDidget = line.at(i - 2) - '0';
                }
                int number = (line.at(i - 1) - '0') + 10 * secondDidget;
                if (line.at(i + 1) == 'b') {
                    if (number > 14) {
                        return false;
                    }
                    continue;
                }
                if (line.at(i + 1) == 'g') {
                    if (number > 13) {
                        return false;
                    }
                    continue;
                }
                if (line.at(i + 1) == 'r') {
                    if (number > 12) {
                        return false;
                    }
                    continue;
                }
            }
        }
    }
    return true;
}

int solve(std::vector<std::string>* input) {
    int sum = 0;
    int counter = 0;
    for (std::string line : *input) {
        counter++;
        if (checkValue(line)) {
            sum += counter;
        }
    }
    delete input;
    return sum;
}