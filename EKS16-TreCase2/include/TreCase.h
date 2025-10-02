#pragma once
/**
 *   Program example no. 16 - (Recursive) operations on trees - case 2.
 *
 *   For the program's functionality see:  TreCase2.pdf
 *
 *   (This was problem no. 3 on the exam 17/8-2000 in L189A-Algorithmic Methods I)
 *
 *   @file     EKS_16_Tre_Case2.CPP
 *   @author   Frode Haug, NTNU
 */

/**
 *  Node (with value, ID/data, the sum of both subtrees' values,
 *  left/right pointers to the node's children and a pointer to the parent).
 */
struct Node {
    int   value;              //  Node's value. Tree is ordered by this (NOT ID!).
    char  ID;                 //  Node's ID/name (a letter).
    int   sum;                //  The sum of all children's values.
    Node* left;               //  Pointer to left subtree.
    Node* right;              //  Pointer to right subtree.
    Node* parent;             //  Pointer to the node's parent.
};


extern Node* gRoot;    ///<  Pointer to the tree's root.
extern int  gCount;         ///<  First node has value=1 and ID='A'.
                          //      Used to auto-generate a test tree.


void  visit(Node* node);
Node* generate(const int depth, const int probability);
void  setParent(Node* node);            //  TASK 3B
void  setSum(Node* node);               //  TASK 3A
void  traverse(Node* node);             //  The three other functions
                                        //    are extra code ONLY to
                                        //    show/print that the task's
                                        //    functions work correctly.



