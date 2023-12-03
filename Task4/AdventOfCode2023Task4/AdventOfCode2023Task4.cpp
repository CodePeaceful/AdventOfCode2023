#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int checkValue(std::string& line);

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

int checkValue(std::string& line)
{
    int spaceCounter = 0;
    int blue = 0;
    int red = 0;
    int green = 0;
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
                    if (number > blue) {
                        blue = number;
                    }
                    continue;
                }
                if (line.at(i + 1) == 'g') {
                    if (number > green) {
                        green = number;
                    }
                    continue;
                }
                if (line.at(i + 1) == 'r') {
                    if (number > red) {
                        red = number;
                    }
                    continue;
                }
            }
        }
    }
    return red * green * blue;
}

int solve(std::vector<std::string>* input) {
    int sum = 0;
    for (std::string line : *input) {
        sum += checkValue(line);
    }
    delete input;
    return sum;
}