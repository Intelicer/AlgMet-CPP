/**
 *   Program Example no. 9 - Basic/simple examples of recursion.
 *
 *   Examples showing recursion in a basic/simple way
 *   using prints of numbers/characters.
 *
 **************************************************************************
 *   RECURSION:                                                          **
 *      - Used when a problem can be divided into smaller, simpler        **
 *        subproblems that resemble each other. Each subproblem can       **
 *        be solved by applying the same technique. The WHOLE problem    **
 *        is solved by COMBINING the solutions of the subproblems.       **
 *        In other words, this is a form of "divide-and-conquer"         **
 *        technique.                                                     **
 *      - In programming, this in practice means:                        **
 *           - A function that, among other things, calls/uses itself    **
 *             to arrive at/find the solution.                           **
 *           - The function MUST have a stopping condition, i.e. a       **
 *             situation (if-else) where it no longer calls itself.      **
 *      - Examples: Traversing trees and graphs, permutations,           **
 *        Quicksort, placing 8 queens on a chessboard without them       **
 *        attacking each other                                           **
 **************************************************************************
 *
 *  @file     EKS_09_SimpleRecursion.CPP
 *  @author   Frode Haug, NTNU
 */


#include <iostream>                  //  cout
using namespace std;

class SimpleRecursion {


private:
    const int MAXCALL = 5;               //  Max. number of recursive calls.



public:
    /**
     *  Recursive function that may call itself ALL the way at the end (=iteration).
     *
     *  @param   n  -  Counter indicating which recursive call is happening
     */
    void display1(int n);

    /**
     *  Recursive function that prints 2x times and may call itself
     *  ALL the way at the end (=iteration).
     *
     *  @param   n  -  Counter indicating which recursive call is happening
     */
    void display2a(int n);


    /**
     *  Recursive function that prints 2x times and may call itself
     *  BETWEEN the two prints.
     *
     *  NB: Notice the difference in the output compared to 'display2a' !!!
     *
     *  @param   n  -  Counter indicating which recursive call is happening
     */
    void display2b(int n);


    /**
     *  Recursive function that reads ONE character, calls itself
     *  OR prints '\n', and finally prints its ONE input character.
     *
     *  NB: Notice the backwards output of the characters!
     *
     *  @param   n  -  Counter indicating which recursive call is happening
     */

    void display3(int n);


    /**
     *  Recursive function that, without stopping condition, calls itself ("well").
     *
     *  NB: The program crashes !!!
     */
    //void display4(int n);

    int get_max_call() const;


};


