#include <iostream>
#include <fstream>
#include <string>
#include <map>

// Function to read the input file and store item frequencies in a map
std::map<std::string, int> readInputFile() {
    std::map<std::string, int> itemFrequency;
    std::ifstream file("CS210_Project_Three_Input_File.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file: CS210_Project_Three_Input_File.txt" << std::endl;
        return itemFrequency;
    }

    std::string item;
    while (file >> item) {
        ++itemFrequency[item];
    }

    file.close();
    return itemFrequency;
}

// Function to get the frequency of a specific item
void getItemFrequency(const std::map<std::string, int>& itemFrequency) {
    std::string item;
    std::cout << "Enter the item you wish to look for: ";
    std::cin >> item;

    auto it = itemFrequency.find(item);
    if (it != itemFrequency.end()) {
        std::cout << "The frequency of " << item << " is " << it->second << std::endl;
    }
    else {
        std::cout << "Item not found." << std::endl;
    }
}

// Function to print all items with their frequencies
void printAllFrequencies(const std::map<std::string, int>& itemFrequency) {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

// Function to print a histogram of item frequencies
void printHistogram(const std::map<std::string, int>& itemFrequency) {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << ": ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

// Main function to display the menu and process user choices
int main() {
    auto itemFrequency = readInputFile();

    if (itemFrequency.empty()) {
        std::cerr << "No data to process. Exiting." << std::endl;
        return 1;
    }

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Look up item frequency\n";
        std::cout << "2. Print all item frequencies\n";
        std::cout << "3. Print histogram of item frequencies\n";
        std::cout << "4. Exit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            getItemFrequency(itemFrequency);
            break;
        case 2:
            printAllFrequencies(itemFrequency);
            break;
        case 3:
            printHistogram(itemFrequency);
            break;
        case 4:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}