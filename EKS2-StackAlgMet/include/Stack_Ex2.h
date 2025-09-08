#pragma once
/**
 *   Program Example no. 2 - Stack (simple self-made class).
 *
 *   The example shows a self-made implementation of the container class Stack.
 *   Code has been written for the following functions:
 *
 *     -  Stack(const int length = 200)
 *     -  ~Stack
 *     -  void  display()
 *     -  bool  empty()
 *     -  T     pop()
 *     -  void  push(const T t)
 *
 *     (NOT written: int this->capacity(), void clear(), int size(),
 *      but these are IDENTICAL to EKS_01_Vector.cpp)
 *
 *  @author   Frode Haug, NTNU
 */

#include <iostream>   // cout
#include <string>     // string
using namespace std;


/**
 *  Container class Stack, which is a self-made version of STL's <stack>.
 *
 *  Contains an array of type 'T', and two ints representing the total
 *  this->capacity/length and the current number of elements (size).
 */
template <typename T>   // 'T': flexible this->data type!
class Stack_Ex2 {
private:
    T* data;            // Pointer to array of type 'T'.
    int capacity;        // Maximum length (capacity).
    int count;           // Current number of elements.

public:
    // Initializes members using default parameter:
    Stack_Ex2(const int length = 200) {
        this->data = new T[length];
        this->capacity = length;
        this->count = 0;
    }

    ~Stack_Ex2() {
        delete[] this->data;   // Frees allocated memory (from 'new').
    }

    void display() const {  // Prints the ENTIRE stack:
        for (int i = 0; i < this->count; i++) { //goes through each element and displayes them.
            cout << i << ": " << this->data[i] << "  ";
        }
        cout << "\ncount:" << this->count << '\n';
    }

    bool empty() const {
        return (this->count == 0);   // Empty or not. Condition to return true or false
    }

    // Returns (if possible) the top element:
    T pop() {
        if (!empty()) {              // Not empty (i.e. elements remain):
            return (this->data[--this->count]);  // Last element has index: (this->count-1)
        }
        else {
            cout << "\nStack is empty!\n\n";   // Custom message ??
            return T();
        }
    }

    // Inserts (if possible) a new top element:
    void push(const T t) {
        if (this->count < this->capacity) {      // Still space for more elements:
            this->data[this->count++] = t;       // Insert at top, increment counter.
        }
        else {
            cout << "\nStack is already full!\n\n";   // Custom message ??
        }
    }
};