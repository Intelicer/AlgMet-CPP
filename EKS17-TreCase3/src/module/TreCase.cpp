#include "../../include/TreCase.h"

#include <iostream>          //  cout
#include <cstdlib>           //  (s)rand

Node* gRoot;                 ///<  Pointer to the tree's root.
int gNextAscii = 65;       ///<  First node is 'A' (ASCII code no. 65).



void visit(Node* node) {       //  Shows the contents of ONE node.
    cout << ' ' << node->id << ":  " << node->level << '\n';
}



void leafToRoot(Node* node, Node* leaf) {
    if (node != leaf) {             //  Have NOT reached the target:
        //  The leaf is down to the left (smaller):
        if (leaf->id < node->id) {
            leafToRoot(node->left, leaf);
        }
        else {                    //  The leaf is to the right (greater):
            leafToRoot(node->right, leaf);
        }
    }
    cout << node->id << ' ';         //  Print the node's ID.
    if (node == gRoot) {
        cout << '\n';                //  Print '\n' when the root is reached.
    }
}



void gatherValues(Node* node, int& sumLevels, int& count) {
    if (node) {                       //  The node is a real node:
        sumLevels += node->level;     //  Sum up the nodes' levels TOTAL.
        count++;                      //  Count their total number.
        //  NOTE: The two lines above are placed
        //        preorder, but they could just as
        //        well be inorder or postorder !!!
        gatherValues(node->left, sumLevels, count);   //  Visit left subtree.
        gatherValues(node->right, sumLevels, count);   //  Visit right subtree.
    }
}



Node* generate(const int depth, const int probability) {
    Node* root = nullptr;                    //  Pointer to what is returned.
    //  NOTE: Initialized to 'nullptr'!
    if (depth > 0) {                         //  Can still add another level:
        if (rand() % 100 < probability) {    //  Drawn number in the interval:
            root = new Node;                 //  Create a new node.
            root->left = generate(depth - 1, probability); // Maybe left subtree.
            root->id = static_cast<char>(gNextAscii++);    //  Set own ID.
            root->right = generate(depth - 1, probability); // Maybe right subtree.
        }
    }
    return root;                      //  Return generated tree or nullptr.
}



void setLevels(Node* node) {
    //  NOTE: We know that 'node' is ALWAYS non-nullptr !!!
    //        (due to the precondition and calls below)
    if (node->left) {                        //  Has a real left child:
        node->left->level = node->level + 1; //  Set child's level.
        setLevels(node->left);               //  Same recursively for left child.
    }

    if (node->right) {                       //  Has a real right child:
        node->right->level = node->level + 1; // Set child's level.
        setLevels(node->right);               // Same recursively for right child.
    }
}


void printAncestors(Node* node) {
    if (node) {                                   //  The node is real:
        if (!node->left && !node->right) {        //  The node is a leaf:
            //  Walks from the root and prints the nodes on the
            //    path down to the leaf node. Finds that path
            //    because the tree is a binary search tree, and
            //    we know the leaf node's ID:
            cout << '\t';                         //  Indentation BEFORE print.
            Node* q = gRoot;                      //  Start at the root.
            while (q) {                           //  Loop until passed the leaf:
                //  We CANNOT write: while (q != node),
                //    because then the leaf itself would not be
                //    printed. It could of course be printed
                //    manually after the while-loop.
                cout << q->id << ' ';             //  Print nodes' (ancestors') IDs.
                //  Step further, until we have PASSED 'node'.
                q = (node->id < q->id) ? q->left : q->right;
            }
            cout << '\n';                         //  '\n' AFTER the output.

            //  Instead of the while-loop above we COULD have made a recursive function that
            //  starts at the root and searches down to the leaf using the tree's binary
            //  ordering. It prints node names BACKWARDS (FROM the leaf and UP TO the root)
            //  when unwinding/terminating:
            //          leafToRoot(gRoot, node);

        }
        else {                             //  NOT a leaf: Find and print
            printAncestors(node->left);          //  ancestors for leaf nodes in
            printAncestors(node->right);         //  left and right subtrees.
        }
    }
}



void traverse(Node* node) {
    if (node) {
        traverse(node->left);
        visit(node);
        traverse(node->right);
    }
}