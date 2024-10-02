#include <iostream>
#include "project1.h"

using namespace std; 

string tokens[] = {"3", "+", "*", "4"};

int main() {
    
    getNextToken();

    Node* ast = expression();

    cout << "Abstract Syntax Tree: " << endl;
    printAST(ast);

    return 0;
}