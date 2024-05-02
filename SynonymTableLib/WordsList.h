//
// Created by RobotComp.ru on 02.05.2024.
//

#ifndef CPP_TASK4_WORDSLIST_H
#define CPP_TASK4_WORDSLIST_H

#include <string>
#include <iterator>
#include <vector>
#include "SynonymTable.h"

/// Это класс предназначен для удобного хранения списка слов и предоставляет метод для "синонимизации" хранимых слов
class WordsList {
public:
    typedef std::vector<std::string>::iterator iterator;
    WordsList(std::vector<std::string>* init);
    ~WordsList();

    WordsList* getSynonimizedList(SynonymTable* synonymTable);
    iterator begin();
    iterator end();

private:
    std::vector<std::string>* words;
};


#endif //CPP_TASK4_WORDSLIST_H
