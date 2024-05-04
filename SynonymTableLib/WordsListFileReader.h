//
// Created by RobotComp.ru on 04.05.2024.
//

#ifndef CPP_TASK4_WORDSLISTFILEREADER_H
#define CPP_TASK4_WORDSLISTFILEREADER_H


#include "WordsList.h"
#include "FileReader.h"

#include <utility>

class WordsListFileReader : public FileReader<WordsList> {
public:
    explicit WordsListFileReader(std::string filePath) : FileReader<WordsList>(std::move(filePath)) {};
protected:
    WordsList* parse(std::ifstream &in) override;
};


#endif //CPP_TASK4_WORDSLISTFILEREADER_H
