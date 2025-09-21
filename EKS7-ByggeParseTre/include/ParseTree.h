#include <iostream>
using namespace std;

/**
 *   Program example no. 7 - Builds a parse tree from a postfix expression.
 *
 *   Example showing how to read a postfix expression, while at the same time
 *   building a tree in memory, from the bottom up, using a stack of pointers
 *   to nodes. ALL LEAF NODES contain ONE letter/ONE digit,
 *   and ALL INTERNAL nodes contain ONLY '+' or '*'.
 *   In the end there will be ONLY one pointer back to the root of the tree
 *   left on the stack.
 *
 *   Algorithm: - Reads one character at a time (letter/digit, '+' or '*')
 *              - If it’s a letter/digit, it is just pushed on the stack
 *              - If it’s '+' or '*', nodes are popped from the stack that
 *                become the right and left subtree, before the root node
 *                itself is pushed on the stack
 *
 *   NOTE: The postfix expression MUST consist of only ONE letter/ONE digit,
 *         '+' and '*'.
 *         It does NOT have to contain blanks between them.
 *         The expression CANNOT end with one or more blanks.
 *
 *   @file     EKS_07_BuildParseTree.CPP
 *   @author   Frode Haug, NTNU
 */


/**
 *  Node (with ID/key/data and left and right pointers to the node’s children).
 */
struct Node {
    char ID;
    Node *left, *right;
    //same as Node* left, right;
    //Node* left;
    //Node* right;

    Node(char id) {
        ID = id;
        left = right = nullptr;
    }
};

/**
 *  RECURSIVE traversal (and output) of a tree in a postorder way.
 *
 *  @param   node  -  Pointer to a node
 */
void traversePostorder(const Node* node);

/**
 *  RECURSIVE traversal (and output) of a tree in an inorder way.
 *
 *  @param   node  -  Pointer to a node
 */
void traverseInorder(const Node* node);
