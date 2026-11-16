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
        cout << "Tree successfully built from codes.txt!\n\n";
    }

    cout << "Displaying BST records (First few will be numbers/capitals):\n";
    tree.displayInOrder();

    return 0;
}