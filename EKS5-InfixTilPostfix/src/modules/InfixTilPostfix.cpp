#include "../../include/InfixTilPostfix.h"


void InfixTilPostfix::printStack(stack<char> st){
    while (!st.empty()) {           //  Still elements left:
        cout << ' ' << st.top();    //  Print the current top element.
        st.pop();                   //  Remove the top element.
    }
    cout << '\n';
}

void InfixTilPostfix::read_from_user() {
    cout << "\n\nType an infix expression:\n";
    cout << "--------------------" << "\n";
    //  Read ALL characters, including ' ' (spaces), until '\n':
    while ((this->ch = cin.get()) != '\n') {
        if (this->ch == ')') {                //  Closing parenthesis found:
            cout << this->stackObj.top();     //  Print top of the stack.
            stackObj.pop();             //  Remove the operator.
        }
        else if (this->ch == '+' || this->ch == '*') {
            stackObj.push(this->ch);          //  Push '+' or '*'
        }

        //  While digits in ONE number:
        while (this->ch >= '0' && this->ch <= '9') {  // Print multi-digit number:
            cout << this->ch;                   // Print ONE digit.
            this->ch = cin.get();               // Read next digit/character. if removing this you will be stuck in a loop of 8
        }

        //  Print a space (important to do after every number).
        if (this->ch != '(') {
            cout << ' ';
        }
        //printStack(this->stackObj);  //  Comment out the 3x other cout's if you use this.
        //                        //  Ignore duplicate output lines!
    }
    cout << "\n\n";
}

stack<char> InfixTilPostfix::get_stack() {
    return this->stackObj;
}