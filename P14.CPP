#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
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
// Function to swap the first and last nodes of the doubly linked list without using head reference
Node* swapFAndL(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* first = head;
    Node* last = head;

    while (last->next != nullptr) {
        last = last->next;
    }

    if (first->next == last) {
        last->prev = nullptr;
        first->next = nullptr;
        last->next = first;
        first->prev = last;
        head = last;
    } else {
        Node* second = first->next;
        Node* secondLast = last->prev;
        first->next = nullptr;
        first->prev = secondLast;
        // Disconnect last node
        last->next = second;
        last->prev = nullptr;
       second->prev = last;
        // Adjust pointers for the second last node
        secondLast->next = first;
        head = last;
    }
return head;
}
void printl(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
int main() {
     Node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
     cout << "Original list: ";
    printl(head);
 head = swapFAndL(head);
cout << "List after swapping first and last nodes: ";
    printl(head);

    return 0;
}
