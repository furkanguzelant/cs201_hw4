#include <iostream>
using namespace std;
#include "StrangeCalculator.h"
int main(){
cout << "prefix of: 5+6 is: " << infix2prefix("5+6") << endl;
cout << "prefix of: 5+6*7 is: " << infix2prefix("5+6*7") << endl;
cout << "prefix of: 5+6*(7/2) is: " << infix2prefix("5+6*(7/2)") << endl;
cout << "prefix of: (5+6)*(7/2) is: " << infix2prefix("(5+6)*(7/2)") << endl;
cout << "prefix of: (5+6)*(7/2)-5+7*(8*2) is: " << infix2prefix("(5+6)*(7/2)-5+7*(8*2)") << endl;
cout<< "Checkpoint 1" << endl;
cout << "result of: 5+6 is: " << evaluatePrefix( infix2prefix("5+6")) << endl;
cout << "result of: 5+6*7 is: " << evaluatePrefix( infix2prefix("5+6*7")) << endl;
cout << "result of: 5+6*(7/2) is: " << evaluatePrefix(infix2prefix("5+6*(7/2)")) << endl;
cout << "result of: (5+6)*(7/2) is: " << evaluatePrefix( infix2prefix("(5+6)*(7/2)")) << endl;
cout << "result of: (5+6)*(7/2)-5+7*(8*2) is: " << evaluatePrefix(infix2prefix("(5+6)*(7/2)-5+7*(8*2)")) << endl;
cout << "Checkpoint 2" << endl;
cout << isBalancedInfix( "((5+7" ) << endl;
cout << isBalancedInfix( "((5+7)))" ) << endl;
cout << isBalancedInfix( "(5+4" ) << endl;
cout << isBalancedInfix( "(5+4)*3-4*(9+8))" ) << endl;
cout << isBalancedInfix( "(5+4)*3-(4*(9+8))" ) << endl;

cout << endl;

cout << "prefix of: (5+4)*3-(4*(9+8)) is: " << infix2prefix("(5+4)*3-(4*(9+8))") << endl;
cout << "result of: (5+4)*3-(4*(9+8)) is: " << evaluatePrefix(infix2prefix("(5+4)*3-(4*(9+8))")) << endl;
cout << "prefix of: 2+3*(4-6)+7 is: " << infix2prefix("2+3*(4-6)+7") << endl;
cout << "result of: 2+3*(4-6)+7 is: " << evaluatePrefix(infix2prefix("2+3*(4-6)+7")) << endl;
cout << "prefix of: (2+3)*(4-6)+7 is: " << infix2prefix("(2+3)*(4-6)+7") << endl;
cout << "result of: (2+3)*(4-6)+7 is: " << evaluatePrefix(infix2prefix("(2+3)*(4-6)+7")) << endl;
cout << "prefix of: ((2+3)*(4-6)+7)/2 is: " << infix2prefix("((2+3)*(4-6)+7)/2") << endl;
cout << "result of: ((2+3)*(4-6)+7)/2 is: " << evaluatePrefix(infix2prefix("((2+3)*(4-6)+7)/2")) << endl;
cout << "prefix of: ((4+2)*(9-2)+3)/4+2/7-5*2 is: " << infix2prefix("((4+2)*(9-2)+3)/4+2/7-5*2") << endl;
cout << "result of: ((4+2)*(9-2)+3)/4+2/7-5*2 is: " << evaluatePrefix(infix2prefix("((4+2)*(9-2)+3)/4+2/7-5*2")) << endl;
cout << "prefix of: ((4+2)*(9-2)+3)/4+2/7-5*2/(7+4)/(3-5) is: " << infix2prefix("((4+2)*(9-2)+3)/4+2/7-5*2/(7+4)/(3-5)") << endl;
cout << "result of: ((4+2)*(9-2)+3)/4+2/7-5*2/(7+4)/(3-5) is: " << evaluatePrefix(infix2prefix("((4+2)*(9-2)+3)/4+2/7-5*2/(7+4)/(3-5)")) << endl;

cout << isBalancedInfix("3*((5+2)-1") << endl;
cout << isBalancedInfix("3*((5+2)-1)") << endl;

int con;
do {
    evaluateInputPrefixExpression();
    cout << "Enter 1 to continue: ";
    cin >> con;
    cin.ignore();
} while(con == 1);
return 0;
}
