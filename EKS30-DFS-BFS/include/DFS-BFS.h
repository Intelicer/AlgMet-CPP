/**
 *   Program example no. 30 - DFS and BFS on a graph.
 *
 *   The example shows both DFS (Depth-First Search) and BFS (Breadth-First Search)
 *   on a (small) graph. It demonstrates how to do this using both
 *   an adjacency matrix and an adjacency list.
 *
 *   Algorithm/behavior:
 *        Uses a helper array ('gVisited') that contains:
 *            - UNSEEN (= 0) if a node has not yet been seen/visited.
 *            - N (= 1 to V) when the node was seen/visited as no. N.
 *              The variable 'gVisitOrder' is used for this counting.
 *            - LATER (= -1) if we have been through the node (i.e., partially seen),
 *              but it shall be properly visited later in a Breadth-First Search (BFS).
 *        The DFS algorithm is recursive.
 *        The BFS algorithm is iterative.
 *
 *   Complexity ( O(...)):
 *        - DFS on a graph represented with an adjacency MATRIX is O(V*V)
 *        - DFS on a graph represented with an adjacency LIST is O(V+E)
 *
 *   Note: - The nodes' IDs/numbers are converted to the index range 0 to NODE_COUNT-1
 *         - The adjacency matrix for an undirected graph is ALWAYS a mirror around
 *           the main diagonal (from upper left to lower right corner).
 *         - If we return to a node that has previously been
 *           seen/visited, then the graph obviously contains at least one cycle.
 *         - The number of times each for-loop in main finds that
 *           (gVisited[i] == UNSEEN) is true equals the number of components in the graph.
 *
 *
 *   The Depth-First Search tree for the graph in this example (starting at A):
 *   =======================================================================
 *
 *                     ..... A......
 *                     :   /    :  :
 *                     :  B     :  :
 *                     :/   \   :  :
 *                     C     F  :  :
 *                            \ :  :
 *                              D  :
 *                               \ :
 *                                 E
 *
 *   - If this tree is traversed
 *     - preorder:  you get the order the nodes were seen/visited.
 *     - postorder: you get the order in which nodes finished visiting all neighbors.
 *   - Dotted lines show edges/recursive calls that are NOT
 *     followed/started. These ALWAYS go upward in the tree!
 *   - The tree with dotted lines is therefore YET another way to draw the graph!
 *
 *
 *   @file     EKS_30_DFS_BFS.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>          //  cout
#include <queue>             //  queue
#include <vector>            //  vector
using namespace std;


const int NODE_COUNT = 6;              ///<  Number of nodes in the graph (V).
const int UNSEEN = 0;              ///<  Node has NOT been seen yet.
const int LATER = -1;             ///<  Touched, but not fully seen/visited yet.

void BFS(int id);
void DFS(const int id);
void DFS_List(const int id);
void initAdjList();
void resetState();
void printVisited();


int  gAdjMatrix[NODE_COUNT][NODE_COUNT]       ///<  Adjacency matrix for the graph:
= { { 0, 1, 1, 1, 1, 0 },   // A = 0
    { 1, 0, 1, 0, 0, 1 },   // B = 1          E-------A-------C
    { 1, 1, 0, 0, 0, 0 },   // C = 2          |      / \      |
    { 1, 0, 0, 0, 1, 1 },   // D = 3          D------   B------
    { 1, 0, 0, 1, 0, 0 },   // E = 4          |         |
    { 0, 1, 0, 1, 0, 0 } }; // F = 5          F----------
//         A  B  C  D  E  F


int  gVisited[NODE_COUNT];                     ///<  Status for node i.
int  gVisitOrder;                              ///<  Visited the node as no. X.

queue  <int> gVisitLaterQueue;                 ///<  Nodes to visit later/soon.
vector <int> gAdjList[NODE_COUNT];             ///<  Adjacency lists for the same graph.
//    ARRAY OF VECTORS !!!



/**
 *  Using BFS and the adjacency matrix, iteratively visit ALL nodes in the component.
 *
 *  @param   id  - Index (0 to NODE_COUNT-1) for the START NODE of the visit
 */
void BFS(int id) {
    int j;                                      //  Index for current neighbors.
    gVisitLaterQueue.push(id);                  //  Put at the BACK of the visit queue.
    while (!gVisitLaterQueue.empty()) {         //  Still nodes left to visit:
        id = gVisitLaterQueue.front();          //  READ the first node's ID.
        gVisitLaterQueue.pop();                 //  REMOVE/TAKE OUT from the queue.
        gVisited[id] = ++gVisitOrder;           //  Set visit order number.
        for (j = 0; j < NODE_COUNT; j++) {    //  The node's row in the matrix:
            if (gAdjMatrix[id][j]) {            //  Is neighbor with id j,
                if (gVisited[j] == UNSEEN) {    //    and that one is unvisited:
                    gVisitLaterQueue.push(j);   //  Put neighbor at the BACK of the queue.
                    gVisited[j] = LATER;        //  Mark as partially visited!!!
                }
            }
        }
        //                                              printVisited();
    }
}


/**
 *  Using DFS and the ADJACENCY MATRIX, recursively visit ALL nodes in the component.
 *
 *  @param   id  -  Index (0 to NODE_COUNT-1) for the node to be visited
 */
void DFS(const int id) {
    gVisited[id] = ++gVisitOrder;                //  Set visit order number.
    //                                              printVisited();
    for (int j = 0; j < NODE_COUNT; j++) {     //  The node's row in the matrix:
        if (gAdjMatrix[id][j]) {                 //  IS neighbor with id j:
            if (gVisited[j] == UNSEEN) {         //  j is unseen:  Visit it
                DFS(j);
            }
        }
    }
}


/**
 *  Using DFS and the ADJACENCY LIST, recursively visit ALL nodes in the component.
 *
 *  @param   id  -  Index (0 to NODE_COUNT-1) for the node to be visited
 */
void DFS_List(const int id) {
    int neighbor;                                //  Current neighbor's ID/number.
    gVisited[id] = ++gVisitOrder;                //  Set visit order number.
    //                                              printVisited();
                                                     //  Go through neighbors:
    for (unsigned int j = 0; j < gAdjList[id].size(); j++) {
        neighbor = gAdjList[id].at(j);           //  Get the neighbor's ID/number.
        //  Unseen neighbor is visited:
        if (gVisited[neighbor - 1] == UNSEEN) {
            DFS_List(neighbor - 1);
        }
    }
}


/**
 *  Initialize adjacency list (with a "random" order) for the example graph.
 *  Note: The list stores node labels as 1..N (A=1..F=6), so we subtract 1 when indexing.
 */
void initAdjList() {
    gAdjList[0].push_back(5);    gAdjList[0].push_back(4);
    gAdjList[0].push_back(2);    gAdjList[0].push_back(3);
    gAdjList[1].push_back(3);    gAdjList[1].push_back(1);
    gAdjList[1].push_back(6);
    gAdjList[2].push_back(2);    gAdjList[2].push_back(1);
    gAdjList[3].push_back(1);    gAdjList[3].push_back(6);
    gAdjList[3].push_back(5);
    gAdjList[4].push_back(1);    gAdjList[4].push_back(4);
    gAdjList[5].push_back(4);    gAdjList[5].push_back(2);
}


/**
 *  Reset/initialize the global variables 'gVisitOrder' and 'gVisited'.
 */
void resetState() {
    gVisitOrder = 0;
    for (int i = 0; i < NODE_COUNT; i++) {
        gVisited[i] = UNSEEN;
    }
}


/**
 *  Print the entire contents of the 'gVisited' array to the screen.
 */
void printVisited() {
    for (int i = 0; i < NODE_COUNT; i++) {
        cout << ' ' << gVisited[i];
    }
    cout << '\n';
}
