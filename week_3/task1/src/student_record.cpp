/*
 * ============================================================
 *  Mini Project: Student & Employee Record Management System
 * ============================================================
 *  Task: Week 3 - Task 1 (Structures & Basic Data Modeling)
 *
 *  Concepts demonstrated:
 *    1. Structures (grouping related data)
 *    2. Arrays of structures
 *    3. Functions (passing structures/arrays to functions)
 *    4. Pointers (pointer to struct, pointer arithmetic on arrays,
 *       passing by pointer to modify data, function returning a pointer)
 *
 *  Compile:
 *      g++ -std=c++17 -o record_system student_employee_record.cpp
 *  Run:
 *      ./record_system
 * ============================================================
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAX_RECORDS = 50;

// ---------------------------------------------------------
// STRUCTURES
// ---------------------------------------------------------
struct Student {
    int    id;
    char   name[50];
    float  marks[3];   // marks for 3 subjects
    float  average;
};


// ---------------------------------------------------------
// FUNCTION PROTOTYPES
// ---------------------------------------------------------
// Student functions
void addStudent(Student students[], int &count);
void calculateAverage(Student *s);                 // pointer to struct
void displayStudents(const Student students[], int count);
Student* findStudentById(Student students[], int count, int id); // returns pointer


// Utility
void printLine();

// ---------------------------------------------------------
// MAIN
// ---------------------------------------------------------
int main() {
    Student  students[MAX_RECORDS];
    // Employee employees[MAX_RECORDS];
    int studentCount = 0;
    int employeeCount = 0;

    int choice = 0;

    do {
        printLine();
        cout << "  STUDENT & EMPLOYEE RECORD SYSTEM\n";
        printLine();
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "0. Exit\n";
        printLine();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3: {
                int id;
                cout << "Enter Student ID to search: ";
                cin >> id;
                // pointer returned from function
                Student *found = findStudentById(students, studentCount, id);
                if (found != nullptr) {
                    cout << "\nRecord found via pointer:\n";
                    cout << "ID: " << found->id
                         << " | Name: " << found->name
                         << " | Average: " << fixed << setprecision(2)
                         << found->average << "\n";
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }
       
            case 0:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }

    } while (choice != 0);

    return 0;
}

// ---------------------------------------------------------
// FUNCTION DEFINITIONS
// ---------------------------------------------------------

void printLine() {
    cout << "----------------------------------------\n";
}

// Add a new student record into the array
void addStudent(Student students[], int &count) {
    if (count >= MAX_RECORDS) {
        cout << "Student list is full!\n";
        return;
    }

    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    cout << "Enter Student Name: ";
    cin.ignore();
    cin.getline(s.name, 50);

    for (int i = 0; i < 3; i++) {
        cout << "Enter marks for subject " << (i + 1) << ": ";
        cin >> s.marks[i];
    }

    calculateAverage(&s); // pass address of the struct

    students[count] = s;  // store struct copy into the array
    count++;

    cout << "Student added successfully!\n";
}

// Calculates average using a pointer to the struct
// (s->marks is equivalent to (*s).marks)
void calculateAverage(Student *s) {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += s->marks[i];
    }
    s->average = sum / 3.0f;
}

// Displays all students; array is passed (decays to pointer) to the function
void displayStudents(const Student students[], int count) {
    if (count == 0) {
        cout << "No student records yet.\n";
        return;
    }

    printLine();
    cout << left << setw(6) << "ID" << setw(20) << "Name" << "Average\n";
    printLine();

    for (int i = 0; i < count; i++) {
        cout << left << setw(6) << students[i].id
             << setw(20) << students[i].name
             << fixed << setprecision(2) << students[i].average << "\n";
    }
}

// Returns a pointer to the matching student, or nullptr if not found
Student* findStudentById(Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        // pointer arithmetic: (students + i) points to the i-th element
        if ((students + i)->id == id) {
            return (students + i);
        }
    }
    return nullptr;
}
