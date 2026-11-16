#include <iostream>
#include <string>
#include "StringBinaryTree.h"
using namespace std;

int main() {
    StringBinaryTree tree;
    
    // Testing the string modifications
    tree.insertNode("apple");
    tree.insertNode("zebra");
    tree.insertNode("banana");
    
    cout << "Testing string BST in-order:\n";
    tree.displayInOrder();
    
    return 0;
}