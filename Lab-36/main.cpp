#include <iostream>
#include <fstream>
#include <string>
#include "StringBinaryTree.h"
using namespace std;

int main() {
    ifstream file("codes.txt");
    string code;

    if (file.is_open()) {
        cout << "Reading first few codes from file:\n";
        // Just reading 5 codes to test
        for(int i = 0; i < 5; i++) {
            file >> code;
            cout << code << endl;
        }
        file.close();
    } else {
        cout << "Error: Could not open codes.txt\n";
    }

    return 0;
}