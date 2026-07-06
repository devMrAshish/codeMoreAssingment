/*
 * Week 4 - Task 2: Inheritance and Polymorphism
 * -----------------------------------------------
 * Demonstrates:
 *   - Base and derived classes (inheritance)
 *   - Virtual functions and dynamic dispatch (runtime polymorphism)
 *   - A virtual destructor for safe cleanup through base pointers
 *   - Use of a base class pointer/reference to call overridden methods
 */

#include <iostream>
#include <vector>
#include <memory>
#include <string>

// ---------------------- Base Class ----------------------
class Shape {
protected:
    std::string name;

public:
    Shape(const std::string& shapeName) : name(shapeName) {}

    // Virtual function - enables runtime polymorphism.
    // Derived classes override this to provide their own behavior.
    virtual double area() const {
        return 0.0;
    }

    virtual double perimeter() const {
        return 0.0;
    }

    // Non-virtual function shared by all shapes (code reuse via inheritance)
    void describe() const {
        std::cout << name << " -> Area: " << area()
                  << ", Perimeter: " << perimeter() << std::endl;
    }

    // Virtual destructor ensures derived class destructors run correctly
    // when deleting through a base class pointer.
    virtual ~Shape() {
        std::cout << "Destroying shape: " << name << std::endl;
    }
};

// ---------------------- Derived Class 1 ----------------------
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }
};

// ---------------------- Derived Class 2 ----------------------
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    double area() const override {
        return 3.14159265 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14159265 * radius;
    }
};

// ---------------------- Derived Class 3 ----------------------
class Triangle : public Shape {
private:
    double base, height, s1, s2, s3;

public:
    Triangle(double b, double h, double side1, double side2, double side3)
        : Shape("Triangle"), base(b), height(h), s1(side1), s2(side2), s3(side3) {}

    double area() const override {
        return 0.5 * base * height;
    }

    double perimeter() const override {
        return s1 + s2 + s3;
    }
};

int main() {
    std::cout << "--- Inheritance and Polymorphism Demo ---\n\n";

    // A collection of base class pointers holding different derived objects.
    // This is the key demonstration of polymorphism: the same interface
    // (describe/area/perimeter) behaves differently depending on the actual
    // object type, resolved at runtime via the vtable.
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Circle>(3.0));
    shapes.push_back(std::make_unique<Triangle>(5.0, 4.0, 5.0, 5.0, 6.0));

    for (const auto& shapePtr : shapes) {
        shapePtr->describe();   // calls the correct overridden version at runtime
    }

    std::cout << "\n--- End of Demo ---\n";
    return 0;
}
