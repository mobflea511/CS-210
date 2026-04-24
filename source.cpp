#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Class to handle grocery tracking
class GroceryTracker {
private:
    map<string, int> itemFrequency; // Stores item counts

public:
    // Constructor: reads file and builds frequency map
    GroceryTracker() {
        ifstream inFile("CS210_Project_Three_Input_File.txt");
        string item;

        while (inFile >> item) {
            itemFrequency[item]++;
        }

        inFile.close();

        // Create backup file automatically
        createBackupFile();
    }

    // Menu Option 1: Search item frequency
    void searchItem() {
        string item;
        cout << "Enter item to search: ";
        cin >> item;

        if (itemFrequency.count(item)) {
            cout << item << " appears " << itemFrequency[item] << " times.\n";
        }
        else {
            cout << item << " appears 0 times.\n";
        }
    }

    // Menu Option 2: Print all frequencies
    void printAllFrequencies() {
        for (auto const& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Menu Option 3: Print histogram
    void printHistogram() {
        for (auto const& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Create backup file
    void createBackupFile() {
        ofstream outFile("frequency.dat");

        for (auto const& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }

        outFile.close();
    }
};

// Function to display menu
void displayMenu() {
    cout << "\n===== Corner Grocer Menu =====\n";
    cout << "1. Search for an item\n";
    cout << "2. Display all item frequencies\n";
    cout << "3. Display histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    GroceryTracker tracker;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            tracker.searchItem();
            break;
        case 2:
            tracker.printAllFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
