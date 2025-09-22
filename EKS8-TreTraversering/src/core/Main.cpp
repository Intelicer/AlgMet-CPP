#include "../../include/TreeTraversal.h"
using namespace std;

#include <iostream>

using namespace std;

int main() {
    Node* root = buildTree();

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