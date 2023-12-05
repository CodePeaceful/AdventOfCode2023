#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <array>

std::vector<std::string>* getInput(std::string filePath);
int solve(std::vector<std::string>* lines);
std::vector<std::string> split(std::string line, char seperator);
void buildMaps(std::vector<std::string>* lines); 
std::vector<std::string> getMapData(std::vector<std::string>* lines, int mapId);

std::array<std::map<int, int>, 7> maps;

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
    int min = 2147483647;
    std::vector<std::string> seedStrings = split(split(lines->at(0), ':')[1], ' ');
    std::vector<int> seeds;
    for (std::string seedString : seedStrings) {
        seeds.push_back(std::stoi(seedString));
    }
    buildMaps(lines);

    for (int seed : seeds) {
        int value = seed;
        for (std::map<int, int> map : maps) {
            if (map.count(value)) {
                value = map[value];
            }
        }
        if (value < min) {
            min = value;
        }
    }

    delete lines;
    return min;
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

void buildMaps(std::vector<std::string>* lines) {
    int mapId = 0;
    for (std::map<int,int> map : maps) {
        std::vector<std::string> mapData = getMapData(lines, mapId);

        for (std::string line : mapData) {
            int key, value, range;
            std::vector<std::string> strings = split(line, ' ');
            key = std::stoi(strings[0]);
            value = std::stoi(strings[1]);
            range = std::stoi(strings[2]);
            for (int i = 0; i < range; i++) {
                map.insert(std::pair<int,int>(key + i, value + i));
            }
        }
        mapId++;
    }
}

std::vector<std::string> getMapData(std::vector<std::string>* lines, int mapId) {
    std::vector<std::string> data;
    int todos = mapId + 1;
    int lineId = 0;
    while (todos > 0)
    {
        if (lines->at(lineId) == "") {
            todos--;
        }
        lineId++;
    }
    lineId++;
    while (lineId != lines->size() && lines->at(lineId) != "")
    {
        data.push_back(lines->at(lineId));
        lineId++;
    }
    return data;
}