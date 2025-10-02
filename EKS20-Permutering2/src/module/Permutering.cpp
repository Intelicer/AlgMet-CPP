#include "../../include/Permutering.h"

void swapValues(int& value1, int& value2) {
    int temp = value1;           //  Temporary storage.
    value1 = value2;
    value2 = temp;
}


void printArray(const int arr[], const int n) {
    //                       cout << "\tPrint: ";
    for (int i = 0; i < n; i++) {
        cout << ' ' << arr[i];
    }
    cout << '\n';
}


void permute(int arr[], const int i, const int n) {
    //                       cout << "Permute: " <<  i << ", " << n << '\n';
    if (i == n - 1) {                   //  Reached a new permutation:
        printArray(arr, n);             //  Print the array contents.
    }
    else {                            //  Need to permute:
        permute(arr, i + 1, n);         //  Keep current at index 'i'.
        //    Permute the rest.
        for (int t = i + 1; t < n; t++) {
            swapValues(arr[i], arr[t]); //  Swap index 'i' in turn with
            //    EACH of the subsequent ones.
//                       cout << "Swap: " << i << " <-> " << t << '\n';
            permute(arr, i + 1, n);     //  For each swap: permute
        }                               //    the rest of the subsequent ones.
//                       cout << "Rotate left: " <<  i << ", " << n << '\n';
        rotateLeft(arr, i, n);          //  Restore the original array!!!
    }
}


void rotateLeft(int arr[], const int i, const int n) {
    int leftmostValue = arr[i];            //  Save the first element.
    for (int k = i + 1; k < n; k++) {    //  Rotate (shift all down
        arr[k - 1] = arr[k];               //     ONE step/index).
    }
    arr[n - 1] = leftmostValue;            //  Place the first element at the end.
}
