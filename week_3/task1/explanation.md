# Code Explanation

This document walks through how `student_record.cpp` satisfies
each requirement of the task: **structures, arrays, functions, and
pointers.**

## 1. Structures

One structure group related data into a single unit:

```cpp
struct Student {
    int    id;
    char   name[50];
    float  marks[3];
    float  average;
};

```

Instead of tracking separate arrays for IDs, names, and marks, each
`Student` bundles everything about one person into one variable —
this is the core idea of data modeling with structures.

## 2. Arrays of Structures

```cpp
Student  students[MAX_RECORDS];

```

Each array holds many records of the same structure type. A running
`count` variable tracks how many slots are actually filled, so the
arrays act like simple, fixed-capacity databases.

## 3. Functions

The program is broken into small, single-purpose functions instead of
one long `main()`:

- `addStudent()` / `addEmployee()` — collect input and store a new record
- `displayStudents()` / `displayEmployees()` — print formatted tables
- `calculateAverage()` — compute a student's average marks


Arrays are passed to functions by passing the array name, which decays
to a pointer to its first element — so functions like
`displayStudents(students, studentCount)` can read the whole array
without copying it. `count` variables that need to be updated by the
function (like in `addStudent`) are passed **by reference** (`int &count`)
so the change is visible back in `main()`.

## 4. Pointers

Pointers show up in distinct ways:

**a) Pointer to a struct, modifying data directly**

```cpp
void calculateAverage(Student *s) {
    float sum = 0;
    for (int i = 0; i < 3; i++) sum += s->marks[i];
    s->average = sum / 3.0f;
}
```

`s->marks` is shorthand for `(*s).marks`. Because `s` is a pointer to
the original struct, changes made here are permanent — no copy is
made.

**b) Passing the address of a local variable**

```cpp
calculateAverage(&s);
```

`&s` takes the address of the local `Student s` and hands it to the
function so it can be modified in place.

**c) A function returning a pointer**

```cpp
Student* findStudentById(Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if ((students + i)->id == id) return (students + i);
    }
    return nullptr;
}
```

`students + i` is **pointer arithmetic** — it moves the pointer
forward by `i` elements (not `i` bytes) to reach the i-th student.
The function returns a pointer directly into the array, or `nullptr`
if nothing matches.

```



## Summary

| Concept | Where it's used |
|---|---|
| Structure definition | 
| Array of structures | `students[]`|
| Function with array parameter | `displayStudents()` |
| Function with reference parameter | `addStudent(..., int &count)` |
| Pointer to struct | `calculateAverage(Student *s)` |
| Pointer arithmetic | `students + i`, `ptr + i` |
| Function returning a pointer | `findStudentById()` |

