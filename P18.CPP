#include <iostream>
#define MAX 100
using namespace std;

class Employee {
public:
    string name;
    int emp_id;
    double salary;

    Employee(){
        name="";
        emp_id=0;
        salary=0.0; }
    Employee(string n, int id, double sal){
       name=n;
       emp_id=id;
       salary=sal;}
};

class Stack {
public:
    Employee s[MAX];
    int top=-1;

    bool isFull() {
        return top == MAX - 1;
    }
    bool isEmpty() {
        return top == -1;
    }

    void push(Employee emp) {
        if (isFull()) {
            cout << "Stack is full. Cannot push employee data." << endl;
            return;
        }
        s[++top] = emp;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop employee data." << endl;
            return;
        }
        top--;
    }

    Employee peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek employee data." << endl;
            return Employee();
        }
        return s[top];
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to print." << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << "Name: " << s[i].name << ", ID: " << s[i].emp_id << ", Salary: " << s[i].salary << endl;
        }
    }
};

int main() {
    Stack emp;

    Employee emp1("DAISY", 1, 50000.0);
    Employee emp2("JOHN", 2, 60000.0);
    Employee emp3("RAY", 3, 70000.0);

    emp.push(emp1);
    emp.push(emp2);
    emp.push(emp3);

    cout << "Stack after pushing 3 employees:" << endl;
    emp.printStack();

    cout << "\nPeeking top employee:" << endl;
    Employee topEmp = emp.peek();
    cout << "Name: " << topEmp.name << ", ID: " << topEmp.emp_id << ", Salary: " << topEmp.salary << endl;

    emp.pop();

    cout << "\nStack after popping one employee:" << endl;
    emp.printStack();

    return 0;
}
