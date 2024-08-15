//C++ Program to remove duplicates from a sorted linked list.
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void removeDuplicates(Node* head) {
    Node* current = head;
    if (current == NULL) return;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            Node* temp = current->next->next;
            delete current->next;
            current->next = temp;
        } else {
            current = current->next;
        }
    }
}
void push(Node** head,int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
    *head=new_node;
}
void print(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<"\n";
}
int main()
{
    Node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 2);

    cout << "Linked list before duplicate removal " << endl;
    print(head);

    removeDuplicates(head);

    cout << "\nLinked list after duplicate removal "<< endl;
    print(head);

    return 0;
}
