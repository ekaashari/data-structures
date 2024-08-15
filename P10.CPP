//Program of find middle of double linked list
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
};
void push(Node** head,int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}
Node* findMiddle(Node* head) {
    if (head == NULL)
        return NULL;

    Node* t1 = head;
    Node* t2 = head;

    while (t2 != NULL && t2->next != NULL) {
        t1 = t1->next;
        t2 = t2->next->next;
    }
    return t1;
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
int main() {
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    print(head);

    Node* middle = findMiddle(head);
    if (middle != NULL)
        cout << "Middle of the Doubly Linked List: " << middle->data << endl;
    else
        cout << "The list is empty." << endl;
    return 0;
}
