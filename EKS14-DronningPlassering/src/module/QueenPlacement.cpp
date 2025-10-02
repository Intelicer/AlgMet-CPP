#include "../../include/QueenPlacement.h"

void printBoard() {                   //  Prints the board's contents.
    int i, j;

    cout << "\n\n\nSolution no." << ++gSolutionCount << ":\n\t";
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            cout << gBoard[i][j] << "  ";
        }
        cout << "\n\t";
    }
    cout << "\t\t\tPress any key .....";   getchar();
}

bool isLegalPosition(int row, int col) {
    int i;

    for (i = 0; i < col; i++) {               //  Checks for any other piece:
        if (gBoard[row][i]) {                 //    - on the same row:
            return false;
        }
    }

    for (i = col - 1; i >= 0; i--) {          //    - on one of the diagonals:
        if (row - (col - i) >= 0) {           //  If inside the board:
            if (gBoard[row - (col - i)][i]) { //  Occupied on diagonal
                return false;                 //    UP to the left.
            }
        }
        if (row + (col - i) < BOARD_SIZE) {   //  If inside the board:
            if (gBoard[row + (col - i)][i]) { //  Occupied on diagonal
                return false;                 //    DOWN to the left.
            }
        }
    }
    return true;                              //  Unattacked placement.
}

void placeQueen(int j) {
    int i;
    if (j == BOARD_SIZE) {          //  The board is full, i.e., reached a solution.
        printBoard();                //  Prints/draws the solution.
    }
    else {
        for (i = 0; i < BOARD_SIZE; i++) {   //  Goes through ALL rows in the column:
            //  1st column or allowed to place:
            if (j == 0 || isLegalPosition(i, j)) {
                gBoard[i][j] = true;           //  Marks the position as occupied.
                placeQueen(j + 1);             //  Places a queen on the next column.
                gBoard[i][j] = false;          //  Frees the position - BACKTRACKS !!!
            }
        }
    }
}