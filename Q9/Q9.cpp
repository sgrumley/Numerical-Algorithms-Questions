#include <bits/stdc++.h>

using namespace std;

vector<double> xval;
vector<double> yval;

vector<double> yval1;

void dataDump() {
    ofstream myfile;

    myfile.open("graph.txt");

    for (int i = 0; i < xval.size(); i++) {
        myfile << xval[i] << " " << yval[i] << " " << yval1[i] <<  endl;
    }

    myfile.close();
}

double f(double x) {
    return 2510 * log(2800000 / (2800000 - 13300 * x)) - 9.81 * x;
}

double interpolate(int n, double xv, vector<double>& x, vector<double>& y) {
    // Generate divided difference table


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
            cout << setw(j + 1 * 15) << dd[i][j];
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
    int n            = 7;
    double xv        = 3.5;
    vector<double> y = { 2, 5.4375, 7.3516, 7.5625, 8.4453, 9.1875, 12 };
    vector<double> x = { 0, 1, 2.5, 3, 4.5, 5, 6 };

    cout << "f(x) x = 3.5 y = " << interpolate(n, xv, x, y) << endl;

    // for (int i = 0; i < 8; i++) {
    //     double a = interpolate(n, i, x, y);
    //     xval.push_back(i);
    //     yval.push_back(a);
    // }

    x = { 3, 2.5, 4.5, 5, 1, 6, 0 };
    y = { 7.5625, 7.3516, 8.4453, 9.1875, 5.4375, 12, 2 };

    cout << "f(x) x = 3.5 y = " << interpolate(n, xv, x, y);

    // for (int i = 0; i < 8; i++) {
    //     double a = interpolate(n, i, x, y);
    //     yval1.push_back(a);
    // }

    // dataDump();

    return 0;
}
