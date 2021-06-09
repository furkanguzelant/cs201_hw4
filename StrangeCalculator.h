#ifndef __STRANGECALCULATOR_H
#define __STRANGECALCULATOR_H
#include <string>
using namespace std;

string infix2prefix( const string exp );
double evaluatePrefix( const string exp );
bool isBalancedInfix( const string exp );
void evaluateInputPrefixExpression( );


template<typename StackItemType>
class Stack{

public:
   Stack<StackItemType>();
   Stack<StackItemType>(const Stack<StackItemType>& aStack);
   ~Stack();

   bool isEmpty() const;
   bool push(StackItemType newItem);
   bool pop();
   bool pop(StackItemType& stackTop);
   bool getTop(StackItemType& stackTop) const;

private:
   struct StackNode {            // a node on the stack
      StackItemType item;        // a data item on the stack
      StackNode    *next;        // pointer to next node
   };

   StackNode *topPtr;     // pointer to first node in the stack
};
#endif
