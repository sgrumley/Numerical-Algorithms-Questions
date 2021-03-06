#include <bits/stdc++.h>

using namespace std;

double h[] = { 0, 1.9, 2, 2, 2.4, 2.6, 2.25, 1.12, 0 };
vector<double> hstep;
vector<double> yval;

double func(double x) {
    return h[(int)x];
}

void dataDump() {
    ofstream myfile;

    myfile.open("graph.txt");

    for (int i = 0; i < hstep.size(); i++) {
        myfile << hstep[i] << " " << yval[i] << endl;
    }

    myfile.close();
}

double multiTrap(double a, double b,  int n) {
    double h = (b - a) / pow(2, n);

    hstep.push_back(h);
    yval.push_back(func(h));
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
    dataDump();

    return 0;
}
