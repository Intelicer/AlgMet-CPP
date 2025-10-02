#include "../../include/PrintStars.h"

void printStars(int numStars, int numSpaces) {
    int i;                               //  Loop variable.

    if (numStars >= 1) {                 //  Still need to write stars:

        //  Writes half as many stars,
        //  STARTING IN THE SAME COLUMN
        //  AS ITSELF (same number of blanks):
        printStars(numStars / 2, numSpaces);

        for (i = 1; i <= numSpaces; i++) {   //  Writes leading blanks:
            cout << "  ";
        }

        for (i = 1; i <= numStars; i++) {    //  Writes the correct number of stars:
            cout << "* ";
        }
        cout << '\n';                        //  Write newline.

        //  Writes half as many stars
        //  AFTERWARDS, STARTING RIGHT
        //  AFTER ITS OWN MIDPOINT:
        printStars(numStars / 2, numSpaces + (numStars / 2));
    }
}