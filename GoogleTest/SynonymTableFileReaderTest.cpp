//
// Created by RobotComp.ru on 04.05.2024.
//

//
// Created by RobotComp.ru on 03.05.2024.
//

#include "gtest/gtest.h"
#include "FileReader.h"
#include "SynonymTable.h"
#include "SynonymTableFileReader.h"
#include "gmock/gmock-matchers.h"

class SynonymTableFileReaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        fileReader = new SynonymTableFileReader("resources/test_synonyms_table.txt");
    }

    void TearDown() override {
        delete fileReader;
    }

    FileReader<SynonymTable>* fileReader;
};

TEST_F(SynonymTableFileReaderTest, getFilePathTest)
{
    std::cout << fileReader->getFilePath() << std::endl;
    EXPECT_EQ("resources/test_synonyms_table.txt", fileReader->getFilePath());
}

TEST_F(SynonymTableFileReaderTest, parseTest)
{
    SynonymTable* parsed = fileReader->read();
    EXPECT_EQ(parsed->getRandomSynonymFor("девайс"), "гаджет");
    EXPECT_EQ(parsed->getRandomSynonymFor("гаджет"), "девайс");
    EXPECT_THAT(
            parsed->getRandomSynonymFor("ведро"),
            ::testing::AnyOf(::testing::Eq("бадья"), ::testing::Eq("тара")));
    EXPECT_THAT(
            parsed->getRandomSynonymFor("бадья"),
            ::testing::AnyOf(::testing::Eq("ведро"), ::testing::Eq("тара")));
    EXPECT_THAT(
            parsed->getRandomSynonymFor("тара"),
            ::testing::AnyOf(::testing::Eq("бадья"), ::testing::Eq("ведро")));
}