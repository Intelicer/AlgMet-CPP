#include <iostream>;
#include "../../include/VectorAlgMet_EKS1.h"

using namespace std;

int main() {


    //VectorAlgMet_EKS1<int>    iVec;
    //VectorAlgMet_EKS1<char>   cVec;
    VectorAlgMet_EKS1<string> sVec;

    sVec.push_back("AA");    
    sVec.push_back("BB");
    sVec.push_front("CC");   
    sVec.push_front("DD");

    cout << "capacity: " << sVec.capacity() << ",  size: " << sVec.size() << '\n';
    sVec.display();

    cout << "___________________________" << "\n\n";

    cout << "removing first element and last element from previous added in the vector:" << "\n";
    sVec.remove(3);   //remove element number 4
    sVec.remove(0);   //remove element number 1

    cout << "showing the new order of the vector items:" << "\n\n";
    sVec.display();

    cout << "___________________________" << "\n";

    sVec.pop_back();  // pop removes with return if you want to set the value to and variable
    sVec.pop_front(); // same but does it for the front element
    cout << "showing that all elements are gone now" << "\n\n";
    sVec.display();

    cout << "___________________________" << "\n\n";

    cout << "adding elements to the vector" << "\n";
    sVec.push_back("EE");    
    sVec.push_back("FF");
    sVec.push_front("GG");   
    sVec.push_front("HH");
    cout << "showing the elements" << "\n";
    sVec.display();

    cout << "___________________________" << "\n\n";


    sVec.insert(2, "II");  
    sVec.insert(0, "JJ");   
    sVec.insert(6, "KK");
    sVec.insert(7, "PP"); 
    sVec.insert(8, "QQ");
    sVec.display();

    cout << "___________________________" << "\n\n";


    sVec.set(6, "MM");  
    sVec.set(3, "NN");
    sVec.display();
    cout <<"\n";

    cout << "No.3: " << sVec.get(3) << "  No.6: " << sVec.get(6) << "\n";

    cout << "___________________________" << "\n\n";
    sVec.pop_back();  
    sVec.pop_front();
    sVec.pop_back();  
    sVec.pop_front();
    sVec.pop_back();  
    sVec.pop_front();
    sVec.pop_back();  
    sVec.pop_front();
    sVec.display();
    cout << "___________________________" << "\n";


    cout << "\n\nTrying 2 more 'pop' operations:\n";
    sVec.pop_back();  
    sVec.pop_front();
    sVec.display();
    cout << "___________________________" << "\n";

    return 0;


}