# Introduction to OOP in C++ — Week 3, Task 2

## About
This task introduces Object-Oriented Programming (OOP) concepts in C++, including **classes**, **objects**, **encapsulation**, and **access specifiers**. The program demonstrates how OOP helps structure and organize larger programs.

## Files
| File | Description |
|---|---|
| `oop_intro.cpp` | Main C++ program with a `Student` class demonstrating classes, objects, constructors, and encapsulation |
| `explanation.md` | Detailed explanation of the OOP concepts used in the program |
| `README.md` | This file |

## How to Compile & Run
```bash
g++ oop_intro.cpp -o oop_intro
./oop_intro
```

On Windows (using MinGW):
```bash
g++ oop_intro.cpp -o oop_intro.exe
oop_intro.exe
```

## What the Program Does
- Creates a `Student` class with private data members (`name`, `rollNumber`, `marks`) and a protected member (`department`)
- Demonstrates a **default constructor** and a **parameterized constructor**
- Uses **public getter/setter methods** to safely access and modify private data (encapsulation)
- Validates input (marks must be between 0–100) before updating private data
- Displays student information using a public `displayInfo()` method

## Deliverables Checklist
- [x] Program using classes, objects, and constructors
- [x] Output screenshots (to be added after running the program)
- [x] OOP concept explanation (`explanation.md`)
