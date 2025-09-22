#include "../../include/TreeTraversal.h"


stack<Node*> gStack;                 ///<  Stack with Node pointers.
queue<Node*> gQueue;                 ///<  Queue with Node pointers.


void  visit(const Node* node) {
    cout << ' ' << node->ID;
}

Node* buildTree(int z) {
    /*   Builds the tree:                                     A=0
                                                  /                 \
                                             B=1                     C=2
                                        /         \                  /
                                      D=3           E=4           F=5
                                  /       \           \          /
                                G=6         H=7         I=8      J=9
                                  \        /  \         /        \
                                  K=10  L=11 M=12      N=13      O=14
    */
    Node* nodes[15];
    for (int i = 0; i < 15; i++) {
        nodes[i] = new Node(static_cast <char>('A' + i)); //using ASCII unicode to get diffrent letters
    }

    //B                         //C
    nodes[0]->left = nodes[1];  nodes[0]->right = nodes[2];
    //D                         //E
    nodes[1]->left = nodes[3];  nodes[1]->right = nodes[4];
    //F
    nodes[2]->left = nodes[5];
    //G                         //H
    nodes[3]->left = nodes[6];  nodes[3]->right = nodes[7];
    //I
    nodes[4]->right = nodes[8];
    //J
    nodes[5]->left = nodes[9];
    //K
    nodes[6]->right = nodes[10];
    //L                         //M
    nodes[7]->left = nodes[11]; nodes[7]->right = nodes[12];
    //N
    nodes[8]->left = nodes[13];
    //O
    nodes[9]->right = nodes[14];
    return nodes[z];
}


void traverseInorder(Node* node) {
    while (node || gStack.empty()) { //  Real node OR something on the stack:
        if (node) {                    //  Real node:
            gStack.push(node);         //  Push it on the stack.
            node = node->left;         //  Go left.
        }
        else {                       //  'node' == nullptr:
            node = gStack.top();
            gStack.pop();              //  Pop one node.
            visit(node);               //  Visit it.
            node = node->right;        //  Go right.
        }
    }
}


void traverseLevelorder(Node* node) {
    if (node) {                                  //  Real node:
        gQueue.push(node);                       //  Put the root in the queue.
        while (!gQueue.empty()) {                //  Still nodes left:
            node = gQueue.front();
            gQueue.pop();                        //  Take out the first node.
            visit(node);                         //  Visit it. and print its id
            if (node->left) {
                gQueue.push(node->left);         //  Put left subtree
            }
            if (node->right) {
                gQueue.push(node->right);        //  and right subtree LAST.
            }
        }
    }
}


void traversePostorder(Node* node) {

    //   IMPLEMENT BODY IN ASSIGNMENT NO.5

}



void traversePreorder(Node* node) {
    if (node) {                                  //  Real node:
        gStack.push(node);                       //  Put the root on the stack.
        while (!gStack.empty()) {                //  Still nodes left:
            node = gStack.top();
            gStack.pop();                        //  Take off top node.
            visit(node);                         //  Visit it.
            if (node->right) {
                gStack.push(node->right);        //  Push right
            }
            if (node->left) {
                gStack.push(node->left);         //  and left subtree.
            }
        }
    }
}