
#include "../../include/TreCase.h"
#include <iostream>   // cout

using namespace std;

/**
 *  Main program:
 */
int main() {
    char ch;

    gRoot = buildTree();                   //  Builds the tree from the task text.
    traverseInorder(gRoot);                //  The printout!  :-)


    cout << "\n\nTesting Task A - Find max level for an odd-level leaf node:\n";
    traverseTaskA(gRoot);
    cout << "Highest level for an odd-level terminal node is: " << gMaxOddLeafLevel << '\n';


    cout << "\n\nTesting Task B - Convert to binary search tree:\n";
    //  Without changing a tree’s structure/shape, convert an arbitrary
    //  binary tree into a binary SEARCH TREE (via the three next functions):
    gIndex = 0;
    traverseTaskB(gRoot);      //  Collect all tree IDs.
    gKeys[0] = '\0';           //  'insertionSort' requires a 'sentinel key'!
    insertionSort(gKeys, gIndex);   //  Sort them ascending alphabetically!

    gIndex = 0;                 //  Set all the tree’s IDs again to obtain a
    traverseInorder2(gRoot);    //    binary search tree. MUST be inorder!

    cout << "Binary search tree, traversed inorder (i.e., alphabetical output):\n";
    traverseInorder(gRoot);     //  Print the new BST contents (sorted).


    cout << "\n\n\nTesting Task C - Find two swapped nodes:\n";
    cout << "Swapping 'G' and 'S'. \n";
    ch = gNodes[7]->ID;  gNodes[7]->ID = gNodes[9]->ID;  gNodes[9]->ID = ch;
    traverseInorder(gRoot);

    findNodes(gRoot);

    cout << "\nSwapping back 'node1' and 'node2'. \n";
    ch = gFirstNode->ID;   gFirstNode->ID = gSecondNode->ID;   gSecondNode->ID = ch;
    traverseInorder(gRoot);

    gFirstNode = gSecondNode = gPrev = nullptr;
    cout << "\n\nSwapping 'E' (the root) and 'O'. \n";
    ch = gNodes[1]->ID;  gNodes[1]->ID = gNodes[8]->ID;  gNodes[8]->ID = ch;
    traverseInorder(gRoot);

    findNodes(gRoot);

    cout << "\nSwapping back 'node1' and 'node2'. \n";
    ch = gFirstNode->ID;   gFirstNode->ID = gSecondNode->ID;   gSecondNode->ID = ch;
    traverseInorder(gRoot);

    cout << "\n\n";
    return 0;
}