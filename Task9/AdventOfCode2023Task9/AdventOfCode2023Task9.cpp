#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <array>

std::vector<std::string>* getInput(std::string filePath);
long long solve(std::vector<std::string>* lines);
std::vector<std::string> split(std::string line, char seperator);
std::array<std::map<long long, long long>, 7> buildMaps(std::vector<std::string>* lines);
std::vector<std::string> getMapData(std::vector<std::string>* lines, int mapId);



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
    int min = 2147483647;
    std::vector<std::string> seedStrings = split(split(lines->at(0), ':')[1], ' ');
    std::vector<long long> seeds;
    for (std::string seedString : seedStrings) {
        seeds.push_back(std::stoll(seedString));
    }
    std::array<std::map<long long, long long>, 7> maps = buildMaps(lines);

    for (long long seed : seeds) {
        long long value = seed;
        for (std::map<long long, long long> map : maps) {
            if (map.contains(value)) {
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

std::array<std::map<long long, long long>, 7> buildMaps(std::vector<std::string>* lines) {
    int mapId = 0;
    std::array<std::map<long long, long long>, 7> maps;
    for (int j = 0; j < maps.size(); j++) {
        std::vector<std::string> mapData = getMapData(lines, mapId);

        for (std::string line : mapData) {
            long long key, value, range;
            std::vector<std::string> strings = split(line, ' ');
            key = std::stoll(strings[1]);
            value = std::stoll(strings[0]);
            range = std::stoll(strings[2]);
            for (long long i = 0; i < range; i++) {
                maps[j].insert(std::pair<long long, long long>(key + i, value + i));
            }
        }
        mapId++;
    }
    return maps;
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