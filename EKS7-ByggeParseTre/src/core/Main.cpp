
#include "../../include/ParseTree.h"
#include <iostream>                  //  cout
#include <stack>                     //  stack from STL
using namespace std;

/**
 *  The main program:
 */
int main() {
    stack <Node*> stakk;                 //  Stack with Node pointers!!!
    char ch;                             //  Character read from keyboard.
    Node* newNode;                       //  Pointer to new node in tree.

    cout << "\n\nType a postfix expression:\n";

    // Reads ALL characters, including ' ' and '\n'.
    while ((ch = cin.get()) != '\n') {          //  Not yet end of input:
        while (ch == ' ') {                     //  Skips all ' ' (blanks).
            ch = cin.get();
        }

        newNode = new Node(ch);                 //  Creates a new node.

        if (ch == '+' || ch == '*') {           //  If INTERNAL node:
            newNode->right = stakk.top();       //  Attach right
            stakk.pop();
            newNode->left = stakk.top();       //  Attach left subtree.
            stakk.pop();
        }

        stakk.push(newNode);                    //  Push (root) node.
    }

    //  EXTRA:  Test how the tree looks:
    //          NOTE: Have NOT yet learned how to code this / traverse trees!!!
    traversePostorder(stakk.top());  cout << "\n\n"; //postorder
    traverseInorder(stakk.top());    cout << "\n\n"; //inorder

    return 0;
}

/*
   Check/test:
   ===========

   Postorder expression:     3 4 + 3 2 * + 2 + 5 3 * 4 2 + * +

   What happens it will take the stack and read number till it meets a operation symbol
   When the symbol appears:
   we 

   Gives inorder expression: ((((3 + 4) + (3 * 2)) + 2) + ((5 * 3) * (4 + 2)))

   This corresponds to the parse tree:              +
                                              /           \
                                           +                 *
                                        /     \           /     \
                                     +         2        *         +
                                   /   \               / \       / \
                                  +     *             5   3     4   2
                                / \   / \
                               3   4 3   2
*/
