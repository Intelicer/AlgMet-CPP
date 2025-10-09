#include "../../include/Hashing.h"
using namespace std;


/**
 *  Main program:
 */
int main() {

    char text1[] = "EPLEROGBANANER";
    char text2[] = "KRAGEROSTAVERN";

    Hashing hashTable1(LinearProbing, 17);       //  Create two hash tables:
    //   One for linear probing and
    Hashing hashTable2(DoubleHashing, 17);       //   one for double hashing.


    // -------------------------     LINEAR PROBING:     -------------------------

    for (int i = 0; i <= 13; i++) {              //  Hash text into the one
        hashTable1.insert(4, text1[i]);          //    for linear probing.
    }
    cout << "\t\t\t\t\tPress ENTER .....";  getchar();


    // -------------------------     DOUBLE HASHING:     -------------------------

    for (int i = 0; i <= 13; i++) {              //  Hash text into the one
        hashTable2.insert(4, text2[i]);          //    for double hashing.
    }
    cout << "\t\t\t\t\tPress ENTER .....";  getchar();

    cout << "\n\n";
    return 0;
}
