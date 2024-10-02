#ifndef PROJECT1_H
#define PROJECT1_H
#define INTEGER 256
#include <string>
using namespace std;

// Define the Node struct for the Abstract Syntax Tree
struct Node {
    string value;
    Node* left;
    Node* right;

    //Constructor
    Node(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};
const int TOKEN_COUNT = 100; 
extern string tokens[];
// Function declarations
Node* expression();
Node* term();
Node* factor();
void getNextToken();
void match(string expected);
void error(string message);
void printAST(Node* node, int indentLevel = 0);
#endif