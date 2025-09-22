#include "../../include/SimpleRecursion.h"
#include <iostream>                  //  cout
using namespace std;

int main() {
	SimpleRecursion s1;


    cout << "\nWrite and then RECURSION:\n\t";
    s1.display1(1);  

    cout << "\nwrite, write and then recursion:\n\t";
    s1.display2a(1);   

    cout << "\nwrite, recursion and then write:\n\t";
    s1.display2b(1);    

    cout << "\nenter " << (s1.get_max_call() * 2) << " characters "
        << "(read characters and then print them backwards):\n\t";
    s1.display3(1);      

    cout << "\nrecursion without stopping condition:\n";
    //s1.display4(1);

    cout << "\n\n";
    return 0;
	

}
