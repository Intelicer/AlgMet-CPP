#include "../../include/RecursiveTreeTraversal.h"

/**
 *  Main program:
 */
int main() {
    Node* root;

    root = buildTree();

    //gNr = 0;                        //  MUST be reset for each traversal!
    //  While 'gLevel' counts back to -1!!!
    cout << "\n\nPreorder traversal:\n";
    traversePreorder(root);

    //gNr = 0;
    cout << "\n\nInorder traversal:\n";
    traverseInorder(root);

    //gNr = 0;
    cout << "\n\nPostorder traversal:\n";
    traversePostorder(root);

    cout << "\n\n";
    return 0;
}