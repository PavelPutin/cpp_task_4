//
// Created by RobotComp.ru on 04.05.2024.
//

#include "SynonymTableFileReader.h"
SynonymTable* SynonymTableFileReader::parse(std::ifstream &in) {
    auto initMap = new std::map<std::string, std::vector<std::string>>();


    for (std::string word, synonym; std::getline(in, word, ' ') && std::getline(in, synonym, '\n');) {
        if (initMap->count(word)) {
            initMap->find(word)->second.push_back(synonym);
        } else {
            initMap->insert({word, std::vector<std::string>{synonym}});
        }
    }

    return new SynonymTable(initMap);
}