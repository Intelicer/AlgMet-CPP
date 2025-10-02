/**
 *   Program example no. 14 – Placing 8 queens on an 8x8 chessboard,
 *                           without any of them being able to capture each other.
 *
 *   The program tries RECURSIVELY to place MAX chess queens UNATTACKED on a
 *   MAX x MAX board. That is: two queens cannot be on the same row (i),
 *   column (j) or diagonal, otherwise they "capture/take" each other.
 *
 *   NOTE:
 *     The program does NOT filter out solutions that are actually found earlier,
 *     when what appears to be a "new" solution is really a:
 *        - reflection about the horizontal/vertical midline and/or
 *        - reflection about the main/secondary diagonal (between opposite corners) and/or
 *        - rotation (e.g., CLOCKWISE) by 90, 180 or 270 degrees
 *     of the already found solution.
 *     This implies that for an 8x8 board the program will report 92 solutions,
 *     when there are actually only 12 UNIQUE solutions. (For an NxN board, the
 *     following numbers are NON-UNIQUE solutions:  4: 2,   5: 10,   6: 4,   7: 40.)
 *
 *   @file     EX_14_QueenPlacement.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>    //  cout
using namespace std;

const int BOARD_SIZE = 8;     ///<  The board's size.

bool gBoard[BOARD_SIZE][BOARD_SIZE]; ///<  The chessboard. Uses 0-(BOARD_SIZE-1) in both directions.
//    The entire board is automatically set to 'false'.
int  gSolutionCount = 0;             ///<  Counts the number of solutions found.


/**
 *  Prints the board's contents (true = '1', false = '0').
 */
void printBoard();


/**
 *  Checks whether a queen can be placed at position [row][col].
 *
 *  This is done by testing whether there is already 'true' on the given 'row'
 *  or on one of the diagonals on the columns to the LEFT of 'col'.
 *
 *  @param    row     -  The current queen's own placement on 'row'
 *  @param    col     -  The current queen's own placement on 'col'
 *  @return   Whether the queen can stand unattacked at this position or not.
 */
bool isLegalPosition(int row, int col);


/**
 *  Recursively tries to place a queen in turn in ALL
 *  legal positions in column 'j'.
 *
 *  @param   j  -  The column on which the queen will be attempted placed unattacked.
 */
void placeQueen(int j);




/*
  ALTERNATIVE SOLUTION:
     The problem could also be solved by permutation (lecture 9a) of
     the numbers 0 to BOARD_SIZE-1. The index/element number indicates the column number,
     while the number at that position indicates the row number.
     Thus, you avoid testing whether two queens are on the same row
     (as long as all numbers are unique). You "only" need to test that no neighboring numbers
     are +/- 1 relative to each other, that none with a distance of two between them are
     +/- 2 relative to each other, etc..... up to BOARD_SIZE-1.

     The pruning above (reflections/rotations) could have been handled
     by performing various transformations on the permuted array. If
     a new array thus obtained, interpreted as a whole number (from all its digits
     0–9 in it), is smaller than the permuted array's number, then that solution
     has already been found (and printed) earlier.
*/