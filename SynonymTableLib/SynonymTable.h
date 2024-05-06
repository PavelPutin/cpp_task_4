//
// Created by RobotComp.ru on 30.03.2024.
//

#ifndef UNTITLED_SYNONYMTABLE_H
#define UNTITLED_SYNONYMTABLE_H

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

class SynonymTable {
    friend class BaseSynonymTableConverter;
public:
    SynonymTable(std::map<std::string, std::vector<std::string>> *init);
    ~SynonymTable();

    std::string getRandomSynonymFor(const std::string &word);
    const std::map<std::string, std::vector<std::string>>* getValues();
private:
    std::map<std::string, std::vector<std::string>> *synonyms;
};


#endif //UNTITLED_SYNONYMTABLE_H
