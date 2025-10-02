#pragma once
/**
 *   Program example no. 17 - (Recursive) operations on trees - case 3.
 *
 *   For the program's functionality see:  TreCase3.pdf
 *
 *   (This was exercise no. 3 on the exam 13/12-1999 in L189A-Algorithmic Methods I)
 *
 *   @file     EKS_17_Tre_Case3.CPP
 *   @author   Frode Haug, NTNU
 */
using namespace std;


/**
 *  Node (with ID/key/data, level, and left/right pointers to the node's children).
 */
struct Node {
    char id;                 //  The node's ID/key/name (a single letter).
    int  level;              //  The node's level in the tree relative to the root.
    Node* left;              //  Pointer to left subtree, or nullptr.
    Node* right;             //  Pointer to right subtree, or nullptr.
    Node() { id = '-';  level = 0;  left = right = nullptr; }
};


extern Node* gRoot;                 ///<  Pointer to the tree's root.
extern int   gNextAscii;       ///<  First node is 'A' (ASCII code no. 65).


/**
 *  Visits/prints a node's contents/data.
 *
 *  @param   node  -  Current node to print
 */
void  visit(Node* node);


/**
 *  Recursively prints (backwards) the nodes' IDs on the path from 'node' to 'leaf'.
 *
 *  The function is an alternative partial solution to task C.
 *
 *  @param   node  -  The root of the current subtree
 *  @param   leaf  -  The leaf node to print the path towards
 */
void  leafToRoot(Node* node, Node* leaf);

/**
 *  TASK B - Recursively sums TOTAL levels and counts total number of nodes.
 *
 *  @param   node       -  Current node to process
 *  @param   sumLevels  -  TOTAL sum of node levels (passed by reference)
 *  @param   count      -  Total number of nodes in the tree (by reference)
 */
void  gatherValues(Node* node, int& sumLevels, int& count);      //  TASK B

/**
 *  Recursive function that (if possible) generates a node
 *  and MAYBE its left and/or right subtree.
 *
 *  @param    depth        -  Current depth/level in the tree
 *  @param    probability  -  Probability of creating a subtree
 *  @return   Pointer to the generated (sub)tree
 */
Node* generate(const int depth, const int probability);

/**
 *  TASK A - Recursively sets all tree nodes' levels relative to the root.
 *
 *  @param   node  -  Current node to process
 */
void  setLevels(Node* node);                                     //  TASK A


/**
 *  TASK C - Recursively prints ALL leaf nodes' path from the root.
 *
 *  @param   node  -  Current node to process
 */
void  printAncestors(Node* node);                                //  TASK C

/**
 *  Traverses a tree recursively INORDER.
 *
 *  @param   node  -  Current node to process
 *  @see     visit(...)
 */
void  traverse(Node* node);                  //  The five other functions
//    are extra code ONLY to
//    show/print that the task's
//    functions work correctly.

