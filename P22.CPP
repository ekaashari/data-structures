#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
// Add an element to the rear of the queue
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }



    // Print the queue elements
    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
cout << "Queue after enqueuing 3 elements: ";
    q.printQueue();
     q.dequeue();
    cout << "Queue after dequeuing one element: ";
    q.printQueue();   q.printQueue();
     q.dequeue();
    cout << "Queue after dequeuing one element: ";
    q.printQueue();
return 0;
}
