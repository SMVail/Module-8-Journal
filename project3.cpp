// Samantha Vaillancourt
/*
/* Project 3: Grocery List Corner Grocer
/* Date: 06/22/2025
/*
*/


#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// This class is used to store the frequency of items in a grocery list.
class grocer {
    private: map<string, int> itemFrequency;

    public:
    void readFromFile(const string& filename) {
        ifstream inputFile;
        inputFile.open(filename);

        if (inputFile.is_open()) {
            string item;
            while (inputFile >> item) {
                itemFrequency[item]++;
            }
            inputFile.close();
        } else {
            cerr << "Error opening file: " << filename << endl;
        }

        // Backup the data in the .dat file.
        ofstream backupFile("frequency.dat");
        if (backupFile.is_open()) {
            for (const auto& pair : itemFrequency) {
                backupFile << pair.first << " " << pair.second << endl;
            }
            backupFile.close();
        }
        else {
            cerr << "Error creating backup file." << endl;
        }

    }

    // Display the frequency of each item.
    int displayItemFrequency(const string& item) const {
        auto it = itemFrequency.find(item);
        if (it != itemFrequency.end()) {
            return it->second;
        } else {
            return 0; // Item not found
        }
    }

    // Display all items and their frequencies.
    void displayAllItems() const {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }

    // Display a histogram of item frequencies.
    void displayHistogram() const {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << ": ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
    // Backup the data in a .dat file.
    void backupData(const string& filename) const {
        ofstream backupFile(filename);
        if (backupFile.is_open()) {
            for (const auto& pair : itemFrequency) {
                backupFile << pair.first << " " << pair.second << endl;
            }
            backupFile.close();
        } else {
            cerr << "Error creating backup file." << endl;
        }
    }

    // Display menu options.
    void displayMenu() const {
        cout << "Menu Options:" << endl;
        cout << "1. Search item: " << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display histogram of item frequencies" << endl;
        cout << "4. Exit" << endl;
    }
}; // <-- Ensure this semicolon is present after the class definition
    
// Main function to run the program.
int main() {
    grocer groceryList;
    groceryList.readFromFile("CS210_Project_Three_Input_File.txt");
    int choice;
    string item;

    do {
        groceryList.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            // Search for an item and display its frequency.
            case 1:
                cout << "Enter item to search: ";
                cin >> item;
                cout << "Frequency of " << item << ": " 
                     << groceryList.displayItemFrequency(item) << endl;
                break;
            // Display all item frequencies.
            case 2:
                cout << "Displaying all item frequencies:" << endl;
                groceryList.displayAllItems();
                break;
            // Display histogram of item frequencies.
            case 3:
                cout << "Displaying histogram of item frequencies:" << endl;
                groceryList.displayHistogram();
                break;
            // Exit the program.
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    while (choice != 4);
    return 0;
}
