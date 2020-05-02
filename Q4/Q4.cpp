/*

   Given the following formula for a falling body:

   𝑣= 𝑔𝑚 / 𝑐 * (1−	𝑒,^-(c/m)t)

   where g = 9.8 m/s2 and linear drag c = 10 kg/s.

   Write a C++ program that uses Romberg integration which determines how far the body falls,
   to an approximate error of 1%, in the first 8 seconds when m = 80kg.

 */
#include <bits/stdc++.h>

using namespace std;

double func(double t) {
    double e = exp(1.0);
    double g = 9.81;
    double m = 80.0;
    double c = 10.0;

    return g * m / c * (1 - pow(e, -(c / m) * t));
}

double errorFunction(double total, double current) {
    return (total * current / total) * 100;
}

double multiTrap(double a, double b,  int n) {
    double h      = (b - a) / n;
    double result = func(a) + func(b);

    for (int i = 1; i < n; i++) {
        result += 2 * func(a + i * h);
    }
    result *= (b - a) / (2 * n);

    return result;
}

double rhomberg(double a, double b) {
    int size             = 5;
    int n                = 1;
    double R[size][size] = {};

    // Use Trapazoidal rule to construct [i][1] values
    for (int i = 1; i < size; i++) {
        R[i][1] = multiTrap(a, b, n);
        n      *= 2;
    }

    // Iterate through the rest of the matric and compute using Romberg Formula
    for (int k = 2; k < size; k++) {
        for (int j = 1; j < size - k + 1; j++) {
            R[j][k] = (pow(4, (k - 1)) * R[j + 1][k - 1] - R[j][k - 1]) / (pow(4, (k - 1)) - 1);
        }
    }

    // Print resulting grid
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size - i; j++) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
    return R[1][size - 1];
}

int main() {
    double a      = 0.0;
    double b      = 8.0;
    double actual = 230.969;
    double result = rhomberg(a, b);

    cout << "Result: " << result << endl;

    return 0;
}
