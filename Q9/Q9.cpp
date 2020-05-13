#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return 2510 * log(2800000 / (2800000 - 13300 * x)) - 9.81 * x;
}

double secant() {
    double x0 = -1, x1 = -1.1, x2;
    double fx0 = f(x0), fx1 = f(x1);

    while (fabs(x1 - x0) >= 0.00001)
    { x2  = (fx1 * x0 - fx0 * x1) / (fx1 - fx0);
      x0  = x1;
      fx0 = fx1;
      x1  = x2;
      fx1 = f(x1); }
    return x2;
}

double interpolate(int n, double xv) {
    // Generate divided difference table
    double y[7] = { 2, 5.4375, 7.3516, 7.5625, 8.4453, 9.1875, 12 };
    double x[7] = { 0, 1, 2.5, 3, 4.5, 5, 6 };

    // double x[] = { -5, -1, 0, 2 };
    // double y[] = { -2, 6, 1, 3 };

    double dd[n][n];

    for (int i = 0; i < n; i++) {
        dd[0][i] = y[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            dd[i][j] = (dd[i - 1][j + 1] - dd[i - 1][j]) / (x[i + j] - x[j]);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << dd[i][j] << " ";
        } cout << endl;
    }

    // Calculate interpolated value
    double result = 0;

    for (int i = 0; i < n; i++) {
        double prod = 1;

        for (int j = 0; j < i; j++) {
            prod *= (xv - x[j]);
        }
        result += prod * dd[i][0];
    }
    return result;
}

int main() {
    int n     = 6;
    double xv = 3.5;

    cout << "final result " << interpolate(n, xv);

    // printf("x = %.4lf, f(x) = %lf\n", xr, f(xr));
    return 0;
}
