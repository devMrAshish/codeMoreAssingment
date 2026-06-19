
---
# Pointer concepts in C++
## what is a pointer ? 
A pointer is a variable that stores the memory address of another variable.
Example : 

```cpp
int x=10;
int *ptr=&x;
```

Here:

- `x` stores the value 10
- `&x` gives the memory address of x
- `ptr` stores that address

---

## Dereferencing

Dereferencing means accessing the value stored at the address contained in a pointer.

```cpp
cout << *ptr;
```

Output:

```text
10
```

---

## Pointer Arithmetic

Pointer arithmetic allows movement through memory locations.

```cpp
int arr[5] = {1,2,3,4,5};
int *ptr = arr;

cout << *(ptr + 2);
```

Output:

```text
3
```

---

## Pointer vs Reference

| Pointer | Reference |
|----------|------------|
| Can be reassigned | Cannot be reassigned |
| Can be NULL | Must refer to an object |
| Requires dereferencing | Direct access |
| Uses * and & | Uses & only |

Example:

```cpp
int a = 10;

int *ptr = &a;
int &ref = a;
```

---

## Memory Addresses

Each variable occupies a unique memory location.

```cpp
cout << &a;
```

The address displayed is typically shown in hexadecimal format.

---

## Conclusion

Pointers are powerful tools for memory management, array manipulation, and function parameter passing in C++.
 
 