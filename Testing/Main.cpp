/**
 *  Program Example No. 20 - Number placement (under certain rules) in a grid.
 *
 *  For the program’s functionality see:  PermutationExample.pdf
 *
 *  The example is ALMOST IDENTICAL to EKS_19_Permutation.cpp,
 *  except that:
 *     - the function 'hasRightSum(...)' is new
 *     - the content of 'permute' is slightly extended (with if-statements)
 *     - 'displayArray' is slightly rewritten
 *
 *  (This was problem no. 5 on the exam 1994-12-15 in LO164A-Algorithmic Methods)
 *
 *  @file     EKS_20_PermutationExample.CPP
 *  @author   Frode Haug, NTNU
 */


#include <iostream>                 //  cout
#include <iomanip>                  //  setw
using namespace std;


const int N = 16;                   ///<  Array length.

int gSolutionCount;                 ///<  Number of solutions found (so far).
//    There are 7040 solutions (including
//      mirrorings and rotations).
//    There are 416 solutions when '1' is
//      fixed in the upper-left corner.
void swapValues(int& value1, int& value2);
void displayArray(const int arr[], const int n);
void permute(int arr[], const int i, const int n);
bool hasRightSum(int arr[], int n);
void rotateLeft(int arr[], const int i, const int n);


/**
 *  Main program:
 */
int main() {
    int arr[N];                     //  Array to be permuted.

    for (int i = 0; i < N; i++) {   //  Fill array with: 1, 2, 3, ..., N
        arr[i] = i + 1;
    }

    permute(arr, 0, N);             //  Create (and print) permutations of
    //    ALL array elements.
    cout << '\n';
    displayArray(arr, N);           //  Print array after finishing
    //    (to show original is restored).

    cout << "\n\n";
    return 0;
}


/**
 *  Swaps the contents of two pass-by-reference variables.
 *
 *  @param   value1  -  The value to be swapped with 'value2' (by reference)
 *  @param   value2  -  The value to be swapped with 'value1' (by reference)
 */
void swapValues(int& value1, int& value2) {
    int temp = value1;              //  Temporary storage.
    value1 = value2;
    value2 = temp;
}


/**
 *  Prints the ENTIRE content of array 'arr'.
 *
 *  @param   arr  -  The array whose entire content will be printed
 *  @param   n    -  Number of elements in the array (last used index is n-1)
 */
void displayArray(const int arr[], const int n) {
    cout << "\nSolution no." << ++gSolutionCount << ":";
    for (int i = 0; i < N; i++) {
        if (i % 4 == 0) { cout << '\n'; }
        cout << setw(5) << arr[i];
    }
    cout << '\n';
}


/**
 *  Recursively generates ALL possible permutations of 'arr' content.
 *
 *  @param   arr  -  The array to permute
 *  @param   i    -  The index that ALL SUBSEQUENT values should be moved to
 *  @param   n    -  Number of elements in the array (last used index is n-1)
 *  @see     swapValues(...)
 *  @see     displayArray()
 *  @see     hasRightSum(...)
 *  @see     rotateLeft(...)
 */
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


/**
 *  Checks whether 'arr' satisfies the requirements described in PermutationExample.pdf.
 *
 *  @param    arr  -  The array to check for 34-sums
 *  @param    n    -  The index to check BACKWARDS from
 *  @return   Whether ALL 10 row/column/diagonal sums are 34 or not
 */
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


/**
 *  Left-rotates part of an array’s content.
 *
 *  @param   arr  -  The array whose (part of) content is left-rotated
 *  @param   i    -  Lowest index to be left-rotated
 *  @param   n    -  'n-1' is the highest index to be left-rotated
 */
void rotateLeft(int arr[], const int i, const int n) {
    int leftValue = arr[i];                 //  Store the first element.
    for (int k = i + 1; k < n; k++) {       //  Rotate (shift all down by
        arr[k - 1] = arr[k];                //     ONE position/index).
    }
    arr[n - 1] = leftValue;                 //  Put the first element at the end.
}
