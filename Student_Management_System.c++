#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    float marks;
    char grade;

    void calculateGrade() {
        if (marks >= 80) grade = 'A';
        else if (marks >= 60) grade = 'B';
        else if (marks >= 40) grade = 'C';
        else grade = 'F';
    }

    void display() {
        cout << "Name: " << name 
             << " | Marks: " << marks 
             << " | Grade: " << grade << endl;
    }
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter name: ";
    cin >> s.name;

    cout << "Enter marks: ";
    cin >> s.marks;

    s.calculateGrade();
    students.push_back(s);

    cout << "Student added successfully!\n\n";
}

void viewStudents() {
    if (students.empty()) {
        cout << "No students found.\n\n";
        return;
    }

    for (auto &s : students) {
        s.display();
    }
    cout << endl;
}

void searchStudent() {
    string name;
    cout << "Enter name to search: ";
    cin >> name;

    for (auto &s : students) {
        if (s.name == name) {
            s.display();
            return;
        }
    }

    cout << "Student not found.\n\n";
}

int main() {
    int choice;

    while (true) {
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: return 0;
            default: cout << "Invalid choice\n\n";
        }
    }
}