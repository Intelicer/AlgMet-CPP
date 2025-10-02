#pragma once
/**
 *   Program example no. 15 - (Recursive) operations on trees - case 1.
 *
 *   Declarations for the Node type and tree operations.
 *
 *   For the program’s functionality see:  TreCase1.pdf
 *
 *   (This was problem no. 3 on the exam 2011-12-20 in IMT2021 - Algorithmic Methods)
 *
 *   @file     tree.h
 *   @author   Frode Haug, NTNU
 */

 /**
  *  Node (with ID/key/data and left/right pointers to the node’s children).
  */
struct Node {
    int ID;
    Node* left, * right;                //  Initializing constructor:
    Node(int id, Node* l, Node* r) {   //  (int instead of char for clarity)
        ID = id;
        left = l;
        right = r;
    }
};

/**
 * Global pointer to the tree’s root.
 * Defined in tree.cpp, declared here for use in other translation units.
 */
extern Node* root;

/**
 *  TASK A - Prints the path from 'root' to the rightmost leaf node.
 */
void printRightmostPath();

/**
 *  TASK B - Prints the path from 'root' down to the leaf node 'node'.
 *
 *  @param   node  -  The specific node whose path from the root should be printed
 */
void printPath(Node* node);

/**
 *  TASK C - Prints the paths down to ALL leaf nodes.
 *
 *  @param   node  -  Current node to check whether it is a leaf
 */
void printAllLeafPaths(Node* node);

/*  
    Preorder above?    Postorder below?    No !!! - these are if-else branches.

    If you want to use this method copy it and set it in module/TreCase.cpp
*/
//void printAllLeafPaths(Node* node) {
//  if (node) {
//     if (node->left  ||  node->right) {  //  Keep searching downwards for leaf nodes:
//        printAllLeafPaths(node->left);     //  Visit left subtree.
//        printAllLeafPaths(node->right);    //  Visit right subtree.
//     } else {                              //  Leaf node – print the path down to it:
//        printPath(node);  cout << '\n';
//     }
//  }
//}

