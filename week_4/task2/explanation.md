# Explanation: Inheritance and Polymorphism

## What the Program Does
The program models different geometric shapes (`Rectangle`, `Circle`, `Triangle`) that all
derive from a common base class, `Shape`. Each derived class implements its own version of
`area()` and `perimeter()`, while sharing common functionality (like `describe()`) from the
base class.

## Inheritance
`Rectangle`, `Circle`, and `Triangle` all inherit from `Shape` using `public` inheritance:

```cpp
class Rectangle : public Shape { ... };
```

This means:
- Each derived class automatically gets the `name` member and the `describe()` method from `Shape`.
- Common logic is written once in the base class instead of being duplicated in every shape.
- Adding a new shape (e.g., `Square`) only requires writing the parts that are unique to it.

## Polymorphism
`Shape` declares `area()` and `perimeter()` as `virtual`. Each derived class overrides them:

```cpp
double area() const override { return width * height; }
```

Because these functions are virtual, calling `shapePtr->describe()` on a `Shape*` (or reference)
automatically invokes the **correct derived-class version** at runtime — this is called
**dynamic dispatch**. The program stores different derived objects in a single
`std::vector<std::unique_ptr<Shape>>` and loops over them, calling the same `describe()` method
on each one, yet getting different, shape-specific results.

A **virtual destructor** (`virtual ~Shape()`) is also included. Without it, deleting a derived
object through a base class pointer would only call the base class destructor, potentially
leaking resources owned by the derived class.

## Benefits of Using These Features

1. **Code Reusability** — Shared behavior (like `describe()`) is written once in the base class
   and reused by every derived class, avoiding duplication.
2. **Flexibility and Extensibility** — New shapes can be added by creating a new derived class
   without modifying existing code (this follows the Open/Closed Principle).
3. **Uniform Interface** — Code that works with `Shape*` or `Shape&` doesn't need to know the
   exact derived type; it can treat all shapes uniformly while still getting correct,
   type-specific behavior.
4. **Maintainability** — Changes to shared logic only need to happen in one place (the base
   class), reducing the risk of inconsistent behavior across shape types.
5. **Safer Resource Management** — A virtual destructor ensures that objects are destroyed
   correctly regardless of which pointer type is used to delete them, preventing memory leaks
   and undefined behavior.

## Summary
Inheritance lets us model an "is-a" relationship (a `Circle` **is a** `Shape`) and reuse code
efficiently, while polymorphism lets that shared interface behave differently depending on the
actual object type at runtime. Together, they make the code more modular, reusable, and easier
to extend.
