/*
 * CornerGrocer.cpp
 *
 *  Date: 10/24/2024
 *  Author: Jacob Wisniewski
 */

#include "Menu.h"
#include "ItemList.h"
#include <iostream>

int main()
{
    try{
		// Load the frequencies from the input file and write them to a backup file
        auto itemList = std::make_unique<ItemList>();
        itemList->loadFrequencies("CS210_Project_Three_Input_File.txt");
        itemList->writeBackupFile("frequency.dat");

		// Display the menu
        auto menu = std::make_unique<Menu>();
        menu->displayMenu(*itemList);
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    std::cout << "\nThank you for using the Corner Grocer Inventory App. Goodbye!" << std::endl;
    return 0;
}