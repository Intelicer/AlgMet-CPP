#include <iostream>
/**
 *   Program example no. 15 - (Recursive) operations on trees - case 1.
 *
 *   Implementations for the tree operations.
 *
 *   For the program’s functionality see:  TreCase1.pdf
 *
 *   (This was problem no. 3 on the exam 2011-12-20 in IMT2021 - Algorithmic Methods)
 *
 *   @file     tree.cpp
 *   @author   Frode Haug, NTNU
 */

#include "../../include/TreCase.h"


using namespace std;

Node* root = nullptr;        ///<  Pointer to the tree’s root.

/**
 *  TASK A - Prints the path from 'root' to the rightmost leaf node.
 */
void printRightmostPath() {
    Node* node = root;               //  Start at the root.
    while (node) {                   //  As long as we haven’t reached the bottom:
        cout << node->ID << ' ';     //  Print the node’s ID.
        //  Go PRIMARILY RIGHT, otherwise
        node = (node->right) ? node->right : node->left; // go left.
    }
}

/**
 *  TASK B - Prints the path from 'root' down to the leaf node 'node'.
 *
 *  @param   node  -  The specific node whose path from the root should be printed
 */
void printPath(Node* node) {
    int  id = node->ID;               //  Store the sought leaf node’s ID.
    node = root;                      //  Start at the root.
    while (node) {                    //  As long as we haven’t reached the bottom:
        cout << node->ID << ' ';      //  Print the node’s ID (on the way down).
        //  Go left or right:
        node = (id < node->ID) ? node->left : node->right;
    }                                 //  Continue past duplicates – not yet at bottom!!!
}

/**
 *  TASK C - Prints the paths down to ALL leaf nodes.
 *
 *  @param   node  -  Current node to check whether it is a leaf
 */
void printAllLeafPaths(Node* node) {
    if (node) {                        //  Leaf node – print the path down to it:
        if (!node->left && !node->right) {
            printPath(node);
            cout << '\n';
        }
        else {                       //  Keep searching downwards for leaf nodes:
            printAllLeafPaths(node->left);   //  Visit left subtree.
            printAllLeafPaths(node->right);  //  Visit right subtree.
        }
    }
}
