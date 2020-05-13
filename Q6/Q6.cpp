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

void test() {
    double t = 0.0;
    double v = 0;

    while (v < 335) {
        v = f(t);
        cout << "t" << t << " v " << v << endl;
        t++;
    }
    cout << "Time at 335 m/s " << t << endl;
}

int main() {
    // double xr = secant();

    test();

    // printf("x = %.4lf, f(x) = %lf\n", xr, f(xr));
    return 0;
}
