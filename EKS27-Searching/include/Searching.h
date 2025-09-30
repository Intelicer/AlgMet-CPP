/**
 *  Program example no. 27 - Searching - sequential and binary in (un)sorted array.
 *
 *  The example demonstrates searching in a:
 *        - UNSORTED array, using sequential search
 *        - SORTED array, using binary search
 *
 *  Order ( O(...)):
 *        - SEQUENTIAL search in an UNSORTED array:
 *             - N+1 comparisons (always) when not found
 *             - N/2 comparisons (on average) when found
 *        - BINARY search in a SORTED array:
 *             - No more than  lgN + 1  comparisons for searches
 *               that BOTH find and do not find the value
 *
 *        - For a SORTED LIST, you MUST search sequentially.
 *          Then the order (on average) would be
 *          N/2 comparisons, both when found and not found
 *          (since you stop searching where it IS/SHOULD HAVE BEEN).
 *
 *  @file     EX_27_Searching.cpp
 *  @author   Frode Haug, NTNU
 */


#include <iostream>          //  cout
#include <iomanip>           //  setw
#include <cstdlib>           //  (s)rand
using namespace std;




/**
 *  Prints the entire contents of an array.
 *
 *  @param   arr      -  The array whose entire contents will be printed
 *  @param   n        -  Number of elements in 'arr'
 */
void display(const int arr[], const int n);



/**
 *  Binary search in a SORTED array.
 *
 *  @param    arr    - Sorted array to search in
 *  @param    value  - The value whose index is sought in 'arr'
 *  @param    n      - Number of elements in 'arr'
 *  @return   The index in 'arr' where 'value' was found (0-zero if not found)
 */
int  binarySearch(const int arr[], const int value, const int n);


/**
 *  Sequential search in an UNSORTED array.
 *
 *  @param    arr    - Unsorted array to search in
 *  @param    value  - The value whose index is sought in 'arr'
 *  @param    n      - Number of elements in 'arr'
 *  @return   The index in 'arr' where 'value' was found (0-zero if not found)
 */
int  sequentialSearch(const int arr[], const int value, const int n);



