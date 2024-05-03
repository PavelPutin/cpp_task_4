//
// Created by RobotComp.ru on 03.05.2024.
//

#include "gtest/gtest.h"
#include "FileReader.h"
#include "WordsList.h"

class FileReaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        fileReader = new FileReader<WordsList>("GoogleTest/resources/test_words_list.txt");
    }

    void TearDown() override {
        delete fileReader;
    }

    FileReader<WordsList>* fileReader;
};

TEST_F(FileReaderTest, getFilePathTest)
{
    std::cout << fileReader->getFilePath() << std::endl;
    EXPECT_EQ("GoogleTest/resources/test_words_list.txt", fileReader->getFilePath());
}