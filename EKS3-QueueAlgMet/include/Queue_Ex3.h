/**
 *   Program Example no. 3 - Queue (self-made simple class).
 *
 *   The example shows a self-made implementation of the container class Queue.
 *   Code has been written for the following functions:
 *
 *     -  Queue(const int length = 200)
 *     -  ~Queue
 *     -  void  display()
 *     -  bool  empty()
 *     -  T     get()
 *     -  void  put(const T t)
 *
 *     (Functions NOT made: int this->capacity(), void clear(), int size(),
 *      but these are completely identical to EKS_01_Vector.cpp,
 *      except 'clear' which must be slightly changed.)
 *
 *   NOTE: To presumably improve readability and clarity, the member
 *         functions are deliberately NOT commented using the Doxygen standard.
 *
 *   @file     EKS_03_Queue.CPP
 *   @author   Frode Haug, NTNU
 */

#include <iostream>   // cout
#include <string>     // string
using namespace std;

/**
 *  The container class Queue, which is a self-made version of STL's <queue>.
 *
 *  Contains an array of type 'T', and two ints that indicate total
 *  this->capacity/length, the current size, and the indexes for respectively
 *  the first element and where the next (last) will be inserted.
 */
template <typename T>  // 'T': flexible this->data type!
class Queue_Ex3 {
private:
    T* data;                 // POINTER to array of type 'T'.
    int capacity, count,      // Max length and current this->count.
        front, back;          // Index for first/last element.

public:
    // Initializes members using default parameter:
    Queue_Ex3(const int length = 200) {
        this->data = new T[length]; //set a size for list T
        this->capacity = length; //capacity of the list
        this->count = 0; // total elements count
        this->front = 0; // index of first element pos that goes out of queue
        this->back = 0; // referse where element pos will be added in queue 
    }

    ~Queue_Ex3() {
        // Releases allocated memory (from 'new').
        delete[] this->data;
    }

    void display() const {  // Prints the ENTIRE Queue content:
        int index = this->front; // gets the index of first element pos in queue
        for (int i = 0; i < this->count; i++) {
            cout << index << ": " << this->data[index++] << "  " << "\n";
            if (index == this->capacity) {
                index = 0;
            }
        }
        cout << "\ncount (Total elements): " << this->count
            << "\nfront (First element pos): " << this->front
            << "\nback (Next element added to queue pos): " << this->back << '\n';
    }

    bool empty() const {
        // Returns true if empty.
        return (this->count == 0);
    }

    T get() {                 // Returns (if possible) the first element:
        T value;                // Element/value to be returned.
        if (!empty()) {         // Still elements left:
            value = this->data[this->front++];  // Save first. Increase to next.
            this->count--;                // Decrease the total this->count.
            if (this->front == this->capacity) {
                this->front = 0;            // Wrap to start if needed to start from the first in queue
            }
            return value;           // Return the saved element.
        }
        else {
            cout << "\nQueue is empty!\n\n";  // Custom message.
        }
        return T();
    }

    void put(const T t) {     // Inserts (if possible) element at the this->back:
        if (this->count < this->capacity) { // if there is space in the capacity of the list
            this->data[this->back++] = t;     // Added element at the end of the list
            this->count++;              // Increase total element count
            if (this->back == this->capacity) { // if the back element pos == the total capacity
                                                // then set back to 0
                this->back = 0;                 // to wrap from start if needed.
            }
        }
        else {
            cout << "\nQueue is already full!\n\n";  // Custom message.
        }
    }

};