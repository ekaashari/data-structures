#include <iostream>
using namespace std;
class Node {
public:
 int data;
 Node* next;
 Node(int value) : data(value), next(nullptr) {}
};
class MergeableStack {
private:
 Node* top;
public:
 MergeableStack() : top(nullptr) {}
 // Push an item onto the stack
 void push(int x) {
 Node* newNode = new Node(x);
 newNode->next = top;
 top = newNode;
 }
 // Pop an item from the stack
 void pop() {
 if (top == nullptr) {
 cout << "Stack is empty. Cannot pop." << endl;
 return;
 }
 Node* temp = top;
 top = top->next;
 delete temp;
 }
 // Peek at the top item of the stack
 int peek() {
 if (top == nullptr) {
 cout << "Stack is empty." << endl;
 return -1; // Or some other sentinel value
 }
 return top->data;
 }
 // Print stack
 void printStack() {
 if (top == nullptr) {
 cout << "Stack is empty." << endl;
 return;
 }
 Node* temp = top;
 while (temp != nullptr) {
 cout << temp->data << " ";
 temp = temp->next;
 }
 cout << endl;
 }
 // Merge two sorted stacks
 static void merge(MergeableStack& s1, MergeableStack& s2) {
 Node* merged = nullptr;
 while (s1.top != nullptr && s2.top != nullptr) {
 Node* nodeToPush;
 if (s1.top->data < s2.top->data) {
 nodeToPush = s1.top;
 s1.top = s1.top->next;
 } else {
 nodeToPush = s2.top;
 s2.top = s2.top->next;
 }
 nodeToPush->next = merged;
 merged = nodeToPush;
 }
 while (s1.top != nullptr) {
 Node* nodeToPush = s1.top;
 s1.top = s1.top->next;
 nodeToPush->next = merged;
 merged = nodeToPush;
 }
 while (s2.top != nullptr) {
 Node* nodeToPush = s2.top;
 s2.top = s2.top->next;
 nodeToPush->next = merged;
 merged = nodeToPush;
 }
 // Reassign merged stack to s1
 s1.top = merged;
 }
};
int main() {
 MergeableStack stack1, stack2;
 stack1.push(10);
 stack1.push(5);
 stack1.push(1);
 stack2.push(20);
 stack2.push(15);
 stack2.push(8);
 cout << "Stack 1 before merge: ";
 stack1.printStack();
 cout << "Stack 2 before merge: ";
 stack2.printStack();
 MergeableStack::merge(stack1, stack2);
 cout << "Stack 1 after merge: ";
 stack1.printStack();
 return 0;
}
