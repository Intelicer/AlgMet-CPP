#include "../../include/List_Ex4.h"

int main() {

    //the parameter here is the dummy also known as the head
    List_Ex4<string> list("");  //  NB:   vs.  list <string> list;
    
    list.insert("Oslo");  //node 1
    list.insert("Bergen"); //node 2    
    list.insert("Molde");//node 3
    list.insert("Nas");     //node 4
    list.insert("Armenistis"); //node 5
    list.insert("Hamar");//node 6
    list.display();

    cout << "\nHamar exists";
    if (!list.find("Hamar")) { //exists
        cout << " NOT!";
    }
    cout << "\nLarvik exists";
    if (!list.find("Larvik")) { //doesnt exist
        cout << " NOT!";
    }
    cout << '\n';

    if (!list.remove("Molde")) {
        cout << "Removing 'Molde' failed!\n"; //after remove the nodeCount is down to 5
    }
    if (!list.remove("Oslo")) {
        cout << "Removing 'Oslo' failed!\n"; // nodeCount down to 4
    }
    if (!list.remove("Gjovik")) {
        cout << "Removing 'Gjovik' failed!\n"; //doesnt exist
    }

    list.display();

    cout << "Removed no.3: " << list.removeNo(3) << '\n'; //Hamar is out 3 nodes left
    list.display();
    cout << "Removed no.3: " << list.removeNo(3) << '\n';//Nas is out 2 nodes left
    list.display();
    cout << "Removed no.1: " << list.removeNo(1) << '\n';//Armenistis out 1 node left
    list.display();

    list.removeNo(4);  // No.4 does not exist
    cout << "Removed no.4:\n ";
    list.display();

    // ======================   LIST WITH INTS:   ==============================

    List_Ex4<int> list2(0);
    list2.insert(29); //node 1
    list2.insert(17);//node 2
    list2.insert(22);//node 3
    list2.display();

    if (list2.remove(312) == 0) { //false and false print the cout
        cout << "\n\nDid not find 312!\n";
    }
    if (list2.removeNo(6) == 0) { // false and false print the cout
        cout << "Did not find no.6!\n";
    }

    cout << "\n\n";
    return 0;
}