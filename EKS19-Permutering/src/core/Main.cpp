
#include "../../include/Permutering.h"
#include <iostream>   // cout

using namespace std;


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
