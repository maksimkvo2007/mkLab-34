#include <iostream>
#include <fstream>
#include <string>
#include "StringBinaryTree.h"
using namespace std;

int main() {
    StringBinaryTree tree;
    
    // Look inside the Lab-36 folder for the file
    ifstream file("Lab-36/codes.txt");
    string code;

    // Build the tree
    if (file.is_open()) {
        while (file >> code) {
            tree.insertNode(code);
        }
        file.close();
    } else {
        cout << "Error opening codes.txt" << endl;
        return 1;
    }

    int choice = 0;
    string inputCode, newCode;

    // Full Interactive Menu
    while (choice != 6) {
        cout << "\n=== Record Manager ===\n";
        cout << "1. Add a record\n2. Delete a record\n3. Search for a record\n";
        cout << "4. Modify a record\n5. Display all records\n6. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter code to add: ";
            cin >> inputCode;
            tree.insertNode(inputCode);
            cout << "Record Added.\n";
        } 
        else if (choice == 2) {
            cout << "Enter code to delete: ";
            cin >> inputCode;
            if (tree.searchNode(inputCode)) {
                tree.remove(inputCode);
                cout << "Record Deleted.\n";
            } else {
                cout << "Error: Record not found.\n";
            }
        } 
        else if (choice == 3) {
            cout << "Enter code to search: ";
            cin >> inputCode;
            if (tree.searchNode(inputCode)) {
                cout << "Success: Record found in tree!\n";
            } else {
                cout << "Record not found.\n";
            }
        } 
        else if (choice == 4) {
            cout << "Enter old code to modify: ";
            cin >> inputCode;
            
            if (tree.searchNode(inputCode)) {
                tree.remove(inputCode); // Remove the old one
                cout << "Enter the new code: ";
                cin >> newCode;
                tree.insertNode(newCode); // Insert the new one
                cout << "Record Modified successfully.\n";
            } else {
                cout << "Error: Original record not found.\n";
            }
        } 
        else if (choice == 5) {
            cout << "\n--- All Records ---\n";
            tree.displayInOrder();
        } 
        else if (choice == 6) {
            cout << "Exiting program...\n";
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}