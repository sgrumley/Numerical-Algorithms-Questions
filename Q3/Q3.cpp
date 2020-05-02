/*

   The depths of a river H are measured at equally spaced distances across a channel as tabulated below.
   The rivers cross-sectional area can be determined by integration as in:

   𝐴c = Ux->0 𝐻(𝑥)𝑑𝑥

   Write a C++ program that uses Romberg integration to perform the integration to a stopping criterion of 1%

   x, m |       0       2               4       6       8               10		12		14              16
   H, m |       0       1.9     2       2       2.4     2.6     2.25    1.12    0

 */

#include <bits/stdc++.h>

using namespace std;


double h[] = { 0, 1.9, 2, 2, 2.4, 2.6, 2.25, 1.12, 0 };

double func(double x) {
    return h[(int)x];
}

double multiTrap(double a, double b,  int n) {
    double h      = (b - a) / pow(2, n);
    double result = func(a) + func(b);

    for (int i = 1; i <= n; i++) {
        result += 2 * func(a + i * h);
    }

    result *= (b - a) / pow(2, n);
    return result;
}

double romberg(double a, double b) {
    int size             = 5;
    int n                = 1;
    double R[size][size] = {};

    // Use Trapazoidal rule to construct [i][1] values
    for (int i = 1; i < size; i++) {
        R[i][1] = multiTrap(a, b, n);
        n++;
    }

    // Iterate through the rest of the matric and compute using Romberg Formula
    for (int k = 2; k < size; k++) {
        for (int j = 1; j < size - k; j++) {
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

    return R[1][size - 2];
}

int main() {
    double a      = 0.0;
    double b      = 16.0;
    double result = romberg(a, b);

    cout << "Result: " << result << endl;

    return 0;
}
