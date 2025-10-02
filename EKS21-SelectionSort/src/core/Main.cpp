#include "../../include/SelectionSort.h"

/**
 *  The main program:
 */
int main() {
    int values[N];                 //  Array to be sorted.

    srand(0);                      //  Used for randomness.

    for (int i = 0; i < N; i++) {  //  Fills array with random numbers 1–100:
        values[i] = (rand() % 100) + 1;
    }

    cout << "\n\nArray BEFORE sorting:\n\t";
    displayArray(values, N);       //  Prints array BEFORE sorting.


    selectionSort(values, N);      //  PERFORM SELECTION SORT !!!


    cout << "\n\nArray AFTER SELECTION sort:\n\t";
    displayArray(values, N);       //  Prints array AFTER sorting.

    cout << "\n\n";
    return 0;
}
