Shamir's Secret Sharing Implementation
This project implements a simplified version of Shamir's Secret Sharing algorithm for the Catalog Placements Assignment.

Problem Statement
Given polynomial roots in encoded format, find the constant term (secret) of the polynomial using Lagrange interpolation.

Key Features
✅ Base conversion for decoding Y values (supports bases 2-36)

✅ Lagrange interpolation for polynomial reconstruction

✅ Professional code structure with comprehensive documentation

✅ Error handling and validation

✅ Support for both test cases provided

Algorithm Overview
Decode Y Values: Convert encoded values from various bases to decimal

Select Points: Use minimum required points (k) for interpolation

Lagrange Interpolation: Reconstruct polynomial and evaluate at x=0

Extract Secret: The value at x=0 is the constant term (secret)

Files
shamir_secret_sharing_professional.cpp - Main implementation

COMPILATION_GUIDE.md - Compilation and execution instructions

README.md - This file

Mathematical Foundation
Polynomial Degree: m = k - 1 (where k is minimum points required)

Lagrange Formula: f(x) = Σ(yi × Li(x)) where Li(x) is the Lagrange basis polynomial

Secret Recovery: Evaluate f(0) to get the constant term

Test Cases
Test Case 1: 4 points, k=3, expected secret calculation

Test Case 2: 10 points, k=7, large number handling

Author
Akshat Bisht
akshatbisht7777@gmail.com
28 July 2025
