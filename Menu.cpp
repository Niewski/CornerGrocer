#include "Menu.h"
#include <iostream>
#include <iomanip>

void Menu::displayMenu(const ItemList& itemList) const {
	// Initialize the menu option
    MenuOption option = MenuOption::EXIT;
    int userChoice = 0;

    while (true) {
		// Display the menu options
        std::cout << MENU_PROMPT;
        std::cout << MENU_OPTIONS;

		// Get the user's choice
        if (!(std::cin >> userChoice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

		// Cast the user's choice to a MenuOption
        option = static_cast<MenuOption>(userChoice);

		// Perform the selected action
        switch (option) {
            case MenuOption::FIND_FREQUENCY:
                frequencySearch(itemList);
                break;
            case MenuOption::DISPLAY_FREQUENCIES:
                displayAllFrequencies(itemList);
                break;
            case MenuOption::DISPLAY_HISTOGRAM:
                displayHistogram(itemList);
                break;
            case MenuOption::EXIT:
                std::cout << "Exiting program." << std::endl;
                return;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }
    }
}

void Menu::frequencySearch(const ItemList& itemList) const {
    std::string t_item;
    std::cout << "Enter item to find frequency: ";
    std::cin >> t_item;

    int frequency = itemList.getFrequency(t_item);
    if (frequency > 0) {
        std::cout << "Frequency of " << t_item << ": " << frequency << std::endl;
    }
    else {
        std::cout << t_item << " not found in the data." << std::endl;
    }
}

void Menu::displayAllFrequencies(const ItemList& itemList) const {
    itemList.displayAllItems();
}

void Menu::displayHistogram(const ItemList& itemList) const {
    itemList.displayHistogram();
}