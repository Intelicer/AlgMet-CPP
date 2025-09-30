/**
 *   Program example no. 28 - Binary Search Tree (BST) - simple self-made class.
 *
 *   The example shows a self-made implementation of the container class BST.
 *   This does NOT only contain 'data' (ID/key), as in the previous examples,
 *   but also associated data ('extraData').
 *
 *   Code is made for the following functions:
 *     - BST
 *     - ~BST
 *     - void    display() const;
 *     - void    insert(const Data value, const ExtraData extraData);
 *     - bool    remove(const Data value);
 *     - ExtraData search(const Data value) const;
 *     - void    traverseInorder(Node* node) const;
 *
 *
 *   Order ( O(...)):
 *    For a BST built from N nodes, search/insert requires about  2 ln N
 *    comparisons on average. In the "worst case" it requires N comparisons.
 *    (This is when ALL nodes ONLY have ONE left OR right child,
 *    i.e., the entire tree is actually a LIST, and we are to find/insert
 *    after the VERY last.)
 *
 *
 *   NB:  - In a binary search tree EVERYTHING to the left of a node is ALWAYS
 *          LESS than the value in the node itself, and EVERYTHING to the right
 *          is GREATER OR EQUAL.
 *        - EQUAL 'data'/ID/key may therefore be spread to the right of each
 *          other differently down the tree, but they will ALWAYS come right
 *          after each other if you print the tree's nodes in INORDER sequence!
 *        - During 'remove' a node must ALWAYS be replaced with the SEQUENTIALLY
 *          succeeding node (if it exists). This one will NEVER have any left
 *          child, but possibly only a right subtree.
 *        - 'extraData' is made to show that in reality it is seldom that only
 *          'data' is the only and most relevant thing, but that it is most
 *          often actually the key to an associated data set.
 *          However, 'extraData' in this example is ONLY a single little string.
 *
 *   @file     EKS_28_BinarySearchTree.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>          //  cout
#include <string>            //  string
using namespace std;


/**
 *  Container class Binary Search Tree (BST)
 *
 *  Contains a binary search tree consisting of 'Node' structs,
 *  and has a "dummy" 'head' that has 'data' (ID/key) smaller than anything else
 *  in the tree. 'head->right' points to the tree's real root !!!
 *
 */
template <typename Data, typename ExtraData>  //  Common also with 'T', 'T2', ...
class BST {
private:
    struct Node {                   //  The nodes in the binary search tree.
        Data data;                  //  ID/key.
        ExtraData extraData;        //  Additional data/info to the ID/key.
        Node* left, * right;        //  Pointer to left/right subtree/child.
        //  Constructor:
        Node(const Data d, const ExtraData ed) {
            data = d;  extraData = ed;
            left = right = nullptr;
        }
    };

    Node* head;      //  Dummy head, where 'head->right' is the tree's root!
    //  Convenient to have when the root itself shall be deleted.

    void traverseInorder(Node* node) const {
        if (node) {
            traverseInorder(node->left);
            cout << '\t' << node->data;    //  Writes the node's data/ID/key.
            if (node->left) {        //  Writes any left child:
                cout << "    L.child: " << node->left->data;
            }
            if (node->right) {       //  Writes any right child:
                cout << "    R.child:    " << node->right->data;
            }
            cout << '\n';
            traverseInorder(node->right);
        }
    }

public:
    BST() {                //  Initializes 'head' - according to the data types:
        head = new Node(Data(), ExtraData());
    }

    ~BST() {    /*  delete <entire tree>   */ }


    void display() const {                 //  Writes the ENTIRE tree inorder:
        traverseInorder(head->right);       //  Starts at the real root.
    }

    //  Inserts 'value' with associated 'extraData' into the tree:
    void insert(const Data value, const ExtraData extraData) {
        Node* parent = head,          //  Parent of 'node' (lags one behind).
            * node = head->right;

        if (node) {                    //  There is ALREADY at least one node/root:
            while (node) {              //  Scrolls to where to insert at the BOTTOM:
                parent = node;           //  'parent' follows after.
                //  'node' searches further down:
                node = (value < node->data) ? node->left : node->right;
            }
            node = new Node(value, extraData);          //  Creates the new to insert.
            if (value < parent->data) { parent->left = node; } //  Hooks in to left.
            else { parent->right = node; }                       //  or right of 'parent'.
        }
        else {                        //  1st node in the tree (the root):
            head->right = new Node(value, extraData);
        }
    }

    //  Removes and returns (if possible)
    bool remove(const Data value) {       //    node with the ID 'value':
        Node* parentToRemove,               //  The "parent" of 'toRemove'.
            * toRemove,                     //  The one to remove/delete.
            * parentSuccessor,              //  The "parent" of 'successor'.
            * successor;                    //  The SEQUENTIALLY succeeding.

        parentToRemove = head;              //  Initializes 2x pointers:
        toRemove = head->right;
        //  Scrolls forward to 'value'(?):
        while (toRemove && value != toRemove->data) {
            parentToRemove = toRemove;      //  'parentToRemove' hops after.
            //  'toRemove' scrolls left/right:
            toRemove = (value < toRemove->data) ? toRemove->left : toRemove->right;
        }

        if (!toRemove) { return false; }   //  The node was NOT found.

        successor = toRemove;    //  'toRemove' IS the node to be deleted !!!
        //  CASE 1: =================================
        if (!toRemove->right) {  //  Has no HIGHER/GREATER successor!
            successor = successor->left; // Successor is LEFT subtree!
        }
        //  CASE 2: =================================
        else if (!toRemove->right->left) {
            successor = successor->right; // Successor is RIGHT subtree!
            successor->left = toRemove->left; //Takes over left subtree from 'toRemove'.
        }
        //  CASE 3: =================================
        else {                   // MUST search MORE for the SEQUENTIAL successor:
            parentSuccessor = successor->right; // Initializes 'parentSuccessor'.

            while (parentSuccessor->left->left) {   //  Scrolls to the NEXT-to-bottom
                parentSuccessor = parentSuccessor->left; //  left node:
            }

            successor = parentSuccessor->left;   //  'successor' is the node
            //     ALL the way down to the left.
            //  Transfers any right subtree:
            parentSuccessor->left = successor->right;  // Has NO left subtree anyway!

            successor->left = toRemove->left;    // 'successor' takes 'toRemove's
            successor->right = toRemove->right;  //    place.
        }

        delete toRemove;	              	    //  'toRemove' is removed/deleted.

        //  Moved node ('successor')
        //  is hooked correctly under 'parentToRemove':
        if (value < parentToRemove->data) { parentToRemove->left = successor; }
        else { parentToRemove->right = successor; }

        return true;                       //  The node found and removed.
    }

    //  Searches for node with 'data' equal to 'value'.
    //  If possible returns its 'extraData':
    ExtraData search(const Data value) const {
        Node* node = head->right;               //  Initialize to the root.
        while (node && node->data != value) { //  Search until found or bottom.
            node = (value < node->data) ? node->left : node->right;
        }

        if (node) { return node->extraData; }   //  Found - 'extraData' returned.
        else { return head->extraData; }        //  NOT found!
    }
};
