/**
 *   Program example no. 21 - Selection sort.
 *
 *   Algorithm/behavior:
 *          Finds the smallest element in the remaining part of the array
 *          starting from index 'i', and places it at position 'i'.
 *          Let 'i' increase toward 'N'.
 *
 *   Order ( O(...)):
 *          Uses approximately (N*N)/2 comparisons and N swaps.
 *
 *   NOTE: - Is LINEAR when the values being compared are small while any
 *           associated data are large. That means you should keep the number
 *           of swaps to a minimum, since a LOT of associated data must be
 *           moved around for each swap.
 *         - Is NOT STABLE. "Stable" means that equal elements retain the same
 *           relative order after sorting.
 *               The following example shows this:    SMS'AS"
 *               The first S will swap with the smallest (i.e., A). Thus it is
 *               actually correctly placed, while S has ended up between S' and S".
 *
 *   @file     EKS_21_SelectionSort.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>          //  cout
#include <cstdlib>           //  (s)rand
using namespace std;


const int N = 20;            ///<  Number of elements in the array to be sorted.

/**
 *  Swaps the contents of two pass-by-reference variables.
 *
 *  @param   value1  -  The value to be swapped with 'value2' (passed by reference)
 *  @param   value2  -  The value to be swapped with 'value1' (passed by reference)
 */
void swapValues(int& value1, int& value2);

/**
 *  Prints the ENTIRE contents of array 'arr'.
 *
 *  @param   arr  -  The array whose full content will be printed
 *  @param   n    -  Number of elements in the array (last used index is n-1)
 */
void displayArray(const int arr[], const int n);

/**
 *  Sorts an input array in ASCENDING order using SELECTION SORT.
 *
 *  @param   arr  -  The array to be sorted
 *  @param   n    -  Number of elements in array 'arr'
 *  @see     swapValues(...)
 */
void selectionSort(int arr[], const int n);




