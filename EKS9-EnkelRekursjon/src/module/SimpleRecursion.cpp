#include "../../include/SimpleRecursion.h"
void SimpleRecursion::display1(int n) {
    cout << n << ' ';
    if (n < this->MAXCALL) {
        display1(n + 1);
    }
}


/**
 *  Recursive function that prints 2x times and may call itself
 *  ALL the way at the end (=iteration).
 *
 *  @param   n  -  Counter indicating which recursive call is happening
 */
void SimpleRecursion::display2a(int n) {
    cout << n << ' ';
    cout << n + 100 << ' ';
    if (n < this->MAXCALL) {
        display2a(n + 1);
    }
}


/**
 *  Recursive function that prints 2x times and may call itself
 *  BETWEEN the two prints.
 *
 *  NB: Notice the difference in the output compared to 'display2a' !!!
 *
 *  @param   n  -  Counter indicating which recursive call is happening
 */
void SimpleRecursion::display2b(int n) {
    cout << n << ' ';
    if (n < this->MAXCALL) {
        display2b(n + 1);
    }
    cout << n + 100 << ' ';
}


/**
 *  Recursive function that reads ONE character, calls itself
 *  OR prints '\n', and finally prints its ONE input character.
 *
 *  NB: Notice the backwards output of the characters!
 *
 *  @param   n  -  Counter indicating which recursive call is happening
 */

void SimpleRecursion::display3(int n) {
    if (n <= this->MAXCALL * 2) {
        char ch;
        cin >> ch;
        display3(n + 1);
        cout << ch << ' ';
    }
    else {
        cout << "\n\n";
    }
}


/**
 *  Recursive function that, without stopping condition, calls itself ("well").
 *
 *  NB: The program crashes !!!
 */
//void SimpleRecursion::display4(int n) {
//    cout << n << ' ';
//    display4(n + 1); // no maxcall used the method class itself until memory fills up
//}

int SimpleRecursion::get_max_call() const {
    return this->MAXCALL;
}