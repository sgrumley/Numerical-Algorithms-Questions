#include <bits/stdc++.h>

using namespace std;

vector<double> xval;
vector<double> yval;

void dataDump() {
    ofstream myfile;

    myfile.open("graph.txt");

    for (int i = 0; i < xval.size(); i++) {
        myfile << xval[i] << " " << yval[i] << endl;
    }

    myfile.close();
}

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
    double h = (b - a) / n;


    double result = func(a) + func(b);

    for (int i = 1; i < n; i++) {
        result += 2 * func(a + i * h);
    }
    result *= (b - a) / (2 * n);

    return result;
}

double romberg(double a, double b) {
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
    double result = romberg(a, b);

    cout << "Result: " << result << endl;

    for (; a <= b; a++) {
        xval.push_back(a);
        yval.push_back(func(a));
    }

    dataDump();

    return 0;
}
