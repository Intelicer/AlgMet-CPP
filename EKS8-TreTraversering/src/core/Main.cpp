#include "../../include/TreeTraversal.h"
using namespace std;

#include <iostream>

using namespace std;

int main() {
    //return the start 0
    Node* root = buildTree(0);

    //to make inorder work give it the last node on the left
    Node* root2 = buildTree(6);

    cout << "\n\nPreorder traversal:\n\t";
    traversePreorder(root);

    cout << "\n\nLevelorder traversal:\n\t";
    traverseLevelorder(root);

    cout << "\n\nInorder traversal:\n\t";
    traverseInorder(root);

    cout << "\n\nPostorder traversal:\n\t";
    traversePostorder(root);

    cout << "\n\n";
    return 0;
}