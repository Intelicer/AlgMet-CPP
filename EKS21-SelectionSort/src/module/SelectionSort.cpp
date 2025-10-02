#include "../../include/SelectionSort.h"

void swapValues(int& value1, int& value2) {
    int temp = value1;           //  Temporary storage.
    value1 = value2;
    value2 = temp;
}



void displayArray(const int arr[], const int n) {
    for (int i = 0; i < n; i++) {
        cout << ' ' << arr[i];
    }
    cout << '\n';
}



void selectionSort(int arr[], const int n) {
    int i, j,                      //  Loop variables
        minIndex;                  //  Index of the SMALLEST value
    //    within the current search interval.
    for (i = 0; i < n - 1; i++) {  //  Goes up to the NEXT-TO-LAST element:
        minIndex = i;              //  Initialize to the FIRST of the remaining.
        for (j = i + 1; j < n; j++) {   //  Find the smallest AFTER index 'i':
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swapValues(arr[minIndex], arr[i]);  //  Move it down to position 'i'.
    }
}
