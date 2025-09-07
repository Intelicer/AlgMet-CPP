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
    VectorAlgMet_EKS1(const int length = 200) { //length cant be edited becasue const
        this->data = new T[length]; //length of the list - creating new list using pointer data
        this->capacityVal = length; //maximum contained values
        this->count = 0; //size within object declearation
    }

    // Destructor: releases allocated memory by deleting the list created in constructor this->data = new T[length]
    ~VectorAlgMet_EKS1() {
        delete[] this->data;
    }

    // Returns total capacity that cant be modified
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

    // Checks if empty. const to not modify the bool value
    bool empty() const {
        return (this->count == 0);
    }

    // Equivalent to: ... = vec[pos]. Gets element if possible.
    T get(const int pos) const {
        if (pos >= 0 && pos < this->count) { //checks if the position is valid higher or equals 0 and lower than count 
            return this->data[pos]; // returns the item via position
        }
        else { // it pos is not valid it will return 
            cout << "\nIndex out of bounds .....\n\n";
            return T();
        }
    }

    // Inserts 't' at position 'pos' if possible.
    bool insert(const int pos, const T t) {
        if (this->count < this->capacityVal) {                      // TODO: could auto-resize
            if (pos >= 0 && pos <= this->count) {               // Valid index: pos equal 0 or higher and pos lower or equals this->count
                for (int i = count; i > pos; i--) {         // Shift all after one step up. 
                                                                /*
                                                                *   pos 7
                                                                *   Lets say count = 9
                                                                *   i = 9
                                                                *   
                                                                * 
                                                                *   data[9] = data[9-1] // this says that element number 8 will take element number 9 pos
                                                                * 
                                                                *   (i--) ---> i = 8
                                                                *   
                                                                *   ----------------
                                                                * 
                                                                *   data[8] = data[8-1] //elemnt number 8 stores elemnt number 7
                                                                * 
                                                                *   ----------------
                                                                * 
                                                                *   Now that element number 7 is empty and t will be stored in that pos
                                                                *   and the elements count will increase by one
                                                                *   after that it will return true verify its done
                                                                */
                    data[i] = data[i - 1];
                }
                this->data[pos] = t;                              // Insert new value.
                this->count++;                                    // Increase count.
                return true;                                       
            }
            else {                  
                cout << "\nIndex out of bounds .....\n\n";      // prints out of bound because the index is not withing the condition 
                                                                // pos >= 0 && pos <= this->count
                return false;
            }
        }
        else {
            cout << "\nVector is already full!\n\n";            // prints this if the count and size is equal or (count is higher that this->capacity and that impossible)
            return false;
        }
    }

    // Removes last element if possible and returns it.
    T pop_back() {
        if (!empty()) { //check if not empty
            T last = this->data[this->count - 1]; //store last element by taking (this->count - 1) in a local variable
                                                  //and sets it in this->data[this->count - 1]
            this->count--;                        //then the elements count is now -1 lower than before doing the pop
            return last;                          //now the last can be taken to deal with it.
        }
        else {
            cout << "\nEmpty Vector - impossible to pop!\n\n"; // if the vector is empty then a message prints out
            return T(); //returns the empty vector 
        }
    }

    // Removes first element if possible and returns it.
    T pop_front() {
        if (!empty()) {
            T first = this->data[0]; // same consept as pop_back but takes the first index of the vector, and stores it in a local variable
            remove(0);               // remove the first index and 
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
            for (int i = pos; i < this->count - 1; i++) {   /*
                                                            * Example:
                                                            * we have a list with (this->count = 16) and want to remove pos 13
                                                            * 
                                                            * i = pos = 13
                                                            * 
                                                            * if(13 < (16-1)){ // 16 - 1 because this is the total element -1 
                                                            *                  //to get the last element for the condition
                                                            *   this->data[13] = this->data[13+1]
                                                            * }
                                                            * 
                                                            * i++
                                                            * 
                                                            * ----------------------
                                                            * 
                                                            * now i = 14
                                                            * 
                                                            * if(14<15){
                                                            *   this->data[14] = this->data[14+1]
                                                            * }
                                                            * 
                                                            * i++
                                                            * 
                                                            * ----------------------
                                                            * 
                                                            * now i = 15
                                                            * 
                                                            * if(15<15) false
                                                            * 
                                                            * then this->count-- from 16 to 15 and last element is 14
                                                            * 
                                                            * and return true to verfiy that the element is removed
                                                            * 
                                                            */
                this->data[i] = this->data[i + 1];
            }
            this->count--;
            return true;
        }
        else {
            cout << "\nIndex out of bounds .....\n\n"; // if pos is not within 0 and (this->count - 1)
            return false;
        }
    }

    // Resizes the array (capacity). Keeps elements up to new capacity.
    void resize(const int newLength) {
        if (newLength <= 0) {
            cout << "\nIllegal new capacity .....\n\n"; //if the new length is 0 or negativ
            return;
        }

        if (newLength == this->capacityVal) { //if new length equals this->capacityVal
            return; // Nothing to do.
        }

        T* newData = new T[newLength];

        // Copy as many as will fit:
        int newCount = (this->count < newLength) ? this->count : newLength; // if this->count < length this will set newCount same as this->count, 
                                                                            // else it will sett the newlength for new count
        for (int i = 0; i < newCount; i++) { //store the old elements in the new list element pos
            newData[i] = this->data[i];
        }

        delete[] this->data; //delete old list
        this->data = newData;
        this->capacityVal = newLength;
        this->count = newCount;  // Reduce count if we shrank.
    }

    // Equivalent to: vec[pos] = value.
    void set(const int pos, const T value) { //set new value for element in the vector
        if (pos >= 0 && pos < this->count) { // if the pos is within the 0 and the this->count
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

