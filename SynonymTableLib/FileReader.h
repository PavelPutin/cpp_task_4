//
// Created by RobotComp.ru on 03.05.2024.
//

#ifndef CPP_TASK4_FILEREADER_H
#define CPP_TASK4_FILEREADER_H

#include <string>
#include <fstream>

template <class Type> class FileReader {
public:
    FileReader(std::string filePath);
    ~FileReader() = default;

    Type* read(Type *reader(const std::ifstream &in));
    const std::string& getFilePath();

private:
    std::string filePath;
};


template <class Type>
FileReader<Type>::FileReader(std::string filePath) : filePath(filePath) {}

template <class Type>
Type* FileReader<Type>::read(Type *reader(const std::ifstream &in))
{
    std::ifstream in(filePath);

    if (in.is_open())
    {
        Type *result = reader(in);
        in.close();
        return result;
    }
    else {
        in.close();
        throw std::invalid_argument(std::sprintf("can't open file %s", filePath.c_str()));
    }
}

template <class Type>
const std::string& FileReader<Type>::getFilePath()
{
    return filePath;
}

#endif //CPP_TASK4_FILEREADER_H
