#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <array>
#include <ranges>

std::vector<std::string>* getInput(std::string filePath);
long long solve(std::vector<std::string>* lines);
std::vector<std::string> split(std::string line, char seperator);
std::vector<std::string> endsWith(std::vector<std::string> input, char value);

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

long long solve(std::vector<std::string>* lines) {
    long long sum = 0;
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
    auto kv = std::views::keys(nodes);
    std::vector<std::string> keys{ kv.begin(), kv.end() };
    
    std::vector<std::string> workNodes = endsWith(keys, 'A');
    std::vector<std::string> zNodes = endsWith(workNodes, 'Z');
    while (zNodes.size() != workNodes.size())
    {
        if (instruction[sum % instruction.size()] == 'L') {
            for (int i = 0; i < workNodes.size(); i++) {
                workNodes[i] = std::get<0>(nodes[workNodes[i]]);
            }
        }
        else {
            for (int i = 0; i < workNodes.size(); i++) {
                workNodes[i] = std::get<1>(nodes[workNodes[i]]);
            }
        }
        sum++;
        zNodes = endsWith(workNodes, 'Z');
        /*for (auto s : zNodes) {
            std::cout << s << std::endl;
        }
        if (zNodes.size() > 0)
            std::cout << std::endl;*/
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

std::vector<std::string> endsWith(std::vector<std::string> input, char value)
{
    std::vector<std::string> output;
    for (std::string s : input) {
        if (s[s.size() - 1] == value) {
            output.push_back(s);
        }
    }
    return output;
}

