#include "../../include/TreCase.h"
#include <iostream>          //  cout
#include <iomanip>           //  setw
#include <cstdlib>           //  (s)rand
using namespace std;



Node* gRoot = nullptr;    
int   gCount = 0;         




/**
 *  Visits/prints a node's contents/data.
 *
 *  @param   node  -  Current node to print
 */
void visit(Node* node) {
    cout << setw(4) << node->value << " -  ID: " << node->ID
        << "   sum:" << setw(4) << node->sum;
    if (node->parent) {  //  Check for parent before printing.
        cout << "   parent: " << node->parent->ID;
    }
    cout << '\n';
}


/**
 *  Recursive function that (if possible) generates a node
 *  and MAYBE its left and/or right subtree.
 *
 *  @param    depth        -  Current (depth) level in the tree
 *  @param    probability  -  Probability of creating a subtree
 *  @return   Pointer to the generated (sub)tree
 */
Node* generate(const int depth, const int probability) {
    Node* root = nullptr;                 //  Pointer to what is returned.
    //  NOTE: Initialized to 'nullptr'!
    if (depth > 0) {                      //  Can still add a level:
        if (rand() % 100 < probability) { //  Drawn number in the right range:
            root = new Node;              //  Create a new node.
            root->left = generate(depth - 1, probability);  // Maybe left subtree.
            //  4x lines with "visit":
            root->value = ++gCount;                 //  Set own value.
            root->ID = static_cast<char>('A' - 1 + gCount);  //  Set ID.
            root->sum = 0;                           //  Reset own sum.
            root->parent = nullptr;                  //  Reset own parent.

            root->right = generate(depth - 1, probability); // Maybe right subtree.
        }
    }
    return root;                        //  Return generated tree or nullptr.
}


/**
 *  TASK B - For ALL nodes in the (sub)tree under 'node', their 'parent'
 *           is set recursively.
 *
 *  @param   node  -  Current node to process and its possible subtrees
 */
void setParent(Node* node) {
    if (node) {                                 //  Node/root is not empty:
        setParent(node->left);                  //  Recursive parent setting
        setParent(node->right);                 //    in each subtree.
        node->parent = nullptr;                 //  Set OWN parent.
        if (node->left) {                       //  If left child exists,
            node->left->parent = node;          //  set its parent to self.
        }
        if (node->right) {                      //  If right child exists,
            node->right->parent = node;         //  set its parent to self.
        }
    }
}


/**
 *  TASK A - 'node''s 'sum' is set recursively to be its own 'value'
 *           PLUS THE SUM of the values in both subtrees.
 *
 *  @param   node  -  Current node to process
 */
void setSum(Node* node) {
    if (node) {                                 //  Node/root is not empty:
        setSum(node->left);                     //  Recursive setting of sums
        setSum(node->right);                    //    in each subtree.
        node->sum = node->value;                //  Initialize own sum.
        if (node->left) {                       //  Add, if present,
            node->sum += node->left->sum;       //  the left subtree's sum.
        }
        if (node->right) {                      //  Add, if present,
            node->sum += node->right->sum;      //  the right subtree's sum.
        }
    }
}


/**
 *  Traverses/goes through a tree recursively in an INORDER manner.
 *
 *  @param   node  -  Current node to process
 *  @see     visit(...)
 */
void traverse(Node* node) {
    if (node) {
        traverse(node->left);
        visit(node);
        traverse(node->right);
    }
}