/**
 *   Skeleton for assignment no. 2.
 *
 *   For the program’s functionality see:  Oblig2.pdf
 *
 *   @file    OBLIG2.CPP
 *   @author  Frode Haug, NTNU
 */


#include <iostream>             //  cout
using namespace std;


/**
 *  Node (with ID/key/data and left/right pointers to the node’s children).
 */
struct Node {
    int ID;                 //  The node’s ID/key/name (a number).
    Node* left, * right;     //  Pointer to both subtrees (possibly 'nullptr').
    Node(int id) { ID = id;  left = right = nullptr; }
};


Node* gRoot1 = nullptr, * gRoot2 = nullptr; ///< 2x root pointers
// (so we don’t have head->right as root)
Node* buildTree();
void  setAllIDsEqual(Node* t);
bool  areTreesIdentical(Node* t1, Node* t2);    //  Task A
bool  isTreeSymmetric(Node* t1, Node* t2);      //  Task B
