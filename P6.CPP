#include <iostream>
using namespace std;

class Student {
public:
    string name;
    double grade;
};

void selectionSortByGrade(Student s[],int n) {
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j].grade < s[mini].grade) {
                mini= j;
            }
        }
        Student temp = s[mini];
        s[mini] = s[i];
        s[i] = temp;
    }
}
int main() {
    int n;
    cout << "Enter the number of Students: ";
    cin >> n;

    Student s[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name of Student " << i + 1 << ": ";
        cin >> s[i].name;
        cout << "Enter grade of Student " << i + 1 << ": ";
        cin >> s[i].grade;
    }

    selectionSortByGrade(s, n);

    cout << "\nStudents sorted by grade in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].name << " - " << s[i].grade << endl;
    }
    return 0;
}
