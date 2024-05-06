//
// Created by RobotComp.ru on 06.05.2024.
//

#include "SynonymTableToStandardItemModelConverter.h"

SynonymTableToStandardItemModelConverter::SynonymTableToStandardItemModelConverter(QStandardItemModel *model,
                                                                                   SynonymTable *synonyms)
                                                                                   : model(model), synonyms(synonyms) {}

void SynonymTableToStandardItemModelConverter::convert() {
    model->clear();
    QStandardItem *parentItem = model->invisibleRootItem();

    for (const auto& [word, synonymsList] : *synonyms->getValues()) {
        QStandardItem *item = new QStandardItem(QString(word.c_str()));
        parentItem->appendRow(item);

        std::for_each(synonymsList.begin(), synonymsList.end(), [item](const std::string &synonym){
            QStandardItem *child = new QStandardItem(QString(synonym.c_str()));
            item->appendRow(child);
        });
    }
}
