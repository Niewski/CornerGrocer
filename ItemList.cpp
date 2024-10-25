#include "ItemList.h"
#include <fstream>
#include <iostream>
#include <exception>
#include <unordered_map>
#include <iomanip>

void ItemList::loadFrequencies(const std::string& filename) {
	// Open the file
    std::ifstream file(filename);
    if (!file) {
		// Throw an exception if the file cannot be opened (Main will catch it)
        throw std::ios_base::failure("Error opening file: " + filename);
    }

	// Read the file and store the frequencies in a map
	// Map allows O(1) lookup time on our search
    std::string itemName;
    while (file >> itemName) {
        ++m_items[itemName];
    }
    file.close();
}

void ItemList::writeBackupFile(const std::string& filename) const {
    try {
		// Open the file
        std::ofstream backupFile(filename);
        if (!backupFile) {
            // Throw an exception if the file cannot be opened (Catch and continue)
            throw std::ios_base::failure("Error opening backup file: " + filename);
        }
		// Write the items to the file
        for (const auto& item : m_items) {
            backupFile << item.first << " " << item.second << std::endl;
        }
        backupFile.close();
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int ItemList::getFrequency(const std::string& itemName) const {
    // Convert the input to lowercase
    std::string lowerItem = toLowerCase(itemName);
	// Search for the item in the map
    auto it = m_items.find(itemName);
    if (it != m_items.end()) {
        return it->second;
    }
    return 0;
}

void ItemList::displayAllItems() const {
    std::cout << "Item Frequencies:\n";
    for (const auto& pair : m_items) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void ItemList::displayHistogram() const {
    std::cout << "Histogram of Item Frequencies:\n";
    for (const auto& pair : m_items) {
        std::cout << std::setw(10) << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
