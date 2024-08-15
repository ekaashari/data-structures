#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    double salary;
};

void bubbleSort(Employee a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j].salary > a[j + 1].salary) {
                Employee temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee emp[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name of employee " << i + 1 << ": ";
        cin >> emp[i].name;
        cout << "Enter salary of employee " << i + 1 << ": ";
        cin >> emp[i].salary;
    }

    bubbleSort(emp, n);

    cout << "\nEmployees sorted by salary in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cout << emp[i].name << " - " << emp[i].salary << endl;
    }
    return 0;
}
