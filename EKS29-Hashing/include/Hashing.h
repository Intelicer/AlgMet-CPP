/**
 *   Program example no. 29 - Hashing - simple self-made class.
 *
 *   The example shows two different forms of hashing:
 *      - Linear Probing
 *      - Double Hashing
 *
 *   A bit more about hashing:  Hashing.pdf
 *
 *   Order ( O(...)):
 *     LINEAR PROBING uses on average fewer than five probes
 *     to place an element, for a table that is less than 2/3 full.
 *     DOUBLE HASHING uses on average fewer probes than linear probing.
 *     SEPARATE CHAINING reduces the number of comparisons in sequential search
 *     by an average factor of M, when there are M stacks/LIFO-lists.
 *
 *   @file     EKS_29_Hashing.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>          //  cout
#include <iomanip>           //  setw
#include <cctype>            //  toupper
using namespace std;


/**
 *  Enum for hash table type (linear probing or double hashing).
 */
enum HashType { LinearProbing, DoubleHashing };


/**
 *  Container class Hashing.
 *
 *  Contains a char array ('table'), max. number of elements in
 *  the array ('length'), and which type the table is ('hType').
 */
class Hashing {
private:
    char* table;                         //  The hash table
    int   length;                        //  Table length.
    HashType hType;                      //  Table type for hashing.

    //  Returns  k % M:
    int hash1(const int modValue, const int kValue);

    //  Returns  H - (k % H):
    int hash2(const int hashValue, const int kValue);

    int kValue(char letter);

public:
    Hashing(const HashType hT, const int len);

    ~Hashing();           //  Destructor.

    void display() const;

    //  Inserts 'data' into the hash table:
    //   (And where 'hash2' uses 'hashValue')
    void insert(const int hashValue, const char data);
};

