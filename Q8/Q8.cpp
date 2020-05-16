#include <bits/stdc++.h>

using namespace std;


void leastSquare(vector<double>& x, vector<double>& y) {
    double xsum = 0, x2sum = 0, ysum = 0, xysum = 0;
    double a0, a1;
    int    n = y.size();


    for (int i = 0; i < n; i++) {
        // sum of x
        xsum += x[i];

        // sum of y
        ysum += y[i];

        // sum of x squared
        x2sum += pow(x[i], 2);

        // sum of x*y
        xysum += x[i] * y[i];
    }

    // calculate slope
    a1 = (n * xysum - xsum * ysum) / (n * x2sum - xsum * xsum);

    // calculate intercept
    a0 = (ysum / n) - a1 * (xsum / n);

    double sr, st;

    for (int i = 0; i < y.size(); i++) {
        sr += pow(y[i] - a0 - a1 * x[i], 2);
        st += pow(y[i] - (ysum / n), 2);
    }

    double r = (st - sr) / st;
    cout << r << endl;
}

int main() {
    vector<double> m1 = { 8.953, 16.405, 22.607, 27.769, 32.065, 35.641, 38.617, 41.095, 43.156, 44.872, 46.301, 47.490, 48.479, 49.303, 49.988 };
    vector<double> m2 = { 11.240, 18.570, 23.729, 27.556, 30.509, 32.855, 34.766, 36.351, 37.687, 38.829, 39.816, 40.678, 41.437, 42.110, 42.712 };
    vector<double> y  = { 10.00, 16.30, 23.00, 27.50, 31.00, 35.60, 39.00, 41.50, 42.90, 45.00, 46.00, 45.50, 46.00, 49.00, 50.00 };
    vector<double> x  = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

    int n = x.size();

    cout << "Goodness of OG data" << endl;
    leastSquare(x, y);

    cout << "Goodness of M1" << endl;
    leastSquare(x, m1);

    cout << "Goodness of M2" << endl;
    leastSquare(x, m1);

    for (int i = 0; i < n; i++) {
        m1[i] = log10(m1[i]);
        m2[i] = log10(m2[i]);
        y[i]  = log10(y[i]);
        x[i]  = log10(x[i]);
    }


    cout << "Goodness of OG data" << endl;
    leastSquare(x, y);


    cout << "Goodness of M1" << endl;
    leastSquare(x, m1);

    cout << "Goodness of M2" << endl;
    leastSquare(x, m1);

    return 0;
}
