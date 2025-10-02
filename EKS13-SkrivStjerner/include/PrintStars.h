/**
 *   Program example no. 13 - Writes lines with varying numbers of stars/indents.
 *
 *   Example showing how to recursively write the following / create the pattern:
 *
 *         *                        I.e., seen from the 8-star line,
 *         * *                      we should draw 4 stars starting
 *           *                      where the 8 starts, and 4 stars from
 *         * * * *                  the middle of the 8.
 *             *                    For each group of 4 stars, we should draw
 *             * *                  two stars where the 4 starts,
 *               *                  and two stars from the middle of the 4.
 *         * * * * * * * *          For each pair of 2 stars, we should draw
 *                 *                one star where the 2 starts,
 *                 * *              and one star from the middle of the 2
 *                   *              (where it ends).
 *                 * * * *
 *                     *
 *                     * *
 *                       *
 *
 *   (This was problem no. 4 on the exam 13/8-2001 in IMT2021 - Algorithmic Methods)
 *
 *   @file     EX_13_PrintStars.cpp
 *   @author   Frode Haug, NTNU
 */


#include <iostream>                  //  cout
using namespace std;

/**
 *  After 'numSpaces' leading blanks, writes 'numStars' stars.
 *
 *  @param   numStars   -  Number of stars to write/draw
 *  @param   numSpaces  -  Number of leading blanks before the stars
 */
void printStars(int numStars, int numSpaces);
