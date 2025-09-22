#include "../../include/ParseTree.h"

void traversePostorder(const Node* node) { 
    if (node) {                          //  Pointer to a real node:
        traversePostorder(node->left);   //  Visit left subtree/child.
        traversePostorder(node->right);  //  Visit right subtree/child.
        cout << ' ' << node->ID;         //  Write (visit) itself.
    }
}

void traverseInorder(const Node* node) {
    if (node) {                          //  Pointer to a real node:
        if (node->left) {                //  Write '(' before the subtree.
            cout << '(';
        }
        traverseInorder(node->left);     //  Visit left subtree/child.
        cout << ' ' << node->ID;         //  Write (visit) itself.
        traverseInorder(node->right);    //  Visit right subtree/child.
        if (node->right) {               //  Write ')' after the subtree.
            cout << ')';
        }
    }
}
