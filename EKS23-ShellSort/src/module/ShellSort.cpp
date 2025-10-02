#include "../../include/ShellSort.h"





void printArray(const char arr[], const int n) {
    for (int i = 1; i < n; i++) {
        cout << arr[i];
    }
    cout << '\n';
}



void shellSort(char arr[], const int n) {
    int  i, j, h;                  //  Loop variables.
    char value;                    //  The value/element that may be
    //    moved backwards in the subarray.

    for (h = 1; h <= n / 9; h = (3 * h) + 1) {}  //  NOTE: Empty for-loop!!!
    //  i.e., 'h' = 1, 4, 13, 40, 121, 364, ...
    //  Here: 21/9 = 2, then 'h' becomes 4!!!
    //  With 36 elements or A LITTLE more:
    //    36/9 = 4, THEN h becomes 13.

    while (h > 0) {                //  As long as there are subarrays:

        for (i = h + 1; i < n; i++) {   //  Go through the subarrays:
            value = arr[i];        //  The one that may be moved within the subarray.
            j = i;                 //  Initialize to the current element.
            //          logState("Before", arr, i, j, h, value);
                                               //  As long as there is one in the subarray
                                               //    'h' positions earlier and it is larger:
            while (j > h && arr[j - h] > value) {
                //              logState("Inside - start", arr, i, j, h, value);
                arr[j] = arr[j - h]; // Move it up 'h' positions.
                j -= h;              // Index becomes 'h' positions earlier.
                //              logState("Inside - end", arr, i, j, h, value);
            }
            arr[j] = value;        //  Slip it in where 'j' stopped.
            //          logState("After", arr, i, j, h, value);
        }
        //      cout << "\n\nH = " << h << " is done!!\n\n";
        //      getchar();
        h /= 3;                    //  'h' decreases to 1/3 for each loop.
    }
}



void logState(const string& label, const char arr[],
    const int i, const int j, const int h, const char value) {

    cout << '\n' << label << ":\t";

    if (label == "After") {
        cout << "Comparison performed,";
        if (j <= h) {
            cout << "\tJ <= H\t\t";
        }
        else {
            cout << "\t'" << arr[j - h] << "' <= '" << value << "'\t";
        }
        printArray(arr, N + 1);
    }   //  i.e., "Before", "Inside - start", and "Inside - end":
    else {
        if (label == "For") {
            cout << '\t';
        }
        cout << "H: " << h
            << "\tI: " << i << "\tJ: " << j
            << "\tJ-H: " << j - h;
        if (label == "Inside - end") {
            cout << "  ";
            printArray(arr, N + 1);
        }
        else {   //  i.e., "Before" and "Inside - start":
            cout << "\t\tarr[" << j - h << "]: '" << arr[j - h]
                << "'  >  value: '" << value << "'";
            if (label == "For") {
                cout << "   ?";
            }
            else {
                cout << "   !!!";   //  i.e., "Inside - start"
            }
        }
    }
    getchar();
}