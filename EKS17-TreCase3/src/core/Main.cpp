#include <iostream>   // cout
#include "../../include/TreCase.h"

using namespace std;

/**
 *  Main program:
 */
int main() {
    int sumLevels = 0, count = 0;  //  Important that both are zeroed.

    srand(0);                      //  Used for randomness.

    cout << "\nNodes in the initial tree:\n";
    //  Generates a test tree (max. 5 levels,
    gRoot = generate(5, 80);      //      80% chance to create a subtree)
    traverse(gRoot);              //  Traverses (and shows) the tree.
    getchar();

    cout << "\n\nTesting task A - Nodes after 'level' has been set:\n";
    setLevels(gRoot);             //  Sets ALL nodes' levels.
    traverse(gRoot);              //  Traverses (and shows) the tree.
    getchar();

    cout << "\n\nTesting task B - Finding TOTAL levels and number of nodes:\n";
    gatherValues(gRoot, sumLevels, count);   //  Finds the sum of node levels
    //      and the count.
    cout << "Sum of levels:  " << sumLevels << "\tCount: " << count << '\n';

    cout << "Average level in the tree:  "          //  Computes average level.
        << static_cast<float>(sumLevels) / count;
    getchar();

    cout << "\n\nTesting task C - All leaf nodes' ancestors:\n";
    printAncestors(gRoot);         //  Prints predecessors for ALL leaf nodes.
    cout << "\n\n";
    return 0;
}
