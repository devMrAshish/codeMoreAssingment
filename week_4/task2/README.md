# Week 4 - Task 2: Inheritance and Polymorphism

## Overview
This task demonstrates two core object-oriented programming concepts in C++:

- **Inheritance** – building class hierarchies where derived classes reuse and extend a base class.
- **Polymorphism** – using virtual functions so the correct derived-class behavior is chosen at runtime.

## Files
- `shapes.cpp` — C++ program with a `Shape` base class and three derived classes (`Rectangle`, `Circle`, `Triangle`).
- `explanation.md` — write-up explaining how inheritance and polymorphism are used and why they're beneficial.

## How to Compile and Run

```bash
g++ -std=c++17 -Wall -o shapes shapes.cpp
./shapes
```

## Expected Output

```
--- Inheritance and Polymorphism Demo ---

Rectangle -> Area: 24, Perimeter: 20
Circle -> Area: 28.2743, Perimeter: 18.8496
Triangle -> Area: 10, Perimeter: 16

--- End of Demo ---
Destroying shape: Rectangle
Destroying shape: Circle
Destroying shape: Triangle
```

## Concepts Demonstrated
- Base class: `Shape`
- Derived classes: `Rectangle`, `Circle`, `Triangle`
- Virtual functions: `area()`, `perimeter()`
- Virtual destructor for safe cleanup through base pointers
- Runtime polymorphism using a `std::vector<std::unique_ptr<Shape>>`
