#include "../../include/PostfixToResualt.h"

void PostfixToResualt::read_and_get_result(){
    cout << "\n\nEnter a postfix expression:\n";

    // Read ALL characters, including ' ', until newline:
    while ((this->ch = cin.get()) != '\n') {
        this->number = 0;  // Reset accumulator.

        // Skip any extra spaces.
        while (this->ch == ' ') {
            this->ch = cin.get();
        }

        if (this->ch == '+') {                  // '+' found:
            this->number = this->stackObj.top();
            this->stackObj.pop();               // Pop first operand
            this->number += this->stackObj.top();
            this->stackObj.pop();               // Add to second operand
        }
        else if (ch == '*') {           // '*' found:
            this->number = this->stackObj.top();
            this->stackObj.pop();               // Pop first operand
            this->number *= this->stackObj.top();
            this->stackObj.pop();               // Multiply with second operand
        }

        // Build multi-digit number if digits are found:
        while (this->ch >= '0' && this->ch <= '9') {
            this->number = (10 * this->number) + (this->ch - '0'); // Shift left and add digit
            this->ch = cin.get();                      // Read next character
        }

        // Push either the computed or the built number.
        this->stackObj.push(this->number);

        printStack(this->stackObj);
    }
}

void PostfixToResualt::printStack(stack<int> st) {
    while (!st.empty()) {        // Still elements left:
        cout << ' ' << st.top(); // Print the current top.
        st.pop();                // Remove the top element.
    }
    cout << '\n';
}

stack<int> PostfixToResualt::getStack() const {
    return this->stackObj;
}