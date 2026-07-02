# Structures & Basic Data Modeling — Student Record System

**Internship Task:** Week 3, Task 1
**Level:** Beginner | **Duration:** 2–3 Days | **Track:** C++ Development

## About

A console-based mini project that models real-world data using C++
`struct`s. It manages one record types — **Students** —
stored in arrays, manipulated through functions, and updated using
pointers.

## Files

| File | Description |
|---|---|
| `student_record.cpp` | Main source code |
| `README.md` | This file |
| `explanation.md` | Line-by-line / concept-by-concept code walkthrough |

## How to Build & Run

```bash
g++ -std=c++17 -o record_system student_record.cpp
./record_system
```

On Windows (MinGW):

```bash
g++ -std=c++17 -o record_system.exe student_record.cpp
record_system.exe
```

## Features

- Add and display student records (ID, name, marks, computed average)
- Search a student by ID (returns a **pointer** to the record)


## Sample Menu

```
1. Add Student
2. Display All Students
3. Search Student by ID
0. Exit
```

