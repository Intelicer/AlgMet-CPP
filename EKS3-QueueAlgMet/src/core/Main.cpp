#include "../../include/Queue_Ex3.h"
using namespace std;

int main() {
	Queue_Ex3<int>    intQueue;      // NB: vs. queue<int> intQueue;
	Queue_Ex3<char>   charQueue;     //      from STL, written with small 'q'.
	Queue_Ex3<string> stringQueue;

	intQueue.put(29);  
	intQueue.put(22);  
	intQueue.put(17);
	intQueue.put(7);   
	intQueue.put(6);   
	intQueue.display();

	cout << "\nget: " << intQueue.get();
	cout << "  get: " << intQueue.get() << '\n';
	intQueue.display();

	intQueue.get();  
	intQueue.get();  
	intQueue.get();
	intQueue.display();

	intQueue.get();  // At the last 'get' it is empty.

	intQueue.put(304);  
	intQueue.put(312);
	intQueue.get();
	intQueue.display();

	intQueue.get();
	intQueue.display();

	// ======================   QUEUE WITH CHARs:   ============================
	charQueue.put('G');
	charQueue.get();
	charQueue.get();  // At the last 'get' it is empty.

	// ======================   QUEUE WITH STRINGs:   ==========================
	string st;

	stringQueue.put("BananaMash");

	st = stringQueue.get();
	cout << "\nRetrieved text: '" << st << "'\n\n";

	st = stringQueue.get();  // At the last 'get' it is empty.
	cout << "Retrieved text: '" << st << "'\n\n";

	return 0;
}