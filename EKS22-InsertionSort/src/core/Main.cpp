#include "../../include/InsertionSort.h"
#include <iostream>


/**
 *  Main program:
 */
int main() {
    int array[N + 1];                //  Array to be sorted.
    //  Uses indices 1..N
    //    because there is a SENTINEL KEY
    //    (STOP VALUE) in element no. 0 !!!

    srand(0);                      //  Used for randomness.

    array[0] = -1;                 //  Insert SENTINEL KEY !!!

    for (int i = 1; i <= N; i++) { //  Fill array with random numbers 1–100:
        array[i] = (rand() % 100) + 1;
    }

    cout << "\n\nArray BEFORE sorting:\n\t";
    printArray(array, N + 1);        //  Print array BEFORE sorting.


    insertionSort(array, N + 1);     //  INSERTION SORTS !!!


    cout << "\n\nArray AFTER INSERTION sort:\n\t";
    printArray(array, N + 1);        //  Print array AFTER sorting.

    cout << "\n\n";
    return 0;
}
