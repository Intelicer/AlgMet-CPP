#include "../../include/QuickSort.h"

const int N = 20;            ///<  Number of elements in the array to be sorted.


/**
 *  Main program:
 */
int main() {
    char array[N + 1];                 //  Array to be sorted.
    //  Uses indices 1–N
    //    since index 0 holds the
    //    SENTINEL KEY (STOP VALUE) !!!

    srand(0);                        //  Used for randomness.

    array[0] = ' ';                  //  Insert SENTINEL KEY !!!

    for (int i = 1; i <= N; i++) {   //  Fill array with random letters A–Z:
        array[i] = static_cast <char> ('A' + (rand() % 26));
    }

    display("\n\nArray BEFORE sorting:\n", array, 1, N);

    quickSort(array, 1, N);          //  QUICKSORT SORTS !!!

    //  Print array AFTER sorting:
    display("\n\nArray AFTER QUICKSORT sorting:\n", array, 1, N);

    cout << "\n\n";
    return 0;
}