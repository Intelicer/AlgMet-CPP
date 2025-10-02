#include "../../include/ShellSort.h"
#include <iostream>


/**
 *  Main program:
 */
int main() {
    char data[N + 1];              //  Array to be sorted.
    //  Uses indices 1–N
    //    since element no. 0 contains a
    //    SENTINEL KEY (STOP VALUE)!!!

    srand(0);                      //  Used for randomness.

    data[0] = ' ';                 //  Insert SENTINEL KEY!!!

    for (int i = 1; i <= N; i++) { //  Array with random letters A–Z:
        data[i] = static_cast<char>('A' + (rand() % 26));
    }

    cout << "\n\nArray BEFORE sorting:\n\t";
    printArray(data, N + 1);       //  Print array BEFORE sorting.


    shellSort(data, N + 1);        //  SHELL SORT SORTS!!!


    cout << "\n\nArray AFTER SHELL SORT:\n\t";
    printArray(data, N + 1);       //  Print array AFTER sorting.

    cout << "\n\n";
    return 0;
}