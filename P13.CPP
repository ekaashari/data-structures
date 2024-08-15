//C++ program to reverse every element in the doubly linked list and also reverse and print the reversed
//elements in the doubly linked list
#include <iostream>
using namespace std;
class Node {
public:
    string data;
    Node* prev;
    Node* next;
    Node(string data) : data(data), prev(NULL), next(NULL) {}
};
Node* push(const string arr[], int n) {
    if (n == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* tail = head;

    for (int i = 1; i < n; ++i) {
        Node* newNode = new Node(arr[i]);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    return head;
}
// Function to reverse a string
string reverseString(string str) {
    string reversed = str;
    int left = 0, right = str.length() - 1;
    while (left < right) {
        swap(reversed[left], reversed[right]);
        left++;
        right--;
    }
    return reversed;
}
// Function to reverse the doubly linked list
Node* reverseLL(Node* head) {
    Node* p = NULL;
    Node* q = head;
    // Swap next and prev for all nodes in the list
    while (q != NULL) {
        p = q->prev;
        q->prev = q->next;
        q->next = p;
        q = q->prev;
    }
    if (p != NULL) {
        head = p->prev;
    }

    return head;
}
// Function to reverse every element in the doubly linked list and print the reversed elements
void reverseAndPrint(Node* head) {
    Node* current = head;
    while (current != NULL) {
        current->data = reverseString(current->data);
        current = current->next;
    }

    head = reverseLL(head);

    cout << "[";
    current = head;
    while (current != NULL) {
        cout << "'" << current->data << "'";
        if (current->next != NULL) cout << ",";
        current = current->next;
    }
    cout << "]" << endl;
}
int main() {
    string arr[] = {"apple", "tree", "banana", "cherry", "goa"};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = push(arr, n);

    cout << "Original Elements: [";
    for (int i = 0; i < n; ++i) {
        cout << "'" << arr[i] << "'";
        if (i < n - 1) cout << ",";
    }
    cout << "]" << endl;

    cout << "Reversed Elements: ";
    reverseAndPrint(head);

    return 0;
}

