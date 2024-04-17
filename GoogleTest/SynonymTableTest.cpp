//
// Created by RobotComp.ru on 30.03.2024.
//

#include "gtest/gtest.h"
#include "SynonymTable.h"

class SynonymTableFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        auto initMap = new std::map<std::string, std::vector<std::string>>();
        initMap->insert({"ведро", std::vector<std::string> {"бадья", "тара"}});
        initMap->insert({"бадья", std::vector<std::string> {"ведро", "тара"}});
        initMap->insert({"тара", std::vector<std::string> {"бадья", "ведро"}});

        initMap->insert({"девайс", std::vector<std::string> {"гаджет"}});
        initMap->insert({"гаджет", std::vector<std::string> {"девайс"}});
        synonymTable = new SynonymTable(initMap);
    }

    void TearDown() override
    {
        delete synonymTable;
    }

    SynonymTable *synonymTable;
};

TEST_F(SynonymTableFixture, getValue)
{
    std::string result = synonymTable->getRandomSynonymFor("девайс");
    EXPECT_EQ(result, "гаджет");
}

#include <iostream>

TEST_F(SynonymTableFixture, valueGettingRandomly)
{
    int iterationNumber = 1000000;
    std::map<std::string, int> synonymsCounter
    {
            {"бадья", 0},
            {"тара", 0}
    };

    for (int i = 0; i < iterationNumber; i++)
    {
        std::string result = synonymTable->getRandomSynonymFor("ведро");
        synonymsCounter[result]++;
    }

    std::map<std::string, double> synonymsProbability
            {
                    {"бадья", (double)synonymsCounter["бадья"] / iterationNumber},
                    {"тара", (double)synonymsCounter["тара"] / iterationNumber}
            };

    EXPECT_NEAR(synonymsProbability["бадья"], 0.5, 1e-3);
    EXPECT_NEAR(synonymsProbability["тара"], 0.5, 1e-3);
}
