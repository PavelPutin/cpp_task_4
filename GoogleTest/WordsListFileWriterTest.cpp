#include <gtest/gtest.h>
#include "WordsList.h"
#include "WordsListFileWriter.h"
#include "FileReader.h"
#include "WordsListFileReader.h"

//
// Created by RobotComp.ru on 05.05.2024.
//
class WordsListFileWriterFixture : public ::testing::Test {
protected:
    void SetUp() override {
        std::vector<std::string> *init = new std::vector<std::string>();
        init->emplace_back("ведро");
        init->emplace_back("девайс");

        wordsList = new WordsList(init);

        wordsListFileWriter = new WordsListFileWriter("resources/test_words_list_writer.txt", wordsList);
        fileReader = new WordsListFileReader("resources/test_words_list_writer.txt");
    }

    void TearDown() override {
        delete wordsList;
        delete wordsListFileWriter;
        delete fileReader;
    }

    WordsList *wordsList;
    WordsListFileWriter *wordsListFileWriter;
    FileReader<WordsList>* fileReader;
};

TEST_F(WordsListFileWriterFixture, getFilePathTest)
{
    EXPECT_EQ("resources/test_words_list_writer.txt", wordsListFileWriter->getFilePath());
}

TEST_F(WordsListFileWriterFixture, parseTest)
{
    wordsListFileWriter->write();

    WordsList* parsed = fileReader->read();
    WordsList::iterator iterator = parsed->begin();
    EXPECT_EQ(*iterator, "ведро");
    iterator++;
    EXPECT_EQ(*iterator, "девайс");
}