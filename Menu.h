#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "ItemList.h"

const std::string MENU_PROMPT = "\nMenu:\n";
const std::string MENU_OPTIONS = "1. Find frequency of an item\n2. Display all item frequencies\n3. Display histogram of item frequencies\n4. Exit\nSelect an option (1-4): ";

enum class MenuOption {
    FIND_FREQUENCY = 1,
    DISPLAY_FREQUENCIES,
    DISPLAY_HISTOGRAM,
    EXIT
};

class Menu {
public:
    void displayMenu(const ItemList& itemList) const;

private:
    void frequencySearch(const ItemList& itemList) const;
    void displayAllFrequencies(const ItemList& itemList) const;
    void displayHistogram(const ItemList& itemList) const;
};

#endif
