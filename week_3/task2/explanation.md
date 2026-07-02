# OOP Concept Explanation — Introduction to OOP in C++

This document explains the core Object-Oriented Programming (OOP) concepts demonstrated in `oop_intro.cpp`.

## 1. Class
A **class** is a user-defined blueprint or template that groups related data (member variables) and behavior (member functions) together.

In the program, `Student` is a class that models a student, holding data such as name, roll number, marks, and department, along with functions to work with that data.

## 2. Object
An **object** is a concrete instance of a class, created in memory using that class's blueprint.

In `main()`, `s1` and `s2` are objects of the `Student` class. Each object has its own independent copy of the class's data members.

## 3. Constructors
A **constructor** is a special member function that runs automatically when an object is created, typically used to initialize data.

- **Default Constructor** — `Student()` — takes no arguments and sets default values (used for `s1`).
- **Parameterized Constructor** — `Student(string n, int roll, double m, string dept)` — accepts arguments so the object can be initialized with specific values immediately upon creation (used for `s2`).

Constructors have the same name as the class and no return type.

## 4. Encapsulation
**Encapsulation** means bundling data and the methods that operate on it within a class, while restricting direct access to the internal data from outside the class.

In `Student`:
- The data members `name`, `rollNumber`, and `marks` are declared `private`, so they cannot be accessed or modified directly from outside the class (e.g., `s2.marks = 95;` would cause a compile error).
- Public **getter** methods (`getName()`, `getMarks()`, etc.) allow controlled *read* access.
- Public **setter** methods (`setMarks()`, `setDepartment()`) allow controlled *write* access, and can include validation logic (e.g., `setMarks()` rejects values outside 0–100).

This protects the object's internal state from invalid or unintended changes — a key benefit of OOP.

## 5. Access Specifiers
Access specifiers control the visibility of class members:

| Specifier | Accessible From |
|---|---|
| `private` | Only within the same class |
| `protected` | Within the same class and any derived (child) classes |
| `public` | From anywhere the object is visible (outside the class too) |

In the program:
- `private`: `name`, `rollNumber`, `marks` — fully hidden from outside code.
- `protected`: `department` — hidden from outside code, but would be accessible if another class inherited from `Student`.
- `public`: constructors, getters, setters, and `displayInfo()` — the class's public interface.

## Why OOP Matters for Large Programs
As programs grow, organizing code into classes with clear boundaries (encapsulation + access control) makes it:
- Easier to maintain and debug, since data and logic are grouped together
- Safer, since invalid changes to internal data can be prevented (as with `setMarks()` validation)
- More reusable, since classes can be extended through inheritance (using `protected` members)
- Easier to reason about, since each object manages its own state independently
