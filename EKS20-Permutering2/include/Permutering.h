#pragma once
/**
 *   Program example no. 19 – Permutation (reordering / swapping positions).
 *
 *   The example shows how to reorder in EVERY conceivable way ALL elements
 *   in an (int) array.
 *   N DISTINCT elements can be permuted in N! different ways.
 *
 *   More explanation of the algorithm/functionality:  Permutering.pdf
 *
 *   For a visual display of all (recursive) function calls with
 *   int-arrays "123" and "1234", see:
 *      - Eks19_(recursive)_function_calls_with_array123.pdf   and
 *      - Eks19_(recursive)_function_calls_with_array1234.pdf
 *   Approximately the same can be observed by removing the four '//'
 *   in front of the 'cout' statements inside the functions 'printArray' and 'permute'
 *
 *   @file     EKS_19_Permutering.CPP
 *   @author   Frode Haug, NTNU
 */

#include <iostream>             //  cout
using namespace std;

const int N = 4;                       ///<  Length of the array.


/**
 *  Swaps the contents of two pass-by-reference variables.
 *
 *  @param   value1  -  The value to be swapped with 'value2' (by reference)
 *  @param   value2  -  The value to be swapped with 'value1' (by reference)
 */
void swapValues(int& value1, int& value2);

/**
 *  Prints the ENTIRE contents of the array 'arr'.
 *
 *  @param   arr  -  The array whose entire contents will be printed
 *  @param   n    -  Number of elements in the array (last used index is n-1)
 */
void printArray(const int arr[], const int n);

/**
 *  Recursively generates ALL possible permutations of the contents of 'arr'.
 *
 *  @param   arr  -  The array to be permuted
 *  @param   i    -  The index to which ALL SUBSEQUENT values will be moved
 *  @param   n    -  Number of elements in the array (last used index is n-1)
 *  @see     swapValues(...)
 *  @see     printArray()
 *  @see     rotateLeft(...)
 */
void permute(int arr[], const int i, const int n);


/**
 *  Left-rotates a portion of the array.
 *
 *  @param   arr  -  The array whose (part of) contents will be left-rotated
 *  @param   i    -  Lowest index to be left-rotated
 *  @param   n    -  'n-1' is the highest index to be left-rotated
 */
void rotateLeft(int arr[], const int i, const int n);

