#include "../../include/Searching.h"


void display(const int arr[], const int n) {
    cout << ' ';
    for (int i = 1; i <= n; i++) {                 //  Print the indexes:
        cout << setw(3) << i << ':';
    }
    cout << '\n';
    for (int i = 1; i <= n; i++) {                 //  Print the array contents:
        cout << setw(4) << arr[i];
    }
    cout << '\n';
}

int binarySearch(const int arr[], const int value, const int n) {
    int left = 1,                          //  Initialize left and right
        right = n,                         //    outer bounds of the search area.
        middle;                            //  The MIDDLE of this search area.

    while (left <= right) {                //  Still something to search, and NOT found:
        middle = (left + right) / 2;       //  Compute/find the midpoint.
        //  Is this the one we seek?
        if (value == arr[middle]) { return middle; }    //  Return index.
        //  Is it in the left/right half?
        if (value < arr[middle]) { right = middle - 1; }  //  Update the current
        else { left = middle + 1; }                        //    outer bound.
    }
    return 0;                               //  Not found: return 0 (zero).
}


int sequentialSearch(const int arr[], const int value, const int n) {
    int index = n + 1;                      //  Initialize to AFTER the array!
    //  As long as within the array and
    //    NOT found, keep searching:
    while (index > 0 && value != arr[--index]) {   //  NOTE:  EMPTY BODY !!
    }
    return (index);                         //  Return the index or 0.
}
