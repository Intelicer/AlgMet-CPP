/**
 *   Program Example no. 11 - Example of graphics recursion.
 *
 *   Example that "shows" the code for the EXE file listed below.
 *   It draws a cross inside a frame. This creates four
 *   new frames. Recursively, it also draws crosses inside those.
 *   In this way, crosses are drawn inside crosses until a depth
 *   of MAXDEPTH is reached.
 *
 *   ************************************************
 *   **  Run and see EKS_11_GrafikkRekursjon2.EXE  **
 *   **  (unfortunately ONLY works on Windows!)    **
 *   ************************************************
 *
 *   @file     EKS_11_GrafikkRekursjon.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>                  //  cout
using namespace std;


const int MAXDEPTH = 5;              ///<  Max. depth of the cross-drawing.


/**
 *  Draws (using 'line(...)') ONE cross inside the frame defined by the parameters.
 *
 *  @param  x1, y1  -  Upper/lower LEFT corner
 *  @param  x2, y2  -  Lower/upper RIGHT corner
 *  @param  n       -  Recursive call no.'n'  (the recursion level)
 */
void cross(int x1, int y1, int x2, int y2, int n) {
    int dx = (x2 - x1) / 2;                 //  Calculates the midpoint of the frame.
    int dy = (y2 - y1) / 2;

    //  line(x1 + dx, y1, x1 + dx, y2);           //  Draws a cross IN THE MIDDLE of the frame.
    //  line(x1, y1 + dy, x2, y1 + dy);
    cout << n << ' ';                       //  INSTEAD OF 'line(...)' !!!

    if (n < MAXDEPTH) {                     //  Draws in the four new frames
        cross(x1, y1, x1 + dx, y1 + dy, n + 1);   //   that have now been created:
        cross(x1 + dx, y1, x2, y1 + dy, n + 1);
        cross(x1, y1 + dy, x1 + dx, y2, n + 1);
        cross(x1 + dx, y1 + dy, x2, y2, n + 1);
    }
}


/**
 *  The main program:
 */
int main() {

    //rectangle(0, 0, 1919, 1079);      //  Draws an outer frame around the crosses.

    cross(0, 0, 1919, 1079, 1);

    cout << "\n\n";
    return 0;
}
