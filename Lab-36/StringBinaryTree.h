// Specification file for the StringBinaryTree class
#ifndef STRINGBINARYTREE_H
#define STRINGBINARYTREE_H
#include <string>

// The StringBinaryTree class manages a binary tree of strings.
class StringBinaryTree {
private:
   struct TreeNode {
      std::string value;           
      TreeNode *left;    
      TreeNode *right;   
   };

   TreeNode *root;      

   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(std::string, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;

public:
   StringBinaryTree()     { root = nullptr; }
   ~StringBinaryTree()    { destroySubTree(root); }

   void insertNode(std::string);
   bool searchNode(std::string);
   void remove(std::string);

   void displayInOrder() const     {  displayInOrder(root); }
   void displayPreOrder() const    {  displayPreOrder(root); }
   void displayPostOrder() const   {  displayPostOrder(root); }
};

// Implementation file for the StringBinaryTree class
#include <iostream>
using namespace std;

void StringBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
   if (!nodePtr)
      nodePtr = newNode;                  
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     
   else 
      insert(nodePtr->right, newNode);    
}
                 
void StringBinaryTree::insertNode(string code) {
   TreeNode *newNode;      

   newNode = new TreeNode;
   newNode->value = code;
   newNode->left = newNode->right = nullptr;
   
   insert(root, newNode);
}
               
void StringBinaryTree::destroySubTree(TreeNode *nodePtr) {
   if (nodePtr) {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
                    
bool StringBinaryTree::searchNode(string code) {
   TreeNode *nodePtr = root;

   while (nodePtr)    {
      if (nodePtr->value == code)
         return true;
      else if (code < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

void StringBinaryTree::remove(string code) {
   deleteNode(code, root);
}
             
void StringBinaryTree::deleteNode(string code, TreeNode *&nodePtr) {
   if (code < nodePtr->value)
      deleteNode(code, nodePtr->left);
   else if (code > nodePtr->value)
      deleteNode(code, nodePtr->right);
   else
      makeDeletion(nodePtr);
}
    
void StringBinaryTree::makeDeletion(TreeNode *&nodePtr) {
   TreeNode *tempNodePtr;

   if (!nodePtr)
      cout << "Cannot delete empty node.\n";
   else if (!nodePtr->right) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   
      delete tempNodePtr;
   } else if (!nodePtr->left) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  
      delete tempNodePtr;
   }
   else {
      tempNodePtr = nodePtr->right;
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

void StringBinaryTree::displayInOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

void StringBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

void StringBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}
#endif