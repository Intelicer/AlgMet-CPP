#include "../../include/BST.h"
using namespace std;

int main() {
    BST <char, string> bst;

    bst.insert('L', "Liam");     /*  Builds the search tree (inside 'BST'):  */
    bst.insert('C', "Charlie");  /*               L                           */
    bst.insert('F', "Frank");    /*          /         \                      */
    bst.insert('T', "Tony");     /*        C             T                    */
    bst.insert('P', "Pat");      /*          \          /                     */
    bst.insert('N', "Nigel");    /*           F        P                      */
    bst.insert('S', "Steve");    /*            \     /   \                    */
    bst.insert('R', "Ray");      /*             I   N      S                  */
    bst.insert('I', "Ian");      /*                  \    /                   */
    bst.insert('O', "Oliver");   /*                   O  R                    */
    bst.display();   cout << "\n\n";

    cout << "ExtraData fetched: " << bst.search('C') << '\n';
    cout << "ExtraData fetched: " << bst.search('N') << '\n';
    cout << "ExtraData fetched: " << bst.search('Q') << '\n';   //  Does not exist!

    if (bst.remove('L')) { cout << "\nRemoved 'L':\n"; }        //  Case 3
    bst.display();

    if (bst.remove('T')) { cout << "\nRemoved 'T':\n"; }        //  Case 1
    bst.display();

    if (bst.remove('C')) { cout << "\nRemoved 'C':\n"; }        //  Case 2
    bst.display();

    cout << "\n\n";
    return 0;
}
