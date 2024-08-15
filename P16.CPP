#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
};
void insertFront(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}
void modifyList(Node* head) {
    if (head == nullptr) {
        return;
    }
    int totalSum = 0;
    Node* temp = head;
    do {
        totalSum += temp->data;
        temp = temp->next;
    } while (temp != head);

    temp = head;
    do {
        temp->data = totalSum - temp->data;
        temp = temp->next;
    } while (temp != head);
}
void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    Node* head = NULL;

    insertFront(head,8);
    insertFront(head,7);
    insertFront(head,6);
    insertFront(head,5);
    insertFront(head,4);
    cout << "Original Circular Doubly Linked List: ";
    print(head);

    modifyList(head);
    cout << "Modified Circular Doubly Linked List: ";
    print(head);
    return 0;
}
