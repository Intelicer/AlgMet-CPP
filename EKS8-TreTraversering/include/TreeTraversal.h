#pragma once
/**
 *   Program example no. 8 - Traverses a binary tree in three/four different ways
 *                           (using stack and queue).
 *
 *   Example showing traversal (using stack/queue) of a binary tree
 *   in preorder, levelorder and inorder.
 *
 *   @file     EKS_08_TreTraversering.CPP
 *   @author   Frode Haug, NTNU
 */

#include <iostream>
#include <stack>
#include <queue>
using namespace std;


/**
 *  Node (with ID/key/data and left/right pointers to the node�s children,
 *        as well as a 'settFor' that CAN be used when necessary).
 */
struct Node {
    char ID;
    bool seenBefore;                     //  'settFor' is ONLY used with postorder.
    Node* left, * right;               //  Initializing constructor:
    Node(char id) { ID = id;  left = right = nullptr;   seenBefore = false; }
};

/**
 *  Visits a node � by only printing out its ID/key/data.
 *
 *  'visit' can be many different operations.
 *   For example (as here) just a simple printout. But it could also be things like
 *   changing its data, comparing the data with something, doing calculations,
 *   changing the node�s structure, etc...
 *
 *  @param   node  -  Current node to visit
 */
void visit(const Node* node);



/**
 *  Builds a binary example tree.
 *
 *  @return   Pointer to the root of the built tree
 */
Node* buildTree(int z); //edited this because inorder needs a start point for G node



/**
 *  Traverses/goes through a tree UNDER 'node'
 *  in an INORDER way using a stack.
 *
 *   @param   node  -  Current node to process
 *   @see     visit(...)
 */
void  traverseInorder(Node* node);


/**
 *  Traverses/goes through a tree UNDER 'node'
 *  in a LEVELORDER way using a queue.
 *
 *   @param   node  -  Current node to process
 *   @see     visit(...)
 */
void  traverseLevelorder(Node* node);

/**
 *  Traverses/goes through a tree UNDER 'node'
 *  in a POSTORDER way using a stack.
 *
 *   @param   node  -  Current node to process
 *   @see     visit(...)
 */
void  traversePostorder(Node* node);

/**
 *  Traverses/goes through a tree UNDER 'node'
 *  in a PREORDER way using a stack.
 *
 *  Process:
 *  Visit the root node, recurisve left, then recursive right
 *
 *   @param   node  -  Current node to process
 *   @see     visit(...)
 */
void  traversePreorder(Node* node);




