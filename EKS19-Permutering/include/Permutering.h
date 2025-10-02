/**
 *  Program Example No. 20 - Number placement (under certain rules) in a grid.
 *
 *  For the program’s functionality see:  PermutationExample.pdf
 *
 *  The example is ALMOST IDENTICAL to EKS_19_Permutation.cpp,
 *  except that:
 *     - the function 'hasRightSum(...)' is new
 *     - the content of 'permute' is slightly extended (with if-statements)
 *     - 'displayArray' is slightly rewritten
 *
 *  (This was problem no. 5 on the exam 1994-12-15 in LO164A-Algorithmic Methods)
 *
 *  @file     EKS_20_PermutationExample.CPP
 *  @author   Frode Haug, NTNU
 */


#include <iostream>                 //  cout
#include <iomanip>                  //  setw
using namespace std;


const int N = 16;                   ///<  Array length.

extern int gSolutionCount;                 ///<  Number of solutions found (so far).
//    There are 7040 solutions (including
//      mirrorings and rotations).
//    There are 416 solutions when '1' is
//      fixed in the upper-left corner.


/**
 *  Swaps the contents of two pass-by-reference variables.
 *
 *  @param   value1  -  The value to be swapped with 'value2' (by reference)
 *  @param   value2  -  The value to be swapped with 'value1' (by reference)
 */
void swapValues(int& value1, int& value2);

/**
 *  Prints the ENTIRE content of array 'arr'.
 *
 *  @param   arr  -  The array whose entire content will be printed
 *  @param   n    -  Number of elements in the array (last used index is n-1)
 */
void displayArray(const int arr[], const int n);


/**
 *  Recursively generates ALL possible permutations of 'arr' content.
 *
 *  @param   arr  -  The array to permute
 *  @param   i    -  The index that ALL SUBSEQUENT values should be moved to
 *  @param   n    -  Number of elements in the array (last used index is n-1)
 *  @see     swapValues(...)
 *  @see     displayArray()
 *  @see     hasRightSum(...)
 *  @see     rotateLeft(...)
 */
void permute(int arr[], const int i, const int n);



/**
 *  Checks whether 'arr' satisfies the requirements described in PermutationExample.pdf.
 *
 *  @param    arr  -  The array to check for 34-sums
 *  @param    n    -  The index to check BACKWARDS from
 *  @return   Whether ALL 10 row/column/diagonal sums are 34 or not
 */
bool hasRightSum(int arr[], int n);

/**
 *  Left-rotates part of an array’s content.
 *
 *  @param   arr  -  The array whose (part of) content is left-rotated
 *  @param   i    -  Lowest index to be left-rotated
 *  @param   n    -  'n-1' is the highest index to be left-rotated
 */
void rotateLeft(int arr[], const int i, const int n);
