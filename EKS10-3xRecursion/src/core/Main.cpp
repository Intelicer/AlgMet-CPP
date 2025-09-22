#include "../../include/TxRecursion.h"

/**
 *  The main program:
 */
int main() {
    TxRecursion t1;

    string tekst = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    cout << "\n\nThe text:        " << tekst << '\n';
    t1.reverser(tekst, 0, tekst.length() - 1); //length -1 because we start at 0 so the last should be 16
    cout << "Reversed:        " << tekst << '\n';


    // --------------------------------------------------------------------------
    //    2x standard examples of recursion found in "all" textbooks/explanations:


    cout << "\n\n5! is:     " << t1.fakultet(5) << '\n';


    // --------------------------------------------------------------------------
    // Fibonacci numbers:
    //  Nr:    0    1    2    3    4    5    6    7    8    9   10   11   12   13
    //         1    1    2    3    5    8   13   21   34   55   89  144  233  377

    cout << "\n\nFibonacci number no.45 is:     " << t1.fibonacci(45) << "\n\n\n";

    //  Fibonacci number no.43 requires 1,402,817,465 RECURSIVE CALLS !!!
    //                (no.44 OVERFLOWS the int counter!)
    //  Fibonacci number no.46 also OVERFLOWS the int!



    /**
     *  EXTRA - DYNAMIC PROGRAMMING (stores intermediate results/calculations):
     */

    cout << "\n\nFibonacci number no.45 is:   " << t1.fibonacci2(44);

    t1.show_store_fibonacci_number();

    return 0;
}


