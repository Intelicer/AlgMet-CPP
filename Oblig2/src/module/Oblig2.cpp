#include "../../include/Oblig2.h"

/**
 *  Builds a binary test tree.
 *
 *  @return  Pointer to the root of the tree that was built
 */
Node* buildTree() {
    Node* p[12];
    for (int i = 1; i <= 11; i++) {
        p[i] = new Node(i); //  Builds the tree:   //
    }
    //p[1]
    p[1]->left = p[2];    
    p[1]->right = p[3]; 
    //p[2]
    p[2]->left = p[4];    
    p[2]->right = p[5]; 
    //p[3]
    p[3]->left = p[6];    
    p[3]->right = p[7]; 
    //p[5]
    p[5]->left = p[8];                        
    //p[6]
    p[6]->right = p[9];
    //p[7]
    p[7]->left = p[10];   
    p[7]->right = p[11];

    //            1             //
    //        /       \         //
    //       2         3        //
    //     /   \     /   \      //
    //    4     5   6     7     //
    //         /     \   / \    //
    //        8       9 10 11   //


    return p[1];                              

}


/**
 *  Goes through and sets all tree IDs/keys to '99'.
 *
 *  @param  t  -  Pointer to the (sub)tree root
 */
void setAllIDsEqual(Node* t) {
    if (t) {
        t->ID = 99;
        setAllIDsEqual(t->left);
        setAllIDsEqual(t->right);
    }
}


/**
 *  TASK A - Finds out and returns whether two binary trees are COMPLETELY IDENTICAL:
 *
 *  @param   t1  -  Pointer to (sub)tree no.1
 *  @param   t2  -  Pointer to (sub)tree no.2
 *  return  Whether the two (sub)trees are COMPLETELY identical or not
 */
bool areTreesIdentical(Node* t1, Node* t2) {

    //  WRITE THE BODY  (see assignment text)
}


/**
 *  TASK B - Finds out and returns whether a binary tree is TOTALLY SYMMETRIC:
 *
 *  @param   t1  -  Pointer to (sub)tree no.1
 *  @param   t2  -  Pointer to (sub)tree no.2
 *  @return  Whether the whole tree is symmetric around/under the root or not
 */
bool isTreeSymmetric(Node* t1, Node* t2) {

    //  WRITE THE BODY  (see assignment text)
} 