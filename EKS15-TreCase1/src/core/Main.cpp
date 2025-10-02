#include <iostream>   // cout
#include "../../include/TreCase.h"

using std::cout;

int main() {
    Node* node6, * node8, * node11a, * node11b, * node12, * node13a, * node13b,
        * node17, * node28, * node31, * node33, * node34, * node35a, * node35b, * node39;
    /*
    Builds the tree:        17
                        /        \
                       11         33
                     /    \     /    \
                    6      13  28     35
                     \    /  \  \     / \
                      8  12  13  31  34  39
                         /            /
                        11           35
    */
    node8 = new Node(8, nullptr, nullptr);
    node11b = new Node(11, nullptr, nullptr);
    node13b = new Node(13, nullptr, nullptr);
    node31 = new Node(31, nullptr, nullptr);
    node34 = new Node(34, nullptr, nullptr);
    node35b = new Node(35, nullptr, nullptr);
    node12 = new Node(12, node11b, nullptr);
    node39 = new Node(39, node35b, nullptr);
    node6 = new Node(6, nullptr, node8);
    node13a = new Node(13, node12, node13b);
    node28 = new Node(28, nullptr, node31);
    node35a = new Node(35, node34, node39);
    node11a = new Node(11, node6, node13a);
    node33 = new Node(33, node28, node35a);
    node17 = new Node(17, node11a, node33);
    root = node17;

    cout << "\n\nTesting task A:\n";
    printRightmostPath();
    cout << "\n\n\n";   //  Output:  17 33 35 39 35

    cout << "Testing task B:\n";
    printPath(node31);
    cout << '\n';       //  Output:  17 33 28 31
    printPath(node8);
    cout << '\n';       //  Output:  17 11 6 8
    printPath(node35b);
    cout << '\n';       //  Output:  17 33 35 39 35
    printPath(node13b);
    cout << '\n';       //  Output:  17 11 13 13
    printPath(node11b);
    cout << '\n';       //  Output:  17 11 13 12 11
    printPath(node34);
    cout << "\n\n\n";   //  Output:  17 33 35 34

    cout << "Testing task C:\n";
    printAllLeafPaths(root);      //  Same output as the six previous lines,
    //     just a slightly different line order.

    cout << "\n\n";
    return 0;
}
