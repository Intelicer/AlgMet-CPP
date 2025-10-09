#include "../../include/DFS-BFS.h"
using namespace std;


/**
 *  Main program:
 */
int main() {
    int i;

    cout << "\n\n DEPTH-FIRST SEARCH (DFS) using adjacency MATRIX:\n";
    resetState();                          //  Reset helper variables.

    for (i = 0; i < NODE_COUNT; i++) {     //  Go through ALL nodes:
        if (gVisited[i] == UNSEEN) {       //  Visit the first UNSEEN encountered
            DFS(i);                        //    in EACH COMPONENT !!!
        }
    }


    cout << "\n\n BREADTH-FIRST SEARCH (BFS) using adjacency MATRIX:\n";
    resetState();

    for (i = 0; i < NODE_COUNT; i++) {
        if (gVisited[i] == UNSEEN) {
            BFS(i);
        }
    }



    cout << "\n\n DEPTH-FIRST SEARCH (DFS) using adjacency LIST:\n";
    resetState();
    initAdjList();

    for (i = 0; i < NODE_COUNT; i++) {
        if (gVisited[i] == UNSEEN) {
            DFS_List(i);
        }
    }



    cout << "\n\n";
    return 0;
}
