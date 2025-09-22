#pragma once
/**
 *   Program Example No. 12 - Traverses a binary tree RECURSIVELY.
 *
 *   Example showing traversal of a binary tree using recursion.
 *   It demonstrates how simply the tree can be traversed
 *   in preorder, inorder, and postorder ways.
 *
 *   @file     EKS_12_RekursivTreTraversering.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>                  //  cout
#include <iomanip>                   //  setw
using namespace std;


/**
 *  Node (with ID/key/data and left/right pointers to the node’s children).
 */
struct Node {
    char ID;
    Node* left, * right;              //  Initializing constructor:
    Node(char id) { ID = id;  left = right = nullptr; }
};


void  visit(const Node* node);
Node* buildTree();
void  traverseInorder(Node* node);
void  traversePostorder(Node* node);
void  traversePreorder(Node* node);

