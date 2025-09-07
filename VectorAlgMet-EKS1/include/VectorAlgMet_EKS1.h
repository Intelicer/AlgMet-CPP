/**
 *   Program Example No. 1 - Vector (self-made simple class).
 *
 *   The example shows a self-made implementation of the container class Vector.
 *   Code has been created for the following functions:
 *
 *     -  Vector(const int length = 200)
 *     -  ~Vector
 *     -  int   capacity()
 *     -  void  clear()
 *     -  void  display()
 *     -  bool  empty()
 *     -  T     get(const int pos)                  //  i.e.: ..... = vec[pos]
 *     -  bool  insert(const int pos, const T t)
 *     -  T     pop_back()
 *     -  T     pop_front()
 *     -  bool  push_back(const T t)
 *     -  bool  push_front(const T t)
 *     -  bool  remove(const int pos)
 *     -  void  resize(const int newLength)
 *     -  void  set(const int pos, const T value)   //  i.e.: vec[pos] = value
 *     -  int   size()
 *
 *   NOTE: To increase readability, member functions are deliberately
 *   NOT commented in full Doxygen style.
 */

#include <iostream>   // cout
#include <string>     // string
using namespace std;

/**
 *  Container class Vector, a self-made version of STL's <vector>.
 *
 *  Contains an array of type 'T', and two ints indicating the total
 *  capacity (capacity) and the current number of elements (size).
 */
template <typename T>
class VectorAlgMet_EKS1 {
private:
    T* data;        // Pointer to array of type 'T'.
    int capacityVal; // Maximum length (capacity).
    int count;       // Current number of elements (size).

public:
    // Constructor: allocates storage and sets count = 0.
    VectorAlgMet_EKS1(const int length = 200) {
        this->data = new T[length]; //length of the list - creating new list using pointer data
        this->capacityVal = length; //maximum contained values
        this->count = 0; //size within object declearation
    }

    // Destructor: releases allocated memory by deleting the list created in constructor this->data = new T[length]
    ~VectorAlgMet_EKS1() {
        delete[] this->data;
    }

    // Returns total capacity.
    int capacity() const {
        return this->capacityVal;
    }

    // Clears all elements (but keeps the capacity).
    void clear() {
        // for (int i = 0; i < count; i++) { data[i] = 0; } // Not necessary.
        this->count = 0;
    }

    // Prints the entire Vector content (position and value).
    void display() const {
        for (int i = 0; i < this->count; i++) {
            cout << i << ": " << this->data[i] << "  ";
        }
        cout << "\n\t'count': " << this->count << '\n';
    }

    // Checks if empty.
    bool empty() const {
        return (this->count == 0);
    }

    // Equivalent to: ... = vec[pos]. Gets element if possible.
    T get(const int pos) const {
        if (pos >= 0 && pos < this->count) {
            return this->data[pos];
        }
        else {
            cout << "\nIndex out of bounds .....\n\n";
            return T();
        }
    }

    // Inserts 't' at position 'pos' if possible.
    bool insert(const int pos, const T t) {
        if (count < this->capacityVal) {                      // TODO: could auto-resize
            if (pos >= 0 && pos <= this->count) {               // Valid index:
                for (int i = count; i > pos; i--) {         // Shift all after one step up.
                    data[i] = data[i - 1];
                }
                this->data[pos] = t;                              // Insert new value.
                this->count++;                                    // Increase count.
                return true;
            }
            else {
                cout << "\nIndex out of bounds .....\n\n";
                return false;
            }
        }
        else {
            cout << "\nVector is already full!\n\n";
            return false;
        }
    }

    // Removes last element if possible and returns it.
    T pop_back() {
        if (!empty()) {
            T last = this->data[this->count - 1];
            this->count--;
            return last;
        }
        else {
            cout << "\nEmpty Vector - impossible to pop!\n\n";
            return T();
        }
    }

    // Removes first element if possible and returns it.
    T pop_front() {
        if (!empty()) {
            T first = this->data[0];
            remove(0);
            return first;
        }
        else {
            cout << "\nEmpty Vector - impossible to pop!\n\n";
            return T();
        }
    }

    // Adds a new element at the end.
    bool push_back(const T t) {
        return insert(this->count, t);
    }

    // Adds a new element at the beginning.
    bool push_front(const T t) {
        return insert(0, t);
    }

    // Removes element at position 'pos' if possible.
    bool remove(const int pos) {
        if (pos >= 0 && pos < this->count) {
            for (int i = pos; i < this->count - 1; i++) {
                this->data[i] = this->data[i + 1];
            }
            this->count--;
            return true;
        }
        else {
            cout << "\nIndex out of bounds .....\n\n";
            return false;
        }
    }

    // Resizes the array (capacity). Keeps elements up to new capacity.
    void resize(const int newLength) {
        if (newLength <= 0) {
            cout << "\nIllegal new capacity .....\n\n";
            return;
        }

        if (newLength == this->capacityVal) {
            return; // Nothing to do.
        }

        T* newData = new T[newLength];

        // Copy as many as will fit:
        int newCount = (this->count < newLength) ? this->count : newLength; // if this->count < length this will set newCount same as this->count, 
                                                                            // else it will sett the newlength for new count
        for (int i = 0; i < newCount; i++) {
            newData[i] = this->data[i];
        }

        delete[] data;
        this->data = newData;
        this->capacityVal = newLength;
        this->count = newCount;  // Reduce count if we shrank.
    }

    // Equivalent to: vec[pos] = value.
    void set(const int pos, const T value) {
        if (pos >= 0 && pos < this->count) {
            this->data[pos] = value;
        }
        else {
            cout << "\nIndex out of bounds .....\n\n";
        }
    }
     
    // Returns current number of elements.
    int size() const {
        return this->count;
    }
};

