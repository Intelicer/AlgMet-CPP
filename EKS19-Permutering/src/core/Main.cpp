
#include "../../include/Permutering.h"
#include <iostream>   // cout

using namespace std;


/**
 *  Main program:
 */
int main() {
    int numbers[N];                    //  Array to be permuted.

    for (int idx = 0; idx < N; idx++) { //  Fill array with: 1, 2, 3, ..., N
        numbers[idx] = idx + 1;
    }

    permute(numbers, 0, N);            //  Create (and print) permutations of
    //    ALL array elements.
    cout << '\n';
    printArray(numbers, N);            //  Print array after finishing
    //    (to show original is restored).

    cout << "\n\n";
    return 0;
}