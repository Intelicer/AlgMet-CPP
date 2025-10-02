#include "../../include/TreCase.h"

#include <iostream>          //  cout
#include <cstdlib>           //  (s)rand

Node* gRoot = nullptr;       ///<  Root pointer to the entire tree.
Node* gNodes[10];            ///<  For creating and handling the tree/nodes.
Node* gFirstNode = nullptr,  ///<  Node no. 1 in the wrong place.         (Task C)
	* gSecondNode = nullptr, ///<  Node no. 2 in the wrong place.         (Task C)
	* gPrev = nullptr;       ///<  Helper pointer to find 'gFirst/Second' (Task C)
int   gMaxOddLeafLevel = -1; ///<  = HeightOddLeafNode                    (Task A)
int   gLevel = -1;           ///<  Current node’s level.                  (Task A)
char  gKeys[101];            ///<  Array with room for ALL tree IDs.      (Task B)
int   gIndex = 0;            ///<  Current index into 'gKeys'             (Task B)



void visitTaskA(Node* node) {   //  Leaf node, at odd level and highest so far:
    if (!node->left && !node->right && (gLevel % 2) && (gLevel > gMaxOddLeafLevel)) {
        gMaxOddLeafLevel = gLevel;
    }
}


void visitTaskC(Node* node) {
    if (gPrev) {                         //  NOT the 1st node in inorder sequence:
        if (gPrev->ID > node->ID) {      //  Previous has a larger ID:
            if (!gFirstNode) {           //  PREVIOUS was the 1st swapped node.
                gFirstNode = gPrev;
            }
            else {                     //  CURRENT is the 2nd swapped node.
                gSecondNode = node;
            }
        }
    }
    gPrev = node;                        //  'gPrev' moves along.
}


Node* buildTree() {
    gNodes[1] = new Node('A');  gNodes[2] = new Node('G');     //  Set up
    gNodes[3] = new Node('E');  gNodes[4] = new Node('O');     //  the
    gNodes[5] = new Node('S');  gNodes[6] = new Node('A');     //  level-
    gNodes[7] = new Node('R');  gNodes[8] = new Node('N');     //  order:
    gNodes[9] = new Node('L');
    gNodes[1]->left = gNodes[2];  gNodes[1]->right = gNodes[3];  //  Connect
    gNodes[2]->right = gNodes[4];  gNodes[3]->left = gNodes[5];  //  the whole
    gNodes[3]->right = gNodes[6];  gNodes[5]->left = gNodes[7];  //  tree:
    gNodes[6]->left = gNodes[8];  gNodes[6]->right = gNodes[9];
    return gNodes[1];                                    //  Return root ('A').
}



void findNodes(Node* node) {
    if (node) {
        findNodes(node->left);
        visitTaskC(node);
        findNodes(node->right);
    }
}



void insertionSort(char arr[], const int N) {
    int i, j;
    char v;
    for (i = 2; i <= N; i++) {
        v = arr[i];
        j = i;
        while (arr[j - 1] > v) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = v;
    }
}


void traverseInorder(Node* node) {
    if (node) {
        traverseInorder(node->left);
        cout << ' ' << node->ID;            //  = 'visit'
        traverseInorder(node->right);
    }
}



void traverseInorder2(Node* node) {
    if (node) {                    //  The tree MUST be traversed inorder!!!
        traverseInorder2(node->left);
        node->ID = gKeys[++gIndex];  //  = 'visit', which sets node IDs by
        //    sequentially fetching from the
        //    sorted array 'gKeys'.
        traverseInorder2(node->right);
    }
}



void traverseTaskA(Node* node) {
    if (node) {
        gLevel++;                         //  Move one level down.
        visitTaskA(node);                 //  Arbitrary whether the tree is
        traverseTaskA(node->left);        //  visited pre-, in-, or postorder.
        traverseTaskA(node->right);       //  I.e., 'visitTaskA' may be before,
        //  between, or after the calls!
        gLevel--;                         //  Go back to 'parent' again.
    }
}



void traverseTaskB(Node* node) {
    if (node) {
        traverseTaskB(node->left);    //  Arbitrary whether the tree is visited
        traverseTaskB(node->right);   //     pre-, in-, or postorder.
        gKeys[++gIndex] = node->ID;   //  = 'visit', gathering all node IDs
    }                                  //     into a separate array.
}