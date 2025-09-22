#pragma once
/**
 *   Program Example no. 10 - Three completely independent examples of recursion.
 *
 *   Three small, short and TOTALLY independent examples that show
 *   recursion in a "simple" way.
 *
 *   @file     EKS_10_3xRekursjonsEks.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>                  //  cout
#include <string>                    //  STL's string class.
using namespace std;

class TxRecursion {
private:
	int gFibotall[1000] = { 1, 1 };      ///<  Stored Fibonacci numbers.
	//     (initializes ONLY element no.0 and 1!)



public:

    /**
     *  Calculates and returns what n! (n factorial) is using recursion.
     *
     *  @param    n  -  Will calculate the answer to what 'n' factorial (n!) is
     *  @return   The answer to 'n' factorial (n!)
     */
    int fakultet(const int n);


    /**
     *  Calculates and returns what the n'th Fibonacci number is using recursion.
     *
     *  @param    n  -  Will calculate the answer to what the n'th Fibonacci number is
     *  @return   The answer to the n'th Fibonacci number
     */
    int fibonacci(const int n);

    /**
     *  Calculates and returns what the (n+1)'th Fibonacci number is
     *    using recursion AND DYNAMIC PROGRAMMING.
     *
     *  @param    n  -  Will calculate the answer to what the (n+1)'th Fibonacci number is
     *  @return   The answer to the (n+1)'th Fibonacci number
     */
    int fibonacci2(const int n);

    /**
     *  Reverses a text (turns it backwards) using recursion.
     *
     *  @param   s      - The text that will be reversed. MUST be passed by reference !!!
     *  @param   left   - Lowest/lower index in 's' to be swapped
     *  @param   right  - Highest/upper index in 's' to be swapped
     */
    void reverser(string& s, const int left, const int right);


    void show_store_fibonacci_number();
};
