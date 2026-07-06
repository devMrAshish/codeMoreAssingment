# Explanation: File I/O Operations

## What the Program Does
The program reads a list of numbers from `input.txt`, computes the square of each number
along with a running sum and average, and writes a formatted report to `output.txt`. It
also demonstrates how to detect and handle problems that can occur when working with files.

## Reading Data (`std::ifstream`)
```cpp
std::ifstream inFile(filename);
if (!inFile.is_open()) {
    throw std::runtime_error("Could not open input file: " + filename);
}
```
`is_open()` confirms the file was actually found and opened before we try to read from it.
Each line is read with `std::getline()` and parsed into a number using `std::istringstream`.
If a line doesn't contain a valid number, the program doesn't crash — it prints a warning
and continues processing the remaining lines.

## Writing Data (`std::ofstream`)
```cpp
std::ofstream outFile(filename);
if (!outFile.is_open()) {
    throw std::runtime_error("Could not open output file: " + filename);
}
```
The results (value, square, total, average) are written to `output.txt` in a clear,
readable format. After writing, `fail()` is checked to catch any error that might have
occurred during the write itself (for example, running out of disk space).

## Error Handling Strategy
Three layers of error handling are used:

1. **Stream state checks** — `is_open()`, `bad()`, and `fail()` are used to detect problems
   at the point they occur (missing file, corrupted stream, failed write).
2. **Exceptions** — Problems are converted into `std::runtime_error` exceptions and thrown,
   rather than having each function silently return an error code that could be ignored.
3. **Centralized handling in `main()`** — A single `try/catch` block in `main()` catches
   any file-related error, prints a clear message, and exits with a non-zero status code
   so the failure is visible to whoever/whatever runs the program.

## Benefits of This Approach

1. **Persistence** — File I/O lets a program store and retrieve data beyond a single run,
   which is essential for real-world applications (logs, configuration, reports, etc.).
2. **Robustness** — Checking stream state before and after operations prevents the program
   from silently producing wrong results or crashing when a file is missing or corrupted.
3. **Clear Failure Reporting** — Using exceptions and a centralized `catch` block means
   errors are reported in one consistent way instead of being scattered throughout the code.
4. **Graceful Degradation** — Invalid individual lines are skipped with a warning instead of
   aborting the entire operation, so a single bad line doesn't waste all the good data.
5. **Separation of Concerns** — Reading, processing, and writing are handled by separate
   functions, making the code easier to test, reuse, and maintain.

## Summary
File I/O operations let a C++ program interact with persistent storage. By combining
`std::ifstream`/`std::ofstream` with careful state checks and exception-based error handling,
the program can reliably read, process, and write data — even when the file system behaves
unexpectedly (missing files, malformed input, or write failures).
