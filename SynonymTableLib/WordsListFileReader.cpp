//
// Created by RobotComp.ru on 04.05.2024.
//

#include "WordsListFileReader.h"

#include <string>

WordsList* WordsListFileReader::parse(std::ifstream &in) {
    std::vector<std::string> *words = new std::vector<std::string>();

    for(std::string word; std::getline(in, word);) {
        words->push_back(word);
    }

    return new WordsList(words);
}