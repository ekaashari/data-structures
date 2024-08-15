//C++ Program that uses a singly linked list to store employee details (ID, name and salary). Find and display
//the employee with the highest salary.
#include <iostream>
using namespace std;
class Node {
public:
    int id;
    string name;
    double salary;
    Node* next;
};
void push(Node** head, int id, string name, double salary)
{
    Node* new_node = new Node();
    new_node->id = id;
    new_node->name = name;
    new_node->salary = salary;
    new_node->next = *head;
    *head=new_node;
}
Node* maxsalary(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* maxNode = head;
    Node* current = head->next;

    while (current != NULL) {
        if (current->salary > maxNode->salary) {
            maxNode = current;
        }
        current = current->next;
    }

    return maxNode;
}
void print(Node* n)
{
    while(n!=NULL)
    {
        cout << "ID: " << n->id << ", Name: " << n->name << ", Salary: " << n->salary << endl;;
        n=n->next;
    }
    cout<<"\n";
}
int main()
{
    Node* head=NULL;
    push(&head,4, "JANE", 75000);
    push(&head,3, "DIYA", 65000);
    push(&head,2, "ALEX", 90000);
    push(&head,1, "BOB", 60000);
    cout << "Employee Details:" << endl;
    print(head);
    Node* x = maxsalary(head);
    if (x != NULL) {
        cout << "\nEmployee with the highest salary:\n";
        cout << "ID: " << x->id << ", Name: " << x->name << ", Salary: " << x->salary << endl;
    } else {
        cout << "\nNo employees found.\n";
    }
    return 0;
}
