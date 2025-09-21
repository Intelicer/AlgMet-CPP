#include "../../include/Oblig2.h"
/**
 *  Main program:
 */
int main() {

    // (so we don’t have head->right as root)
    Node* gRoot1 = nullptr, * gRoot2 = nullptr; ///< 2x root pointers

    gRoot1 = buildTree();     gRoot2 = buildTree();

    //  Test 3A - Two identical trees:
    cout << "\n\nBoth trees are "
        << (!areTreesIdentical(gRoot1, gRoot2) ? "NOT " : "") << "identical.";

    //  Test 3A - Two non-identical trees:
    delete gRoot2->right->right->left;     //  Deletes node no.10 in tree no.2
    gRoot2->right->right->left = nullptr;
    cout << "\n\nBoth trees are "
        << (!areTreesIdentical(gRoot1, gRoot2) ? "NOT " : "") << "identical.";

    //  Test 3A - Two identical trees again:
    delete gRoot1->right->right->left;     //  Deletes node no.10 also in tree no.1
    gRoot1->right->right->left = nullptr;
    cout << "\n\nBoth trees are "
        << (!areTreesIdentical(gRoot1, gRoot2) ? "NOT " : "") << "identical.";

    //  Test 3B - The tree is NOT symmetric:
    cout << "\n\nThe tree is "
        << (!isTreeSymmetric(gRoot1, gRoot1) ? "NOT " : "") << "symmetric.";

    //  Test 3B - The tree is NOT symmetric:
    delete gRoot1->right->right->right;       //  Deletes node no.11 in tree no.1
    gRoot1->right->right->right = nullptr;
    //  The trees are structurally symmetric,
    cout << "\n\nThe tree is "     //     but the IDs are not.
        << (!isTreeSymmetric(gRoot1, gRoot1) ? "NOT " : "") << "symmetric.";

    //  Test 3B - The tree IS symmetric:
    setAllIDsEqual(gRoot1); // Sets all IDs equal, therefore now symmetric.
    cout << "\n\nThe tree is "
        << (!isTreeSymmetric(gRoot1, gRoot1) ? "NOT " : "") << "symmetric.";

    cout << "\n\n\n";
    return 0;
}