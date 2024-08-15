#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int id;

    Student(){
        name="";
        id=0; }
    Student(string n, int i){
       name=n;
       id=i;}
};

class Stack {
public:
    Student data;
    Stack* next;
    Stack* top=NULL;

    bool isEmpty() {
        return top == NULL;
    }

    void push(Student data) {
        Stack* newNode = new Stack();
        newNode->data=data;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop student data." << endl;
            return;
        }
        Stack* temp = top;
        top = top->next;
        delete temp;
    }

    Student peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek student data." << endl;
            return Student();
        }
        return top->data;
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to print." << endl;
            return;
        }
        Stack* current = top;
        while (current != NULL) {
            cout << "Name: " << current->data.name << ", ID: " << current->data.id << endl;
            current = current->next;
        }
    }
};
int main() {
    Stack s;

    Student s1("ALEX", 1);
    Student s2("BEN", 2);
    Student s3("KEM", 3);

    s.push(s1);
    s.push(s2);
    s.push(s3);

    cout << "Stack after pushing 3 students:" << endl;
    s.printStack();

    cout << "\nPeeking top student:" << endl;
    Student topStudent = s.peek();
    cout << "Name: " << topStudent.name << ", ID: " << topStudent.id <<  endl;

    s.pop();

    cout << "\nStack after popping one student:" << endl;
    s.printStack();

    return 0;
}
