//
// Created by RobotComp.ru on 04.05.2024.
//

#ifndef CPP_TASK4_SYNONYMTABLEFILEREADER_H
#define CPP_TASK4_SYNONYMTABLEFILEREADER_H


#include "SynonymTable.h"
#include "FileReader.h"

class SynonymTableFileReader : public FileReader<SynonymTable> {
public:
    SynonymTableFileReader(std::string filePath) : FileReader<SynonymTable>(filePath) {};
protected:
    SynonymTable* parse(std::ifstream &in) override;
};


#endif //CPP_TASK4_SYNONYMTABLEFILEREADER_H
