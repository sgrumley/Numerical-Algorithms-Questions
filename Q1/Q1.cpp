#include <bits/stdc++.h>

using namespace std;

double f1(double x) {
    return -0.1 * pow(x, 4) - 0.15 * pow(x, 3) - 0.5 * pow(x, 2) - 0.15 * x + 1.2;

    // return -0.1 * x * x * x * x - 0.15 * x * x * x - 0.5 * x * x - 0.15 * x + 1.2;
}

double df1(double x) {
    return -0.4 * pow(x, 3) - 0.45 * pow(x, 2) - x - 0.15;
}

int main() {
    double x, h, v, error;

    x = 0.5;
    h = 0.25;

    // Approximating difference
    v = (f1(x + h) - f1(x - h)) / (2 * h);

    // calculating error
    error = fabs(df1(x) - v) * 100 / df1(x);
    cout << "Function 1 : Value = " << v << ", Error = " << error << "%" << endl;


    return 0;
}

// Need to figure out the value of h

// find round off error and trunctation error
// use random h steps and put them back into h optimal
