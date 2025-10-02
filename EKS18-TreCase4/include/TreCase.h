#pragma once
/**
 *   Program example no. 18 - (Recursive) operations on trees - case 4.
 *
 *   For the program’s functionality see: TreCase4.pdf
 *
 *   Heavy use of recursive 'traverse' functions from:
 *          EKS_12_RekursivTreTraversering.cpp
 *   The assignment is otherwise very similar to assignment no. 6 in the booklet.
 *
 *   Important newly written code is:
 *       Task A:
 *          - The body of 'visitTaskA'
 *       Task B:
 *          - The line  " gKeys[++gIndex] = node->ID; "  in 'traverseTaskB'
 *          - The line  " node->ID = gKeys[++gIndex]; "  in 'traverseInorder2'
 *          And performing ascending sort of the array 'gKeys'
 *          (any sorting method/algorithm may be used).
 *       Task C:
 *          - Only the body of 'visitTaskC'  (and 'findNodes')
 *
 *  (This was task no. 3 on the exam 2017-12-19 in IMT2021-Algorithmic Methods)
 *
 *   @file     EKS_18_Tre_Case4.CPP
 *   @author   Frode Haug, NTNU
 */


using namespace std;


/**
 *  Node (with ID/key/data and left/right pointers to the node's children).
 */
struct Node {
    char ID;                 //  Node’s ID/key/name (a letter).
    Node* left, * right;      //  Pointers to both subtrees (possibly 'nullptr').
    Node(char id) { ID = id;   left = right = nullptr; }
};


extern Node* gRoot;       ///<  Root pointer to the entire tree.
extern Node* gNodes[10];            ///<  For creating and handling the tree/nodes.
extern Node* gFirstNode,     ///<  Node no. 1 in the wrong place.         (Task C)
            * gSecondNode,   ///<  Node no. 2 in the wrong place.         (Task C)
            * gPrev;          ///<  Helper pointer to find 'gFirst/Second' (Task C)
extern int   gMaxOddLeafLevel; ///<  = HeightOddLeafNode                    (Task A)
extern int   gLevel;           ///<  Current node’s level.                  (Task A)
extern char  gKeys[101];            ///<  Array with room for ALL tree IDs.      (Task B)
extern int   gIndex;            ///<  Current index into 'gKeys'             (Task B)


/**
 *  TASK A - Determine if the node is at a higher odd-numbered level
 *           than recorded so far.
 *
 *  @param   node  -  Current node to process
 */
void  visitTaskA(Node* node);                                  //  Task A

/**
 *  TASK C - Determine if 'node' is out of order
 *           - update 'gFirstNode' or 'gSecondNode' if so.
 *
 *  @param   node  -  Current node to process
 */
void  visitTaskC(Node* node);                                  //  Task C

/**
 *  Build a binary tree - identical to the left figure in Task B.
 *
 *  @return   Pointer to the root of the built tree
 */
Node* buildTree();                                             //  Extra

/**
 *  TASK C - Find and set pointers to two swapped nodes in a binary search tree.
 *
 *  @param   node  -  Current node to process
 *  @see     visitTaskC(...)
 */
void  findNodes(Node* node);                                   //  Task C

/**
 *  Task B - Sort 'arr' in ascending order (cf. lecture 10).
 *
 *  @param   arr  -  Array to be sorted ascending
 *  @param   N    -  Number of elements to sort in the array
 */
void  insertionSort(char arr[], const int N);                  //  Task B


/**
 *  EXTRA - Recursively traverse a binary tree inorder and print its contents.
 *
 *  @param   node  -  Current node to process
 */
void  traverseInorder(Node* node);                             //  Extra

/**
 *  TASK B - Recursively set nodes’ consecutively sorted IDs inorder,
 *           so the tree becomes a binary search tree.
 *
 *  @param   node  -  Current node to process
 */
void  traverseInorder2(Node* node);                            //  Task B

/**
 *  TASK A - Recursively find the max level for any odd-level leaf node(s).
 *
 *  @param   node  -  Current node to process
 */
void  traverseTaskA(Node* node);                               //  Task A

/**
 *  TASK B - Without changing the tree’s structure/shape, convert an arbitrary
 *           binary tree into a binary search tree.
 *
 *  @param   node  -  Current node to process
 */
void  traverseTaskB(Node* node);                               //  Task B

