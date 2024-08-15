#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Function to evaluate a prefix expression
int evaluatePrefix(const string& expr) {
 stack<int> s;
 // Traverse the expression from right to left
 for (int i = expr.length() - 1; i >= 0; --i) {
 char c = expr[i];
 if (isdigit(c)) {
 // Push single-digit operand onto the stack
 s.push(c - '0');
 } else if (c == '+' || c == '-' || c == '*' || c == '/') {
 // Pop two operands from the stack
 int operand1 = s.pop();
 int operand2 = s.pop();
 // Perform the operation and push the result back onto the stack
 int result;
 switch (c) {
 case '+':
 result = operand1 + operand2; break;
 case '-':
 result = operand1 - operand2; break;
 case '*':
 result = operand1 * operand2; break;
 case '/':
 result = operand1 / operand2; break;
 }
 s.push(result);
 }
 }
 // The final result will be the only element left in the stack
 return s.top();
}
int main() {
 string prefixExpr;
 cout << "Enter a prefix expression (with single-digit operands and operators): ";
 cin >> prefixExpr;
 // Evaluate and print the result
 int result = evaluatePrefix(prefixExpr);
 cout << "The result of the prefix expression is: " << result << endl;
 return 0;
}
