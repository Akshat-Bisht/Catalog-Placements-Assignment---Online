/*
 * Shamir's Secret Sharing Implementation
 * 
 * This program implements a simplified version of Shamir's Secret Sharing algorithm
 * to find the constant term of a polynomial given encoded roots.
 * 
 * Author: Akshat Bisht
 * Date: 28 July 2025
 * Assignment: Catalog Placements Assignment - Online
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Converts a number from any base (2-36) to decimal
 * @param value: String representation of the number
 * @param base: Base of the input number (2-36)
 * @return: Decimal equivalent as long long
 */
long long convertToDecimal(const string& value, int base) {
    long long result = 0;
    long long power = 1;

    // Process digits from right to left
    for (int i = value.length() - 1; i >= 0; i--) {
        char digit = value[i];
        int digitValue;

        // Convert character to numeric value
        if (digit >= '0' && digit <= '9') {
            digitValue = digit - '0';
        } else if (digit >= 'A' && digit <= 'Z') {
            digitValue = digit - 'A' + 10;
        } else if (digit >= 'a' && digit <= 'z') {
            digitValue = digit - 'a' + 10;
        } else {
            continue; // Skip invalid characters
        }

        // Validate digit is within base range
        if (digitValue >= base) {
            cerr << "Error: Invalid digit '" << digit << "' for base " << base << endl;
            return -1;
        }

        result += digitValue * power;
        power *= base;
    }

    return result;
}

/**
 * Performs Lagrange interpolation to find f(x) for given points
 * @param points: Vector of (x, y) coordinate pairs
 * @param x: The x-value to evaluate the polynomial at (default: 0 for constant term)
 * @return: The interpolated value at x
 */
double lagrangeInterpolation(const vector<pair<int, long long>>& points, int x = 0) {
    int n = points.size();
    double result = 0.0;

    // Calculate Lagrange interpolation formula
    for (int i = 0; i < n; i++) {
        double term = points[i].second; // yi

        // Calculate the Lagrange basis polynomial Li(x)
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (double)(x - points[j].first) / (double)(points[i].first - points[j].first);
            }
        }

        result += term;
    }

    return result;
}

/**
 * Processes a test case and finds the secret (constant term)
 * @param testData: Map containing the encoded points
 * @param k: Minimum number of points required
 * @param testCaseNumber: Test case identifier for output
 * @return: The secret value
 */
long long processTestCase(const map<string, pair<string, string>>& testData, 
                         int k, int testCaseNumber) {

    cout << "\n=== Processing Test Case " << testCaseNumber << " ===" << endl;
    cout << "Minimum points required (k): " << k << endl;
    cout << "\nDecoding points:" << endl;

    vector<pair<int, long long>> points;

    // Decode all available points
    for (const auto& entry : testData) {
        int x = stoi(entry.first);
        int base = stoi(entry.second.first);
        string encodedValue = entry.second.second;

        long long y = convertToDecimal(encodedValue, base);

        if (y == -1) {
            cerr << "Error decoding point for x = " << x << endl;
            continue;
        }

        points.push_back({x, y});
        cout << "  Point (" << x << ", " << y << ") <- '" << encodedValue 
             << "' (base " << base << ")" << endl;
    }

    // Verify we have enough points
    if (points.size() < k) {
        cerr << "Error: Insufficient points for interpolation. Need " << k 
             << ", got " << points.size() << endl;
        return -1;
    }

    // Use exactly k points for interpolation (first k points)
    vector<pair<int, long long>> selectedPoints(points.begin(), points.begin() + k);

    cout << "\nUsing " << k << " points for Lagrange interpolation..." << endl;

    // Find the secret by evaluating polynomial at x = 0
    double secret = lagrangeInterpolation(selectedPoints, 0);

    cout << "Secret (constant term): " << fixed << setprecision(0) << secret << endl;

    return (long long)round(secret);
}

int main() {
    cout << "Shamir's Secret Sharing - Polynomial Reconstruction" << endl;
    cout << "=================================================" << endl;

    // Test Case 1 Data
    map<string, pair<string, string>> testCase1 = {
        {"1", {"10", "4"}},
        {"2", {"2", "111"}},
        {"3", {"10", "12"}},
        {"6", {"4", "213"}}
    };

    // Process Test Case 1
    long long secret1 = processTestCase(testCase1, 3, 1);

    // Test Case 2 Data  
    map<string, pair<string, string>> testCase2 = {
        {"1", {"6", "13444211440455345511"}},
        {"2", {"15", "aed7015a346d63"}},
        {"3", {"15", "6aeeb69631c227c"}},
        {"4", {"16", "e1b5e05623d881f"}},
        {"5", {"8", "316034514573652620673"}},
        {"6", {"3", "2122212201122002221120200210011020220200"}},
        {"7", {"3", "20120221122211000100210021102001201112121"}},
        {"8", {"6", "20220554335330240002224253"}},
        {"9", {"12", "45153788322a1255483"}},
        {"10", {"7", "1101613130313526312514143"}}
    };

    // Process Test Case 2
    long long secret2 = processTestCase(testCase2, 7, 2);

    // Final Results
    cout << "\n" << string(50, '=') << endl;
    cout << "FINAL RESULTS" << endl;
    cout << string(50, '=') << endl;
    cout << "Test Case 1 Secret: " << secret1 << endl;
    cout << "Test Case 2 Secret: " << secret2 << endl;
    cout << string(50, '=') << endl;

    return 0;
}

/*
 * Algorithm Explanation:
 * 
 * 1. Base Conversion:
 *    - Each point has an encoded Y value in a specific base
 *    - Convert each encoded value to decimal using positional notation
 *    - Formula: value = sum(digit_i * base^i) for i from 0 to n-1
 * 
 * 2. Lagrange Interpolation:
 *    - Given k points, we can uniquely determine a polynomial of degree k-1
 *    - The secret is the constant term (coefficient of x^0)
 *    - Evaluate the polynomial at x=0 to get the constant term
 *    - Formula: f(x) = sum(y_i * Li(x)) where Li(x) is the Lagrange basis polynomial
 * 
 * 3. Shamir's Secret Sharing:
 *    - The secret is encoded as the constant term of a polynomial
 *    - Shares are points on this polynomial
 *    - Need at least k shares to reconstruct the secret
 *    - Any k shares will give the same secret value
 */
