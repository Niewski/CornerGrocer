#ifndef ITEM_LIST_H
#define ITEM_LIST_H

#include "Util.h"
#include <vector>
#include <string>
#include <unordered_map>

class ItemList
{
    public:
        void loadFrequencies(const std::string& filename);
        void writeBackupFile(const std::string& filename) const;
        int getFrequency(const std::string& itemName) const;
        void displayAllItems() const;
        void displayHistogram() const;

    private:
        std::unordered_map<std::string, int, CaseInsensitiveHash, CaseInsensitiveEqual> m_items;
};

#endif 

