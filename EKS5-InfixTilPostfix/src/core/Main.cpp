#include <iostream>  //  cout
#include "../../include/InfixTilPostfix.h"
using namespace std;

/**
 *  Main program:
 */
int main() {
    InfixTilPostfix i1;

    i1.read_from_user();


    //if you want to see the stack you need to rmeove comment on 
    // line  35 in module cpp file and comment the (cout's)
    i1.printStack(i1.get_stack());

    return 0;
}
