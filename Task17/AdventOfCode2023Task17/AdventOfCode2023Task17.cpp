#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::string, std::vector;

vector<string> getInput(string filePath);
int solve(vector<string> lines);
vector<string> split(string line, char seperator);

int main() {
    std::cout << solve(getInput(".\\input.txt"));
    string get;
    std::cin >> get;
}

vector<string> getInput(string filePath) {
    std::fstream input;
    input.open(filePath, std::ios::in);
    vector<string> file;
    string line;
    while (std::getline(input, line)) {
        file.push_back(line);
    }
    input.close();
    return file;
}

int solve(vector<string> lines) {
    int sum = 0;
    
    for (string line : lines) {
        vector<vector<int>*> workGroup;
        vector<string> splitLine = split(line, ' ');
        vector<int>* dataLine = new vector<int>;
        for (string dataString : splitLine) {
            dataLine->push_back(std::stoi(dataString));
        }
        workGroup.push_back(dataLine);
        bool hadDifference = true;
        for (int i = 0; hadDifference; i++) {
            vector<int>* differences = new vector<int>;
            hadDifference = false;
            for (int j = 0; j < workGroup[i]->size() - 1; j++) {
                differences->push_back(workGroup[i]->at(j + 1) - workGroup[i]->at(j));
                if (differences->at(j))
                    hadDifference = true;
            }
            workGroup.push_back(differences);
        }
        workGroup[workGroup.size() - 1]->push_back(0);
        int value = 0;
        for (int i = workGroup.size() - 1; i > 0; i--) {
            vector<int>* change = workGroup[i];
            vector<int>* valueList = workGroup[i - 1];
            value = change->at(change->size() - 1) + valueList->at(valueList->size() - 1);
            valueList->push_back(value);

            delete change;
        }
        delete workGroup[0];
        sum += value;
    }

    return sum;
}

vector<string> split(string line, char seperator) {
    vector<string> splitString;
    string stringPart;
    std::stringstream input(line);
    while (std::getline(input, stringPart, seperator))
    {
        if (stringPart != "") {
            splitString.push_back(stringPart);
        }
    }
    return splitString;
}