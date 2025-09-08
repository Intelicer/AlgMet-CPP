/**
 *   Program example no. 4 - List (self-made simple class).
 *
 *   The example shows a self-made implementation of the container class List.
 *   Code has been written for the following functions:
 *
 *     -  List()
 *     -  ~List
 *     -  void  display()
 *     -  bool  empty()
 *     -  bool  find(const T t)
 *     -  void  insert(const T t)
 *     -  bool  remove(const T t)
 *     -  T     removeNo(const int no)   // From 1 (not 0) and upwards!
 *     -  int   size()
 *
 *   NOTE: To (hopefully) increase readability and clarity, the member
 *         functions are deliberately NOT commented according to the
 *         Doxygen standard.
 *
 *   @file     EKS_04_List.CPP
 *   @author   Frode Haug, NTNU
 */

#include <iostream>   //  cout
#include <string>     //  string
using namespace std;

/**
 *  The container class List, which is a self-made version of STL's <list>.
 *
 *  Contains a private struct 'Node', with only one data member and a pointer to
 *  the next node in the list. In addition, there is a pointer ('head') to the
 *  start of the list, and the number of nodes in the list. The list is sorted
 *  by 'T' in ascending order.
 */
template <typename T>  //  'T': flexible data type!
class List_Ex4 {

private:
    struct Node {        //  Hidden struct for list with 'data'.
        T data;          //  Stored 'data'. Exp: int, char, string
        Node* next;      //  Pointer to next in the list. creates Node of same class to connect another node with it.
        
        //  Constructor.
        Node(const T d) {
            data = d;
            next = nullptr;
        }               
    };

    Node* head;          //  Dummy head to simplify much of the code.
    int   nodeCount;     //  Current number of nodes in the list.

public:                  //  Initializes members:
    List_Ex4(const T t) {
        this->head = new Node(t);
        nodeCount = 0;
    }

    ~List_Ex4() {            //  Destructor - deletes the ENTIRE list:
        Node* curr;      //  Helper pointer to next in the list.
        while (this->head) {   //  While something to delete:
            curr = this->head->next;  //  Pointer to the second node.
            delete this->head;        //  Delete the first node.
            this->head = curr;        //  Move head to point to the new first.
        }
    }

    void display() const {        //  Print the list's contents:
        Node* curr = this->head->next;  //  Skip the dummy head.
        while (curr) {            //  While not reached nullptr keep going. there is no limitaion except how much ram you can fill max
            cout << '\t' << curr->data << '\n';  //  Print node data.
            curr = curr->next;    //  Move to next element in the list
        }
        cout << "\n\tNumber of nodes in the list: " << this->nodeCount << '\n';
    }

    bool empty() const {          //  Return whether list is empty:
        return (this->nodeCount == 0);
    }

    bool find(const T t) const {  //  Return whether 't' is found:
        Node* curr = this->head->next;
        while (curr && (curr->data < t)) { // curr(not nullptr) && (curr->data < t)
            curr = curr->next;
        }
        return (curr && curr->data == t);  // Found or not?
    }


    /*
        When inserting the value you insert is sorted by ASCII 
    */
    void insert(const T t) {      //  Insert new node sorted:
        Node* curr = this->head; //takes the dummy node
        Node* newNode = new Node(t); //creates new node for the element that are going to be inserted to the list

        // While next exists and is less than the new node
        while (curr->next && (curr->next->data < newNode->data)) { //curr->next not nullptr and (curr->next->data) < newNode->data
            curr = curr->next;                                    
        }

        newNode->next = curr->next;  /* Link into the chain
                                     * points to the pointer of next curr if the newNode 
                                     * comes last it will take the nullptr from curr
                                     */

        curr->next = newNode;        //  The curr node now will point to the newNode via next
        this->nodeCount++;           //  Increase total node count.
    }

    bool remove(const T t) {         //  Return whether removed:
        Node* curr = this->head;    //dummy
        Node* nextNode = this->head->next; // the node after the dummy

        while (nextNode && (nextNode->data < t)) {
            curr = nextNode;
            nextNode = nextNode->next;
        }

        if (nextNode && (nextNode->data == t)) {  //  Found:
            curr->next = nextNode->next;        //  Unlink 'nextNode'
            delete nextNode;                    //  Delete it.
            this->nodeCount--;                        //  Decrease count.
            return true;
        }
        else {
            return false;                       //  Not removed.
        }
    }

    //example with 2 nodes | read comment with (// node (int)) to follow how it works
    // Notice that node numbers start from 1 head node are not one of them.
    T removeNo(const int no) {   //  Return node no. 'no' if possible:
        Node* curr = this->head; //node 0 dummy
        Node* nextNode = this->head->next;//node 1
        T returnData;

        if ((no >= 1) && (no <= this->nodeCount)) {
            for (int i = 1; i < no; i++) {
                curr = nextNode; //node 1
                nextNode = nextNode->next; //node 2
            }
            curr->next = nextNode->next;  //  Unlink node
            returnData = nextNode->data;  //  Save its data
            delete nextNode;              //  Delete node
            this->nodeCount--;                  //  Decrease count
            return returnData;            //  Return saved data
        }
        else {
            cout << "\nNumber out of bounds .....\n\n";
        }
        return T();
    }

    int size() const {            //  Return number of nodes in the list:
        return this->nodeCount;
    }
};



