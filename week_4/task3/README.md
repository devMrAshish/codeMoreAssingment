# Week 4 - Task 3: File I/O Operations

## Overview
This task demonstrates reading data from a file, processing it, and writing the results
to another file using C++ streams (`<fstream>`), with proper error handling throughout.

## Files
- `file_io.cpp` — C++ program that reads numbers from `input.txt`, calculates each
  number's square along with a running total/average, and writes a formatted report
  to `output.txt`.
- `explanation.md` — write-up explaining the file I/O concepts used and their benefits.

## How to Compile and Run

```bash
g++ -std=c++17 -Wall -o file_io file_io.cpp
./file_io
```

### Input
Create an `input.txt` file in the same directory, with one number per line:

```
10
20
5.5
30
```

### Output
The program creates/overwrites `output.txt` with a report like:

```
File I/O Processing Report
==========================

Value	Square
-----	------
10	100
20	400
5.5	30.25
30	900

Total values processed: 4
Sum of values: 65.5
Average: 16.375
```

## Error Handling
- If `input.txt` does not exist or cannot be opened, the program prints a clear error
  message and exits with a non-zero status instead of crashing.
- Lines that aren't valid numbers are skipped with a warning, rather than stopping
  the whole program.
- If the output file cannot be created (e.g., due to permissions), the program reports
  the error instead of failing silently.
- All file-handling errors are surfaced via C++ exceptions (`std::runtime_error`) and
  caught centrally in `main()`.

## Concepts Demonstrated
- `std::ifstream` / `std::ofstream` for reading and writing files
- Checking `is_open()`, `bad()`, and `fail()` for robust error detection
- Parsing text input with `std::istringstream`
- Exception-based error handling (`throw` / `try` / `catch`)
