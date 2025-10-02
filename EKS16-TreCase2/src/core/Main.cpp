#include <iostream>   // cout
#include "../../include/TreCase.h"

using namespace std;
/**
 *  Main program:
 */
int main() {

    srand(0);                   //  Used for randomness.

    cout << "\nNodes in the initial tree:\n";
    //  Generates a test tree (max. 5 levels,
    gRoot = generate(5, 80);   //      80% chance to create a subtree)
    traverse(gRoot);           //  Traverses (and shows) the tree.
    getchar();

    cout << "\n\nTesting task A - Nodes after 'sum' has been set:\n";
    setSum(gRoot);
    traverse(gRoot);
    getchar();

    cout << "\n\nTesting task B - Nodes after 'parent' has been set:\n";
    setParent(gRoot);
    traverse(gRoot);

    cout << "\n\n";
    return 0;
}
