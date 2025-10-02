#include "../../include/Permutering.h"

int gSolutionCount;

void swapValues(int& value1, int& value2) {
    int temp = value1;              //  Temporary storage.
    value1 = value2;
    value2 = temp;
}



void displayArray(const int arr[], const int n) {
    cout << "\nSolution no." << ++gSolutionCount << ":";
    for (int i = 0; i < N; i++) {
        if (i % 4 == 0) { cout << '\n'; }
        cout << setw(5) << arr[i];
    }
    cout << '\n';
}


void permute(int arr[], const int i, const int n) {
    if (i == n - 1 && hasRightSum(arr, i)) {  //  Reached a new LEGAL permutation:
        displayArray(arr, n);                 //  Print the array content.
    }
    else {                                  //  Need to permute:
        //  Not at the end of a row,
        //    or last row sum = 34 !!!
        if ((i + 1) % 4 != 0 || hasRightSum(arr, i)) {
            permute(arr, i + 1, n);           //  Keep current no. 'i'.
        }                                     //  Permute the rest.
        for (int t = i + 1; t < n; t++) {
            swapValues(arr[i], arr[t]);       //  Swap no. 'i' in turn with
            //    ALL the subsequent ones.
            //  Not at the end of a row,
            //    or last row sum = 34 !!!
            if ((i + 1) % 4 != 0 || hasRightSum(arr, i)) {
                permute(arr, i + 1, n);       //  For each swap: permute
            }                                  //     the remaining subsequent.
        }
        rotateLeft(arr, i, n);                //  Restore the original array!!!
    }
}


bool hasRightSum(int arr[], int n) {
    if (arr[n - 3] + arr[n - 2] + arr[n - 1] + arr[n] != 34) { // Last ROW SUM = 34?
        return false;
    }
    if (n == N - 1) {                          //  Permuted the ENTIRE array:
        for (int i = 0; i < 4; i++) {          //  ALL column sums = 34?
            if (arr[0 + i] + arr[4 + i] + arr[8 + i] + arr[12 + i] != 34) {
                return false;
            }
        }
        if (arr[0] + arr[5] + arr[10] + arr[15] != 34) { //  MAIN DIAGONAL sum = 34?
            return false;
        }
        if (arr[3] + arr[6] + arr[9] + arr[12] != 34) {  //  ANTI-DIAGONAL sum = 34?
            return false;
        }
    }
    return true;
}



void rotateLeft(int arr[], const int i, const int n) {
    int leftValue = arr[i];                 //  Store the first element.
    for (int k = i + 1; k < n; k++) {       //  Rotate (shift all down by
        arr[k - 1] = arr[k];                //     ONE position/index).
    }
    arr[n - 1] = leftValue;                 //  Put the first element at the end.
}