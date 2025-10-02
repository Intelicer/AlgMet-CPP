/**
 *   Program example no. 22 - Insertion sort.
 *
 *   Algorithm/behavior:
 *        Repeatedly takes the next element in the array and inserts it
 *        where it belongs among the elements already sorted earlier in the array.
 *        When a new absolute smallest element is found, the while-loop can
 *        step past the array’s lower bound (index 0). Therefore, element no. 0
 *        contains a value that is smaller than EVERYTHING else in the entire array.
 *        This is called a "SENTINEL KEY" (STOP VALUE).
 *
 *   Order ( O(...)):
 *        Uses roughly (N*N)/4 comparisons and (N*N)/8 swaps ON AVERAGE.
 *        In the WORST CASE (already reverse-sorted): TWICE as much.
 *
 *   Notes:
 *     - Nearly LINEAR for almost-sorted arrays, because the while-loop
 *       runs zero/few times per element. Then it outperforms ALL other
 *       methods (also Quicksort and Heapsort).
 *     - Also fast when ALL elements are already fully sorted, and you append
 *       a VERY SMALL number at the end which must be inserted/moved in.
 *     - Stable?   See exercise no. 10.
 *
 *   @file     EKS_22_InsertionSort.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>          //  cout
#include <cstdlib>           //  (s)rand
using namespace std;


const int N = 20;            ///<  Number of elements in the array to be sorted.


/**
 *  Prints the ENTIRE contents of array 'arr'.
 *
 *  @param   arr  -  The array whose entire contents will be printed
 *  @param   n    -  Number of elements in the array (last used index is n-1)
 */
void printArray(const int arr[], const int n);


/**
 *  Sorts an input array in ASCENDING order using INSERTION SORT.
 *
 *  @param   arr  -  The array to be sorted
 *  @param   n    -  Number of elements in array 'arr'
 */
void insertionSort(int arr[], const int n);