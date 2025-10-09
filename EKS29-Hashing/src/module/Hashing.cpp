#include "../../include/Hashing.h"


int Hashing::hash1(const int modValue, const int kValue) {
    return (kValue % modValue);
}

//  Returns  H - (k % H):
int Hashing::hash2(const int hashValue, const int kValue) {
    return (hashValue - (kValue % hashValue));
}

int Hashing::kValue(char letter) {            //  Converts A-Z to 1-26:
    letter = toupper(letter);                 //  To uppercase.
    if (letter >= 'A' && letter <= 'Z') {    //  IS a letter:
        return (static_cast<int>(letter - 'A') + 1);
    }
    else {                                 //  NOT a letter.
        return 0;
    }
}


Hashing::Hashing(const HashType hT, const int len) {  //  Constructor:
    length = len;    hType = hT;             //  Initialize members.
    table = new char[len];                   //  Create hash table
    for (int i = 0; i < length; i++) {       //  Reset values.
        table[i] = '-';
    }
}

Hashing::~Hashing() { delete[] table; }              //  Destructor.

void Hashing::display() const {                       //  Writes the ENTIRE hash
    for (int i = 0; i < length; i++) {       //   table's content:
        cout << setw(3) << i << ':';
    }
    cout << '\n';
    for (int i = 0; i < length; i++) {
        cout << "  " << table[i] << ' ';
    }
    cout << "\n\n";
}

//  Inserts 'data' into the hash table:
//   (And where 'hash2' uses 'hashValue')
void Hashing::insert(const int hashValue, const char data) {
    int kOfData = kValue(data);                 //  Get 'k' for 'data'.
    int index = hash1(length, kOfData);     //  Find hash1 value.
    int step = hash2(hashValue, kOfData);    //  Find hash2 value.
    //  (Used ONLY with 'DoubleHashing')

//        cout << data << "   k: " << kOfData         //  Print these values:
//             << "   h1: " << index << "   h2: " << step << '\n';

                                          //  Loop until a free slot is found:
    while (table[index] != '-') {
        //  Jump ONE index (linear probing)
        index = (hType == LinearProbing) ?     //  or STEP (d.hash):
            (index + 1) : (index + step);
        index %= length;           //  IF jumping past end, wrap to
    }                               //   the start again !!!
    table[index] = data;            //  Place data in found free slot.
    display();
}