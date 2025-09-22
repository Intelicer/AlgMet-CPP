#include "../../include/TxRecursion.h"
/**
 *  Calculates and returns what n! (n factorial) is using recursion.
 *
 *  @param    n  -  Will calculate the answer to what 'n' factorial (n!) is
 *  @return   The answer to 'n' factorial (n!)
 */
int TxRecursion::fakultet(const int n) {
    if (n <= 1) {
        return 1;                    //   0!  =  1!  =  1
    }
    return  n * fakultet(n - 1);       //   n!  =  n * (n-1)!
}


/**
 *  Calculates and returns what the n'th Fibonacci number is using recursion.
 *
 *  @param    n  -  Will calculate the answer to what the n'th Fibonacci number is
 *  @return   The answer to the n'th Fibonacci number
 */
int TxRecursion::fibonacci(const int n) {
    if (n <= 1) {
        return 1;                    //  fib(0) = fib(1) = 1
    }
    return (fibonacci(n - 1) + fibonacci(n - 2)); //  fib(n) = fib(n-1) + fib(n-2)
}


/**
 *  Calculates and returns what the (n+1)'th Fibonacci number is
 *    using recursion AND DYNAMIC PROGRAMMING.
 *
 *  @param    n  -  Will calculate the answer to what the (n+1)'th Fibonacci number is
 *  @return   The answer to the (n+1)'th Fibonacci number
 */
int TxRecursion::fibonacci2(const int n) {
    if (this->gFibotall[n] == 0) {
        this->gFibotall[n] = fibonacci2(n - 1);
    }
    return (this->gFibotall[n] + this->gFibotall[n - 1]);
}


/**
 *  Reverses a text (turns it backwards) using recursion.
 *
 *  @param   s      - The text that will be reversed. MUST be passed by reference !!!
 *  @param   left   - Lowest/lower index in 's' to be swapped
 *  @param   right  - Highest/upper index in 's' to be swapped
 */
void TxRecursion::reverser(string& s, const int left, const int right) {
    if (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        reverser(s, left + 1, right - 1);
    }
}


void TxRecursion::show_store_fibonacci_number() {
    cout << "\n\nStored Fibonacci numbers:\n";
    for (int i = 0; i <= 44; i++) {
        cout << this->gFibotall[i] << "  ";
    }
    cout << "\n\n";
}