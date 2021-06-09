#include <iostream>
#include <string>
using namespace std;
#include "StrangeCalculator.h"

bool isOperator(char ch);
bool isDigit(char ch);
int precedence(char optr);


string infix2prefix( const string exp ) {
    string postfix = "";
    string prefix = "";
    string reversedExp = "";

    Stack<char> aStack;

    // Expression reversed
    for(int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];
        if(c == '(') {
            reversedExp += ')';
        }
        else if(c == ')') {
            reversedExp += '(';
        }
        else {
            reversedExp += c;
        }
    }

    // Convert to postfix
    for(int i = 0; i < reversedExp.length(); i++) {
        char ch = reversedExp[i];

        if(isDigit(ch)) {
            postfix += ch;
        }

        else if(ch == '(') {
            aStack.push(ch);
        }

        else if(ch == ')') {
            char top;
            aStack.getTop(top);
            while(top != '(') {
                char c;
                aStack.pop(c);
                postfix += c;
                aStack.getTop(top);
            }
            aStack.pop();
        }

        else if(isOperator(ch)) {
            char top;
            aStack.getTop(top);
            while(!aStack.isEmpty() && top != '(' && precedence(ch) < precedence(top)) {
                postfix += top;
                aStack.pop();
                aStack.getTop(top);
            }

            aStack.push(ch);

        }

    }

    while(!aStack.isEmpty()) {
        char top;
        aStack.pop(top);
        postfix += top;
    }

    // Reverse postfix to get prefix
    for(int i = postfix.length() - 1; i >= 0; i--) {
        prefix += postfix[i];
    }

    return prefix;
}


double evaluatePrefix( const string exp ) {

    Stack<double> aStack;

    for(int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];

        if(isDigit(ch)) {
            double operand = ch - '0';
            aStack.push(operand);
        }

        else if(isOperator(ch)) {
            double op1;
            double op2;
            double result;

            aStack.pop(op1);
            aStack.pop(op2);

            switch(ch) {

                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                default : result = op1 / op2; break;
            }

            aStack.push(result);
        }

    }
    double res;
    aStack.getTop(res);

    return res;

}

bool isBalancedInfix( const string exp ) {

    Stack<char> aStack;
    for(int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if(ch == '(') {
            aStack.push(ch);
        }
        else if(ch == ')') {
            if(!aStack.pop()) {
                return false;
            }
        }
    }

    if(!aStack.isEmpty())
        return false;

    return true;
}

void evaluateInputPrefixExpression( ) {

    string inExp = "";
    cout << "Enter an infix expression: ";
    getline(cin, inExp);

    string exp = "";
    for(int i = 0; i < inExp.length(); i++) {
        if(inExp[i] != ' ')
            exp += inExp[i];
    }

    if(isBalancedInfix(exp)) {
        string prefix = infix2prefix(exp);
        cout << "The result of the expression " << exp << " is "<< evaluatePrefix(prefix) << endl;

    }
    else
        cout << "The expression is not balanced!" << endl;

}

bool isOperator(char ch) {
    string operators = "+-*/";

    for(int i = 0; i < operators.length(); i++) {
        if(ch == operators[i])
            return true;
    }
    return false;
}

bool isDigit(char ch) {
    string digits = "0123456789";

    for(int i = 0; i < digits.length(); i++) {
        if(ch == digits[i])
            return true;
    }
    return false;
}

int precedence(char optr) {
    if(optr == '*' || optr == '/') {
        return 1;
    }
    return 0;
}


// -------------- Stack Class -------------------------


template<typename StackItemType>
Stack<StackItemType>::Stack() {
    topPtr = NULL;
}

template<typename StackItemType>
Stack<StackItemType>::Stack(const Stack<StackItemType>& aStack) {

    if(aStack.topPtr == NULL) {
        topPtr = NULL;
    }
    else {

        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        StackNode* newNode = topPtr;
        for(StackNode cur = aStack.topPtr->next; cur != NULL; cur = cur->next) {
            newNode->next = new StackNode;
            newNode = newNode->next;
            newNode->item = cur->item;
        }

        newNode->next = NULL;

    }
}

template<typename StackItemType>
Stack<StackItemType>::~Stack() {
    while(!isEmpty()) {
        pop();
    }
}

template<typename StackItemType>
bool Stack<StackItemType>::isEmpty() const {
    return topPtr == NULL;
}

template<typename StackItemType>
bool Stack<StackItemType>::push(StackItemType newItem) {
    StackNode* newNode = new StackNode;
    newNode->item = newItem;

    newNode->next = topPtr;
    topPtr = newNode;
    return true;
}

template<typename StackItemType>
bool Stack<StackItemType>::pop() {
    if(isEmpty())
        return false;

    StackNode* temp = topPtr;
    topPtr = topPtr->next;

    temp->next = NULL;
    delete temp;
    return true;
}

template<typename StackItemType>
bool Stack<StackItemType>::pop(StackItemType& stackTop) {
    if(isEmpty())
        return false;

    stackTop = topPtr->item;
    StackNode* temp = topPtr;
    topPtr = topPtr->next;

    temp->next = NULL;
    delete temp;
    return true;
}

template<typename StackItemType>
bool Stack<StackItemType>::getTop(StackItemType& stackTop) const {
    if(isEmpty())
        return false;
    stackTop = topPtr->item;
    return true;
}




