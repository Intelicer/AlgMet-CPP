#include "../../include/Queue_Ex3.h"
using namespace std;

int main() {
	Queue_Ex3<int>    intQueue;      // NB: vs. queue<int> intQueue;
	Queue_Ex3<char>   charQueue;     //      from STL, written with small 'q'.
	Queue_Ex3<string> stringQueue;

	intQueue.put(22);  //22
	intQueue.put(29);  //29
	intQueue.put(17);  //17
	intQueue.put(7);   //7
	intQueue.put(6);   //6
	intQueue.display();
	cout << "-----------------------" << "\n";

	cout << "\nget: " << intQueue.get(); //22
	cout << "\nget: " << intQueue.get() << "\n\n"; //29
	intQueue.display();// 17 7 6

	cout << "-----------------------" << "\n";

	intQueue.get();  //17
	intQueue.get();  //7
	intQueue.get();	 //6
	intQueue.display(); //empty
	cout << "-----------------------" << "\n";

	intQueue.get();  // At the last 'get' it is empty.
	cout << "-----------------------" << "\n";

	intQueue.put(304);  //pos 5: 304
	intQueue.put(312);	//pos 6: 312
	intQueue.get();		// 304
	intQueue.display(); // 312
	cout << "-----------------------" << "\n";

	intQueue.get();// 312
	intQueue.display(); //empty but pos to add elements are 7
	cout << "-----------------------" << "\n";

	cout << "==========CHAR=========" << "\n";

	// ======================   QUEUE WITH CHARs:   ============================
	charQueue.put('G'); //add G and pos of back is now 1
	charQueue.display();
	cout << "-----------------------" << "\n";

	charQueue.get();	// G
	charQueue.get();  // empty because we had one Char
	cout << "-----------------------" << "\n";

	// ======================   QUEUE WITH STRINGs:   ==========================
	cout << "=========STRING========" << "\n";

	string st;

	stringQueue.put("BananaMash");
https://chatgpt.com/g/g-p-68b5dde781488191bad435220c419638-algmet-mahmoud/c/68be7180-600c-8322-8b27-c1d79e03914f
	st = stringQueue.get();
	cout << "\nRetrieved text: '" << st << "'\n\n";

	st = stringQueue.get();  // At the last 'get' it is empty.
	cout << "Retrieved text: '" << st << "'\n\n";

	return 0;
}