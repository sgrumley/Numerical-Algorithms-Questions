#include <bits/stdc++.h>

using namespace std;

/*

   The depths of a river H are measured at equally spaced distances across a channel as tabulated below.
   The rivers cross-sectional area can be determined by integration as in:

   𝐴c = Ux->0 𝐻(𝑥)𝑑𝑥

   Write a C++ program that uses Romberg integration to perform the integration to a stopping criterion of 1%

   x, m |       0       2               4       6       8               10		12		14              16
   H, m |       0       1.9     2       2       2.4     2.6     2.25    1.12    0

 */


double h[] = { 0, 1.9, 2, 2, 2.4, 2.6, 2.25, 1.12, 0 };

double func(double x) {
    // cout <<  h[(int)x] << "+";
    return h[(int)x];
}

double multiple_trapezoid_rule(double a, double b,  int segment) {
    double result;
    double step = (b - a) / pow(2, segment);

    cout << b << " - " << a << " / 2^" << segment << endl;
    cout << "step" << step << endl;


    result = func(a) + func(b);

    // cout << result << " + ";

    for (int i = 1; i <= segment; i++) {
        result += 2 * func(a + i * step);
    }

    result *= (b - a) / pow(2, segment);

    // cout << endl << "total: " << result << endl;

    return result;
}

double rhomberg(double a, double b) {
    int n        = 5;
    int segments = 1;
    double I[n][n];

    // set all values to 0.0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) I[i][j] = 0.0;

    // iterate over all segments and pass in values for Trap rule
    for (int i = 1; i < n; i++) {
        I[i][1] = multiple_trapezoid_rule(a, b, segments);
        segments++;
    }

    for (int i = 2; i < n; i++) {
        for (int j = 1; j < n - i + 1; j++) {
            // I[j][i] = (pow(4, (i - 1)) * I[j + 1][i - 1] - I[j][i - 1]) / (pow(4, (i - 1)) - 1);
            // I[i][j] = I[i][j - 1] + ((I[i][j - 1] - I[i - 1][j - 1]) / (pow(4, (i - 1)) - 1));
            I[j][i] = I[j][i - 1] + ((I[j][i - 1] - I[j - 1][i - 1]) / (pow(4, (i - 1)) - 1));
        }
    }

    for (int i = 1; i < n; i++)
    { for (int j = 1; j < n - i; j++) cout << I[i][j] << " ";
      cout << endl; }
    return I[1][n - 1];
}

int main() {
    // double a = 1.0;
    // double b = 2.0;

    double a = 0;
    double b = 16;

    // double a      = 0.0; // Function in lecture slides
    // double b      = 0.8; // Function in lecture slides
    double result = rhomberg(a, b);

    cout << "Result: " << result << endl;


    return 0;
}
