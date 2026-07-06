/*
 * Week 4 - Task 3: File I/O Operations
 * -------------------------------------
 * Demonstrates:
 *   - Reading data from an input file
 *   - Processing that data
 *   - Writing the processed result to an output file
 *   - Error handling for file operations (missing file, bad stream state, etc.)
 *
 * Program behavior:
 *   Reads a list of numbers (one per line) from "input.txt", calculates
 *   each number's square and running total, then writes a formatted
 *   report to "output.txt".
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

// Reads numbers from the input file. Throws a std::runtime_error if the
// file cannot be opened, and skips (while warning about) lines that
// aren't valid numbers.
std::vector<double> readNumbersFromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        throw std::runtime_error("Could not open input file: " + filename);
    }

    std::vector<double> numbers;
    std::string line;
    int lineNumber = 0;

    while (std::getline(inFile, line)) {
        lineNumber++;
        if (line.empty()) continue;

        std::istringstream iss(line);
        double value;

        if (iss >> value) {
            numbers.push_back(value);
        } else {
            std::cerr << "Warning: skipping invalid data on line "
                      << lineNumber << ": \"" << line << "\"\n";
        }
    }

    // is_open() true but stream could still have failed mid-read for
    // reasons other than eof (e.g., a device error). Check failbit/badbit
    // that isn't simply eofbit.
    if (inFile.bad()) {
        throw std::runtime_error("I/O error occurred while reading: " + filename);
    }

    inFile.close();
    return numbers;
}

// Processes the numbers (square each) and writes a report to the output
// file. Throws a std::runtime_error if the output file cannot be created.
void writeReportToFile(const std::string& filename, const std::vector<double>& numbers) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        throw std::runtime_error("Could not open output file: " + filename);
    }

    double total = 0.0;

    outFile << "File I/O Processing Report\n";
    outFile << "==========================\n\n";
    outFile << "Value\tSquare\n";
    outFile << "-----\t------\n";

    for (double num : numbers) {
        double square = num * num;
        total += num;
        outFile << num << "\t" << square << "\n";
    }

    outFile << "\nTotal values processed: " << numbers.size() << "\n";
    outFile << "Sum of values: " << total << "\n";

    if (!numbers.empty()) {
        outFile << "Average: " << (total / numbers.size()) << "\n";
    }

    if (outFile.fail()) {
        throw std::runtime_error("I/O error occurred while writing: " + filename);
    }

    outFile.close();
}

int main() {
    const std::string inputFilename = "input.txt";
    const std::string outputFilename = "output.txt";

    try {
        std::vector<double> numbers = readNumbersFromFile(inputFilename);

        if (numbers.empty()) {
            std::cout << "No valid numbers found in " << inputFilename << ".\n";
        }

        writeReportToFile(outputFilename, numbers);

        std::cout << "Success! Processed " << numbers.size()
                  << " values from \"" << inputFilename << "\".\n";
        std::cout << "Report written to \"" << outputFilename << "\".\n";
    }
    catch (const std::runtime_error& e) {
        // Centralized error handling for any file operation failure
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
