/**
 *   Program Example no. 24 - Quicksort.
 *
 *   Algorithm / working principle:
 *        Principle: Divide and conquer, partition into two, sort each part.
 *        This is done by:
 *         - choosing arr[right] as the pivot element/value.
 *         - searching from the left for a greater or equal value, and from
 *           the right for a smaller or equal value, and then swapping them.
 *         - repeating the previous step until the searches have crossed.
 *         - finally swapping arr[right] (the pivot element) with the element
 *           at index 'i' (the very rightmost in the left subarray).
 *        All of this means:
 *         - The pivot element in arr[i] is now in its final place
 *         - ALL values in arr[left] to arr[i-1] are LESS THAN OR EQUAL
 *         - ALL values in arr[i+1] to arr[right] are GREATER THAN OR EQUAL
 *
 *   Complexity:
 *        Quicksort uses on average about  2N ln N  comparisons
 *        (? 1.39N log? N).     "Worst case":  (N*N)/2
 *
 *   NOTE:
 *        - The code in the function 'partition' could also just be moved into
 *          'quickSort' - then it runs even faster.
 *        - Whether to pick the far-right or far-left element as pivot is a
 *          matter of taste. The key is to choose and stay consistent.
 *          ==============================================================
 *          In the code below, the far-right element is used as pivot, and
 *          this is also the assumption on assignments/exams!
 *          ==============================================================
 *        - Quicksort also swaps equal elements with the pivot. If the whole
 *          array had ONLY equal elements, we would otherwise hit the worst
 *          case. This way, the array always splits exactly in half, which
 *          is efficient.
 *        - Uses a SENTINEL KEY – in case the pivot is the smallest element.
 *        - Stable? NO – equal elements can be swapped.
 *
 *        - Since Quicksort is among the fastest sorting algorithms, there
 *          has been much focus on making it even faster. Three ideas:
 *             1) Remove recursion – use an explicit stack:
 *                Recursion is elegant, but memory-expensive. Using your own
 *                stack to push left/right intervals can speed it up.
 *             2) Handle small subarrays separately:
 *                For small subarrays (e.g. 5–25 elements), skip recursive
 *                Quicksort. At the end, run Insertion sort over the whole
 *                array. Since each subarray is locally sorted, Insertion
 *                sort won’t have to move elements far.
 *             3) Median-of-three:
 *                Instead of blindly choosing left/right element as pivot,
 *                take the median of left, middle, and right. Swap them so
 *                they’re in ascending order, move the median to arr[right-1],
 *                and sort between arr[left+1] … arr[right-2]. Avoids
 *                sentinel key as well.
 *          Even with these, Quicksort only becomes 25–30% faster.
 *
 *   @file     Example_24_QuickSort.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>          //  cout
#include <string>            //  string
#include <cstdlib>           //  (s)rand
using namespace std;




/**
 *  Swaps the contents of two reference-transferred variables.
 *
 *  @param   c1  -  Value to be swapped with 'c2'
 *  @param   c2  -  Value to be swapped with 'c1'
 */
void swapChars(char& c1, char& c2);



/**
 *  Prints (parts of) the array 'arr'.
 *
 *  @param   text    -  Leading text printed first
 *  @param   arr     -  The array whose content is printed
 *  @param   left    -  Lower/left index for printing
 *  @param   right   -  Upper/right index for printing
 */
void display(const string& text, const char arr[],const int left, const int right);


/**
 *  Rearranges elements in (part of) the array using the RIGHT pivot element,
 *  so that everything to the left is less/equal, and everything to the right
 *  is greater/equal.
 *
 *  @param    arr     -  The array to be partitioned
 *  @param    left    -  Lower/left index for partitioning
 *  @param    right   -  Upper/right index for partitioning
 *  @return   The index where the pivot ended up
 *  @see      display(...)
 */
int  partition(char arr[], const int left, const int right);


void quickSort(char arr[], const int left, const int right);
