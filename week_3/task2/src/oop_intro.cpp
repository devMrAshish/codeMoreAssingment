/*
 * Task: Introduction to OOP in C++
 * Week 3 - Task 2
 *
 * Demonstrates:
 *   - Classes and Objects
 *   - Constructors (default + parameterized)
 *   - Encapsulation (private data, public methods)
 *   - Access Specifiers (private, public, protected)
 */

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    // Private data members -> encapsulation
    // These cannot be accessed directly from outside the class
    string name;
    int rollNumber;
    double marks;

protected:
    // Protected member -> accessible in this class and derived classes,
    // but not from outside code
    string department;

public:
    // ---- Default Constructor ----
    Student() {
        name = "Unknown";
        rollNumber = 0;
        marks = 0.0;
        department = "Not Assigned";
        cout << "[Default Constructor] Student object created.\n";
    }

    // ---- Parameterized Constructor ----
    Student(string n, int roll, double m, string dept) {
        name = n;
        rollNumber = roll;
        marks = m;
        department = dept;
        cout << "[Parameterized Constructor] Student object created for " << name << ".\n";
    }

    // ---- Public Setter methods (controlled access to private data) ----
    void setMarks(double m) {
        if (m >= 0 && m <= 100) {
            marks = m;
        } else {
            cout << "Invalid marks! Must be between 0 and 100.\n";
        }
    }

    void setDepartment(string dept) {
        department = dept;
    }

    // ---- Public Getter methods ----
    string getName() const {
        return name;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    double getMarks() const {
        return marks;
    }

    string getDepartment() const {
        return department;
    }

    // ---- Public method to display student info ----
    void displayInfo() const {
        cout << "-----------------------------\n";
        cout << "Name       : " << name << "\n";
        cout << "Roll No.   : " << rollNumber << "\n";
        cout << "Department : " << department << "\n";
        cout << "Marks      : " << marks << "\n";
        cout << "-----------------------------\n";
    }
};

int main() {
    cout << "=== Introduction to OOP in C++ ===\n\n";

    // Object created using default constructor
    Student s1;
    s1.displayInfo();

    cout << endl;

    // Object created using parameterized constructor
    Student s2("Aditi Sharma", 101, 88.5, "Computer Science");
    s2.displayInfo();

    cout << endl;

    // Demonstrating encapsulation:
    // s2.marks = 95;  // ERROR: 'marks' is private, cannot be accessed directly
    // Instead we must use the public setter method:
    s2.setMarks(95.0);
    cout << "After updating marks using setMarks():\n";
    s2.displayInfo();

    cout << endl;

    // Using getter methods to read private data safely
    cout << s2.getName() << " scored " << s2.getMarks() << " marks.\n";

    // Trying an invalid value to show validation inside the class
    s2.setMarks(150);

    return 0;
}
