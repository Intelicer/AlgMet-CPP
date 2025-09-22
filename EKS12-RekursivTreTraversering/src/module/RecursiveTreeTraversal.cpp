#include "../../include/RecursiveTreeTraversal.h"

int gLevel = -1;      ///<  Which level we are currently at in the tree.
int gNr;              ///<  Sequential numbering of visited nodes.
//    NB:  Both of these are only used here to show
//         in what order the nodes are visited and
//         which level they are located at.
//         Normally, these are NOT used!



/**
 *  Visits a node - by printing its visit number ('gNr'),
 *  its ID/key/data, and which level ('gLevel') it is on.
 *
 *  @param   node  -  Current node to visit
 */
void visit(const Node* node) {
    cout << setw(6) << ++gNr << ": " << node->ID
        << "  at level: " << gLevel << '\n';
}

/**
 *  Builds a binary example tree (same as in EKS_08).
 *
 *  @return   Pointer to the built tree’s root
 */
Node* buildTree() {
    /*   Builds the tree:                               A=0
                                              /                     \
                                             B=1                     C=2
                                        /         \                  /
                                      D=3         E=4              F=5
                                  /       \           \          /
                                G=6        H=7        I=8     J=9
                                  \        / \         /        \
                                 K=10   L=11 M=12      N=13      O=14
    */
    Node* nodes[15];
    for (int i = 0; i < 15; i++) {
        nodes[i] = new Node(static_cast <char>('A' + i));
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
    return nodes[0]; //return A
}

/**
 *  Traverses/goes through a tree UNDER 'node'
 *  in an INORDER way using recursion.
 *
 *   @param   node  -  Current node to process
 *   @see     visit(...)
 */
void traverseInorder(Node* node) {
    gNr = 0;       
    if (node) {
        gLevel++;
        traverseInorder(node->left); //visit left nodes
        visit(node);                  //  Visits BETWEEN the recursive calls!
        traverseInorder(node->right);
        gLevel--;
    }
    //else {
    //    // No action when node is nullptr
    //}

    /*
        left
        visit itself
        right


                                                    A=0
                                            /                     \
                                         B=1                     C=2
                                      /         \                  /
                                   D=3          E=4              F=5
                                /       \           \           /
                            G=6        H=7        I=8        J=9
                              \        / \         /           \
                             K=10   L=11 M=12      N=13        O=14


        Visit G
        right K
        left D
        left L
        right H
        right M
        left B
        right E
        left N
        right I
        A
        left J
        right O
        left F
        right C


    */
}


/**
*  Traverses/goes through a tree UNDER 'node'
*  in a POSTORDER way using recursion.
*
*   @param   node  -  Current node to process
*   @see     visit(...)
*/
void traversePostorder(Node* node) {
    gNr = 0;
    if (node) {
        gLevel++;
        traversePostorder(node->left);
        traversePostorder(node->right);
        visit(node);                  //  Visits AFTER the recursive calls!
        gLevel--;
    }
    //else {
    //    // No action when node is nullptr
    //}


    /*
        left
        right
        itself


                                                    A=0
                                            /                     \
                                         B=1                     C=2
                                      /         \                  /
                                   D=3          E=4              F=5
                                /       \           \           /
                            G=6        H=7        I=8        J=9
                              \        / \         /           \
                             K=10   L=11 M=12      N=13        O=14


        Visit K
        Left G
        Left L
        Right M
        H
        D
        N
        I
        E
        B
        O
        J
        F
        C
        A

    */
}


/**
 *  Traverses/goes through a tree UNDER 'node'
 *  in a PREORDER way using recursion.
 *
 *   @param   node  -  Current node to process
 *   @see     visit(...)
 */
void traversePreorder(Node* node) {
    gNr = 0; //reset
    if (node) {
        gLevel++;
        visit(node);                  //  Visits BEFORE the recursive calls!
        traversePreorder(node->left);
        traversePreorder(node->right);
        gLevel--;

        /*
            Visit itself
            then all lefts
            at the end the rights


                                                        A=0
                                              /                     \
                                             B=1                     C=2
                                        /         \                  /
                                      D=3         E=4              F=5
                                  /       \           \          /
                                G=6        H=7        I=8     J=9
                                  \        / \         /        \
                                 K=10   L=11 M=12      N=13      O=14


            visit A //start
            left B
            left D
            left G
            right K
            right H
            left L
            right M
            right E
            right I
            left N
            right C
            left F
            left J
            right O //end
        
        */
    }
    else {
        // No action when node is nullptr
    }
}