//
// Created by RobotComp.ru on 03.05.2024.
//

#include "gtest/gtest.h"
#include "FileReader.h"
#include "WordsList.h"
#include "WordsListFileReader.h"

class WordsListFileReaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        fileReader = new WordsListFileReader("resources/test_words_list.txt");
    }

    void TearDown() override {
        delete fileReader;
    }

    FileReader<WordsList>* fileReader;
};

TEST_F(WordsListFileReaderTest, getFilePathTest)
{
    std::cout << fileReader->getFilePath() << std::endl;
    EXPECT_EQ("resources/test_words_list.txt", fileReader->getFilePath());
}

TEST_F(WordsListFileReaderTest, parseTest)
{
    WordsList* parsed = fileReader->read();
    WordsList::iterator iterator = parsed->begin();
    EXPECT_EQ(*iterator, "ведро");
    iterator++;
    EXPECT_EQ(*iterator, "девайс");
}