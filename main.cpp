#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int rollNumber;
    string grade;
};

vector<Student> loadStudents() {
    vector<Student> students;
    ifstream file("students.txt");
    Student student;

    while (file >> student.rollNumber) {
        file.ignore();
        getline(file, student.firstName, '|');
        getline(file, student.lastName, '|');
        getline(file, student.grade);
        students.push_back(student);
    }

    return students;
}

void saveStudents(const vector<Student>& students) {
    ofstream file("students.txt");

    for (const Student& student : students) {
        file << student.rollNumber << "|"
             << student.firstName << "|"
             << student.lastName << "|"
             << student.grade << "\n";
    }
}

void addStudent() {
    vector<Student> students = loadStudents();
    Student student;

    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cin.ignore();

    for (const Student& current : students) {
        if (current.rollNumber == student.rollNumber) {
            cout << "A student with this roll number already exists.\n";
            return;
        }
    }

    cout << "Enter first name: ";
    getline(cin, student.firstName);

    cout << "Enter last name: ";
    getline(cin, student.lastName);

    cout << "Enter grade: ";
    getline(cin, student.grade);

    students.push_back(student);
    saveStudents(students);
    cout << "Student added successfully.\n";
}

void viewStudents() {
    vector<Student> students = loadStudents();

    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }

    for (const Student& student : students) {
        cout << "\nRoll Number: " << student.rollNumber
             << "\nFirst Name: " << student.firstName
             << "\nLast Name: " << student.lastName
             << "\nGrade: " << student.grade << "\n";
    }
}

void updateStudent() {
    vector<Student> students = loadStudents();
    int rollNumber;
    bool found = false;

    cout << "Enter roll number to update: ";
    cin >> rollNumber;
    cin.ignore();

    for (Student& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "Enter new first name: ";
            getline(cin, student.firstName);

            cout << "Enter new last name: ";
            getline(cin, student.lastName);

            cout << "Enter new grade: ";
            getline(cin, student.grade);

            found = true;
            break;
        }
    }

    if (found) {
        saveStudents(students);
        cout << "Student updated successfully.\n";
    } else {
        cout << "Student not found.\n";
    }
}

void deleteStudent() {
    vector<Student> students = loadStudents();
    int rollNumber;
    bool found = false;

    cout << "Enter roll number to delete: ";
    cin >> rollNumber;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNumber == rollNumber) {
            students.erase(students.begin() + i);
            found = true;
            break;
        }
    }

    if (found) {
        saveStudents(students);
        cout << "Student deleted successfully.\n";
    } else {
        cout << "Student not found.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\nStudent Record Management\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
