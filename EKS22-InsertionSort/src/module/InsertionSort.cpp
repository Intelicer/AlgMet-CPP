#include "../../include/InsertionSort.h"


void printArray(const int arr[], const int n) {
    for (int i = 1; i < n; i++) {
        cout << ' ' << arr[i];
    }
    cout << '\n';
}


void insertionSort(int arr[], const int n) {
    int i, j,                      //  Loop variables.
        value;                     //  The value/element that may be
    //    moved down/inserted.
    for (i = 2; i < n; i++) {    //  Walks from no. 2 through the array:
        value = arr[i];            //  The one that may be moved down.
        j = i;                     //  Initialize to the current element.
        while (arr[j - 1] > value) { //  As long as the previous is larger:
            arr[j] = arr[j - 1];     //  Shift it up ONE slot/index.
            j--;                   //  Decrease 'j' until we hit the
        }                          //    SENTINEL key!
        arr[j] = value;            //  Insert where 'j' stopped.
    }
}