// COMSC-210 | Lab 12 (STD::array) | Chevin Jeon 
// IDE used: C++11 VS Code
//
// Real-world simulation: Daily step counts for a 30-day fitness tracker.
// - Reads 30 integers from an external file (one per line) into std::array<int, 30>.
// - Demonstrates std::array member functions and iterator-based operations.
// - Validates file open and data length, prints specific error messages, and shows results.


#include <iostream>     // cout, cin
#include <fstream>      // ifstream
#include <array>        // std::array
#include <algorithm>    // min_element, max_element, sort, copy
#include <numeric>      // accumulate
#include <iomanip>      // setw
#include <string>       // string
using namespace std;


//======================== Constants ========================

const string INPUT_FILE = "steps.txt";   // external data file (30 integers, one per line)
const size_t DAYS = 30;                  // required number of elements for the lab
const int FIELD_W = 6;                   // setw width for printing


//==================== Function Prototypes ==================

// loadSteps() reads exactly 30 integers from a file into an std::array
// arguments: const string& filename, array<int, DAYS>& out
// returns: bool (true if success, false otherwise)
bool loadSteps(const string& filename, array<int, DAYS>& steps);


// printArray() prints the array in rows for readability
// arguments: const array<int, DAYS>& steps
// returns: nothing
void printArray(const array<int, DAYS>& steps);

// computeAndPrintStats() shows min, max, sum, average and front/back via member functions
// arguments: const array<int, DAYS>& steps
// returns: nothing
void computeAndPrintStats(const array<int, DAYS>& steps);

// mutateWithDataPointer() demonstrates array::data() by incrementing all elements via raw pointer
// arguments: array<int, DAYS>& steps, int delta
// returns: nothing
void mutateWithDataPointer(array<int, DAYS>& steps, int delta);

// demoArrayMembers() exercises various std::array members: size(), max_size(), at(), front(), back(), fill(), swap()
// arguments: array<int, DAYS>& steps
// returns: nothing
void demoArrayMembers(array<int, DAYS>& steps);


// printSortedTopK() copies to a temp array, sorts it, and prints top K values
// arguments: const array<int, DAYS>& steps, size_t k
// returns: nothing
void printSortedTopK(const array<int, DAYS>& steps, size_t k);


//======================== main() ===========================

int main() {
    // Program header output
    cout << "COMSC-210 | Lab 12 (STD::array) | Your Name\n";
    cout << "Reading 30 daily step counts from file and exercising std::array...\n\n";

    // Declare the std::array. Default-initialized values are unspecified; we'll read into it.
    array<int, DAYS> steps;

    // Load data from file with validation and specific error messages.
    if (!loadSteps(INPUT_FILE, steps)) {
        cout << "Terminating program due to input error.\n";
        return 1;
    }

    // Show the raw data
    cout << "Raw step counts (from file):\n";
    printArray(steps);

    // Demonstrate computations using iterators and member functions
    computeAndPrintStats(steps);

    // Demonstrate various std::array members in action
    demoArrayMembers(steps);

    // Show effect of demo mutations
    cout << "\nAfter demoArrayMembers() mutations:\n";
    printArray(steps);

    // Demonstrate data() pointer-based mutation (increment all days by +100)
    mutateWithDataPointer(steps, /*delta=*/100);
    cout << "\nAfter mutateWithDataPointer(+100) via array::data():\n";
    printArray(steps);

    // Print Top-5 days after sorting a copy (original remains in original order)
    printSortedTopK(steps, 5);

    cout << "\nDone. Program completed successfully.\n";
    return 0;
}
