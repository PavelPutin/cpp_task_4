//
// Created by RobotComp.ru on 03.05.2024.
//

#include "gtest/gtest.h"
#include "WordsList.h"
#include "gmock/gmock-matchers.h"

class WordsListFixture : public ::testing::Test {
protected:
    void SetUp() override {
        std::vector<std::string> *init = new std::vector<std::string>();
        init->emplace_back("ведро");
        init->emplace_back("девайс");

        wordsList = new WordsList(init);

        auto initMap = new std::map<std::string, std::vector<std::string>>();
        initMap->insert({"ведро", std::vector<std::string>{"бадья", "тара"}});
        initMap->insert({"бадья", std::vector<std::string>{"ведро", "тара"}});
        initMap->insert({"тара", std::vector<std::string>{"бадья", "ведро"}});

        initMap->insert({"девайс", std::vector<std::string>{"гаджет"}});
        initMap->insert({"гаджет", std::vector<std::string>{"девайс"}});
        synonymTable = new SynonymTable(initMap);
    }

    void TearDown() override {
        delete wordsList;
    }

    WordsList *wordsList;
    SynonymTable *synonymTable;
};

TEST_F(WordsListFixture, iterateOverWords) {
    const std::string words[] = {"ведро", "девайс"};
    int i = 0;
    std::for_each(
            wordsList->begin(),
            wordsList->end(),
            [&words, &i](const std::string &word) {
                EXPECT_EQ(words[i++], word);
            }
    );
}

TEST_F(WordsListFixture, synonymizingWords) {
    std::unique_ptr<WordsList> synonymized = std::unique_ptr<WordsList>(wordsList->getSynonimizedList(synonymTable));
    WordsList::iterator iterator = synonymized->begin();
    EXPECT_THAT(
            iterator->c_str(),
            ::testing::AnyOf(
                    ::testing::Eq<std::string>("бадья"),
                    ::testing::Eq<std::string>("тара")
            )
    );
    iterator++;
    EXPECT_THAT(
            iterator->c_str(),
            ::testing::AnyOf(::testing::Eq<std::string>("гаджет"))
    );
}
