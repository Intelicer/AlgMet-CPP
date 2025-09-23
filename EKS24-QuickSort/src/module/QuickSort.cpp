#include "../../include/QuickSort.h"



void swapChars(char& c1, char& c2) {
    char temp = c1;           //  Temporary storage.
    c1 = c2;
    c2 = temp;
}



void display(const string& text, const char arr[],
    const int left, const int right) {
    cout << text << "\t";
    for (int i = left; i <= right; i++) {
        cout << arr[i];
    }
    getchar();                            //  Waits for one ENTER.
}



int partition(char arr[], const int left, const int right) {
    if (right > left) {                 //  At least TWO elements:
        int i, j;                       //  Indices moving toward each other.
        char pivot;                     //  The pivot element.

        pivot = arr[right];             //  Initialize with RIGHT element.
        i = left - 1;                     //  Indices initialized just
        j = right;                      //    outside the interval.
        //  NOTE: 'i' and 'j' increment/decrement BEFORE use.
        //        They stop on the correct indices
        //        without "skipping" too far.
//                            display("\nBefore:", arr, left, right);
        while (true) {                  //  Loop until break:
            //  Search for GREATER OR EQUAL:
            while (arr[++i] < pivot) {
                ;                       //  Empty body !!!
            }
            //  Search for SMALLER OR EQUAL:
            while (arr[--j] > pivot) {
                ;                       //  Empty body !!!
            }

            //                             cout << "i: " << i << "  j: " << j << "   - "
            //                                  << ((i < j) ? "Swap" : "BREAK") << '\n';
            if (i >= j) {
                break;                  //  Indices have met/crossed.
            }
            swapChars(arr[i], arr[j]);  //  Swap at indices i and j.
        }

        swapChars(arr[i], arr[right]);  //  Finally swap pivot
        //    with the very rightmost element
        //    in the LEFT HALF (where 'i' is).
//                             display("After:", arr, left, right);
        return i;                       //  Return pivot’s new position
    }
    return 0;                           //  Less than two elements → dummy.
}


/**
 *  Recursively sorts a char array ASCENDING with QUICKSORT.
 *
 *  @param   arr     -  The array to be sorted
 *  @param   left    -  Lower/left index of sorting interval
 *  @param   right   -  Upper/right index of sorting interval
 *  @see     partition(...)
 */
void quickSort(char arr[], const int left, const int right) {
    if (right > left) {                  //  At least TWO elements:
        int index = partition(arr, left, right);    //  Partition!!!
        quickSort(arr, left, index - 1);   //  Sort left half
        quickSort(arr, index + 1, right);  //  Sort right half
    }
}
