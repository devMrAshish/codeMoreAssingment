/*
 * Task: Introduction to Classes and Objects
 * Week 3 - Task 3
 *
 * Goal: Learn how to define a class, create objects from it,
 * and understand the basic principles of encapsulation in C++.
 *
 * Example used: A "Rectangle" class representing a simple shape
 * with width and height, and methods to work with those values.
 */

#include <iostream>
using namespace std;

// ----------------------------------------------------------
// Class definition
// A class is a blueprint that describes what data (attributes)
// and behavior (methods) its objects will have.
// ----------------------------------------------------------
class Rectangle {
private:
    // Attributes (data members) are kept private.
    // This is encapsulation: the internal data is hidden
    // from outside code and can only be changed through
    // the class's own methods.
    double width;
    double height;

public:
    // Constructor: runs automatically when a Rectangle object
    // is created, used to set its initial width and height.
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    // Method to change the width safely (with validation)
    void setWidth(double w) {
        if (w > 0) {
            width = w;
        } else {
            cout << "Width must be positive. Value ignored.\n";
        }
    }

    // Method to change the height safely (with validation)
    void setHeight(double h) {
        if (h > 0) {
            height = h;
        } else {
            cout << "Height must be positive. Value ignored.\n";
        }
    }

    // Method that calculates and returns the area of the rectangle
    double getArea() const {
        return width * height;
    }

    // Method that calculates and returns the perimeter of the rectangle
    double getPerimeter() const {
        return 2 * (width + height);
    }

    // Method to print the rectangle's details
    void displayInfo() const {
        cout << "Rectangle [ width = " << width
             << ", height = " << height << " ]\n";
        cout << "  Area      = " << getArea() << "\n";
        cout << "  Perimeter = " << getPerimeter() << "\n";
    }
};

// ----------------------------------------------------------
// main(): where objects of the Rectangle class are created
// and used.
// ----------------------------------------------------------
int main() {
    cout << "=== Introduction to Classes and Objects ===\n\n";

    // Creating (instantiating) the first object of class Rectangle
    Rectangle rect1(5.0, 3.0);
    cout << "Object 1:\n";
    rect1.displayInfo();

    cout << endl;

    // Creating a second, independent object of the same class.
    // Each object has its own copy of width and height.
    Rectangle rect2(10.0, 2.5);
    cout << "Object 2:\n";
    rect2.displayInfo();

    cout << endl;

    // Modifying an object's data through its public methods,
    // instead of accessing width/height directly (encapsulation)
    cout << "Updating Object 1's dimensions...\n";
    rect1.setWidth(8.0);
    rect1.setHeight(4.0);
    rect1.displayInfo();

    cout << endl;

    // Demonstrating validation built into the class
    cout << "Trying to set an invalid height on Object 2...\n";
    rect2.setHeight(-5.0);
    rect2.displayInfo();

    return 0;
}
