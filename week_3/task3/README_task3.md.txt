# Introduction to Classes and Objects — Week 3, Task 3

## About
This task introduces **object-oriented programming (OOP)** using classes and objects in C++. It covers how to define a class, create objects from it, and apply basic **encapsulation** principles. These concepts are foundational for building larger, more maintainable applications.

## Files
| File | Description |
|---|---|
| `classes_and_objects.cpp` | C++ program demonstrating the creation and usage of a `Rectangle` class and its objects |
| `explanation_task3.md` | Explanation of the classes/objects/encapsulation concepts used |
| `README_task3.md` | This file |

## How to Compile & Run
```bash
g++ classes_and_objects.cpp -o classes_and_objects
./classes_and_objects
```

On Windows (MinGW):
```bash
g++ classes_and_objects.cpp -o classes_and_objects.exe
classes_and_objects.exe
```

## What the Program Does
- Defines a `Rectangle` class with private attributes `width` and `height`
- Uses a **constructor** to initialize a new object's data
- Creates two independent `Rectangle` objects, each with its own data
- Provides public methods (`setWidth`, `setHeight`, `getArea`, `getPerimeter`, `displayInfo`) as the only way to read or modify the object's data — demonstrating **encapsulation**
- Includes simple validation so invalid values (e.g., negative height) are rejected

## Deliverables Checklist
- [x] A C++ program demonstrating the creation and usage of classes and objects
- [x] Code documentation (inline comments in `classes_and_objects.cpp`, plus `explanation_task3.md`)
