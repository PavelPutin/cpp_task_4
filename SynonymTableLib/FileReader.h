//
// Created by RobotComp.ru on 03.05.2024.
//

#ifndef CPP_TASK4_FILEREADER_H
#define CPP_TASK4_FILEREADER_H

#include <string>
#include <fstream>
#include <utility>

template <class Type> class FileReader {
public:
    FileReader(std::string filePath);
    virtual ~FileReader() = default;

    Type* read();
    const std::string& getFilePath();
protected:
    virtual Type* parse(std::ifstream &in) = 0;
private:
    std::string filePath;
};


template <class Type>
FileReader<Type>::FileReader(std::string filePath) : filePath(std::move(filePath)) {}

template <class Type>
Type* FileReader<Type>::read()
{
    std::ifstream in(filePath);

    if (in.is_open())
    {
        Type *result = parse(in);
        in.close();
        return result;
    }
    else {
        in.close();
        throw std::invalid_argument("can't open file " + filePath);
    }
}

template <class Type>
const std::string& FileReader<Type>::getFilePath()
{
    return filePath;
}

#endif //CPP_TASK4_FILEREADER_H
