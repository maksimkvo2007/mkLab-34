#include <iostream>
#include <fstream>
#include <string>
#include "StringBinaryTree.h"
using namespace std;

int main() {
    StringBinaryTree tree;
    ifstream file("codes.txt");
    string code;

    if (file.is_open()) {
        while (file >> code) {
            tree.insertNode(code);
        }
        file.close();
    }

    int choice = 0;
    string inputCode;

    while (choice != 6) {
        cout << "\n1. Add a record\n2. Delete a record\n3. Search for a record\n";
        cout << "4. Modify a record\n5. Display all records\n6. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter string code to add: ";
            cin >> inputCode;
            tree.insertNode(inputCode);
            cout << "Record Added.\n";
        } 
        else if (choice == 5) {
            cout << "\n--- All Records ---\n";
            tree.displayInOrder();
        } 
        else if (choice == 6) {
            cout << "Exiting program...\n";
        }
    }

    return 0;
}