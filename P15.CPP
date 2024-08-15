#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
void insertNode(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
// Function to merge two sorted circular linked lists
Node* mergeSorted(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* mergedHead = NULL;
    Node* mergedTail = NULL;

    // Convert circular lists to linear lists for merging
    Node* temp1 = head1;
    while (temp1->next != head1) {
        temp1 = temp1->next;
    }
    temp1->next = NULL;

    Node* temp2 = head2;
    while (temp2->next != head2) {
        temp2 = temp2->next;
    }
    temp2->next = NULL;

    // Merge two sorted linear linked lists
    Node* current1 = head1;
    Node* current2 = head2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data < current2->data) {
            if (mergedHead == NULL) {
                mergedHead = mergedTail = current1;
            } else {
                mergedTail->next = current1;
                mergedTail = current1;
            }
            current1 = current1->next;
        } else {
            if (mergedHead == NULL) {
                mergedHead = mergedTail = current2;
            } else {
                mergedTail->next = current2;
                mergedTail = current2;
            }
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        if (mergedHead == NULL) {
            mergedHead = mergedTail = current1;
        } else {
            mergedTail->next = current1;
            mergedTail = current1;
        }
        current1 = current1->next;
    }

    while (current2 != NULL) {
        if (mergedHead == NULL) {
            mergedHead = mergedTail = current2;
        } else {
            mergedTail->next = current2;
            mergedTail = current2;
        }
        current2 = current2->next;
    }

    // Convert the merged linear list back to a circular linked list
    mergedTail->next = mergedHead;

    return mergedHead;
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
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Insert data into the first circular linked list
    insertNode(head1, 1);
    insertNode(head1, 3);
    insertNode(head1, 5);
    cout << "First Sorted Circular Linked List: ";
    print(head1);

    // Insert data into the second circular linked list
    insertNode(head2, 2);
    insertNode(head2, 4);
    insertNode(head2, 6);
    cout << "Second Sorted Circular Linked List: ";
    print(head2);

    // Merge the two sorted circular linked lists
    Node* mergedList = mergeSorted(head1, head2);
    cout << "Merged Sorted Circular Linked List: ";
    print(mergedList);

    return 0;
}
