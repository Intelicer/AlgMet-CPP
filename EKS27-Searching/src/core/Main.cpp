#include "../../include/Searching.h"

const int N = 20;            ///<  Number of elements in the array to search.

/**
 *  Main program:
 */
int main() {
    int data[N + 1];                 //  Array to be searched.
    //  Uses indices 1 to N,
    //   since 0 (zero) means: "Not found".

    srand(0);                      //  Used for randomness.

    for (int i = 1; i <= N; i++) { //  Array with random numbers 1-100:
        data[i] = (rand() % 100) + 1;
    }

    cout << "\n\nArray with indexes:\n";
    display(data, N);

    cout << "\n54 has index no. " << sequentialSearch(data, 54, N) << '\n';
    cout << "\n56 has index no. " << sequentialSearch(data, 56, N) << '\n';
    cout << "\n39 has index no. " << sequentialSearch(data, 39, N) << '\n';
    cout << "\n17 has index no. " << sequentialSearch(data, 17, N) << '\n';
    cout << "\n 4 has index no. " << sequentialSearch(data, 4, N) << '\n';


    // ***************************************************************************

    for (int i = 1; i <= N; i++) {  //  Convert to a sorted array with even numbers.
        data[i] = i * 2;
    }

    cout << "\n\n\nSORTED array with even numbers:\n";
    display(data, N);

    cout << "\n24 has index no. " << binarySearch(data, 24, N) << '\n';
    cout << "\n 8 has index no. " << binarySearch(data, 8, N) << '\n';
    cout << "\n 7 has index no. " << binarySearch(data, 7, N) << '\n';
    cout << "\n98 has index no. " << binarySearch(data, 98, N) << '\n';

    cout << "\n\n";
    return 0;
}