/**
 *   Program Example no. 25 - Heap (priority queue) - self-made simple class.
 *
 *   The example shows a self-made implementation of the container class Heap.
 *   Code is made for the following functions:
 *
 *     - Heap(const int length = 200)
 *     - ~Heap
 *     - void change(const int keyNr, const T newValue)     //  Exercise no.15
 *     - void display()
 *     - void downHeap(T arr[], const int num, int keyNr)
 *     - void extract(const int keyNr)                      //  Exercise no.15
 *     - void insert(const T value)
 *     - T    remove()
 *     - T    replace(const T value)
 *     - void upHeap(int keyNr)
 *
 *   For more explanation of principles and the code, see:  Heap.pdf
 *
 *   Order ( O(...)):
 *        All operations (insert, remove, replace, upHeap, downHeap,
 *        change and extract) require fewer than  2 log N  comparisons
 *        when performed on a heap with N elements.
 *
 *   NB:  - Only the functions 'insert' and 'remove' are made
 *          somewhat robust. The others ('change', 'extract' and 'replace')
 *          are NOT.
 *        - The heap in this code works such that the LARGEST element
 *          should be at element no.1. But, the code could easily be
 *          rewritten so that it instead works for the SMALLEST element.
 *        - Is a .h-file, so includes and is used by EKS_26_HeapSort.CPP
 *
 *   @file     EKS_25_Heap.H
 *   @author   Frode Haug, NTNU
 */


#include <iostream>          //  cout
#include <limits>            //  numeric_limits::max


using namespace std;
 /**
  *  The container class Heap.
  *
  *  Contains an array ('data') of type 'T', two ints that specify the heap’s
  *  max length and current number of elements in the array, as well as a sentinel key.
  */
template <typename T>                //  'template'!  'T': flexible datatype!
class Heap {
private:
    T* data;                        //  POINTER to array of type 'T'.
    int length,                      //  Heap’s max length.
        count;                       //  Current number of elements in the array.
    T   sentinelKey;                 //  Stop-value in element no.0.

    //  PRIVATE function - since ONLY used by OWN functions!
                   //  Moves possible initial data[keyNr]
    void upHeap(int keyNr) {         //    up past all smaller parents:
        T value = data[keyNr];       //  The element that may be moved up.
        data[0] = sentinelKey;       //  Insert sentinel key.
        while (data[keyNr / 2] < value) {   //  Parent is smaller:
            data[keyNr] = data[keyNr / 2];  //  Move parent down.
            keyNr = keyNr / 2;              //  Index becomes parent’s.
        }
        data[keyNr] = value;         //  Insert where it stopped.
    }

public:
    Heap(const int len = 200) {   //  Initializing constructor:
        data = new T[len];  length = len;  count = 0;
        sentinelKey = std::numeric_limits<T>::max();
        //            std::cout << "\n\nsentinelKey:  " << (int)sentinelKey << "\n\n";
    }


    ~Heap() { delete[] data; }      //  Frees allocated memory.

    //  Changes 'data[keyNr]'  to  'newValue':
    void change(const int keyNr, const T newValue) {

        //  MAKE IMPLEMENTATION  in connection with Exercise no.15
    }


    void display() const {           //  Prints out the ENTIRE heap content:
        for (int i = 1; i <= count; i++) {
            std::cout << ' ' << data[i];
        }
    }

    //  Moves element down past all larger children:
    //  MUST HAVE PARAMETERS, SINCE ALSO CALLED/USED FROM OUTSIDE!
    void downHeap(T arr[], const int num, int keyNr) {
        int j;                        //  Index for one of the children.
        T value = arr[keyNr];         //  The element that may be moved down.
        while (keyNr <= num / 2) {      //  Those before halfway have children:
            j = 2 * keyNr;            //  Left child index.
            //  IF has right child and it is larger,
            //    update to ITS index:
            if (j < num && arr[j] < arr[j + 1]) {
                j++;
            }
            if (value >= arr[j]) {    //  Current child is NOT larger,
                break;                 //    break off search downward.
            }
            arr[keyNr] = arr[j];      //  Move child up.
            keyNr = j;                //  New index becomes this child.
        }
        arr[keyNr] = value;           //  Insert where it stopped.
    }


    void extract(const int keyNr) {  // Deletes element no.'keyNr' from heap:

        //  MAKE IMPLEMENTATION  in connection with Exercise no.15
    }


    void insert(const T value) {     //  If possible, insert new value in heap:
        if (count < length - 1) {    //  There is space:
            data[++count] = value;   //  Place at the very back.
            upHeap(count);           //  Possibly move up (upHeap).
        }
        else {                    //  There is NO space:
            std::cout << "\nHeap is full with " << length
                << " elements (including sentinel key)!\n\n";
        }
    }

    //  Removes and returns (if possible)
    T remove() {                    //    the largest/first from the heap:
        if (count > 0) {            //  Heap is NOT empty:
            T value = data[1];      //  Store the first.
            data[1] = data[count--];   //  Move very last element ALL the way front.
            downHeap(data, count, 1);  //  DownHeap this one.
            return value;           //  Return the first (stored away).
        }
        else {                   //  Heap IS empty:
            std::cout << "\nHeap is completely empty - nothing in 'remove'!\n\n";
            return sentinelKey;
        }
    }

    //  Replaces the first element with a new value,
    //    and returns the NOW largest element in the heap:
    T replace(const T value) {
        data[0] = value;            //  Insert into element no.0 !!!
        downHeap(data, count, 0);   //  DownHeap.
        return data[0];             //  Largest is afterwards in element no.0!
    }                               //   And is then EITHER the new one (if largest!),
};                                  //    OR what was initially the root (no.1).


