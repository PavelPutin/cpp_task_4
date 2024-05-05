//
// Created by RobotComp.ru on 05.05.2024.
//

#ifndef CPP_TASK4_WORDSLISTFILEWRITER_H
#define CPP_TASK4_WORDSLISTFILEWRITER_H


#include "WordsList.h"

class WordsListFileWriter {
public:
    WordsListFileWriter(std::string filePath, WordsList *words);
    virtual ~WordsListFileWriter() = default;

    void write();
    const std::string& getFilePath();
protected:
    void parse(std::ofstream &out);
private:
    std::string filePath;
    WordsList *words;
};


#endif //CPP_TASK4_WORDSLISTFILEWRITER_H
