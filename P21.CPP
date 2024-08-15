#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    char arr[1000];
    int top = -1;

    void push(char c) {
        arr[++top] = c;
    }

    char pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};
string removeStars(string x) {
    Stack s;
 for (int i = 0; i < x.length(); ++i) {
        char ch = x[i];
        if (ch == '*') {
            if (!s.isEmpty()) {
                s.pop();
            }
        } else {
            s.push(ch);
        }
}

    string result = "";
    while (!s.isEmpty()) {
        result = s.pop() + result;
    }

    return result;
}

int main() {
    string x;
    cout << "Enter a string: ";
    cin >> x;

    cout << "Expected Output: " << removeStars(x) << endl;

    return 0;
}
