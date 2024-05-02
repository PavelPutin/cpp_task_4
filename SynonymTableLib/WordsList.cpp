//
// Created by RobotComp.ru on 02.05.2024.
//

#include "WordsList.h"
WordsList::WordsList(std::vector<std::string> *init) {
    if (init == nullptr) {
        throw new std::invalid_argument("nullptr isn't allowed as init");
    }
    words = init;
}

WordsList::~WordsList() {
    delete words;
}

WordsList* WordsList::getSynonimizedList(SynonymTable *synonymTable) {
    std::vector<std::string> *synonimizedWords = new std::vector<std::string>();

    std::for_each(
            this->begin(),
            this->end(),
            [&synonimizedWords, &synonymTable](std::string word) {
                synonimizedWords->push_back(
                        synonymTable->getRandomSynonymFor(word)
                        );
            }
            );

    return new WordsList(synonimizedWords);
}

WordsList::iterator WordsList::begin() {
    return words->begin();
}

WordsList::iterator WordsList::end() {
    return words->end();
}
