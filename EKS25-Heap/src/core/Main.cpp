#include "../../include/Heap.h"

//****************************************************************************
//       THE PROGRAM CAN BE TESTED/RUN AS A STANDALONE PROGRAM BY:
//           - RENAMING THE FILE FROM .H to .CPP
//           - REMOVING THE COMMENTING (/*......*/) OF 'MAIN' BELOW
//****************************************************************************


/**
 *  The main program:
 */

 int main() {
   Heap <int>            heap;
 //  Heap <unsigned char>  heap2;          //  Using 'unsigned char' !!!

   cout << "\n\nDemonstrating the use of the heap.";
   heap.insert(1);  
   cout << "\nInsert 1 :  "; 
   heap.display();
   
   heap.insert(5);  
   cout << "\nInsert 5 :  "; 
   heap.display(); 
   
   heap.insert(2);  
   cout << "\nInsert 2 :  "; 
   heap.display();


   heap.insert(6);  
   cout << "\nInsert 6 :  "; 
   heap.display();

   heap.replace(4); 
   cout << "\nReplace 4:  "; 
   heap.display();

   heap.insert(8);  
   cout << "\nInsert 8 :  "; 
   heap.display();

   heap.remove();   
   cout << "\nRemove   :  "; 
   heap.display();
   
   heap.insert(7);  
   cout << "\nInsert 7 :  "; 
   heap.display(); 

   heap.insert(3);  
   cout << "\nInsert 3 :  "; 
   heap.display(); 

   cout << "\n\n\nTesting two self-made functions from exercise no.15:\n";
   heap.change(4, 5); 
   cout<<"\nChange #4 to 5: "; 
   heap.display(); 


   heap.change(3, 1); 
   cout<<"\nChange #3 to 1: "; 
   heap.display(); 

   heap.extract(2);   
   cout<<"\nExtract #2:   ";   
   heap.display(); 
   
   heap.extract(2);   
   cout<<"\nExtract #2:   ";   
   heap.display(); 

   heap.extract(1);   
   cout<<"\nExtract #1:   ";   
   heap.display();



   cout << "\n\n";
   return 0;
 }