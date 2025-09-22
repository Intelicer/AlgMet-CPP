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

    /*
        Example:
        fakultet(5);
        5 * fakultet(5-1)
        ...
        ...
        ...
        ( 5 * ( 4 * ( 3 * ( 2 * fakultet(0) ))));
        ( 5 * ( 4 * ( 3 * ( 2 * 1 ))));
        ( 5 * ( 4 * ( 3 * ( 2 ))));
        ( 5 * ( 4 * ( 3 * 2 ))));
        ( 5 * ( 4 * ( 6 ))));
        ( 5 * ( 24 ));
        ( 120 );

    */
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

    /*
        fibonacci(5):
        fibonacci(5 - 1) + fibonacci(5 - 2) = fib(4) + fib(3) = (fib(3)+fib(2))+3 = 3+2+3 = 8 <--- the answer.
        fibonacci(4 - 1) + fibonacci(4 - 2) = fib(3) + fib(2) =  (fib(2)+fib(1))+2 = (2+1)+2 = 5
        fibonacci(3 - 1) + fibonacci(3 - 2) = fib(2) + fib(1) = 2+1 = 3
        fibonacci(2 - 1) + fibonacci(2 - 2) = fib(1) + fib(0) = 1+1 = 2
    
    */
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
    /*
        Same as fibonacci2 but here you take the list and add elemnt based on the sum
        to the positions without any elemnts

        the @method show_store_fibonacci_number reveals the order and show you the elements.
    */
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

    /*
        Exmaple:

        If we start with 
        string t = "test";
        left = 0;
        right = 3;

        temp = t[0]
        t[0] = t[3]
        t[3] = temp
         reverser(s, 0 + 1, 3 - 1);
    
    */
}


void TxRecursion::show_store_fibonacci_number() {
    cout << "\n\nStored Fibonacci numbers:\n";
    for (int i = 0; i <= 44; i++) {
        cout << this->gFibotall[i] << "  ";
    }
    cout << "\n\n";
}