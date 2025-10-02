/**
 *   Program example no. 23 - Shell sort.
 *
 *   Algorithm/behavior:
 *        Treat every h'th element as part of a subarray.
 *        Iterate (starting at 'h' + 1) and sort (via insertion sort)
 *        ALL such subarrays. Let 'h' move toward 1.
 *
 *   Order ( O(...)):
 *        NEVER does more than N^(3/2) (i.e., N to the 3/2) comparisons
 *        for 'h' values: 1, 4, 13, 40, 121, 364, 1093, .....
 *        (These are good choices for 'h'. Hardly any values are better/faster.
 *        Quite a bit of mathematical analysis exists for different gap sequences.
 *        So another common description of the order is: N*logN*logN)
 *
 *   NOTE: - When 'h' equals 1, Shell sort is the same as Insertion sort!!!
 *         - Feel free to use shell sort! Unless it’s worth replacing
 *           with more sophisticated/advanced ones (like Quicksort, etc.).
 *           Those are NOT THAT much faster!
 *         - Uses a SENTINEL KEY.
 *         - Stable?   See exercise no. 10.
 *
 *   @file     EKS_23_ShellSort.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>          //  cout
#include <string>            //  string
#include <cstdlib>           //  (s)rand
using namespace std;


const int N = 20;            ///<  Number of elements in the array to be sorted.

/**
 *  Prints the ENTIRE content of array 'arr'.
 *
 *  @param   arr  -  The array whose entire content is printed
 *  @param   n    -  Number of elements in the array (last index used is n-1)
 */
void printArray(const char arr[], const int n);

/**
 *  Sorts a char array ASCENDING with SHELL SORT.
 *
 *  @param   arr  -  The array to be sorted
 *  @param   n    -  Number of elements in the array 'arr'
 *  @see     logState(...)
 */
void shellSort(char arr[], const int n);

/**
 *  Prints a label, the array’s content, and many helper-variable values.
 *
 *  @param   label  -  Label printed first
 *  @param   arr    -  Array whose content or element is printed
 *  @param   i      -  Index that increases
 *  @param   j      -  Index that decreases
 *  @param   h      -  Looks at every h'th element backwards
 *  @param   value  -  The element/value that may be moved backwards
 */
void logState(const string& label, const char arr[],
    const int i, const int j, const int h, const char value);
