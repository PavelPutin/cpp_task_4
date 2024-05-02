//
// Created by RobotComp.ru on 30.03.2024.
//

#include "SynonymTable.h"

SynonymTable::SynonymTable(std::map<std::string, std::vector<std::string>> *init) {
    synonyms = init;
}

SynonymTable::~SynonymTable() {
    delete synonyms;
}
//#include <iostream>
std::string SynonymTable::getRandomSynonymFor(const std::string &word) {
    std::vector synonym = (*synonyms)[word];
//    for (auto &v : synonym)
//        std::cout << v << " ";
//    std::cout << std::endl;
    std::vector<std::string> out;
    std::sample(
            synonym.begin(),
            synonym.end(),
            std::back_inserter(out),
            1,
            std::mt19937{std::random_device{}()}
            );
    return out.at(0);
}