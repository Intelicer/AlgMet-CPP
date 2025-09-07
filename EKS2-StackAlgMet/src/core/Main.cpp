#include "../../include/Stack_Ex2.h"
using namespace std;

int main() {
    Stack_Ex2<int> iStack;       // NOTE: vs. stack<int> iStack; from STL (with lowercase 's').
    Stack_Ex2<char> cStack;
    Stack_Ex2<string> sStack; //by default capacity 200

    cout << "Int" << "\n";
    iStack.push(29);
    iStack.push(22);
    iStack.push(17);
    iStack.push(7);
    iStack.push(6);
    iStack.display(); /*
                      * 6
                      * 7
                      * 17
                      * 22
                      * 29
                      */

    int i = iStack.pop(); //6
    cout <<"i = " << i << "\n";
    cout << "pop: " << iStack.pop() << "\n";//7
    cout << "pop: " << iStack.pop() << '\n';//17
    iStack.display(); //22 29

    iStack.pop(); //29
    iStack.pop(); //22
    iStack.display();

    iStack.pop();  // empty stack

    cout << "--------------------------------" << "\n";


    cout << "Char" << "\n";
    // ======================   STACK WITH CHARs:   ============================
    cStack.push('G');
    cStack.display();
    cStack.pop();
    cStack.pop();   // At the last 'pop' the stack is empty.

    // ======================   STACK WITH STRINGs:   ==========================
    string st;
    sStack.push("Banana mash");

    st = sStack.pop();
    cout << "\npopped text: '" << st << "'\n\n";

    st = sStack.pop();   // At the last 'pop' the stack is empty:
    cout << "popped text: '" << st << "'\n\n";

    return 0;
}