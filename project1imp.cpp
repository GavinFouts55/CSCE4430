#include "project1.h"
#include <iostream>
#include <cctype>
using namespace std;

string currentToken;
int tokenIndex = 0;

void getNextToken() {
    if (tokenIndex < TOKEN_COUNT) {
        currentToken = tokens[tokenIndex++];
    } else {
        currentToken = ""; 
    }
}
void match(string expected) {
    if(currentToken == expected) {
        getNextToken();
    } else {
        error("Expected '" + expected + "' but got '" + currentToken + "'");
    }
}
void error(string message) {
    cerr << message << endl;
    exit(1);
}

Node* term() {
    Node* left = factor();
    while (currentToken == "*" || currentToken == "/") {
        Node* node = new Node(currentToken);
        match(currentToken);
        node->left = left;
        node->right = factor();
        left = node;
    }
    return left;
}

Node* factor() {
    if(currentToken.empty()) {
        error("Unexpected end of input.");
    }
    if(isdigit(currentToken[0])) {
        Node* node = new Node(currentToken);
        match(currentToken);
        return node;
    } else if (currentToken == "(") {
        match("(");
        Node* node = expression();
        match(")");
        return node;
    } else {
        error("Unexpected token: " + currentToken);
        return nullptr;
    }
}
Node* expression() {
     if (currentToken.empty()) {
        error("Unexpected end of input while parsing expression.");
    }
    Node* left = term();
    while(currentToken == "+" || currentToken == "-") {
        Node* node = new Node(currentToken);
        match(currentToken);
        node->left = left;
        node->right = term();
        left = node;
    }
    return left;
}
void printAST(Node* node, int indentLevel) {
    if(node == nullptr) {
        return;
    }
    
    for(int i = 0; i < indentLevel; ++i) {
        cout << " ";
    }
    if(node->value == "+" || node->value == "-" || node->value == "*" || node->value == "/") {
        if(node->value == "+") {
            cout << "+(Add)" << endl;
        } else if (node->value == "-") {
            cout << "-(Minus)" << endl;
        } else if (node->value == "*") {
            cout << "*(Multiply)" << endl;
        } else if (node->value == "/") {
            cout << "/(Divide)" << endl;
        }
    } else {
        cout << node->value << "(int)" << endl;
    }
        if (node->value == "+" || node->value == "-" || node->value == "*" || node->value == "/") {
        printAST(node->left, indentLevel + 2); 
        printAST(node->right, indentLevel + 2); 
}
}