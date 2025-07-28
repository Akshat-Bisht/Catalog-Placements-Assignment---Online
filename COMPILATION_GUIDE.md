
# Compilation and Execution Guide

## Prerequisites
- C++ compiler (g++, clang++, or Visual Studio)
- C++11 or later standard support

## Compilation
```bash
# Using g++
g++ -std=c++11 -o shamir_secret_sharing shamir_secret_sharing_professional.cpp

# Using clang++
clang++ -std=c++11 -o shamir_secret_sharing shamir_secret_sharing_professional.cpp

# Using Visual Studio (Windows)
cl /EHsc shamir_secret_sharing_professional.cpp
```

## Execution
```bash
# Linux/Mac
./shamir_secret_sharing

# Windows
shamir_secret_sharing.exe
```

## Expected Output
The program will display:
1. Decoded points for each test case
2. Lagrange interpolation process
3. Final secrets for both test cases

## GitHub Repository Structure
```
your-repo/
├── shamir_secret_sharing_professional.cpp
├── README.md
├── test_case_1.json (optional)
├── test_case_2.json (optional)
└── output.txt (sample output)
```

## Sample Output Format
```
Shamir's Secret Sharing - Polynomial Reconstruction
=================================================

=== Processing Test Case 1 ===
Minimum points required (k): 3

Decoding points:
  Point (1, 4) <- '4' (base 10)
  Point (2, 7) <- '111' (base 2)
  Point (3, 12) <- '12' (base 10)
  Point (6, 39) <- '213' (base 4)

Using 3 points for Lagrange interpolation...
Secret (constant term): 3

==================================================
FINAL RESULTS
==================================================
Test Case 1 Secret: 3
Test Case 2 Secret: [calculated_value]
==================================================
```
