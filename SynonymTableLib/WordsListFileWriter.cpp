//
// Created by RobotComp.ru on 05.05.2024.
//

#include "WordsListFileWriter.h"

#include <utility>
#include <fstream>

WordsListFileWriter::WordsListFileWriter(std::string filePath, WordsList *words) : filePath(std::move(filePath)), words(words) {}

void WordsListFileWriter::write() {
    std::ofstream out;
    out.open(filePath);

    if (out.is_open())
    {
        parse(out);
        out.close();
    }
    else {
        out.close();
        throw std::invalid_argument("can't open file " + filePath);
    }
}

void WordsListFileWriter::parse(std::ofstream &out) {
    std::for_each(words->begin(), words->end(), [&out](std::string &word) {
        out << word << std::endl;
    });
}

const std::string& WordsListFileWriter::getFilePath()
{
    return filePath;
}
