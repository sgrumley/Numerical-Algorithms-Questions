#include <bits/stdc++.h>
#define PI 3.14159265
using namespace std;

double f(double x) {
    return tan(50 * PI / 180.0) * x - (9.81 / 1250 * cos(50 * PI / 180.0) * cos(50 * PI / 180.0)) * pow(x, 2) + 1;
}

double ysection(double m) {
    double a = 1;
    double b = m;
    double c;

    // double n = 0;

    for (int n = 0; n < 80; n++) {
        c = (a + b) / 2;
        cout << a << " " << b << " " << c << endl;
        cout << f(c) << " "  << c << endl;

        if (f(c) > f(c + 1)) {
            b = c;

            // a, c new intervals
        } else {
            a = c + 1;

            // b, c new intervals
        }


        if ((b - a) / pow(2, n + 1) <= 0.01) {
            return c;
        }
    }
}

double bisection() {
    double a = 1;
    double b = 500;
    double c;

    // double n = 0;

    for (int n = 0; n < 15; n++) {
        c = (a + b) / 2;
        cout << a << " " << b << " " << c << endl;
        cout << f(a) << " " << f(b) << " " << f(c) << endl;

        if (f(c) * f(a) < 0) {
            b = c;

            // a, c new intervals
        } else {
            a = c;

            // b, c new intervals
        }


        if ((b - a) / pow(2, n + 1) <= 0.01) {
            // return c;
            return ysection(c);
        }
    }
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

    // test();
    double res = bisection();

    cout << res << endl;

    // printf("x = %.4lf, f(x) = %lf\n", xr, f(xr));
    return 0;
}
